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
static const int actions[132][50] = 
{{35,0,35,35,35,35,35,35,35,35,0,35,0,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,131,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{11,0,158,162,166,170,174,178,190,46,0,138,0,402,258,262,266,270,274,290,10,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,118,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{35,0,35,35,35,35,35,35,35,35,0,35,0,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{3,0,158,162,166,170,174,178,190,46,0,138,0,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,130,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{35,0,35,35,35,35,35,35,35,35,0,35,0,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{7,0,158,162,166,170,174,178,190,46,0,138,0,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,17,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,18,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,0,482,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,0,35,35,35,35,35,35,35,35,35,35,35,0,24,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,186,138,0,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,226,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,238,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,242,138,0,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,286,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,374,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,394,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,410,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,414,402,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,101,26,0,0,0,28,88,0,0,0,0,0,0,0},{31,0,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,118,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,118,0,0,0,0,0,0,0,0,0,338,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,31,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,19,0,19,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,130,418,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,73,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,346,0,130,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,134,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,15,0,15,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,27,27,27,27,27,27,27,27,0,27,246,27,27,27,27,27,27,27,0,27,27,27,27,27,27,27,27,27,27,27,0,0,0,36,0,0,0,0,62,0,0,0,0,0,0,0,108,0},{0,0,27,27,27,27,27,27,27,27,0,27,27,27,27,27,27,27,27,27,0,27,27,27,27,27,27,27,27,27,27,27,0,0,0,37,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,235,235,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,38,0,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,158,162,166,170,174,178,190,46,0,138,231,231,258,262,266,270,274,290,0,110,298,302,306,310,314,318,322,326,330,334,0,0,0,0,38,0,0,0,0,28,88,0,0,0,0,0,0,0},{0,0,23,23,23,23,23,23,23,23,0,23,23,23,23,23,23,23,23,23,0,23,23,23,23,23,23,23,23,23,23,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{43,0,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,43,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{79,0,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{83,0,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,83,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{87,0,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,87,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{91,0,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,91,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,502,0,0,0,0,0,0,0,0,0,0,211,0,0,211,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,45,0,0,0,0,0,0,0,107,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,422,0,0,34,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{103,0,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,502,0,0,0,0,0,0,0,0,0,0,211,0,0,211,0,0,0,0,438,442,194,206,0,0,0,0,0,0,0,0,0,0,0,0,0,0,58,0,0,0,0,0,0,0,107,0,0},{0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,446,450,454,458,462,0,0,0,0,0,0,0,0,0,0,0,0,49,0,0,0,0,0,0},{0,0,62,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,50,0,0,0},{175,0,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,175,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,255,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,446,450,454,458,462,0,0,0,0,0,0,0,0,0,0,0,0,52,0,0,0,0,0,0},{0,0,214,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,218,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,514,0,0,0,0,0,0,0,0,0,239,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,55,0,0,0,121},{0,0,0,0,0,0,0,0,0,0,0,0,38,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,199,418,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,57,0,0,0,0,0,0,0,0,0,0,0},{171,0,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,171,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,422,0,0,42,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{107,0,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{99,0,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,99,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{151,0,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,151,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,254,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{147,0,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,147,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{51,0,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,51,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{55,0,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,55,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{63,0,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,63,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{59,0,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{67,0,278,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,67,282,67,67,67,67,67,67,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{71,0,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,71,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,50,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{75,0,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{47,0,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,47,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{95,0,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{135,0,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,135,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{131,0,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,131,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{139,0,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,139,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{143,0,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,143,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{115,0,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{119,0,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,119,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{111,0,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,111,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{123,0,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,123,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{127,0,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{39,0,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,39,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,199,418,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,85,0,0,0,0,0,0,0,0,0,0,0},{155,0,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,155,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,199,418,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,87,0,0,0,0,0,0,0,0,0,0,0},{159,0,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,159,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,466,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,446,450,454,458,462,470,0,0,0,0,0,0,0,0,0,0,0,89,95,0,0,0,0,0},{0,0,466,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,470,0,0,0,0,0,0,0,0,0,0,0,0,90,0,0,0,0,0},{0,0,474,0,0,0,0,0,0,0,0,366,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,478,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,514,0,0,0,0,0,0,0,0,0,239,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,92,0,0,0,121},{0,0,0,0,0,0,0,0,0,0,0,0,54,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,199,418,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,94,0,0,0,0,0,0,0,0,0,0,0},{163,0,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,163,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,474,0,0,0,0,0,0,0,0,386,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,478,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,514,0,0,0,0,0,0,0,0,0,239,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,0,0,0,121},{0,0,0,0,0,0,0,0,0,0,0,0,58,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,199,418,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,99,0,0,0,0,0,0,0,0,0,0,0},{167,0,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,167,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{183,0,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,183,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{179,0,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,179,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,199,418,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,123,0,0,0,0,0,0,0,0,0,0,0},{199,0,199,199,199,199,199,199,199,199,199,199,199,199,199,418,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,199,0,0,0,0,0,0,124,0,0,0,0,0,0,0,0,0,0,0},{195,0,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,195,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,502,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,106,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,203,0,0,203,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,207,0,0,207,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,227,142,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,187,0,0,0,0,0,0,0,0,0,187,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,191,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,191,191,191,191,191,191,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,263,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,263,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,267,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,267,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,259,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,259,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,271,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,271,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,275,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,275,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,279,0,0,0,0,0,0,0,0,279,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,279,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,283,0,0,0,0,0,0,0,0,283,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,283,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,291,0,0,0,0,0,0,0,0,291,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,291,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,287,0,0,0,0,0,0,0,0,287,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,287,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,514,0,0,0,0,0,0,0,0,0,239,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,122,0,0,0,121},{0,0,0,0,0,0,0,0,0,0,0,0,243,518,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,66,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{295,0,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,295,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{299,0,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,299,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,215,0,0,215,506,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,510,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,219,0,0,219,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,251,251,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,522,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,247,247,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
struct RULE {
	void (*cb) (std::vector<Dynamic>&);
	int sym;
	int cnt;
};
void R0(std::vector<Dynamic>& __ret) {
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
void R1(std::vector<Dynamic>& __ret) {
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
void R2(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = Program("",(States&)hllr__0);
    
	__ret.push_back(retval);
}
void R3(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::string& x = (std::string&)hllr__0;
        x.append(".");
//        x.append((std::string)(ptr<TOKEN>(hllr__2)->data));
	x.append(GetSymbol((ptr<TOKEN>(hllr__2)->data).cast<int>()));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R4(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = GetSymbol((ptr<TOKEN>(hllr__0)->data).cast<int>());
    
	__ret.push_back(retval);
}
void R5(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&)hllr__0;
        x.push_back(ptr<State>(hllr__1));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R6(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;

        retval = States();
    
	__ret.push_back(retval);
}
void R7(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&) hllr__0;
        x.push_back(ptr<State>(hllr__1));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R8(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;

        retval = States();
    
	__ret.push_back(retval);
}
void R9(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise((std::string&)(ptr<TOKEN>(hllr__0)->data)); 
	__ret.push_back(retval);
}
void R10(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol((ptr<TOKEN>(hllr__0)->data).cast<int>()); 
	__ret.push_back(retval);
}
void R11(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateCons(); 
	__ret.push_back(retval);
}
void R12(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise("."); 
	__ret.push_back(retval);
}
void R13(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise(";"); 
	__ret.push_back(retval);
}
void R14(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise("/"); 
	__ret.push_back(retval);
}
void R15(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise("->"); 
	__ret.push_back(retval);
}
void R16(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise("$"); 
	__ret.push_back(retval);
}
void R17(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States list;
        list.push_back(ptr<State>(StateSymbol((ptr<TOKEN>(hllr__1)->data).cast<int>())));
        retval = StateMBrack(dMScopeBrack(list));
    
	__ret.push_back(retval);
}
void R18(std::vector<Dynamic>& __ret) {
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
void R19(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateDatum((std::string&)(ptr<TOKEN>(hllr__0)->data)); 
	__ret.push_back(retval);
}
void R20(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateDatum((std::string&)(ptr<TOKEN>(hllr__0)->data)); 
	__ret.push_back(retval);
}
void R21(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNumber((std::string&)(ptr<TOKEN>(hllr__0)->data)); 
	__ret.push_back(retval);
}
void R22(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNumber((std::string&)(ptr<TOKEN>(hllr__0)->data)); 
	__ret.push_back(retval);
}
void R23(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateImport((std::string&)hllr__1); 
	__ret.push_back(retval);
}
void R24(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateScope((States&)hllr__1); 
	__ret.push_back(retval);
}
void R25(std::vector<Dynamic>& __ret) {
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
void R26(std::vector<Dynamic>& __ret) {
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
void R27(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("local")); 
	__ret.push_back(retval);
}
void R28(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("global")); 
	__ret.push_back(retval);
}
void R29(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("file")); 
	__ret.push_back(retval);
}
void R30(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("object")); 
	__ret.push_back(retval);
}
void R31(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("method")); 
	__ret.push_back(retval);
}
void R32(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("mixin")); 
	__ret.push_back(retval);
}
void R33(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("define")); 
	__ret.push_back(retval);
}
void R34(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("expand")); 
	__ret.push_back(retval);
}
void R35(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateSymbol(GetSymbol("str")); 
	__ret.push_back(retval);
}
void R36(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateCall((States&)hllr__1); 
	__ret.push_back(retval);
}
void R37(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateCall(); 
	__ret.push_back(retval);
}
void R38(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateMImport(dMImport("")); 
	__ret.push_back(retval);
}
void R39(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateMImport(dMImport((std::string&)hllr__1)); 
	__ret.push_back(retval);
}
void R40(std::vector<Dynamic>& __ret) {
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
void R41(std::vector<Dynamic>& __ret) {
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
void R42(std::vector<Dynamic>& __ret) {
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

        retval = StateExpand(dMacro((MSCOPE&)hllr__2, (ptr<TOKEN>(hllr__3)->data).cast<int>(), (std::vector</*Symbol*/int>&)hllr__5, (States&)hllr__7));
    
	__ret.push_back(retval);
}
void R43(std::vector<Dynamic>& __ret) {
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
void R44(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = hllr__0; 
	__ret.push_back(retval);
}
void R45(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = StateNoise(","); 
	__ret.push_back(retval);
}
void R46(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

	__ret.push_back(retval);
}
void R47(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

	__ret.push_back(retval);
}
void R48(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

	__ret.push_back(retval);
}
void R49(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;

	__ret.push_back(retval);
}
void R50(std::vector<Dynamic>& __ret) {
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
void R51(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::vector<MIdent> x;
        x.push_back((MIdent&)hllr__0);
        retval = x;
    
	__ret.push_back(retval);
}
void R52(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;
 retval = std::vector<MIdent>(); 
	__ret.push_back(retval);
}
void R53(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = MIdent((ptr<TOKEN>(hllr__0)->data).cast<int>(),0); 
	__ret.push_back(retval);
}
void R54(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = MIdent((ptr<TOKEN>(hllr__0)->data).cast<int>(), atoi(((std::string&)(ptr<TOKEN>(hllr__2)->data)).c_str()));
    
	__ret.push_back(retval);
}
void R55(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;
 retval = States(); 
	__ret.push_back(retval);
}
void R56(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = hllr__0; 
	__ret.push_back(retval);
}
void R57(std::vector<Dynamic>& __ret) {
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
void R58(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States x;
        x.push_back(ptr<State>(StateArgScope((States&)hllr__0)));
        retval = x;
    
	__ret.push_back(retval);
}
void R59(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;
 retval = States(); 
	__ret.push_back(retval);
}
void R60(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = hllr__0; 
	__ret.push_back(retval);
}
void R61(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::vector<int>& x = (std::vector<int>&)hllr__0;
        x.push_back((ptr<TOKEN>(hllr__2)->data).cast<int>());
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R62(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        std::vector<int> x;
        x.push_back((ptr<TOKEN>(hllr__0)->data).cast<int>());
        retval = x;
    
	__ret.push_back(retval);
}
void R63(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic retval;
 retval = sLocal; 
	__ret.push_back(retval);
}
void R64(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sLocal;  
	__ret.push_back(retval);
}
void R65(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sGlobal; 
	__ret.push_back(retval);
}
void R66(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sFile;   
	__ret.push_back(retval);
}
void R67(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sObject; 
	__ret.push_back(retval);
}
void R68(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;
 retval = sMethod; 
	__ret.push_back(retval);
}
void R69(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States x;
        x.push_back(ptr<State>(StateSymbol((ptr<TOKEN>(hllr__0)->data).cast<int>())));
        retval = x;
    
	__ret.push_back(retval);
}
void R70(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States x;
        x.push_back(ptr<State>(StateNoise((std::string&)(ptr<TOKEN>(hllr__0)->data))));
        retval = x;
    
	__ret.push_back(retval);
}
void R71(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&) hllr__0;
        x.push_back(ptr<State>(StateNoise((std::string&)(ptr<TOKEN>(hllr__1)->data))));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R72(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        States& x = (States&) hllr__0;
        x.push_back(ptr<State>(StateSymbol((ptr<TOKEN>(hllr__1)->data).cast<int>())));
        retval = hllr__0;
    
	__ret.push_back(retval);
}
void R73(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__6 = __ret.back(); __ret.pop_back();
	Dynamic hllr__5 = __ret.back(); __ret.pop_back();
	Dynamic hllr__4 = __ret.back(); __ret.pop_back();
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = RMIXIN((ptr<TOKEN>(hllr__0)->data).cast<int>(), (std::vector<int>&)hllr__2, (States&)hllr__4);
    
	__ret.push_back(retval);
}
void R74(std::vector<Dynamic>& __ret) {
	//arguments
	Dynamic hllr__3 = __ret.back(); __ret.pop_back();
	Dynamic hllr__2 = __ret.back(); __ret.pop_back();
	Dynamic hllr__1 = __ret.back(); __ret.pop_back();
	Dynamic hllr__0 = __ret.back(); __ret.pop_back();
	Dynamic retval;

        retval = RMIXIN((ptr<TOKEN>(hllr__0)->data).cast<int>(), (States&)hllr__1);
    
	__ret.push_back(retval);
}
static const RULE rules[] = {{R0, 32, 4},{R1, 32, 5},{R2, 32, 1},{R3, 34, 3},{R4, 34, 1},{R5, 35, 2},{R6, 35, 0},{R7, 33, 2},{R8, 33, 0},{R9, 36, 1},{R10, 36, 1},{R11, 36, 1},{R12, 36, 1},{R13, 36, 1},{R14, 36, 1},{R15, 36, 1},{R16, 36, 1},{R17, 36, 2},{R18, 36, 5},{R19, 36, 1},{R20, 36, 1},{R21, 36, 1},{R22, 36, 1},{R23, 36, 3},{R24, 36, 3},{R25, 36, 5},{R26, 36, 5},{R27, 36, 1},{R28, 36, 1},{R29, 36, 1},{R30, 36, 1},{R31, 36, 1},{R32, 36, 1},{R33, 36, 1},{R34, 36, 1},{R35, 36, 1},{R36, 36, 3},{R37, 36, 2},{R38, 36, 3},{R39, 36, 4},{R40, 36, 9},{R41, 36, 8},{R42, 36, 10},{R43, 36, 4},{R44, 37, 1},{R45, 37, 1},{R46, 41, 2},{R47, 42, 2},{R48, 38, 1},{R49, 38, 0},{R50, 39, 3},{R51, 39, 1},{R52, 39, 0},{R53, 47, 1},{R54, 47, 3},{R55, 40, 0},{R56, 40, 1},{R57, 48, 3},{R58, 48, 1},{R59, 45, 0},{R60, 45, 1},{R61, 49, 3},{R62, 49, 1},{R63, 43, 0},{R64, 43, 1},{R65, 43, 1},{R66, 43, 1},{R67, 43, 1},{R68, 43, 1},{R69, 44, 1},{R70, 44, 1},{R71, 44, 2},{R72, 44, 2},{R73, 46, 7},{R74, 46, 4}};
static const int entry_state = 0;
ParserResult::ParserResult() {}
ParserResult::ParserResult(std::string& file_name, const Dynamic& data) {
	this->file_name = file_name;
	this->data = data;
}
size_t Parser::run() {
std::vector<int> stack;
std::vector<Dynamic> ret;

ptr<TOKEN> cur = tokens->pop();
if(cur->id==-3) return 0;

std::string fname = cur->data.cast<std::string>();

cur = tokens->pop();
int cstate = entry_state;
while(cur->id!=-3) {
	int action = actions[cstate][cur->id+2];
	switch(action&3) {
		case 0: //error
			results->push(ParserResult(fname,Dynamic::null));
			
			//skip to end of file, or end of process token.
			while(cur->id>=-1) cur = tokens->pop();
			ret.clear();
			
			stack.clear();
			cstate = entry_state;
			cur = tokens->pop();
			if(cur->id!=-3) {
				fname = *(ptr<std::string>(cur->data));
				cur = tokens->pop();
			}

			break;
		case 1: //accept
			results->push(ParserResult(fname,ret.front()));

			ret.clear();
			
			stack.clear();
			cstate = entry_state;
			cur = tokens->pop();
			if(cur->id!=-3) {
				fname = *(ptr<std::string>(cur->data));
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
void Parser::init(tsDeque<ptr<TOKEN> >& tokens, tsDeque<ParserResult>& results) {
	this->tokens = ref<tsDeque<ptr<TOKEN> > > (tokens);
	this->results = ref<tsDeque<ParserResult> >(results);
}
