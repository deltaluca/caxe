default:
	@echo "---------------"
	@echo "CAXE Makefile"
	@echo "---------------"
	@echo "  To compile caxe; use target 'caxe'"
	@echo "  To clean; use target 'clean'"
	@echo "  To create caxe tar; use target 'tar'"
	@echo "  To compile lexer/parser; use target 'bootstrap'"
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
	caxe_util.o \
	writer.o

OBJS= $(_OBJS:%.o=$(OBJ)/%.o)

caxe: $(OBJS)
	@echo "-------------"
	@echo "linking caxe"
	@echo "-------------"
	mkdir -p $(BIN)
	$(CXX) $(OBJS) -o $(BIN)/$(EXEC) $(LFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp
	@echo "compiling " $@
	mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@echo "-------------"
	@echo "cleaning caxe"
	@echo "-------------"
	\rm -f $(OBJ)/*.o $(EXEC)

bootstrap:
	@echo "-------------"
	@echo "compiling lexer/parser"
	@echo "-------------"
	hlex caxe.hlx -c++ lexer
	hllr caxe.hlr parse -c++ -hlex lexer -lalr1
	mv lexer.cpp src/ && mv lexer.hpp incl/
	mv parse.cpp src/ && mv parse.hpp incl/

tar:
	@echo "-------------"
	@echo "tarring caxe"
	@echo "-------------"
	tar cfvz caxe.tar.gz caxe.hlx caxe.hlr $(INCL)/*.hpp $(SRC)/*.cpp Makefile
