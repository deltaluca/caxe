#define MAXARG 20

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

    /*Symbol*/int name;
    int argc;

    Mutex instlock;
    std::map</*Symbol*/int,ptr<State>> instances;

    Macro(const ptr<State>& x);

    static ptr<State> instantiate(ptr<Macro> self, const std::vector<ptr<State>>& args, const ptr<Scope>& cscope);
};

std::ostream& operator<<(std::ostream&,const Macro&);

#endif
