CC    ?= clang
CXX   ?= clang++

EXE = my_js_interpreter

CDEBUG = -g -Wall

CXXDEBUG = -g -Wall

CSTD = -std=c99
CXXSTD = -std=c++11

CFLAGS = -Wno-deprecated-register -O0  $(CDEBUG) $(CSTD) 
CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD)


CPPOBJ = main js_driver
SOBJ =  parser lexer

FILES = $(addsuffix .cpp, $(CPPOBJ))

OBJS  = $(addsuffix .o, $(CPPOBJ))

CLEANLIST =  $(addsuffix .o, $(OBJ)) $(OBJS) \
				js_parser.tab.cc js_parser.tab.hh \
				location.hh position.hh \
			   	stack.hh js_parser.output parser.o \
				lexer.o js_lexer.yy.cc $(EXE)\

.PHONY: all
all: js_interpreter

js_interpreter: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) parser.o lexer.o $(LIBS)


parser: js_parser.yy
	bison -d -v js_parser.yy
	$(CXX) $(CXXFLAGS) -c -o parser.o js_parser.tab.cc

lexer: js_lexer.l
	flex --outfile=js_lexer.yy.cc  $<
	$(CXX)  $(CXXFLAGS) -c js_lexer.yy.cc -o lexer.o

.PHONY: test
test:
	cd test && ./test0.pl

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)