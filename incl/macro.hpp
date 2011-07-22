#define MAXARG 10

#ifndef MACRO_HPP
#define MACRO_HPP

#include <map>
#include <vector>
#include <string>
#include <iostream>

#include <caxe_util.hpp>
#include <parser_obj.hpp>

struct Scope;
struct State;

enum MACRO {
    mMixin,
    mExpand,
    mDefine
};

struct Macro {
    MACRO type;

    int id;

    std::vector<ptr<State>> preamble;
    ptr<Scope> scope;

    std::string name;
    int argc;

    Mutex instlock;
    std::map<std::string,std::vector<ptr<State>>> instances;

    ptr<Scope> parent;
    ptr<Scope> owner;

    Macro(const ptr<State>& x);

    static std::vector<ptr<State>> instantiate(ptr<Macro> self, const std::vector<ptr<State>>& args);
};

std::ostream& operator<<(std::ostream&,const Macro&);

#endif
