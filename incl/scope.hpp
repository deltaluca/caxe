#ifndef scope_hpp
#define scope_hpp

#include <caxe_util.hpp>
#include <vector>
#include <parser_obj.hpp>
#include <macro.hpp>
#include <unordered_map>
#include <unordered_set>

struct MFile;
struct State;
struct MIdent;

struct Macro;

struct MName {
    ptr<Macro> macro;
    std::vector</*Symbol*/int> args;
    MName(const ptr<Macro>& macro, const std::vector</*Symbol*/int>& args);
    MName();
};

typedef std::unordered_map</*Symbol*/int, ptr<Macro>> MacroHash;

struct Macros {
    MacroHash hash[MAXARG];
    Macros();

    ptr<Macro> find(/*Symbol*/int name, int argc);
    void build(const std::vector<MIdent>&);
    bool empty() const;
};
std::ostream& operator<<(std::ostream& out, const Macros& x);

struct Scope {
    int id;

    ptr<MFile> mfile;
    ptr<Scope> parent, parent_macro;
    bool isglobal;

    bool hasrestricts;
    std::unordered_set</*Symbol*/int> restricts[10];

    bool nobrace;
    bool virtuals;
    bool insular;

    std::vector<ptr<Macro>> macros;
    std::vector<ptr<State>> data;

    //may be null; set to null to reset on transition
    ptr<Scope> _file;
    ptr<Scope> _object;
    ptr<Scope> _method;
    static ptr<Scope> file  (ptr<Scope>&);
    static ptr<Scope> object(ptr<Scope>&);
    static ptr<Scope> method(ptr<Scope>&);

    static ptr<Scope> fileScope(const std::vector<ptr<State>>& ast, const std::string& fname, ptr<MFile> mf);

    Scope(bool nid=true);

    Mutex macmut;
    Mutex test;
    ptr<Macros> macsinscope;
    static ptr<Macros> macros_in_scope(ptr<Scope>);

    static ptr<Scope> halfclone(ptr<Scope> ths);
};

std::ostream& operator<<(std::ostream&, const Scope&);

#endif
