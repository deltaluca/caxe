#include <parse.hpp>
#include <vector>

    #include <parser_obj.hpp>

    struct RMIXIN {
        /*Symbol*/int x;
        std::vector</*Symbol*/int> y;
        std::vector<ptr<State>> z;

        RMIXIN() {}
        RMIXIN(/*Symbol*/int x, const std::vector</*Symbol*/int>& y, const std::vector<ptr<State>>& z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }
        RMIXIN(/*Symbol*/int x, const std::vector<ptr<State>>& z) {
            this->x = x;
            this->z = z;
        }

        Dynamic build(const MSCOPE& scope) {
            return StateMixin(dMacro(scope,x,y,z));
        }
    };

    #define States std::vector<ptr<State>>

std::ostream& operator<<(std::ostream& out, const ParserResult& x){
	return out << "\"" << x.file_name << "\"->" << x.data;
}
static const int actions[138][56] = 
{{59,0,59,59,59,59,59,59,59,59,0,59,0,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,137,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{35,0,150,154,158,166,170,106,110,190,0,234,0,442,306,310,314,318,126,334,10,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,54,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{59,0,59,59,59,59,59,59,59,59,0,59,0,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{27,0,150,154,158,166,170,106,110,190,0,234,0,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,102,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{59,0,59,59,59,59,59,59,59,59,0,59,0,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{31,0,150,154,158,166,170,106,110,190,0,234,0,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,250,234,0,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,274,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,286,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,290,234,0,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,326,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,422,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,434,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,450,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,454,442,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,111,53,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,259,259,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,60,0,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,154,158,166,170,106,110,190,0,234,255,255,306,310,314,318,126,334,0,94,342,346,350,354,358,362,366,370,374,174,0,94,95,96,97,98,99,0,0,0,60,0,0,0,0,24,19,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,482,486,490,494,498,174,0,125,0,0,0,0,126,0,0,0,0,0,0,0,0,0,0,20,22,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,174,0,125,0,0,0,0,126,0,0,0,0,0,0,0,0,0,0,0,21,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,130,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,174,0,127,0,0,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,134,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,174,0,127,0,0,0,0,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,54,0,0,0,0,0,0,55,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,402,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,54,0,0,0,0,0,0,56,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,57,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,235,0,0,235,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,133,0,0,0,0,0,0,0,0,0,0,0,61,0,0,0,0,0,0,0,116,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,235,0,0,235,0,0,0,0,474,478,254,262,0,0,0,0,0,0,0,0,133,0,0,0,0,0,0,0,0,0,0,0,70,0,0,0,0,0,0,0,116,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,51,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,64,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,66,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,263,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,135,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,67,0,0,0,129},{91,0,150,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,322,91,91,91,91,91,91,0,82,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,263,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,135,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,104,0,0,0,129},{0,0,150,0,0,0,0,0,0,0,0,0,263,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,135,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,107,0,0,0,129},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,133,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,115,0,0},{0,0,150,0,0,0,0,0,0,0,0,0,263,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,135,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,130,0,0,0,129},{0,0,150,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,136,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{3,0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{7,0,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{11,0,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,166,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,134,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{15,0,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{19,0,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{23,0,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,12,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,13,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,0,142,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,0,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{55,0,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,43,0,43,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{223,0,223,223,223,223,223,223,223,223,223,223,223,223,102,458,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,0,0,0,0,0,0,0,0,0,0,0,0,84,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,410,0,102,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,39,0,39,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,51,51,51,51,51,51,51,51,0,51,294,51,51,51,51,51,51,51,0,51,51,51,51,51,51,51,51,51,51,51,0,0,0,0,0,0,0,0,0,17,0,0,0,0,74,0,0,0,0,0,0,0,117,0},{0,0,51,51,51,51,51,51,51,51,0,51,51,51,51,51,51,51,51,51,0,51,51,51,51,51,51,51,51,51,51,51,0,0,0,0,0,0,0,0,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,47,47,47,47,47,47,47,47,0,47,47,47,47,47,47,47,47,47,0,47,47,47,47,47,47,47,47,47,47,47,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,138,0,0,178,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{127,0,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,279,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,482,486,490,494,498,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,28,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,279,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,482,486,490,494,498,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,29,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,122,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,182,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{223,0,223,223,223,223,223,223,223,223,223,223,223,223,223,458,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,0,0,0,0,0,0,0,0,0,0,0,0,69,0,0,0,0,0,0,0,0,0,0,0},{195,0,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,138,0,0,186,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{131,0,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{123,0,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{175,0,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,302,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{171,0,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{75,0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{79,0,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{87,0,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{83,0,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,194,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{99,0,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{95,0,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{71,0,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{119,0,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{159,0,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{155,0,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{163,0,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{167,0,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{139,0,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{143,0,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{135,0,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{147,0,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{151,0,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{67,0,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{103,0,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{107,0,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{111,0,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{115,0,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{63,0,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{223,0,223,223,223,223,223,223,223,223,223,223,223,223,223,458,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,0,0,0,0,0,0,0,0,0,0,0,0,101,0,0,0,0,0,0,0,0,0,0,0},{179,0,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{223,0,223,223,223,223,223,223,223,223,223,223,223,223,223,458,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,0,0,0,0,0,0,0,0,0,0,0,0,103,0,0,0,0,0,0,0,0,0,0,0},{183,0,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,198,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{223,0,223,223,223,223,223,223,223,223,223,223,223,223,223,458,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,0,0,0,0,0,0,0,0,0,0,0,0,106,0,0,0,0,0,0,0,0,0,0,0},{187,0,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,187,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,202,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{223,0,223,223,223,223,223,223,223,223,223,223,223,223,223,458,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,0,0,0,0,0,0,0,0,0,0,0,0,109,0,0,0,0,0,0,0,0,0,0,0},{191,0,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,191,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{207,0,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,207,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{203,0,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,203,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{223,0,223,223,223,223,223,223,223,223,223,223,223,223,223,458,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,0,0,0,0,0,0,0,0,0,0,0,0,131,0,0,0,0,0,0,0,0,0,0,0},{223,0,223,223,223,223,223,223,223,223,223,223,223,223,223,458,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,223,0,0,0,0,0,0,0,0,0,0,0,0,132,0,0,0,0,0,0,0,0,0,0,0},{219,0,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,227,0,0,227,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,231,0,0,231,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,251,238,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,211,0,0,0,0,0,0,0,0,0,211,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,215,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,215,215,215,215,215,215,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,287,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,287,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,291,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,291,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,283,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,283,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,295,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,295,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,299,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,299,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,303,0,0,0,0,0,0,0,0,303,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,303,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,307,0,0,0,0,0,0,0,0,307,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,307,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,315,0,0,0,0,0,0,0,0,315,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,315,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,311,0,0,0,0,0,0,0,0,311,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,311,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,267,146,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,210,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{319,0,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,319,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{323,0,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,323,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,239,0,0,239,162,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,243,0,0,243,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,275,275,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,271,271,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
struct RULE {
	void (*cb) (std::vector<Dynamic>&);
	int sym;
	int cnt;
};
void R0(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = ((Token&)hllr__0).int_data; 
	__ret.push_back(retval);
}
void R1(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = ((Token&)hllr__0).string_data; 
	__ret.push_back(retval);
}
void R2(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = ((Token&)hllr__0).string_data; 
	__ret.push_back(retval);
}
void R3(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = ((Token&)hllr__0).string_data; 
	__ret.push_back(retval);
}
void R4(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = ((Token&)hllr__0).string_data; 
	__ret.push_back(retval);
}
void R5(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = ((Token&)hllr__0).string_data; 
	__ret.push_back(retval);
}
void R6(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&)hllr__0;
        States& y = (States&)hllr__3;
        for(auto i = y.begin(); i!=y.end(); i++) x.push_back(*i);
        retval = Program("",x);
    
	__ret.push_back(retval);
}
void R7(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = Program((std::string&)hllr__2,(States&)hllr__4);
    
	__ret.push_back(retval);
}
void R8(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = Program("",(States&)hllr__0);
    
	__ret.push_back(retval);
}
void R9(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::string& x = (std::string&)hllr__0;
        x.append(".");
//        x.append((std::string)hllr__2);
	x.append(GetSymbol(hllr__2.cast<int>()));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R10(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = GetSymbol(hllr__0.cast<int>());
    
	__ret.push_back(retval);
}
void R11(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&)hllr__0;
        x.push_back(ptr<State>(hllr__1));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R12(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;

        retval = States();
    
	__ret.push_back(retval);
}
void R13(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&) hllr__0;
        x.push_back(ptr<State>(hllr__1));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R14(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;

        retval = States();
    
	__ret.push_back(retval);
}
void R15(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise((std::string&)hllr__0); 
	__ret.push_back(retval);
}
void R16(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(hllr__0.cast<int>()); 
	__ret.push_back(retval);
}
void R17(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateCons(); 
	__ret.push_back(retval);
}
void R18(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise("."); 
	__ret.push_back(retval);
}
void R19(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise(";"); 
	__ret.push_back(retval);
}
void R20(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise("/"); 
	__ret.push_back(retval);
}
void R21(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise("->"); 
	__ret.push_back(retval);
}
void R22(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise("$"); 
	__ret.push_back(retval);
}
void R23(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States list;
        list.push_back(ptr<State>(StateSymbol(hllr__1.cast<int>())));
        retval = StateMBrack(dMScopeBrack(list));
    
	__ret.push_back(retval);
}
void R24(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = StateString(ptr<State>(new StateArgScope((States&)hllr__3)));
    
	__ret.push_back(retval);
}
void R25(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateDatum((std::string&)hllr__0); 
	__ret.push_back(retval);
}
void R26(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateDatum((std::string&)hllr__0); 
	__ret.push_back(retval);
}
void R27(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNumber((std::string&)hllr__0); 
	__ret.push_back(retval);
}
void R28(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNumber((std::string&)hllr__0); 
	__ret.push_back(retval);
}
void R29(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateImport((std::string&)hllr__1); 
	__ret.push_back(retval);
}
void R30(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateScope((States&)hllr__1); 
	__ret.push_back(retval);
}
void R31(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = StateMScope(dMScopeBrack((std::vector<MIdent>&)hllr__1, (States&)hllr__3));
    
	__ret.push_back(retval);
}
void R32(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = StateMBrack(dMScopeBrack((std::vector<MIdent>&)hllr__1, (States&)hllr__3));
    
	__ret.push_back(retval);
}
void R33(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("local")); 
	__ret.push_back(retval);
}
void R34(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("global")); 
	__ret.push_back(retval);
}
void R35(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("file")); 
	__ret.push_back(retval);
}
void R36(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("object")); 
	__ret.push_back(retval);
}
void R37(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("method")); 
	__ret.push_back(retval);
}
void R38(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("mixin")); 
	__ret.push_back(retval);
}
void R39(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("define")); 
	__ret.push_back(retval);
}
void R40(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("expand")); 
	__ret.push_back(retval);
}
void R41(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("str")); 
	__ret.push_back(retval);
}
void R42(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateCall((States&)hllr__1); 
	__ret.push_back(retval);
}
void R43(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateCall(); 
	__ret.push_back(retval);
}
void R44(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateMImport(dMImport("")); 
	__ret.push_back(retval);
}
void R45(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateMImport(dMImport((std::string&)hllr__1)); 
	__ret.push_back(retval);
}
void R46(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__8 = __ret.back(); __ret.pop_back();
	Dynamic hllr__7 = __ret.back(); __ret.pop_back();
	Dynamic hllr__6 = __ret.back(); __ret.pop_back();
	Dynamic hllr__5 = __ret.back(); __ret.pop_back();
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& pre = (States&) hllr__2;
        ptr<State> x = pre.back(); pre.pop_back();
        int name = ptr<StateSymbol>(x)->data;
        retval = StateDefine(dMacro((MSCOPE&)hllr__1,pre,name,(std::vector</*Symbol*/int>&)hllr__4, (States&)hllr__6));
    
	__ret.push_back(retval);
}
void R47(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__7 = __ret.back(); __ret.pop_back();
	Dynamic hllr__6 = __ret.back(); __ret.pop_back();
	Dynamic hllr__5 = __ret.back(); __ret.pop_back();
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& pre = (States&) hllr__1;
        ptr<State> x = pre.back(); pre.pop_back();
        int name = ptr<StateSymbol>(x)->data;
        retval = StateDefine(dMacro(sLocal,pre,name,(std::vector</*Symbol*/int>&)hllr__3, (States&)hllr__5));
    
	__ret.push_back(retval);
}
void R48(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__9 = __ret.back(); __ret.pop_back();
	Dynamic hllr__8 = __ret.back(); __ret.pop_back();
	Dynamic hllr__7 = __ret.back(); __ret.pop_back();
	Dynamic hllr__6 = __ret.back(); __ret.pop_back();
	Dynamic hllr__5 = __ret.back(); __ret.pop_back();
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = StateExpand(dMacro((MSCOPE&)hllr__2, hllr__3.cast<int>(), (std::vector</*Symbol*/int>&)hllr__5, (States&)hllr__7));
    
	__ret.push_back(retval);
}
void R49(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        RMIXIN& x = (RMIXIN&)hllr__3;
        retval = x.build((MSCOPE&)hllr__2);
    
	__ret.push_back(retval);
}
void R50(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = hllr__0; 
	__ret.push_back(retval);
}
void R51(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise(","); 
	__ret.push_back(retval);
}
void R52(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

	__ret.push_back(retval);
}
void R53(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

	__ret.push_back(retval);
}
void R54(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

	__ret.push_back(retval);
}
void R55(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;

	__ret.push_back(retval);
}
void R56(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::vector<MIdent>& x = (std::vector<MIdent>&)hllr__0;
        x.push_back((MIdent&)hllr__2);
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R57(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::vector<MIdent> x;
        x.push_back((MIdent&)hllr__0);
        retval = x;
    
	__ret.push_back(retval);
}
void R58(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;
 retval = std::vector<MIdent>(); 
	__ret.push_back(retval);
}
void R59(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = MIdent(hllr__0.cast<int>(),0); 
	__ret.push_back(retval);
}
void R60(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = MIdent(hllr__0.cast<int>(), atoi(((std::string&)hllr__2).c_str()));
    
	__ret.push_back(retval);
}
void R61(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;
 retval = States(); 
	__ret.push_back(retval);
}
void R62(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = hllr__0; 
	__ret.push_back(retval);
}
void R63(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&) hllr__0;
        x.push_back(ptr<State>(StateArgScope((States&)hllr__2)));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R64(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States x;
        x.push_back(ptr<State>(StateArgScope((States&)hllr__0)));
        retval = x;
    
	__ret.push_back(retval);
}
void R65(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;
 retval = States(); 
	__ret.push_back(retval);
}
void R66(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = hllr__0; 
	__ret.push_back(retval);
}
void R67(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::vector<int>& x = (std::vector<int>&)hllr__0;
        x.push_back(hllr__2.cast<int>());
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R68(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::vector<int> x;
        x.push_back(hllr__0.cast<int>());
        retval = x;
    
	__ret.push_back(retval);
}
void R69(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;
 retval = sLocal; 
	__ret.push_back(retval);
}
void R70(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sLocal;  
	__ret.push_back(retval);
}
void R71(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sGlobal; 
	__ret.push_back(retval);
}
void R72(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sFile;   
	__ret.push_back(retval);
}
void R73(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sObject; 
	__ret.push_back(retval);
}
void R74(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sMethod; 
	__ret.push_back(retval);
}
void R75(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States x;
        x.push_back(ptr<State>(StateSymbol(hllr__0.cast<int>())));
        retval = x;
    
	__ret.push_back(retval);
}
void R76(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States x;
        x.push_back(ptr<State>(StateNoise((std::string&)hllr__0)));
        retval = x;
    
	__ret.push_back(retval);
}
void R77(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&) hllr__0;
        x.push_back(ptr<State>(StateNoise((std::string&)hllr__1)));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R78(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&) hllr__0;
        x.push_back(ptr<State>(StateSymbol(hllr__1.cast<int>())));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R79(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__6 = __ret.back(); __ret.pop_back();
	Dynamic hllr__5 = __ret.back(); __ret.pop_back();
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = RMIXIN(hllr__0.cast<int>(), (std::vector<int>&)hllr__2, (States&)hllr__4);
    
	__ret.push_back(retval);
}
void R80(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = RMIXIN(hllr__0.cast<int>(), (States&)hllr__1);
    
	__ret.push_back(retval);
}
static const RULE rules[] = {{R0, 33, 1},{R1, 34, 1},{R2, 35, 1},{R3, 36, 1},{R4, 37, 1},{R5, 38, 1},{R6, 32, 4},{R7, 32, 5},{R8, 32, 1},{R9, 40, 3},{R10, 40, 1},{R11, 41, 2},{R12, 41, 0},{R13, 39, 2},{R14, 39, 0},{R15, 42, 1},{R16, 42, 1},{R17, 42, 1},{R18, 42, 1},{R19, 42, 1},{R20, 42, 1},{R21, 42, 1},{R22, 42, 1},{R23, 42, 2},{R24, 42, 5},{R25, 42, 1},{R26, 42, 1},{R27, 42, 1},{R28, 42, 1},{R29, 42, 3},{R30, 42, 3},{R31, 42, 5},{R32, 42, 5},{R33, 42, 1},{R34, 42, 1},{R35, 42, 1},{R36, 42, 1},{R37, 42, 1},{R38, 42, 1},{R39, 42, 1},{R40, 42, 1},{R41, 42, 1},{R42, 42, 3},{R43, 42, 2},{R44, 42, 3},{R45, 42, 4},{R46, 42, 9},{R47, 42, 8},{R48, 42, 10},{R49, 42, 4},{R50, 43, 1},{R51, 43, 1},{R52, 47, 2},{R53, 48, 2},{R54, 44, 1},{R55, 44, 0},{R56, 45, 3},{R57, 45, 1},{R58, 45, 0},{R59, 53, 1},{R60, 53, 3},{R61, 46, 0},{R62, 46, 1},{R63, 54, 3},{R64, 54, 1},{R65, 51, 0},{R66, 51, 1},{R67, 55, 3},{R68, 55, 1},{R69, 49, 0},{R70, 49, 1},{R71, 49, 1},{R72, 49, 1},{R73, 49, 1},{R74, 49, 1},{R75, 50, 1},{R76, 50, 1},{R77, 50, 2},{R78, 50, 2},{R79, 52, 7},{R80, 52, 4}};
static const int entry_state = 0;
ParserResult::ParserResult() {}
ParserResult::ParserResult(std::string& file_name, const Dynamic& data) {
	this->file_name = file_name;
	this->data = data;
}
size_t Parser::run() {
std::vector<int> stack;
std::vector<Dynamic> ret;

ptr<Token> cur = tokens->pop();
if(isTOKEOS(cur)) return 0;

std::string fname = TOKSOF_data(cur);

cur = tokens->pop();
int cstate = entry_state;
//while(cur->id!=-3) {
while(!isTOKEOS(cur)) {
	int action = actions[cstate][isTOKEOF(cur) ? 0 : INDEX(cur)+2];
	switch(action&3) {
		case 0: //error
			results->push(ParserResult(fname,Dynamic::null));
			
			//skip to end of file, or end of process token.
			while(!isTOKEOF(cur)) cur = tokens->pop();
			ret.clear();
			
			stack.clear();
			cstate = entry_state;
			cur = tokens->pop();
			if(!isTOKEOS(cur)) {
				fname = TOKSOF_data(cur);
				cur = tokens->pop();
			}

			break;
		case 1: //accept
			results->push(ParserResult(fname,ret.front()));

			ret.clear();
			
			stack.clear();
			cstate = entry_state;
			cur = tokens->pop();
			if(!isTOKEOS(cur)) {
				fname = TOKSOF_data(cur);
				cur = tokens->pop();
			}
			
			break;
		case 2: //shift
			ret.push_back(cur);
			stack.push_back(cstate);
			cstate = action >> 2;

			cur = tokens->pop();
		
			break;
		case 3: //reduce
			const RULE& c = rules[action>>2];
			(*(c.cb))(ret);
			
			if (c.cnt > 0) {
				for(int i = 0; i<(c.cnt-1); i++) stack.pop_back();
				cstate = stack.back();
			}else stack.push_back(cstate);
			
			cstate = actions[cstate][c.sym];
	}
}
	return 0;
}
Parser::Parser() {}
void Parser::init(tsDeque<ptr<Token> >& tokens, tsDeque<ParserResult>& results) {
	this->tokens = ref<tsDeque<ptr<Token> > > (tokens);
	this->results = ref<tsDeque<ParserResult> >(results);
}
