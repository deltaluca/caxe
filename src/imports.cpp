#include "imports.hpp"

Importer::Importer() {}
void Importer::init(std::deque<ptr<MFile> >::iterator& ite,tsDeque<ptr<MFile> >& files) {
    this->files = files;
    this->ite = ite;
}

static Mutex implock;

int Importer::run() {

    while(true) {
        implock.acquire();
        if(*ite == files->list.end()) {
            implock.release();
            break;
        }
        ptr<MFile>& mfile = *((*ite)++);
        implock.release();

        for(auto xi = mfile->import_states.begin(); xi!=mfile->import_states.end(); xi++) {
            const ptr<State>& x = *xi;
            if(x->id == sImport) {
                const StateImport& y = (const StateImport&) *x;
                ptr<MFile> file;
                for(auto i = files->list.begin(); i!=files->list.end(); i++) {
                    if((*i)->importname.compare(y.data)==0) {
                        file = *i;
                        break;
                    }
                }
                if(file==ptr<MFile>::null) file = ptr<MFile>(new MFile("","",y.data));
                if(file!=mfile) {
                    bool found = false;
                    for(auto k = mfile->imports.begin(); k != mfile->imports.end(); k++) {
                        if(*k==file) {
                            found = true;
                            break;
                        }
                    }
                    if(!found)
                        mfile->imports.push_back(file);
                }
            }else {
                StateMImport& y = (StateMImport&) *x;
                for(auto i = files->list.begin(); i!=files->list.end(); i++) {
                    ptr<MFile> file = (*i);
                    if(file!=mfile && file->importname.find(y.data.x)==0) {
                        bool found = false;
                        for(auto k = mfile->imports.begin(); k != mfile->imports.end(); k++) {
                            if(*k==file) {
                                found = true;
                                break;
                            }
                        }
                        if(!found) {
                            mfile->imports.push_back(file);
                            y.data.xs.push_back(file);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
