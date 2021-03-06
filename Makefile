default:
	@echo "---------------"
	@echo "CAXE Makefile"
	@echo "---------------"
	@echo "  To compile caxe; use target 'caxe'"
	@echo "     (add WINDOWS=true for windows compilation using mingw)"
	@echo "     (add NOTIMES=true to disable timing (doesn't seem to work on macs))"
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
ifeq ($(WINDOWS),true)
	CXXFLAGS = -c -std=gnu++0x -Wall -I$(INCL) -D WINDOWS
else
	CXXFLAGS = -c -std=gnu++0x -Wall -I$(INCL)
endif

ifeq ($(NOTIMES),true)
	CXXFLAGS += -D NOTIMES
endif

ifneq ($(DEBUG),true)
    OP = -Ofast \
      -fmerge-all-constants \
      -fmodulo-sched \
      -fmodulo-sched-allow-regmoves \
      -fno-branch-count-reg \
      -fgcse-lm -fgcse-sm \
      -fgcse-after-reload \
      -funsafe-loop-optimizations -Wunsafe-loop-optimizations
endif


# lexer.cpp doesn't compile with even -O1
ifneq ($(DEBUG),true)
    LEXEROP = -falign-functions\
      -falign-jumps\
      -falign-labels\
      -falign-loops\
      -fdefer-pop\
      -fdelete-null-pointer-checks\
      -fexpensive-optimizations\
      -fguess-branch-probability\
      -fjump-tables\
      -fmerge-all-constants\
      -fmodulo-sched\
      -fmove-loop-invariants\
      -fnon-call-exceptions\
      -fpeel-loops\
      -fpeephole2\
      -foptimize-register-move\
      -fomit-frame-pointer\
      -fprefetch-loop-arrays\
      -freorder-blocks-and-partition\
      -fthread-jumps\
      -ftree-copyrename\
      -ftree-dominator-opts\
      -ftree-loop-optimize\
      -ftree-lrs\
      -ftree-loop-distribution\
      -funsafe-loop-optimizations\
      -funsafe-math-optimizations\
      -funswitch-loops\
      -funwind-tables\
      -fvpt\
      -funroll-all-loops
else
    CXXFLAGS += -g
endif

LFLAGS = -lpthread

ifneq ($(WINDOWS),true)
ifneq ($(NOTIMES),true)
	LFLAGS += -lrt
endif
endif

_OBJS = main.o \
	anal.o \
	imports.o \
	macro.o \
	parser_obj.o \
	parse.o \
	scope.o \
	subber.o \
	caxe_util.o \
	writer.o \
	token.o

OBJS= $(_OBJS:%.o=$(OBJ)/%.o)

caxe: $(OBJS) $(OBJ)/lexer.o
	@echo "-------------"
	@echo "linking caxe"
	@echo "-------------"
	mkdir -p $(BIN)
	$(CXX) $(OBJS) $(OBJ)/lexer.o -o $(BIN)/$(EXEC) $(LFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp
	@echo "compiling " $@
	mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) $< -o $@ $(OP)

$(OBJ)/lexer.o: $(SRC)/lexer.cpp
	@echo "compiling lexer.cpp"
	mkdir -p $(OBJ)
	$(CXX) $(CXXFLAGS) $(SRC)/lexer.cpp -o $(OBJ)/lexer.o $(LEXEROP)

clean:
	@echo "-------------"
	@echo "cleaning caxe"
	@echo "-------------"
	\rm -f $(OBJ)/*.o $(EXEC)

bootstrap:
	@echo "-------------"
	@echo "compiling lexer/parser"
	@echo "-------------"
	hlex caxe.hlx -c++ lexer -token Token -tokenincl token.hpp
	hllr caxe.hlr parse -c++ -hlex lexer -lalr1 -token Token
	mv lexer.cpp src/ && mv lexer.hpp incl/
	mv parse.cpp src/ && mv parse.hpp incl/

tar:
	@echo "-------------"
	@echo "tarring caxe"
	@echo "-------------"
	tar cfvz caxe.tar.gz caxe.hlx caxe.hlr $(INCL)/*.hpp $(SRC)/*.cpp Makefile
