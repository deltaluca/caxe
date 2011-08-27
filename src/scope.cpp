#include "scope.hpp"

std::ostream& operator<<(std::ostream& out, const Scope& x) {
    return out << x.data;
}

MName::MName() {}
MName::MName(const ptr<Macro>& macro, const std::vector</*Symbol*/int>& args) {
    this->args = args;
    this->macro = macro;
}

std::ostream& operator<<(std::ostream& out, const MName& x) {
    return out << x.macro->name << "/{" << x.args << "}";
}

Macros::Macros() {}
std::ostream& operator<<(std::ostream& out, const Macros& x) {
    out << "{";
    bool fst = true;
    for(int i = 0; i<MAXARG; i++) {
        const auto& y = x.hash[i];
        for(auto z = y.begin(); z != y.end(); z++) {
            if(!fst) out << ", ";
            fst = false;
            out << z->first << "/" << i;
        }
    }
    out << "}";
    return out;
}

ptr<Macro> Macros::find(/*Symbol*/int name, int argc) {
    if(argc<0 || argc>=MAXARG) return ptr<Macro>::null;

    MacroHash& hashe = hash[argc];
    MacroHash::iterator ite = hashe.find(name);
    if(ite!=hashe.end()) return ite->second;
    else return ptr<Macro>::null;
}

bool Macros::empty() const {
    for(int i = 0; i<MAXARG; i++)
        if(!hash[i].empty()) return false;
    return true;
}

static Mutex idmut;
static int state_id = 0;

//used to reset file/object/method scopes
static ptr<Scope> RESET (new Scope);

Scope::Scope(bool nid) {
    idmut.acquire();
    id = state_id++;
    idmut.release();
    isglobal = nobrace = virtuals = insular = false;

	parent_macro = ptr<Scope>::null;

    _file = RESET;
    _object = RESET;
    _method = RESET;

    hasrestricts = false;
}

ptr<Scope> Scope::file(ptr<Scope>& cur) {
    if(cur->_file!=RESET) return cur->_file;
    else {
        ptr<Scope> ret = cur;
        while(ret!=ptr<Scope>::null && ret->parent!=ret) ret = ret->parent;
        return cur->_file = ret;
    }
}
ptr<Scope> Scope::object(ptr<Scope>& cur){
    if(cur->_object!=RESET) return cur->_object;
    else {
        ptr<Scope> ret = cur;
        if(ret->parent==ret) return cur->_object = ptr<Scope>::null;
        else {
            while(ret!=ptr<Scope>::null && ret->parent->parent!=ret->parent) ret = ret->parent;
            return cur->_object = ret;
        }
    }
}
ptr<Scope> Scope::method(ptr<Scope>& cur) {
    if(cur->_method!=RESET) return cur->_method;
    else {
        ptr<Scope> ret = cur;
        if(ret->parent==ret) return cur->_method = ptr<Scope>::null;
        else if(ret->parent!=ptr<Scope>::null && ret->parent->parent==ret->parent) return cur->_method = ptr<Scope>::null;
        else {
            while(ret!=ptr<Scope>::null && ret->parent->parent->parent!=ret->parent->parent) ret = ret->parent;
            return cur->_method = ret;
        }
    }
}

static ptr<State> proc(ptr<Scope> cur, ptr<State> x, const std::vector<MName>& names);

ptr<Scope> Scope::fileScope(const std::vector<ptr<State>>& ast, const std::string& fname, ptr<MFile> mf) {
    ptr<Scope> ret (new Scope);
    ret->parent = ret;
    ret->mfile = mf;
    mf->scope = ret;

    mf->globalscope = ptr<Scope>(new Scope);
    ret->virtuals = true;
    mf->globalscope->virtuals = true;
    mf->globalscope->parent = ret;
    mf->globalscope->isglobal = true;

    for(auto i = ast.begin(); i!=ast.end(); i++) {
        std::vector<MName> list;
        ptr<State> j = proc(ret,*i,list);
        if(j!=ptr<State>::null) ret->data.push_back(j);
    }

    return ret;
}

static ptr<Scope> childScope(ptr<Scope> parent, const std::vector<ptr<State>>& ast, const std::vector<MName>& names) {
    ptr<Scope> ret(new Scope);
    ret->parent = parent;

    for(auto i = ast.begin(); i!=ast.end(); i++) {
        ptr<State> j = proc(ret,*i,names);
        if(j!=ptr<State>::null) ret->data.push_back(j);
    }

    return ret;
}

static ptr<Scope> insularScope(ptr<Scope> parent, const std::vector<ptr<State>>& ast, const std::vector<MName>& names) {
    ptr<Scope> ret(new Scope);
    ret->parent = parent;
    ret->insular = true;

    for(auto i = ast.begin(); i!=ast.end(); i++) {
        ptr<State> j = proc(ret,*i,names);
        if(j!=ptr<State>::null) ret->data.push_back(j);
    }

    return ret;
}

static ptr<Scope> getscope(const MSCOPE& x, ptr<Scope> cur) {
    switch(x) {
        case sLocal:  return cur;
        case sGlobal: return cur->insular ? ptr<Scope>::null : Scope::file(cur)->mfile->globalscope;
        case sFile:   return cur->insular ? ptr<Scope>::null : Scope::file(cur);
        case sObject: return cur->insular ? ptr<Scope>::null : Scope::object(cur);
        case sMethod: return cur->insular ? ptr<Scope>::null : Scope::method(cur);
        default:
            return ptr<Scope>::null;
    }
}

ptr<Scope> Scope::halfclone(ptr<Scope> ths) {
    ptr<Scope> ret (new Scope(false));
    ret->id = ths->id;
    ret->insular = ths->insular;
    ret->virtuals = ths->virtuals;
    ret->nobrace = ths->nobrace;
    for(int i = 0; i<MAXARG; i++) ret->restricts[i] = ths->restricts[i];
    ret->hasrestricts = ths->hasrestricts;
    ret->mfile = ths->mfile;
    return ret;
}


Mutex errlock;
static ptr<State> procMacro(ptr<Scope> cur, const std::vector<MName>& names, ptr<State> x, const dMacro& data) {
    MSCOPE acc = data.scope;
    /*Symbol*/int n = data.x;
    const std::vector</*Symbol*/int>& args = data.args;
    const std::vector<ptr<State>>& post = data.post;
    if(args.size()>=MAXARG) {
        errlock.acquire();
        std::cout << "(" << Scope::file(cur)->mfile->rname << ") Error: Too many arguments in macro defn. ";
        if(x->id==sMixin) std::cout << "mixin";
        else if(x->id==sDefine) std::cout << "define";
        else std::cout << "expand";
        std::cout << " macro " << n << "/[";
        for(auto i = args.begin(); i!=args.end(); i++) {
            if(i!=args.begin()) std::cout << ", ";
            std::cout << *i;
        }
        std::cout << "]" << std::endl;
        errlock.release();
    }

    ptr<Scope> sacc = getscope(acc,cur);
    ptr<Macro> mac (new Macro(x));

    std::vector<MName> names2;
    names2.push_back(MName(mac,args));
    for(auto i = names.begin(); i!=names.end(); i++) names2.push_back(*i);

    mac->scope = insularScope(cur,post,names2);
    mac->scope->nobrace = true;

    if(sacc!=ptr<Scope>::null) sacc->macros.push_back(mac);
    else {
        errlock.acquire();
        std::cout << "(" << Scope::file(cur)->mfile->rname << ") Error: Invalid scope in definition of ";
        if(x->id==sMixin) std::cout << "mixin";
        else if(x->id==sDefine) std::cout << "define";
        else std::cout << "expand";
        std::cout << " macro " << n << "/[";
        for(auto i = args.begin(); i!=args.end(); i++) {
            if(i!=args.begin()) std::cout << ", ";
            std::cout << *i;
        }
        std::cout << "]" << std::endl;
        errlock.release();
    }

    if(mac->type!=mMixin)
        return ptr<State>(new StateInstances(mac));
    else
        return ptr<State>::null;
}

static ptr<State> proc(ptr<Scope> cur, ptr<State> x, const std::vector<MName>& names) {
    if(x->id == sSymbol) {
        StateSymbol& y = (StateSymbol&) *x;
        ptr<State> arg;
        
        for(auto i = names.begin(); i!=names.end(); i++) {
            const MName& name = *i;
            int cnt = 0;
            for(auto j = name.args.begin(); j!=name.args.end(); j++) {
                int xarg = *j;
                if(xarg == y.data) {
                    arg = ptr<State>(new StateArgument(dArgument(name.macro->id,cnt)));
                    break;
                }
                cnt++;
            }
            if(arg!=ptr<State>::null)
                break;
        }
        
        if(arg!=ptr<State>::null) return arg;
        else return x;
    }else if(x->id == sScope) {
        StateScope& y = (StateScope&) *x;
        ptr<Scope> s = childScope(cur,y.data,names);
        return ptr<State>(new StateRealScope(s));

    }else if(x->id == sMScope) {
        StateMScope& y = (StateMScope&) *x;
        ptr<Scope> s = childScope(cur,y.data.x,names);
        //s->restricts.build(y.data.ms);
        for(auto ite = y.data.ms.begin(); ite!=y.data.ms.end(); ite++) {
            const MIdent& m = *ite;
            s->restricts[m.argc].insert(m.name);
        }
        s->hasrestricts = true;
        return ptr<State>(new StateRealScope(s));

    }else if(x->id == sMBrack) {
        StateMBrack& y = (StateMBrack&) *x;
        ptr<Scope> s = childScope(cur,y.data.x,names);
        //s->restricts.build(y.data.ms);
        for(auto ite = y.data.ms.begin(); ite!=y.data.ms.end(); ite++) {
            const MIdent& m = *ite;
            s->restricts[m.argc].insert(m.name);
        }
        s->hasrestricts = true;
        s->nobrace = true;
        return ptr<State>(new StateRealScope(s));

    }else if(x->id == sArgScope) {
        StateArgScope& y = (StateArgScope&) *x;
        ptr<Scope> s = insularScope(cur,y.data,names);
        s->virtuals = true;
        return ptr<State>(new StateRealScope(s));

    }else if(x->id == sCall) {
        StateCall& y = (StateCall&) *x;
        ptr<StateCall> s (new StateCall);
        for(auto i = y.data.begin(); i!=y.data.end(); i++)
            s->data.push_back(proc(cur,*i,names));
        return (ptr<State>)s;

    }else if(x->id == sString) {
        StateString& y = (StateString&) *x;
        std::vector<ptr<State>> list; list.push_back(y.data);
        ptr<Scope> s = insularScope(cur, list, names);
        s->virtuals = true;
        return ptr<State>(new StateString(ptr<State>(new StateRealScope(s))));

    }else if(x->id == sMixin)  return procMacro(cur,names,x,((StateMixin &)*x).data);
     else if(x->id == sDefine) return procMacro(cur,names,x,((StateDefine&)*x).data);
     else if(x->id == sExpand) return procMacro(cur,names,x,((StateExpand&)*x).data);

    else if(x->id == sImport) {
        MFile& mf = (MFile&) *Scope::file(cur)->mfile;
        mf.import_states.push_back(x);
        return x;
    }
    else if(x->id == sMImport) {
        MFile& mf = (MFile&) *Scope::file(cur)->mfile;
        mf.import_states.push_back(x);
        return x;
    }

    else
        return x;
}

//----------------------------------------------------------------------

static void merge(ptr<Scope> self, ptr<Macros> ret, ptr<Scope> parent) {	
	ptr<Macros> par = Scope::macros_in_scope(parent);
	for(int i = 0; i<MAXARG; i++) {
		auto& pmap = par->hash[i];
		auto& tmap = ret->hash[i];
		auto& rest = self->restricts[i];
/*!!*/      for(auto ite = pmap.begin(); ite != pmap.end(); ite++) {
/*!*/           if(!self->hasrestricts || rest.find(ite->first)!=rest.end()) {
/*!!*/              tmap.insert(std::pair</*Symbol*/int,ptr<Macro>>(ite->first,ite->second));
			}
		}
	}
}

ptr<Macros> Scope::macros_in_scope(ptr<Scope> self) {
    self->macmut.acquire();
    if(self->macsinscope != ptr<Macros>::null) {
        self->macmut.release();
        return self->macsinscope;
    }

    //can we use parent macro set?
    if(self->macros.empty() && !self->hasrestricts) {
        if(self->parent != self) {
            self->macsinscope = Scope::macros_in_scope(self->parent);
			if(self->parent_macro!=ptr<Scope>::null && self->parent_macro!=self)
				merge(self,self->macsinscope,self->parent_macro);

            self->macmut.release();
            return self->macsinscope;
        }
    }

    //derive it!
    ptr<Macros> ret (new Macros);

    //local macros
    for(auto ite = self->macros.begin(); ite != self->macros.end(); ite++) {
        ptr<Macro>& m = *ite;
        ret->hash[m->argc].insert(std::pair</*Symbol*/int,ptr<Macro>>(m->name,m));
    }

    //restrict set is empty, so no further macros can possibly be visible
    //if discard is non-null, then cannot take this shortcut

    if(self->hasrestricts) {
        //check there are no restrictions
        bool empty = true;
        for(int i = 0; i<MAXARG; i++) {
            if(!self->restricts[i].empty()) {
                empty = false;
                break;
            }
        }
        if(empty) {
            self->macsinscope = ret;
            self->macmut.release();
            return self->macsinscope;
        }
    }

    //if file scope, evaluate globals and imported globals
    if(self->parent == self) {
        const auto& macros = self->mfile->globalscope->macros;
        for(auto ite = macros.begin(); ite!=macros.end(); ite++) {
            const ptr<Macro>& m = *ite;
            ret->hash[m->argc].insert(std::pair</*Symbol*/int,ptr<Macro>> (m->name,m));
        }

        for(auto ite = self->mfile->imports.begin(); ite != self->mfile->imports.end(); ite++) {
            const auto& mfile = (*ite)->globalscope;
            if(mfile!=ptr<MFile>::null) {
                const auto& macros = mfile->macros;
                for(auto jte = macros.begin(); jte!=macros.end(); jte++) {
                    ptr<Macro> m = *jte;
                    ret->hash[m->argc].insert(std::pair</*Symbol*/int,ptr<Macro>> (m->name,m));
                }
            }
        }
    }
    //otherwise query parent macros and unify with restriction
    else
		merge(self,ret,self->parent);

	//merge with macro parent macros
	if(self->parent_macro!=ptr<Scope>::null && self->parent_macro!=self)
		merge(self,ret,self->parent_macro);

    self->macsinscope = ret;
    self->macmut.release();
    return self->macsinscope;
}
