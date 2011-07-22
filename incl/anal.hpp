#ifndef anal_hpp
#define anal_hpp

#include <caxe_util.hpp>
#include <parser_obj.hpp>
#include <parse.hpp>
#include <vector>
#include <string>

class Analyser : public Thread {
    ref<tsDeque<ParserResult> > results;
    ref<tsDeque<ptr<MFile> > > files;
    ref<const std::vector<std::string> > search_dir;

    int run();

public:

    Analyser();
    void init(tsDeque<ParserResult>&,tsDeque<ptr<MFile> >&,const std::vector<std::string>&);
};

#endif
