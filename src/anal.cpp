#include <anal.hpp>
#include <caxe_util.hpp>
#include <parser_obj.hpp>
#include <vector>
#include <string>
#include <stack>
#include <writer.hpp>

Analyser::Analyser() {}
void Analyser::init(tsDeque<ParserResult>& results,tsDeque<ptr<MFile>>& files,const std::vector<std::string>& search_dir) {
    this->files = files;
    this->search_dir = search_dir;
    this->results = results;
}

size_t Analyser::run() {
    ParserResult result;
    while(results->try_pop(&result)) {
        const std::string& fname = result.file_name;
        if(result.data == Dynamic::null) {
            std::cout << "PARSER ERROR IN " << fname << std::endl;
            continue;
        }

        std::string rname;
        unsigned int mincnt = 0xfffff;
        for(auto i = search_dir->begin(); i!=search_dir->end(); i++) {
            const std::string& dir = *i;
            if(fname.find(dir)==0) {
                std::string rnamex = fname.substr(dir.length());
                while(rname.length()>0 && (rnamex.at(0)=='\\' || rnamex.at(0)=='/')) rnamex.erase(0,1);
                if(rnamex.length() < mincnt) {
                    mincnt = rnamex.length();
                    rname = rnamex;
                }
            }
        }

        const Program& ast = (const Program&)result.data;

        ptr<MFile> mf (new MFile(ast.packages,fname,rname));
        Scope::fileScope(ast.scope, fname, mf);
        files->push(mf);
    }
    return 0;
}
