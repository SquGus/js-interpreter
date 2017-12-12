CC = gcc
CFLAGS = -Wall -Wextra -Wno-unused-parameter -O3 -std=c99 -pedantic -D_XOPEN_SOURCE

HAS_FPU = yes
MFPU =

CPUINFO = /proc/cpuinfo
HAS_CPUINFO = $(shell test -e $(CPUINFO) && echo yes)

YACC = bison
YACC_FLAGS = -y -d -t -v

LEX = flex
LEX_FLAGS =

LIBS = -I/usr/local/include -I/usr/include -L/usr/local/lib -L/usr/lib -lm
OBJ_FILES = y.tab.o lex.yy.o js_eval.o js_string.o js_regexp.o js_cli.o \
js_nodes.o js_args.o js_interpreter.o js_debug.o js_gc.o js_props.o \
js_runtime.o lib/Math.o lib/RegExp.o \
lib/Error.o lib/String.o lib/console.o \
lib/gc.o lib/Function.o lib/Object.o \
lib/Boolean.o lib/Number.o lib/Date.o \
lib/Array.o

OUT_FILE = my_js_interpreter
YACC_FILE = js_parser.y
LEX_FILE = js_lexer.l

TEST_FLAGS = --dir test


# Configuration

ifeq ($(HAS_CPUINFO), yes)
  HAS_FPU = $(shell cat $(CPUINFO) | grep fpu | grep yes > /dev/null && echo yes)
  MFPU = $(shell cat $(CPUINFO) | grep -i vfp | tr ' ' '\n' | grep -i vfp | tail -1)
endif


# Build flags, usage: make debug=on

ifeq ($(debug), on)
  CFLAGS += -DFH_DEBUG
endif

ifdef hashfn
  CFLAGS += -DHASH_FUNCTION=$(hashfn)
endif

ifeq ($(gcprofile), on)
  CFLAGS += -DFH_GC_PROFILE
endif

ifneq ($(gcexpose), off)
  CFLAGS += -DFH_GC_EXPOSE
endif

ifeq ($(readline), off)
  CFLAGS += -DFH_NO_REPL
else
  LIBS += -lreadline
endif

ifeq ($(regexp), off)
  CFLAGS += -DFH_NO_REGEXP
else
  LIBS += -lpcre
endif

ifneq ($(HAS_FPU), yes)
  CFLAGS += -mfloat-abi=softfp -mfpu=$(MFPU)
endif

.PHONY: test ctest

all: default

debug: CFLAGS += -g -O0
debug: clean default

malloc-debug: CC = gcc-4.9
malloc-debug: LIBS += -lduma
malloc-debug: debug


lex.yy.c: $(LEX_FILE)
	$(LEX) --header-file=lex.yy.h $(LEX_FLAGS) $(LEX_FILE)

lex.yy.o: lex.yy.c $(LEX_FILE)
	@echo "[CC -o] lex.yy.o"
	@$(CC) -c $(CFLAGS) lex.yy.c -o lex.yy.o

y.tab.o: lex.yy.c $(YACC_FILE)
	$(YACC) $(YACC_FLAGS) $(YACC_FILE)
	@echo "[CC -o] y.tab.o"
	@$(CC) -c $(CFLAGS) y.tab.c -o y.tab.o

linker: $(OBJ_FILES)

.c.o:
	@echo "[CC -c] $@"
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf y.* lex.yy.? y.tab.? $(OUT_FILE) $(OBJ_FILES)

install:
	cp $(OUT_FILE) /usr/local/bin/

default: linker
	@echo "[CC -o] $(OUT_FILE)"
	@$(CC) -o $(OUT_FILE) $(OBJ_FILES) $(LIBS)


ctest:
	node ctest/crunner.js

test:
	bin/test $(TEST_FLAGS) -x bin/flat

test-node:
	bin/test $(TEST_FLAGS) -x node

test-v8:
	bin/test $(TEST_FLAGS) -x v8 -a "test/tools/harness.js [test]"

test-sm:
	bin/test $(TEST_FLAGS) -x js -a "\-f test/tools/harness.js \-f [test]"

test-rhino:
	bin/test $(TEST_FLAGS) -x rhino -t 10000 -a "\-f test/tools/harness.js \-f [test]"

# test-all: TEST_FLAGS += --quiet
# test-all: test test-node test-v8 test-sm test-rhino

test-grammar:
	node_modules/mocha/bin/mocha test/grammar
