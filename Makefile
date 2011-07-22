default:
	@echo "---------------"
	@echo "CAXE Makefile"
	@echo "---------------"
	@echo "  To compile caxe; use target 'caxe'"
	@echo "  To clean; use target 'clean'"
	@echo "  To create caxe tar; use target 'tar'"
	@echo ""


INCL = incl
SRC = src
OBJ = obj
BIN = bin
EXEC = caxe

CXX = g++
CXXFLAGS = -c -std=gnu++0x -Wall -I$(INCL)
LFLAGS = -lpthread

_OBJS = main.o \
	anal.o \
	imports.o \
	lexer.o \
	macro.o \
	parser_obj.o \
	parse.o \
	scope.o \
	subber.o \
	util.o \
	writer.o

OBJS= $(_OBJS:%.o=$(OBJ)/%.o)

caxe: lexer parse $(OBJS)
	@echo "-------------"
	@echo "linking caxe"
	@echo "-------------"
	$(CXX) $(OBJS) -o $(BIN)/$(EXEC) $(LFLAGS)

lexer: caxe.hlx
	@echo "-------------"
	@echo "compiling lexer"
	@echo "-------------"
	/home/luca/Projects/hlex/bin/hlex caxe.hlx -c++ lexer
	mv lexer.cpp src/lexer.cpp
	mv lexer.hpp incl/lexer.hpp
	
parse: caxe.hlr lexer
	@echo "-------------"
	@echo "compiling parser"
	@echo "-------------"
	hllr caxe.hlr parse -c++ -hlex lexer -lalr1
	mv parse.cpp src/parse.cpp
	mv parse.hpp incl/parse.hpp

$(OBJ)/%.o: $(SRC)/%.cpp lexer parse
	@echo "compiling " $@
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@echo "-------------"
	@echo "cleaning caxe"
	@echo "-------------"
	\rm -f $(OBJ)/*.o $(EXEC)
	\rm -f src/lexer.cpp src/parse.cpp incl/lexer.hpp incl/parse.hpp

tar:
	@echo "-------------"
	@echo "tarring caxe"
	@echo "-------------"
	tar cfvz caxe.tar.gz caxe.hlx caxe.hlr $(INCL)/*.hpp $(SRC)/*.cpp --exclude=lexer.* --exclude=parse.* Makefile
