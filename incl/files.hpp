#ifndef file_hpp
#define file_hpp

#include <dirent.h>
#include <fstream>
#include <iostream>

//#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stack>
#include <map>
#include <string>
#include <vector>
//#include <direct.h>

bool isFile(const std::string& path) {
    std::ifstream test;
    test.open(path.c_str(),std::ifstream::in);
    if(!test.good()) return false;
    test.close();
    DIR *dir = opendir(path.c_str());
    if(dir==NULL) return true;
    bool ret = readdir(dir)==NULL;
    closedir(dir);
    return ret;
}
bool isDirectory(const std::string& path) {
    DIR *dir = opendir(path.c_str());
    if(dir==NULL) return false;
    bool ret = readdir(dir)!=NULL;
    closedir(dir);
    return ret;
}

void cdir(const std::string& dir) {
     if(access(dir.c_str(),0)!=0) {
        std::stack<std::string> dirs;
        dirs.push(dir);
        while(!dirs.empty()) {
            std::string dir = dirs.top(); dirs.pop();
            if(access(dir.c_str(),0)==0) {
                if(!isDirectory(dir))
                    printf("OUT ERROR\n");
                else continue;
            }

            if(mkdir(dir.c_str()
#ifndef WINDOWS
	,0777
#endif
	    )!=0) {
                dirs.push(dir);

                size_t c1 = dir.find_last_of('/');
                size_t c2 = dir.find_last_of('\\');

                std::string subdir;
                if(c1!=std::string::npos || c2!=std::string::npos) {
                    if(c1!=std::string::npos && c2!=std::string::npos) {
                        if(c1<c2) subdir = dir.substr(0,c2);
                        else if(c2<c1) subdir = dir.substr(0,c1);
                    }else if(c1!=std::string::npos) subdir = dir.substr(0,c1);
                    else subdir = dir.substr(0,c2);
                }
                if(subdir.length()==0) break;
                dirs.push(subdir);
            }
        }

        if(access(dir.c_str(),0)!=0)
            printf("Unabled to create directory %s\n",dir.c_str());

     }else if(!isDirectory(dir))
         printf("%s is not a directory\n",dir.c_str());
}

std::string directory(const std::string& name) {
    size_t ind1 = name.find_last_of('/');
    size_t ind2 = name.find_last_of('\\');
    if(ind1==std::string::npos && ind2==std::string::npos) return "";
    else if(ind1!=std::string::npos && ind2!=std::string::npos) {
        if(ind1>ind2) return name.substr(0,ind1);
        else return name.substr(0,ind2);
    }else if(ind1!=std::string::npos) return name.substr(0,ind1);
    else               return name.substr(0,ind2);
}
std::string extension(const std::string& name) {
    size_t ind = name.find_last_of('.');
    if(ind!=std::string::npos) return name.substr(ind+1);
    else return "";
}

std::string repair(const std::string& path) {
	std::string ret;
	bool pslash = true;
	for(size_t i = 0; i<path.length(); i++) {
		char c = path.at(i);
		if((c=='/' || c=='\\') && pslash) continue;
		pslash = c=='/' || c=='\\';
		ret.push_back(c);
	}
	return ret;
}

bool notexcluded(const std::vector<std::string>& excludes, const std::string& path) {
	bool ret = true;
	std::string cpath = repair(path);
	for(auto i = excludes.begin(); i!=excludes.end(); i++) {
		if((*i).compare(cpath)==0) {
			ret = false;
			break;
		}
	}
	return ret;
}

void rdir(std::vector<std::string> paths, tsDeque<std::string>& files, const std::vector<std::string>& excludes) {
    for(auto i = paths.begin(); i!=paths.end(); i++) {
        if(access((*i).c_str(),0)!=0) {
            printf("%s not found\n",(*i).c_str());
            return;
        }
    }

    std::map<std::string,bool> fset;
    for(auto i = paths.begin(); i!=paths.end(); i++) {
        std::string& path = *i;
        if(isDirectory(path)) {
            std::stack<std::string> dir; dir.push(path);
            while(!dir.empty()) {
                std::string path = dir.top(); dir.pop();

                struct dirent *dp;
                DIR *xdir = opendir(path.c_str());
                while ((dp=readdir(xdir)) != NULL) {
                    std::string str (dp->d_name);
                    if(str.find_first_not_of('.')!=std::string::npos) {
                        std::string newdir = path + "/" + str;
                        if(isFile(newdir)) {
                            if(extension(newdir).compare("cx")==0
							&& notexcluded(excludes,newdir))
							{
                                if(fset.find(newdir)==fset.end()) {
                                    fset.insert(std::pair<std::string,bool>(newdir,true));
                                    files.push(newdir);
                                }
                            }
                        }else
                            dir.push(newdir);
                    }
                }

                closedir(xdir);
            }
        }else {
            if(extension(path).compare("cx")==0
			&& notexcluded(excludes, path))
			{
                if(fset.find(path)==fset.end()) {
                    fset.insert(std::pair<std::string,bool>(path,true));
                    files.push(path);
                }
            }
        }
    }
}

void rdir(const std::string& path, tsDeque<std::string>& files, const std::vector<std::string>& excludes) {
    std::vector<std::string> paths;
    paths.push_back(path);
    rdir(paths,files,excludes);
}

#endif
