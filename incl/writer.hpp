#ifndef writer_hpp
#define writer_hpp

#include "parser_obj.hpp"
#include "scope.hpp"
#include "macro.hpp"
#include "parse.hpp"
#include <vector>

namespace writer {

    extern bool debug;
    extern bool macros;
    extern bool spaces;

    void print(std::ostream&, ptr<MFile>);
    void print(std::ostream&, ptr<State>);
    void print(std::ostream&, ptr<Scope>);
    void print(std::ostream&, const std::vector<ptr<State> >&);

};

#endif
