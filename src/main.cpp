#include <main.hpp>
#include <caxe_util.hpp>
#include <lexer.hpp>
#include <parse.hpp>
#include <files.hpp>
#include <anal.hpp>
#include <parser_obj.hpp>
#include <imports.hpp>
#include <subber.hpp>
#include <writer.hpp>

#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>

int _threadcnt = 4;

int main(int argc, char* argv[]) {
    if(argc<2) {
        std::cout << "Usage:\n\tcaxe [in_dir]+ [-o out_dir] [-tc thread_count] [--times]\n";
        return 1;
    }

    //-----------------------------------------------------------------

    bool __times = false;

    bool _out = false;
    std::string out;
    std::vector<std::string> cx_args;
    std::vector<std::string> search_dir;

    for(int i = 1; i<argc; i++) {
        std::string arg (argv[i]);
        if(arg.compare("-tc")==0) {
            if(i+1<argc) _threadcnt = atoi(argv[++i]);
            else std::cout << "-tc expected integer argument\n";
        }else if(arg.compare("--times")==0) __times = true;
        else if(arg.compare("-o")==0) {
            if(i+1<argc) {
                out = std::string(argv[++i]);
                _out = true;
            }else std::cout << "-o expects directory for output\n";
        }else {
            cx_args.push_back(arg);
            if(isFile(arg)) search_dir.push_back(directory(arg));
            else search_dir.push_back(arg);
        }
    }

    if(_threadcnt<1) {
        std::cout << "-tc must be >0\n";
        return 1;
    }
    int lpcnt = _threadcnt>>1;
    if(lpcnt<1) lpcnt = 1;

    //-----------------------------------------------------------------

    clock_t clk = clock();

    //-----------------------------------------------------------------

    std::cout << " >> Lex/Parsing files\n";

    tsDeque<std::string> files;

    tsDeque<ptr<TOKEN>>* token_streams = new tsDeque<ptr<TOKEN>>[lpcnt];
    Lexer* lexers = new Lexer[lpcnt];
    Parser* parsers = new Parser[lpcnt];
    tsDeque<ParserResult> results;
    for(int i = 0; i<lpcnt; i++) {
        lexers[i].init(files,token_streams[i]);
        parsers[i].init(token_streams[i],results);
        lexers[i].start();
        parsers[i].start();
    }

    //read files and let lex/parsing commence!
    rdir(cx_args,files);
    for(int i = 0; i<lpcnt; i++) files.push("hlex_eos");

    for(int i = 0; i<lpcnt; i++) {
        lexers[i].wait();
        parsers[i].wait();
    }

    delete [] token_streams;
    delete [] lexers;
    delete [] parsers;
    
    clock_t flpclk = clock();

    //-----------------------------------------------------------------

    std::cout << " >> Analysing ASTs\n";

    tsDeque<ptr<MFile>> mfiles;

    Analyser* ans = new Analyser[_threadcnt];
    for(int i = 0; i<_threadcnt; i++) {
        ans[i].init(results,mfiles,search_dir);
        ans[i].start();
    }

    for(int i = 0; i<_threadcnt; i++)
        ans[i].wait();

    delete [] ans;

    clock_t ansclk = clock();

    //-----------------------------------------------------------------

    //resolving imports, no need to notify such a short task!
    //why I even bothered to thread it... who knows; why not!

    std::deque<ptr<MFile>>::iterator ite = mfiles.list.begin();

    Importer* imp = new Importer[_threadcnt];
    for(int i = 0; i<_threadcnt; i++) {
        imp[i].init(ite,mfiles);
        imp[i].start();
    }

    for(int i = 0; i<_threadcnt; i++)
        imp[i].wait();

    delete [] imp;

    //-----------------------------------------------------------------

    std::cout << " >> Performing macro substitutions\n";

    ite = mfiles.list.begin();

    Subber* sub = new Subber[_threadcnt];
    for(int i = 0; i<_threadcnt; i++) {
        sub[i].init(ite,mfiles);
        sub[i].start();
    }

    for(int i = 0; i<_threadcnt; i++)
        sub[i].wait();

    delete [] sub;
    clock_t subclk = clock();

    //-----------------------------------------------------------------

    if(_out) {
        std::cout << " >> Un-parsing ASTs\n";

        ptr<MFile> mf;
        while(mfiles.try_pop(&mf)) {
            std::string oname = out+"/"+mf->rname.substr(0,mf->rname.length()-3)+".hx";
            cdir(directory(oname));
            std::fstream file;
            file.open(oname.c_str(),std::fstream::out|std::fstream::binary);
            writer::print(file, mf);
            file.flush();
            file.close();
        }
    }

    clock_t fclk = clock();

    //-----------------------------------------------------------------

    if(__times) {
        double dt = double(clock()-clk)/double(CLOCKS_PER_SEC);
        double dt0 = double(flpclk-clk)/double(CLOCKS_PER_SEC);
        double dt1 = double(ansclk-flpclk)/double(CLOCKS_PER_SEC);
        double dt3 = double(subclk-ansclk)/double(CLOCKS_PER_SEC);
        double dt4 = double(fclk-subclk)/double(CLOCKS_PER_SEC);
        std::cout << "--times:\n";
        std::cout << "\tTOTAL:     " << dt << "s\n";
        std::cout << "\n";
        std::cout << "\tlex/parse: " << dt0 << "s\n";
        std::cout << "\tanalysis:  " << dt1 << "s\n";
        std::cout << "\tmacro sub: " << dt3 << "s\n";
        if(_out) std::cout << "\tun-parse:  " << dt4 << "s\n";
    }

    //-----------------------------------------------------------------

    return 0;
}
