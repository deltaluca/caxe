#include "parser_obj.hpp"

State::~State() {}

static const char* names[] = {
    "sNoise","sDatum","sNumber","sIdent",
    "sCons",
    "sImport","sMImport",
    "sMScope","sMBrack","sScope","sArgScope","sString",
    "sRealScope",
    "sMixin","sExpand","sDefine",
    "sInstances",
    "sArgument",
    "sCall",
    
    "sSymbol"
};

MFile::MFile(const std::string& package, const std::string& fname, const std::string& rname) {
    this->package = package;
    this->fname = fname;
    this->rname = rname;

    importname = rname.substr(0,rname.length()-3);
    bool pre = false;
    for(unsigned int i = 0; i<importname.length(); i++) {
        char c = importname[i];
        bool cur = (c=='/' || c=='\\');
        if(cur) importname.replace(i,1,pre ? "" : ".");
        pre = cur;
    }

    while(importname[importname.length()-1]=='.') importname.erase(importname.length()-1);
    while(importname[0]=='.') importname.erase(0,1);
}
MFile::MFile(){}

std::ostream& operator<<(std::ostream& out, const MFile& x) {
    return out << x.scope;
}

MIdent::MIdent(/*Symbol*/int x, int y) {
    name = x;
    argc = y;
}
std::ostream& operator<<(std::ostream& out, const MIdent& x) {
    return out << x.name << "/" << x.argc;
}

std::ostream& operator<<(std::ostream& out, const State& x) {
    out << names[x.id];
    return (&x)->print(out);
}

Program::Program(const std::string& pck, const std::vector<ptr<State> >& scope) {
    packages = pck;
    this->scope = scope;
}

std::ostream& operator<<(std::ostream& out, const Program& x) {
    return out << "package=\"" << x.packages << "\" -> " << x.scope;
}

dMImport::dMImport(const std::string& x) {
    this->x = x;
}
dMImport::dMImport() {}

std::ostream& operator<<(std::ostream& out, const dMImport& x) {
    return out << x.x << ":[" << x.xs << "]";
}

dMScopeBrack::dMScopeBrack(std::vector<MIdent>& ms, std::vector<ptr<State> >& x) {
    this->ms = ms;
    this->x = x;
}
dMScopeBrack::dMScopeBrack(std::vector<ptr<State> >& x) {
    this->x = x;
}
dMScopeBrack::dMScopeBrack(){}
std::ostream& operator<<(std::ostream& out, const dMScopeBrack& x) {
    return out << "$[" << x.ms << " -> " << x.x << "]";
}

dMacro::dMacro(MSCOPE scope, std::vector<ptr<State> >& pre, /*Symbol*/int x,
               std::vector</*Symbol*/int>& args, std::vector<ptr<State> >& post) {
    this->scope = scope;
    this->pre = pre;
    this->x = x;
    this->args = args;
    this->post = post;
}
dMacro::dMacro(MSCOPE scope, /*Symbol*/int x,
               std::vector</*Symbol*/int>& args, std::vector<ptr<State> >& post) {
    this->scope = scope;
    this->x = x;
    this->args = args;
    this->post = post;
}
dMacro::dMacro() {}

static const char* mnames[] = {
    "local",
    "global",
    "file",
    "object",
    "method"
};

std::ostream& operator<<(std::ostream& out, const dMacro& x) {
    return out << mnames[x.scope] << " " << x.pre << " \"" << x.x << "\"( " << x.args << " ) -> " << x.post;
}


dArgument::dArgument(int macroid, int cnt) {
    this->macroid = macroid;
    this->cnt = cnt;
}
dArgument::dArgument() {}

std::ostream& operator<<(std::ostream& out, const dArgument& x) {
    return out << "!ARG!";
}

//--------------------------------------------------------------------------------------------------

static std::vector<std::string> SymbolTable;
static std::unordered_map<std::string, int> SymbolMap;
static Mutex symlock;

int GetSymbol(const std::string& name) {
    symlock.acquire();
    auto ite = SymbolMap.find(name);
    if(ite != SymbolMap.end()) {
        symlock.release();
        return (*ite).second;
    }    
    else {
        int id = SymbolTable.size();
        SymbolTable.push_back(name);
        SymbolMap.insert(std::pair<std::string,int>(name,id));
        symlock.release();
        return id;
    }
}

std::string GetSymbol(int id) {
	symlock.acquire();
    std::string& ret = SymbolTable[id];
    symlock.release();
    return ret;
}

