#include <writer.hpp>
#include <caxe_util.hpp>
#include <macro.hpp>
#include <scope.hpp>
#include <parser_obj.hpp>

static Mutex lock;
bool writer::debug = false;
bool writer::macros = false;

static const std::string TAB = "    "; //who else hates \t ?
static std::string tab;
static bool nl; //need new line where applicable
static bool pre; //previous value if applicable needs seperating via whitespace

bool writer::spaces = true;

static bool try_reset() {
    if(lock.trylock()) {
        tab = "";
        nl = false;
        pre = false;
        return true;
    }else return false;
}

void writer::print(std::ostream& out, ptr<MFile> x) {
    bool release = try_reset();

    out << "package " << x->package << ";\n";
    if(debug || macros) {
        out << "\t";
        std::string pretab = tab;
        tab += "\t";
        print(out,x->globalscope);
        tab = pretab;
    }
    print(out,x->scope);
    if(nl) out << "\n";

    if(release) lock.release();
}

void writer::print(std::ostream& out, const std::vector<ptr<State>>& xs) {
    bool release = try_reset();
    for(auto i = xs.begin(); i!=xs.end(); i++) print(out,*i);
    if(release) lock.release();
}

void writer::print(std::ostream& out, ptr<Scope> x) {
    bool release = try_reset();
    if(nl) out << "\n" << tab;
    nl = false;
    if(!x->nobrace && !x->virtuals) {
        out << "{";
        nl = true; pre = false;
    }else if(debug) {
        nl = true; pre = false;
    }

    if(debug) out << "/*";
    if(debug || macros) {
        out << "vis: " << Scope::macros_in_scope(x);
        nl = true;
    }
    if(debug) out << "*/";
    if(debug&&x->parent==x) nl = true;

    if(debug || macros) {
    for(auto i = x->macros.begin(); i!=x->macros.end(); i++) {
        ptr<Macro> m = *i;
        std::string pretab = tab;
        tab += TAB;

        if(nl) out << "\n" << tab;
        out << "--> ";
        if(m->type == mMixin) out << "mixin"; else if(m->type == mDefine) out << "define"; else out << "expand";
        pre = nl = false;
        tab += TAB;
        print(out,m->preamble);

        if(nl) out << "\n" << tab;
        out << " " << m->name << "$" << m->id << "/" << m->argc << "  ";
        pre = false; nl = true;
        tab += TAB;
        print(out,m->scope);
        tab = pretab;
        pre = false;
        nl = true;
    }

    }

    if(x->data.size()==0) { if(!x->nobrace && !x->virtuals) out << "}"; }
    else {
        std::string pretab = tab;
        if(!x->nobrace && !x->virtuals) tab += TAB;
        for(auto i = x->data.begin(); i!=x->data.end(); i++) print(out,*i);
        tab = pretab;
        if(!x->nobrace && !x->virtuals) {
            out << "\n" << tab << "}";
            pre = false;
        }else if(debug) {
            out << "\n" << tab;
            pre = false;
        }
    }

    if(!x->nobrace && !x->virtuals) nl = true;

    if(release) lock.release();
}

void writer::print(std::ostream& out, ptr<State> x) {
    bool release = try_reset();

    if(x->id==sCons) {
        if(debug||macros) out << "`";
        pre = nl = false;

    }else if(x->id==sArgument) {
        StateArgument& y = (StateArgument&) *x;
        if(debug||macros) {
            if(nl) out << "\n" << tab;
            if(pre && !nl) out << " ";
            out << y.data.macroid << "&" << y.data.cnt;
            pre = false;
            nl = false;
        }else {
            if(nl) out << "\n" << tab;
            if(pre && !nl) out << " ";
            out << "ARG[" << y.data.macroid << "&" << y.data.cnt << "]???";
            pre = false;
            nl = false;
        }

    }else if(x->id==sSymbol) {
        StateSymbol& y = (StateSymbol&) *x;
        if(nl) out << "\n" << tab;
        if(pre && !nl && spaces) out << " ";
        nl = false;
        out << GetSymbol(y.data);
        pre = true;
    }else if(x->id==sNoise) {
        StateNoise& y = (StateNoise&) *x;
        if(nl && y.data[0]!=';') out << "\n" << tab;
        out << y.data;
        if(y.data[y.data.length()-1]==';') nl = true;
        else nl = false;
        pre = false;

    }else if(x->id==sDatum) {
        StateDatum& y = (StateDatum&) *x;
        if(nl) out << "\n" << tab;
        if(pre && !nl && spaces) out << " ";
        nl = false;
        out << y.data;
        pre = true;

    }else if(x->id==sNumber) {
        StateNumber& y = (StateNumber&) *x;
        if(nl) out << "\n" << tab;
        if(pre && !nl && spaces) out << " ";
        nl = false;
        out << y.data;
        pre = true;

    }else if(x->id==sCall) {
        StateCall& y = (StateCall&) *x;
        if(nl) out << "\n" << tab;
        out << "(";
        pre = nl = false;
        for(auto i = y.data.begin(); i!=y.data.end(); i++) {
            if(i!=y.data.begin()) { out << ","; pre = false; }
            print(out,*i);
        }
        out << ")";
        nl = pre = false;

    }else if(x->id==sRealScope) {
        StateRealScope& y = (StateRealScope&) *x;
        print(out,y.data);

    }else if(x->id==sImport) {
        StateImport& y = (StateImport&) *x;
        if(nl) { out << "\n" << tab; }
        if(pre && !nl) out << " ";
        out << "import " << y.data << ";";
        nl = true;
        pre = false;

    }else if(x->id==sMImport) {
        StateMImport& y = (StateMImport&) *x;
        dMImport& z = y.data;
        if(debug) {
            if(nl) out << "\n" << tab;
            out << "//$(import " << z.x << ");";
            nl = true;
            pre = false;
        }
        for(auto i = z.xs.begin(); i!=z.xs.end(); i++) {
            if(nl) out << "\n" << tab;
            if(pre && !nl && spaces) out << " ";
            out << "import " << (*i)->importname << ";";
            nl = true;
            pre = false;
        }
        if(debug) {
            if(nl) out << "\n" << tab;
            out << "//end $import";
            nl = true;
            pre = false;
        }

    }else if(x->id==sInstances) {
        StateInstances& y = (StateInstances&) *x;
        if(debug || macros) {
            if(nl) out << "\n" << tab;
            out << "//sInstances(#" << y.data->id << ")";
            nl = true;
            pre = false;
        }
        if(y.data->instances.size()>0)
            if(nl) out << "\n" << tab;

        for(std::map</*Symbol*/int,ptr<State>>::const_iterator i = y.data->instances.begin();
            i!=y.data->instances.end(); i++)
            print(out,i->second);

    }else if(x->id==sString) {
        StateString& y = (StateString&) *x;
        if(nl) out << "\n" << tab;
        out << "\"";
        pre = false;
        nl = false;
        std::string pretab = tab;
        tab = "";
        print(out,y.data);
        tab = pretab;
        out << "\"";
        nl = pre = false;

    } else {
        out << "!!{" << x->id << "}!!";
    }

    if(release) lock.release();
}
