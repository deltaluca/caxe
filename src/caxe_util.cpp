#include "util.hpp"
#include <deque>
#include <pthread.h>
#include <iostream>
#include <sstream>
#include <cxxabi.h>

std::string NAME__(const char* x) {
    int status;
    char* name = abi::__cxa_demangle(x,0,0,&status);
    return std::string(name);
}

std::ostream& operator<<(std::ostream& out, const ptr<void>& x) {
    if(x.data!=NULL)
        return out << "Dynamic::" << x.data->print();
    else
        return out << "Dynamic::null";
}

Dynamic Dynamic::null;


