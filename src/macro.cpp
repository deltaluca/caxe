#include "macro.hpp"
#include "subber.hpp"
#include <sstream>

static Mutex idmat;
static int macro_id = 0;

Macro::Macro(const ptr<State>& x) {
    idmat.acquire();
    id = macro_id++;
    idmat.release();

    if(x==ptr<State>::null) return;

    if(x->id == sMixin) {
        const StateMixin& y = (const StateMixin&) *x;
        type = mMixin;
        name = y.data.x;
        argc = y.data.args.size();
    }else if(x->id == sExpand) {
        const StateExpand& y = (const StateExpand&) *x;
        type = mExpand;
        name = y.data.x;
        argc = y.data.args.size();
    }else {
        const StateDefine& y = (const StateDefine&) *x;
        type = mDefine;
        name = y.data.x;
        argc = y.data.args.size();
        preamble = y.data.pre;
    }
}

std::ostream& operator<<(std::ostream& out,const Macro& x) {
    return out << "MACRO! " << x.scope;
}

//-------------------------

static ptr<Macro> half_clone(ptr<Macro> m) {
    ptr<Macro> ret(new Macro(ptr<State>::null));
    ret->id = m->id;
    ret->type = m->type;

    for(auto i = m->preamble.begin(); i!=m->preamble.end(); i++) {
        ptr<State> x = *i;
        if(x->id==sSymbol) {
            StateSymbol& y = (StateSymbol&) *x;
            ret->preamble.push_back(ptr<State>(new StateSymbol(y.data)));
        }else { 
            StateNoise& y = (StateNoise&) *x;
            ret->preamble.push_back(ptr<State>(new StateNoise(y.data)));
        }
    }

    ret->name = m->name;
    ret->argc = m->argc;
    return ret;
}

#include "writer.hpp"

static ptr<Scope> instScope(const ptr<Macro>& self, const ptr<Scope>& s, const std::vector<ptr<State>>& args, const ptr<Scope>& cscope);
static void inst(ptr<Macro> self, std::vector<ptr<State>>& ret, const std::vector<ptr<State>>& post, const std::vector<ptr<State>>& args, ptr<Scope> cscope) {

    for(auto i = post.begin(); i!=post.end(); i++) {
        ptr<State> x = *i;
        if(x->id == sArgument) {
            StateArgument& y = (StateArgument&) *x;
            if(self->id == y.data.macroid) {
                StateRealScope& s = (StateRealScope&) *args[y.data.cnt];
                ptr<Scope> ns = instScope(self, s.data, args, cscope);
                ret.insert(ret.end(), ns->data.begin(), ns->data.end());
                for(auto j = ns->macros.begin(); j!=ns->macros.end(); j++) {
                    ptr<Macro> m = *j;
                    cscope->macros.push_back(m);
                }
            }else
                ret.push_back(x);
        }else if(x->id==sSymbol) {
            //copy it incase concatenation operators modify value later!.
            ret.push_back(ptr<State>(new StateSymbol(((StateSymbol&)*x).data)));
        }else if(x->id==sDatum) {
            ret.push_back(x);
        }else if(x->id==sNumber) {
            ret.push_back(x);
        }else if(x->id==sImport) {
            ret.push_back(x);
        }else if(x->id==sMImport) {
            ret.push_back(x);
        }else if(x->id==sCons) {
            ret.push_back(x);
        }else if(x->id==sNoise) {
            ret.push_back(x);

        }else if(x->id==sString) {
            StateString& y = (StateString&) *x;
            ptr<Scope> sc = ((ptr<StateRealScope>) y.data)->data;
            ptr<Scope> s = instScope(self, sc, args, cscope);
            ret.push_back(ptr<State>(new StateString(ptr<State>(new StateRealScope(s)))));

        }else if(x->id==sCall) {
            StateCall& y = (StateCall&) *x;
            std::vector<ptr<State>> list;
            ptr<StateCall> rx (new StateCall(list));
            for(auto j = y.data.begin(); j!=y.data.end(); j++) {
                ptr<Scope> sc = ((ptr<StateRealScope>) *j)->data;
                sc = instScope(self, sc, args, cscope);
                rx->data.push_back(ptr<State>(new StateRealScope(sc)));
            }
            ret.push_back((ptr<State>)rx);

        }else if(x->id==sRealScope) {
            StateRealScope& y = (StateRealScope&) *x;
            ptr<Scope> ns = instScope(self, y.data,args,cscope);
            if(y.data->virtuals) {
                ret.insert(ret.end(),ns->data.begin(),ns->data.end());
                for(auto j = ns->macros.begin(); j!=ns->macros.end(); j++) {
                    ptr<Macro> m = *j;
                    cscope->macros.push_back(m);
                }
            }else
                ret.push_back(ptr<State>(new StateRealScope(ns)));

        }else if(x->id==sInstances) {
            ptr<Macro> mac = ((StateInstances&)*x).data;
            ptr<Scope> sc = cscope;
            ptr<Macro> nmac;
            while(true) {
                for(auto j = sc->macros.begin(); j!=sc->macros.end(); j++) {
                    ptr<Macro> m = *j;
                    if(m->id == mac->id) {
                        nmac = m;
                        break;
                    }
                }
                if(nmac!=ptr<Macro>::null) break;
                sc = sc->parent;
            }
            ret.push_back(ptr<State>(new StateInstances(nmac)));
        }

    }
}

static ptr<Scope> instScope(const ptr<Macro>& self, const ptr<Scope>& s, const std::vector<ptr<State>>& args, const ptr<Scope>& cscope) {
    ptr<Scope> ret = Scope::halfclone(s);
    for(auto i = s->macros.begin(); i!=s->macros.end(); i++) {
        const ptr<Macro>& omac = *i;
        ptr<Macro> mac = half_clone(omac);
        //handle macros in mac.scope.macros?
        mac->scope = instScope(self, omac->scope,args, ret);
        ret->macros.push_back(mac);
    }

    ret->parent = cscope;
    inst(self, ret->data, s->data, args, ret);

    return ret;
}

static Mutex writelock;

ptr<State> Macro::instantiate(ptr<Macro> self, const std::vector<ptr<State>>& args, const ptr<Scope>& cscope) {
	if(self->type==mMixin) {
		auto sc = instScope(self, self->scope, args, cscope);
		sc->parent_macro = self->scope->parent;
		subs(sc);
		return ptr<State>(new StateRealScope(sc));
	} else {
		std::stringstream str;
		writelock.acquire();
		writer::spaces = false; //disable spacing
		writer::print(str, args);
		writer::spaces = true;
		writelock.release();

		std::string skey = GetSymbol(self->name)+"_"+str.str();
        for(unsigned int i = 0; i<skey.length(); i++) {
            char c = skey[i];
            if(c<=32) skey.erase(i,1);
            else if(!((c>=48&&c<=57)||(c>=65&&c<=90)||(c>=97&&c<=122))) skey.replace(i,1,"_");
        }
        int key = GetSymbol(skey);

        self->instlock.acquire();
        if(self->instances.find(key)==self->instances.end()) {
			ptr<State>& ret = self->instances.insert(std::pair</*Symbol*/int,ptr<State>>(key,ptr<State>::null)).first->second;
            self->instlock.release();

			auto sc = instScope(self, self->scope, args, cscope);
			if(self->type == mDefine) {
				std::vector<ptr<State>> inx;
				inst(self, inx, self->preamble, args, sc);

				sc->data.insert(sc->data.begin(), ptr<State>(new StateSymbol(key)));
				for(auto i = inx.rbegin(); i!=inx.rend(); i++)
					sc->data.insert(sc->data.begin(),*i);
			}
			sc->parent_macro = self->scope->parent;
			subs(sc);
			ret = ptr<State>(new StateRealScope(sc));
		}else
			self->instlock.release();

		if(self->type==mDefine) return ptr<State>(new StateSymbol(key));
		else return ptr<State>::null;
	}
}

