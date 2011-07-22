#include "subber.hpp"
#include "main.hpp"

static std::vector<ptr<State>> concatenate(const std::vector<ptr<State>>& xs) {
    std::vector<ptr<State>> ret;
    std::string* preident = NULL;
    bool precons = false;
    
    for(auto i = xs.begin(); i!=xs.end(); i++) {
        ptr<State> x = *i;
        if(x->id==sRealScope) {
            StateRealScope& y = (StateRealScope&) *x;
            ptr<Scope> yscope = y.data;
            if(yscope->data.empty() && yscope->nobrace) {
                if(precons && preident!=NULL)
                    ret.pop_back();
                else {
                    ptr<StateIdent> nx (new StateIdent(""));
                    ret.push_back(ptr<State>(nx));
                    preident = &nx->data;
                }
                precons = false;
            }else {
                precons = false;
                preident = NULL;
                ret.push_back(x);
            }
        }else if(x->id==sCons) {
            if(!precons) {
                if(preident!=NULL) {
                    precons = true;
                    ret.push_back(x);
                }
            }
        }else if(x->id==sIdent) {
            StateIdent& y = (StateIdent&) *x;
            if(precons && preident!=NULL) {
                ret.pop_back();
                (*preident) += y.data;
            }else {
                ret.push_back(x);
                preident = &y.data;
            }
            precons = false;
        }else if(x->id==sNumber) {
            StateNumber& y = (StateNumber&) *x;
            if(precons && preident!=NULL) {
                ret.pop_back();
                (*preident) += y.data;
            }else {
                if(precons)
                    ret.pop_back();
                ret.push_back(x);
            }
            precons = false;
        }else {
            precons = false;
            preident = NULL;
            ret.push_back(x);
        }
    }

    return ret;
}

void subs_data(std::vector<ptr<State>>& ret, std::vector<ptr<State>>& in_data, ptr<Macros> macros) {
    std::vector<ptr<State>> data = concatenate(in_data);

    ref<std::string> preident;
    for(auto i = data.begin(); i!=data.end(); i++) {
        ptr<State> x = *i;
        if(x->id==sRealScope) {
            StateRealScope& y = (StateRealScope&) *x;
            subs(y.data);
            ret.push_back(x);
            preident = ref<std::string>::null;

        }else if(x->id==sString) {
            StateString& y = (StateString&) *x;
            subs(((StateRealScope&) *y.data).data);
            ret.push_back(x);
            preident = ref<std::string>::null;

        }else if(x->id==sIdent) {
            StateIdent& y = (StateIdent&) *x;
            ptr<Macro> macro = macros->find(y.data,0);
            if(macro==ptr<Macro>::null) {
                preident = y.data;
                ret.push_back(x);
            }else {
                std::vector<ptr<State>> args;
                std::vector<ptr<State>> inst = Macro::instantiate(macro,args);
                subs_data(ret, inst, Scope::macros_in_scope(macro->scope));
            }

        }else if(x->id==sCall) {
            StateCall& y = (StateCall&) *x;
            bool snd = true;
            for(auto i = y.data.begin(); i!=y.data.end(); i++) subs(((StateRealScope&) **i).data);

            if(preident!=ref<std::string>::null) {
                ptr<Macro> macro = macros->find(*preident,y.data.size());
                if(macro!=ptr<Macro>::null) {
                    snd = false;
                    ret.pop_back();
                    std::vector<ptr<State>> inst = Macro::instantiate(macro,y.data);
                    subs_data(ret, inst, Scope::macros_in_scope(macro->scope));
                }
            }

            if(snd) ret.push_back(x);
            preident = ref<std::string>::null;
        }else {
            preident = ref<std::string>::null;
            ret.push_back(x);
        }
    }
}

void subs(ptr<Scope> cscope) {
    while(!cscope->test.trylock())
        std::cout << "???????\n";
    std::vector<ptr<State>> data;
    subs_data(data, cscope->data, Scope::macros_in_scope(cscope));
    cscope->data.swap(data);
    cscope->test.release();
}

//----------------------------------------------------

Subber::Subber() {}
void Subber::init(std::deque<ptr<MFile>>::iterator& ite,tsDeque<ptr<MFile>>& files) {
    this->files = files;
    this->ite = ite;
}

Mutex sublock;
int Subber::run() {
    while(true) {
        sublock.acquire();
        if(*ite == files->list.end()) {
            sublock.release();
            break;
        }
        ptr<MFile> mfile = *((*ite)++);
        sublock.release();

        subs(mfile->scope);
    }

    return 0;
}


