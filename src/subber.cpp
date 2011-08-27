#include "subber.hpp"
#include "main.hpp"

static std::vector<ptr<State>> concatenate(const std::vector<ptr<State>>& xs) {
    std::vector<ptr<State>> ret;
    
    /*Symbol*/int* preident = NULL;
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
                    ptr<StateSymbol> nx (new StateSymbol(GetSymbol("")));
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
        }else if(x->id==sSymbol) {
            StateSymbol& y = (StateSymbol&) *x;
            if(precons && preident!=NULL) {
                ret.pop_back();
                (*preident) = GetSymbol(GetSymbol(*preident) + GetSymbol(y.data));
            }else {
                ret.push_back(x);
                preident = &y.data;
            }
            precons = false;
        }else if(x->id==sNumber) {
            StateNumber& y = (StateNumber&) *x;
            if(precons && preident!=NULL) {
                ret.pop_back();
                (*preident) = GetSymbol(GetSymbol(*preident) + y.data);
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

void subs_data(std::vector<ptr<State>>& ret, std::vector<ptr<State>>& in_data, ptr<Macros> macros, ptr<Scope> cscope) {
    std::vector<ptr<State>> data = concatenate(in_data);

    int preident = -1;
    for(auto i = data.begin(); i!=data.end(); i++) {
        ptr<State> x = *i;
        if(x->id==sRealScope) {
            StateRealScope& y = (StateRealScope&) *x;
            subs(y.data);
            ret.push_back(x);
            preident = -1;

        }else if(x->id==sString) {
            StateString& y = (StateString&) *x;
            subs(((StateRealScope&) *y.data).data);
            ret.push_back(x);
            preident = -1;

        }else if(x->id==sSymbol) {
            StateSymbol& y = (StateSymbol&) *x;
            ptr<Macro> macro = macros->find(y.data,0);
            if(macro==ptr<Macro>::null) {
                preident = y.data;
                ret.push_back(x);
            }else {
				std::vector<ptr<State>> args;
				ptr<State> inst = Macro::instantiate(macro,args,cscope);
				if(inst!=ptr<State>::null)
					ret.push_back(inst);
				preident = -1;
            }
        }else if(x->id==sCall) {
            StateCall& y = (StateCall&) *x;
            bool snd = true;
            for(auto i = y.data.begin(); i!=y.data.end(); i++) subs(((StateRealScope&) **i).data);

            if(preident!=-1) {
                ptr<Macro> macro = macros->find(preident,y.data.size());
                if(macro!=ptr<Macro>::null) {
                    snd = false;
                    ret.pop_back();

					ptr<State> inst = Macro::instantiate(macro,y.data,cscope);
					if(inst!=ptr<State>::null)
						ret.push_back(inst);
                }
            }

            if(snd) ret.push_back(x);
            preident = -1;
        }else {
            preident = -1;
            ret.push_back(x);
        }
    }
}

void subs(ptr<Scope> cscope) {
    while(!cscope->test.trylock())
        std::cout << "???????\n";
    std::vector<ptr<State>> data;
    subs_data(data, cscope->data, Scope::macros_in_scope(cscope), cscope);
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
size_t Subber::run() {
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


