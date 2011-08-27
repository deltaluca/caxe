#ifndef parse_obj
#define parse_obj

#include <vector>
#include <deque>
#include <string>
#include <caxe_util.hpp>
#include <scope.hpp>
#include <macro.hpp>

struct Macro;

struct MFile {
    std::string package;
    std::string rname;
    std::string fname;
    ptr<Scope> scope;

    std::vector<ptr<MFile>> imports;
    std::vector<ptr<State>> import_states;

    ptr<Scope> globalscope;
    std::string importname;

    MFile(const std::string& package, const std::string& fname, const std::string& rname);
    MFile();
};

std::ostream& operator<<(std::ostream&, const MFile&);

enum STATE_ID {
    sNoise,sDatum,sNumber,sIdent,
    sCons,
    sImport,sMImport,
    sMScope,sMBrack,sScope,sArgScope,sString,
    sRealScope,
    sMixin,sExpand,sDefine,
    sInstances,
    sArgument,
    sCall,
    
    sSymbol
};

struct State {
    STATE_ID id;

    virtual ~State();
    virtual std::ostream& print(std::ostream&) const = 0;
};

std::ostream& operator<<(std::ostream& out, const State&);

template <STATE_ID ID, typename T = Dynamic>
struct SubState : public State {
    T data;
    SubState(const T& data) {
        this->data = data;
        id = ID;
    }
    SubState() {
        id = ID;
    }
    virtual std::ostream& print(std::ostream& out) const {
        return out << "(" << data << ")";
    }
};

struct Program {
    std::string packages;
    std::vector<ptr<State>> scope;

    Program(const std::string& pck, const std::vector<ptr<State>>& scope);
};

std::ostream& operator<<(std::ostream& out, const Program& x);

//----------------------------------------------------------------------

enum MSCOPE {
    sLocal,sGlobal,sFile,sObject,sMethod
};

struct MIdent {
    /*Symbol*/int name;
    int argc;

    MIdent(/*Symbol*/int x, int y);
};

std::ostream& operator<<(std::ostream&, const MIdent&);

//----------------------------------------------------------------------

typedef SubState<sNoise, std::string> StateNoise;
typedef SubState<sDatum, std::string> StateDatum;
typedef SubState<sNumber,std::string> StateNumber;
//typedef SubState<sIdent, std::string> StateIdent;

typedef SubState<sCons> StateCons;

typedef SubState<sImport,std::string> StateImport;

//----------------------------------------------------------------------

struct dMImport {
    std::string x;
    std::vector<ptr<MFile>> xs;

    dMImport(const std::string& x);
    dMImport();
};

std::ostream& operator<<(std::ostream&, const dMImport&);

typedef SubState<sMImport,dMImport> StateMImport;

//----------------------------------------------------------------------

struct dMScopeBrack {
    std::vector<MIdent> ms;
    std::vector<ptr<State>> x;

    dMScopeBrack(std::vector<MIdent>& ms, std::vector<ptr<State>>& x);
    dMScopeBrack(std::vector<ptr<State>>& x);
    dMScopeBrack();
};

std::ostream& operator<<(std::ostream&, const dMScopeBrack&);

typedef SubState<sMScope, dMScopeBrack> StateMScope;
typedef SubState<sMBrack, dMScopeBrack> StateMBrack;

//----------------------------------------------------------------------

typedef SubState<sScope, std::vector<ptr<State>>> StateScope;
typedef SubState<sArgScope, std::vector<ptr<State>>> StateArgScope;
typedef SubState<sString, ptr<State>> StateString;

typedef SubState<sRealScope, ptr<Scope>> StateRealScope;

//----------------------------------------------------------------------

struct dMacro {
    MSCOPE scope;
    std::vector<ptr<State>> pre;
    /*Symbol*/int x;
    std::vector</*Symbol*/int> args;
    std::vector<ptr<State>> post;

    dMacro(MSCOPE scope, std::vector<ptr<State>>& pre, /*Symbol*/int x,
           std::vector</*Symbol*/int>& args, std::vector<ptr<State>>& post);
    dMacro(MSCOPE scope, /*Symbol*/int x,
           std::vector</*Symbol*/int>& args, std::vector<ptr<State>>& post);
    dMacro();
};

std::ostream& operator<<(std::ostream&, const dMacro&);

typedef SubState<sMixin,  dMacro> StateMixin;
typedef SubState<sExpand, dMacro> StateExpand;
typedef SubState<sDefine, dMacro> StateDefine;

typedef SubState<sInstances, ptr<Macro>> StateInstances;

//----------------------------------------------------------------------

struct dArgument {
    int macroid;
    int cnt;
    dArgument(int macroid, int cnt);
    dArgument();
};

std::ostream& operator<<(std::ostream&, const dArgument&);

typedef SubState<sArgument, dArgument> StateArgument;
typedef SubState<sCall, std::vector<ptr<State>>> StateCall;

//----------------------------------------------------------------------

int GetSymbol(const std::string&);
std::string GetSymbol(int id);

typedef SubState<sSymbol, int> rrStateSymbol;

struct StateSymbol : public rrStateSymbol {
	StateSymbol(int data) : rrStateSymbol(data) {}
	std::ostream& print(std::ostream& out) const {
		return rrStateSymbol::print(out) << "=" << GetSymbol(data);
	}
};

#endif
