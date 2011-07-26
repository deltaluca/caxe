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

int _threadcnt = 1;

int main(int argc, char* argv[]) {
    if(argc<2) {
        std::cout << "For help use --help option\n";
        return 1;
    }
    
    if(std::string(argv[1]).compare("--help")==0) {
        std::cout << "Usage: caxe [in_dir]+ [options...]\n";
        std::cout << "Options:\n";
        std::cout << "\t-o out_dir\n";
        std::cout << "\t\tproduce output in given directory\n";
        std::cout << "\t-tc thread_count\n";
        std::cout << "\t\tuse `thread_count` number of threads for preprocessing\n";
        std::cout << "\t--times\n";
        std::cout << "\t\tproduce benchmarking results in stdout\n";
        return 0;
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

    struct timespec clk; clock_gettime(CLOCK_MONOTONIC, &clk);

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
    
    struct timespec flpclk; clock_gettime(CLOCK_MONOTONIC, &flpclk);

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

    struct timespec ansclk; clock_gettime(CLOCK_MONOTONIC, &ansclk);

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

    struct timespec subclk; clock_gettime(CLOCK_MONOTONIC, &subclk);

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

    struct timespec fclk; clock_gettime(CLOCK_MONOTONIC, &fclk);

    //-----------------------------------------------------------------

    if(__times) {
        struct timespec curclk; clock_gettime(CLOCK_MONOTONIC, &curclk);
        double dt  = double(curclk.tv_sec - clk.tv_sec)    + double(curclk.tv_nsec - clk.tv_nsec   )*1e-9;
        double dt1 = double(flpclk.tv_sec - clk.tv_sec)    + double(flpclk.tv_nsec - clk.tv_nsec   )*1e-9;
        double dt2 = double(ansclk.tv_sec - flpclk.tv_sec) + double(ansclk.tv_nsec - flpclk.tv_nsec)*1e-9;
        double dt3 = double(subclk.tv_sec - ansclk.tv_sec) + double(subclk.tv_nsec - ansclk.tv_nsec)*1e-9;
        double dt4 = double(fclk.tv_sec   - subclk.tv_sec) + double(fclk.tv_nsec   - subclk.tv_nsec)*1e-9;
        std::cout << "--times:\n";
        std::cout << "\tTOTAL:     " << dt << "s\n";
        std::cout << "\n";
        std::cout << "\tlex/parse: " << dt1 << "s\n";
        std::cout << "\tanalysis:  " << dt2 << "s\n";
        std::cout << "\tmacro sub: " << dt3 << "s\n";
        if(_out) std::cout << "\tun-parse:  " << dt4 << "s\n";
    }

    //-----------------------------------------------------------------

    return 0;
}
