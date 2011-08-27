#ifndef subber_hpp
#define subber_hpp

#include <parser_obj.hpp>
#include <caxe_util.hpp>
#include <deque>
#include <vector>
#include <string>

class Subber : public Thread {
    ref<std::deque<ptr<MFile>>::iterator> ite;
    ref<tsDeque<ptr<MFile>>> files;

    size_t run();

public:

    Subber();
    void init(std::deque<ptr<MFile>>::iterator&,tsDeque<ptr<MFile>>&);
};

void subs_data(std::vector<ptr<State>>& ret, std::vector<ptr<State>>& in_data, ptr<Macros> macros);
void subs(ptr<Scope> cscope);

#endif

