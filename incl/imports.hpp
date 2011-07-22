#ifndef imports_hpp
#define imports_hpp

#include <parser_obj.hpp>
#include <caxe_util.hpp>
#include <deque>
#include <vector>
#include <string>

class Importer : public Thread {
    ref<std::deque<ptr<MFile> >::iterator> ite;
    ref<tsDeque<ptr<MFile> > > files;

    int run();

public:

    Importer();
    void init(std::deque<ptr<MFile> >::iterator&,tsDeque<ptr<MFile> >&);
};

#endif
