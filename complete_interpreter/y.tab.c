/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "js_parser.y" /* yacc.c:339  */

/* IMPORT LIBRARIES, SYMBOL TABLE AND OTHER C CODE HERE */
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <math.h>
    #include <getopt.h>
    #include <setjmp.h>

    #ifndef JS_NO_REPL
        #include <readline/readline.h>
        #include <readline/history.h>
    #endif

    #include "lex.yy.h"
    #include "js_interpreter.h"
    #include "js_nodes.h"
    #include "js_eval.h"
    #include "js_runtime.h"
    #include "js_debug.h"
    #include "js_cli.h"

    /* Does not equips parser with tracing code */
    #define YYDEBUG 0

    /* Defines macros to create each ast_node struct that will build
     * the Abstract Syntax Tree. Each node has slot for three child
     * nodes, a double, a string and a type.
     */

    #define NEW_NODE(t,e1,e2,e3,d,s)   node_new(t,e1,e2,e3,d,s,yylloc.first_line,yylloc.first_column)

    #define NEW_ARGLST(head,tail)      NEW_NODE(NODE_ARG_LST,head,tail,0,0,0)
    #define NEW_ARR(ellst)             NEW_NODE(NODE_ARR,ellst,0,0,0,0)
    #define NEW_ASGN(a,b,op)           NEW_NODE(NODE_ASGN,a,b,0,0,op)
    #define NEW_BLOCK(stmtlst)         NEW_NODE(NODE_BLOCK,stmtlst,0,0,0,0)
    #define NEW_BOOL(x)                NEW_NODE(NODE_BOOL,0,0,0,x,0)
    #define NEW_BREAK()                NEW_NODE(NODE_BREAK,0,0,0,0,0)
    #define NEW_CALL(call,args)        NEW_NODE(NODE_CALL,call,args,0,0,0);
    // #define NEW_CASEBLOCK(c1,def,c2)   NEW_NODE(NODE_CASE_BLOCK,c1,def,c2,0,0)
    // #define NEW_CATCH(id,block)        NEW_NODE(NODE_CATCH,id,block,0,0,0)
    // #define NEW_CLAUSE(exp,stmtlst)    NEW_NODE(NODE_CLAUSE,exp,stmtlst,0,0,0)
    // #define NEW_CLAUSELST(head,tail)   NEW_NODE(NODE_CLAUSE_LST,head,tail,0,0,0)
    #define NEW_CONT()                 NEW_NODE(NODE_CONT,0,0,0,0,0)
    // #define NEW_DEBUGGER()             NEW_NODE(NODE_DEBUG_STMT,0,0,0,0,0)
    #define NEW_DOWHILE(cnd,blck)      NEW_NODE(NODE_DOWHILE,cnd,blck,0,0,0)
    #define NEW_ELISION()              NEW_NODE(NODE_ELISION,0,0,0,0,0)
    #define NEW_ELLST(head,tail)       NEW_NODE(NODE_EL_LST,head,tail,0,0,0)
    #define NEW_EMPTSTMT()             NEW_NODE(NODE_EMPT_STMT,0,0,0,0,0)
    #define NEW_EXP(a,b,op)            NEW_NODE(NODE_EXP,a,b,0,0,op)
    #define NEW_EXPGRP(e1,e2,e3)       NEW_NODE(NODE_EXPGRP,e1,e2,e3,0,0)
    #define NEW_EXPSTMT(exp)           NEW_NODE(NODE_EXP_STMT,exp,0,0,0,0)
    // #define NEW_FINALLY(block)         NEW_NODE(NODE_FINALLY,block,0,0,0,0)
    #define NEW_FOR(exps,stmt)         NEW_NODE(NODE_FOR,exps,stmt,0,0,0)
    // #define NEW_FORIN(lhs,in,stmt)     NEW_NODE(NODE_FORIN,lhs,in,stmt,0,0)
    #define NEW_FUNC(params,body,id)   NEW_NODE(NODE_FUNC,params,body,id,0,0)
    #define NEW_IDENT(name)            NEW_NODE(NODE_IDENT,0,0,0,0,name)
    #define NEW_IF(p,q,r)              NEW_NODE(NODE_IF,p,q,r,0,0)
    #define NEW_MEMBER(head,tail,exp)  NEW_NODE(NODE_MEMBER,head,tail,0,exp,0)
    #define NEW_NEW(exp)               NEW_NODE(NODE_NEW,exp,0,0,0,0);
    #define NEW_NULL()                 NEW_NODE(NODE_NULL,0,0,0,0,0)
    #define NEW_NUM(x)                 NEW_NODE(NODE_NUM,0,0,0,x,0)
    #define NEW_OBJ(proplst)           NEW_NODE(NODE_OBJ,proplst,0,0,0,0)
    #define NEW_PARAMLST(head,tail)    NEW_NODE(NODE_PARAM_LST,head,tail,0,0,0)
    #define NEW_PROP(name,exp)         NEW_NODE(NODE_PROP,name,exp,0,0,0)
    #define NEW_PROPLST(head,tail)     NEW_NODE(NODE_PROP_LST,head,tail,0,0,0)
    // #define NEW_REGEXP(x)              NEW_NODE(NODE_REGEXP,0,0,0,0,x)
    #define NEW_RETURN(exp)            NEW_NODE(NODE_RETURN,exp,0,0,0,0)
    #define NEW_SRCLST(head,tail)      NEW_NODE(NODE_SRC_LST,head,tail,0,0,0)
    #define NEW_STMTLST(head,tail)     NEW_NODE(NODE_STMT_LST,head,tail,0,0,0)
    #define NEW_STR(x)                 NEW_NODE(NODE_STR,0,0,0,0,x)
    #define NEW_SWITCH(exp,cases)      NEW_NODE(NODE_SWITCH_STMT,exp,cases,0,0,0)
    #define NEW_TERN(p,q,r)            NEW_NODE(NODE_TERN,p,q,r,0,0)
    // #define NEW_THIS()                 NEW_NODE(NODE_THIS,0,0,0,0,0)
    // #define NEW_THROW(exp)             NEW_NODE(NODE_THROW,exp,0,0,0,0)
    // #define NEW_TRY(block,catch,final) NEW_NODE(NODE_TRY_STMT,block,catch,final,0,0)
    #define NEW_UNPOST(a,op)           NEW_NODE(NODE_UNARY_POST,a,0,0,0,op)
    #define NEW_UNPRE(a,op)            NEW_NODE(NODE_UNARY_PRE,a,0,0,0,op)
    #define NEW_VARDEC(id,exp)         NEW_NODE(NODE_VAR_DEC,id,exp,0,0,0)
    #define NEW_VARDECLST(head,tail)   NEW_NODE(NODE_VAR_DEC_LST,head,tail,0,0,0)
    #define NEW_VARSTMT(declst)        NEW_NODE(NODE_VAR_STMT,declst,0,0,0,0)
    #define NEW_WHILE(cnd,blck)        NEW_NODE(NODE_WHILE,cnd,blck,0,0,0)
    // #define NEW_WITH(exp,stmt)         NEW_NODE(NODE_WITH_STMT,exp,stmt,0,0,0)

    void yyerror(const char *);
    int yycolumn;
    int yydebug;
    int js_get_input(char *, int);
    ast_node *root;
    eval_state *state;
    js_state *js;

#line 159 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMBER = 258,
    IDENT = 259,
    STRING = 260,
    TRUE = 261,
    FALSE = 262,
    LOGIC_AND_OP = 263,
    LOGIC_OR_OP = 264,
    UNIT_ADD_OP = 265,
    UNIT_SUB_OP = 266,
    TYPEOF = 267,
    EQ_V_OP = 268,
    GE_OP = 269,
    LE_OP = 270,
    NEG_V_OP = 271,
    EQ_VT_OP = 272,
    NEG_VT_OP = 273,
    INSTANCEOF = 274,
    BIT_SHIFT_L_OP = 275,
    BIT_SHIFT_S_R_OP = 276,
    BIT_SHIFT_Z_R_OP = 277,
    SHORT_ADD_OP = 278,
    SHORT_SUB_OP = 279,
    SHORT_MUL_OP = 280,
    SHORT_DIV_OP = 281,
    SHORT_MOD_OP = 282,
    SHORT_BIT_SHIFT_L_OP = 283,
    SHORT_BIT_SHIFT_S_R_OP = 284,
    SHORT_BIT_SHIFT_Z_R_OP = 285,
    SHORT_BIT_AND_OP = 286,
    SHORT_BIT_XOR_OP = 287,
    SHORT_BIT_OR_OP = 288,
    WHILE = 289,
    DO = 290,
    FOR = 291,
    IF = 292,
    ELSE = 293,
    BREAK = 294,
    CONTINUE = 295,
    RETURNT = 296,
    VAR = 297,
    NULLT = 298,
    FUNCTION = 299,
    NEW = 300
  };
#endif
/* Tokens.  */
#define NUMBER 258
#define IDENT 259
#define STRING 260
#define TRUE 261
#define FALSE 262
#define LOGIC_AND_OP 263
#define LOGIC_OR_OP 264
#define UNIT_ADD_OP 265
#define UNIT_SUB_OP 266
#define TYPEOF 267
#define EQ_V_OP 268
#define GE_OP 269
#define LE_OP 270
#define NEG_V_OP 271
#define EQ_VT_OP 272
#define NEG_VT_OP 273
#define INSTANCEOF 274
#define BIT_SHIFT_L_OP 275
#define BIT_SHIFT_S_R_OP 276
#define BIT_SHIFT_Z_R_OP 277
#define SHORT_ADD_OP 278
#define SHORT_SUB_OP 279
#define SHORT_MUL_OP 280
#define SHORT_DIV_OP 281
#define SHORT_MOD_OP 282
#define SHORT_BIT_SHIFT_L_OP 283
#define SHORT_BIT_SHIFT_S_R_OP 284
#define SHORT_BIT_SHIFT_Z_R_OP 285
#define SHORT_BIT_AND_OP 286
#define SHORT_BIT_XOR_OP 287
#define SHORT_BIT_OR_OP 288
#define WHILE 289
#define DO 290
#define FOR 291
#define IF 292
#define ELSE 293
#define BREAK 294
#define CONTINUE 295
#define RETURNT 296
#define VAR 297
#define NULLT 298
#define FUNCTION 299
#define NEW 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 126 "js_parser.y" /* yacc.c:355  */

    char *val;
    int intval;
    double floatval;
    struct ast_node *node;

#line 296 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 327 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  140
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1734

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  93
/* YYNRULES -- Number of rules.  */
#define YYNRULES  271
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  471

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,     2,     2,     2,    49,    64,     2,
      56,    57,    48,    46,    54,    47,    69,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    53,
      65,    55,    66,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,    63,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    62,    52,    68,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   244,   244,   248,   250,   254,   256,   260,   262,   264,
     266,   268,   270,   272,   274,   276,   290,   292,   296,   298,
     302,   306,   308,   312,   314,   318,   320,   324,   326,   330,
     334,   338,   342,   346,   348,   352,   354,   366,   368,   370,
     372,   374,   376,   378,   380,   382,   384,   386,   388,   392,
     396,   400,   402,   465,   467,   469,   471,   473,   479,   481,
     483,   485,   491,   493,   495,   497,   499,   503,   505,   509,
     511,   513,   515,   519,   521,   525,   529,   533,   537,   539,
     541,   545,   547,   551,   555,   557,   559,   569,   571,   582,
     586,   592,   594,   598,   601,   604,   608,   612,   614,   616,
     620,   624,   626,   628,   632,   634,   638,   640,   644,   646,
     650,   652,   656,   658,   662,   664,   668,   670,   674,   676,
     680,   682,   686,   688,   692,   694,   698,   700,   704,   706,
     710,   712,   716,   718,   722,   724,   728,   730,   734,   736,
     740,   742,   744,   746,   748,   752,   754,   756,   758,   760,
     764,   766,   768,   770,   772,   776,   778,   780,   782,   784,
     786,   792,   794,   796,   798,   800,   802,   806,   808,   810,
     812,   814,   816,   820,   822,   824,   826,   830,   832,   834,
     836,   840,   842,   844,   848,   850,   852,   856,   858,   860,
     862,   866,   868,   870,   872,   876,   882,   884,   886,   888,
     890,   892,   894,   898,   904,   906,   908,   910,   912,   914,
     916,   920,   922,   924,   928,   930,   932,   936,   938,   942,
     944,   948,   950,   954,   956,   958,   962,   964,   966,   970,
     972,   974,   978,   980,   982,   984,   986,   988,   990,   992,
     994,   996,   998,  1002,  1004,  1008,  1010,  1014,  1016,  1018,
    1020,  1024,  1026,  1028,  1030,  1034,  1036,  1040,  1042,  1046,
    1048,  1050,  1052,  1054,  1058,  1060,  1062,  1064,  1068,  1070,
    1074,  1076
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "IDENT", "STRING", "TRUE",
  "FALSE", "LOGIC_AND_OP", "LOGIC_OR_OP", "UNIT_ADD_OP", "UNIT_SUB_OP",
  "TYPEOF", "EQ_V_OP", "GE_OP", "LE_OP", "NEG_V_OP", "EQ_VT_OP",
  "NEG_VT_OP", "INSTANCEOF", "BIT_SHIFT_L_OP", "BIT_SHIFT_S_R_OP",
  "BIT_SHIFT_Z_R_OP", "SHORT_ADD_OP", "SHORT_SUB_OP", "SHORT_MUL_OP",
  "SHORT_DIV_OP", "SHORT_MOD_OP", "SHORT_BIT_SHIFT_L_OP",
  "SHORT_BIT_SHIFT_S_R_OP", "SHORT_BIT_SHIFT_Z_R_OP", "SHORT_BIT_AND_OP",
  "SHORT_BIT_XOR_OP", "SHORT_BIT_OR_OP", "WHILE", "DO", "FOR", "IF",
  "ELSE", "BREAK", "CONTINUE", "RETURNT", "VAR", "NULLT", "FUNCTION",
  "NEW", "'+'", "'-'", "'*'", "'%'", "'/'", "'{'", "'}'", "';'", "','",
  "'='", "'('", "')'", "'['", "']'", "':'", "'?'", "'|'", "'^'", "'&'",
  "'<'", "'>'", "'!'", "'~'", "'.'", "$accept", "Program",
  "SourceElements", "SourceElement", "Statement", "Block", "StatementList",
  "VariableStatement", "VariableDecList", "VariableDecListNoIn",
  "VariableDeclaration", "VariableDeclarationNoIn", "Initializer",
  "InitializerNoIn", "EmptyStatement", "ExpressionStatement",
  "IfStatement", "IterationStatement", "ContinueStatement",
  "BreakStatement", "ReturnStatement", "Literal", "LiteralNoObj",
  "ArrayLiteral", "Elision", "ElementList", "BooleanLiteral",
  "StringLiteral", "NullLiteral", "NumericLiteral", "ObjectLiteral",
  "PropertyNameAndValueList", "PropertyAssignment", "PropertyName",
  "NamedFunction", "FunctionDeclaration", "FunctionExpression",
  "FormalParameterList", "FunctionBody", "Identifier", "PrimaryExpression",
  "PrimaryExpressionNoObj", "ConditionalExpression",
  "ConditionalExpressionNoIn", "ConditionalExpressionNoFn",
  "LogicalORExpression", "LogicalORExpressionNoIn",
  "LogicalORExpressionNoFn", "LogicalANDExpression",
  "LogicalANDExpressionNoIn", "LogicalANDExpressionNoFn",
  "BitwiseORExpression", "BitwiseORExpressionNoIn",
  "BitwiseORExpressionNoFn", "BitwiseXORExpression",
  "BitwiseXORExpressionNoIn", "BitwiseXORExpressionNoFn",
  "BitwiseANDExpression", "BitwiseANDExpressionNoIn",
  "BitwiseANDExpressionNoFn", "EqualityExpression",
  "EqualityExpressionNoIn", "EqualityExpressionNoFn",
  "RelationalExpression", "RelationalExpressionNoIn",
  "RelationalExpressionNoFn", "ShiftExpression", "ShiftExpressionNoFn",
  "AdditiveExpression", "AdditiveExpressionNoFn", "MultiExpression",
  "MultiExpressionNoFn", "UnaryExpression", "UnaryExpressionNoFn",
  "PostfixExpression", "PostfixExpressionNoFn", "Expression",
  "ExpressionNoIn", "ExpressionNoFn", "AssignmentExpression",
  "AssignmentExpressionNoIn", "AssignmentExpressionNoFn",
  "AssignmentOperator", "LeftHSExpression", "LeftHSExpressionNoFn",
  "CallExpression", "CallExpressionNoFn", "NewExpression",
  "NewExpressionNoFn", "MemberExpression", "MemberExpressionNoFn",
  "Arguments", "ArgumentList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    43,    45,    42,    37,
      47,   123,   125,    59,    44,    61,    40,    41,    91,    93,
      58,    63,   124,    94,    38,    60,    62,    33,   126,    46
};
# endif

#define YYPACT_NINF -332

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-332)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     950,  -332,  -332,  -332,  -332,  -332,  1666,  1666,  1666,   -44,
    1127,    27,    49,   -25,    43,  1281,    50,  -332,    50,    36,
    1666,  1666,  1009,  -332,  1666,   265,  1666,  1666,    60,   950,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,    12,    99,    90,    52,    58,    32,    53,   233,
      87,   154,  -332,  -332,    92,  -332,   197,     1,  -332,    13,
    1666,  1666,  1666,    36,  1666,  1666,   134,  1666,  1666,  1666,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,   203,    74,  -332,    95,  -332,  -332,  1666,
     120,  1145,  1666,  -332,  -332,  -332,  -332,    17,   164,   121,
     125,   126,   149,    70,   236,   185,   215,  -332,   207,  -332,
     753,   213,  -332,   151,   155,  -332,    95,  -332,  -332,  -332,
    -332,  1068,    -2,  -332,  -332,   338,    -3,  -332,  -332,  -332,
    -332,  -332,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,
    1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,
    1666,  1666,  1666,  1666,  1666,  -332,  1666,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    1666,  1666,   701,  1666,    50,  -332,  1666,    50,  -332,  -332,
    -332,  -332,  -332,    95,  -332,  -332,  -332,  -332,  -332,    23,
    -332,   191,  -332,   128,  -332,  -332,  -332,  -332,  1666,    50,
    -332,  1666,    50,  -332,   135,   229,    50,  1299,  -332,    38,
     241,   227,   231,   232,   157,    76,   236,   220,  -332,  1670,
     137,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,
    1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,
    1666,  1666,  1666,  1666,  -332,  1666,  1666,  1666,  -332,    50,
    1666,  -332,    40,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    1204,  -332,   164,   235,   121,   125,   126,   149,    70,    70,
      70,    70,   236,   236,   236,   236,   236,   185,   185,   185,
     215,   215,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
     142,     7,  -332,    69,  -332,  -332,  -332,   145,  1666,  -332,
     102,  -332,   109,  -332,  1127,  1666,   226,  -332,   237,  1358,
     228,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,  1666,
    1666,  1666,  1666,  1666,  1666,  1666,  1376,  1666,  1666,  1666,
    1127,   164,   238,   121,   125,   126,   149,    70,    70,    70,
      70,   236,   236,   236,   236,   236,   185,   185,   185,   215,
     215,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,   239,
     144,  -332,  -332,  1222,  -332,  1666,  1666,  -332,  -332,  -332,
    -332,  -332,  -332,  -332,  -332,  -332,   161,  1435,    50,  1666,
    -332,  1127,   182,  1453,   241,   243,   227,   231,   232,   157,
      76,    76,    76,    76,   236,   236,   236,   236,   236,  1512,
     230,  -332,  -332,  -332,   253,  1666,   950,    50,   242,  -332,
    -332,  -332,  -332,   244,  1530,   234,  -332,  -332,  -332,  1127,
    1127,   183,  1666,  1127,   187,  1589,  1127,  -332,   950,   247,
    -332,   950,  -332,  1127,   188,  1607,  -332,  -332,  1127,  -332,
    -332,  1127,  1127,   189,  -332,  -332,   249,  -332,  1127,  1127,
     193,  -332,  -332,  -332,  1127,  -332,  -332,  -332,  1127,  -332,
    -332
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    77,    95,    75,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     2,
       3,     5,     7,     8,     9,    10,    11,    12,    13,    14,
      15,   101,   102,    59,    61,    58,    60,    89,     6,   100,
     264,   229,   108,   114,   120,   126,   132,   138,   150,   167,
     177,   184,   191,   203,     0,   221,   214,   246,   245,   257,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,    98,    54,    56,    53,    55,    57,    90,   260,    96,
     259,   205,   195,   211,   244,   243,   255,   206,   204,     0,
       0,     0,     0,    50,    49,    51,   223,   104,   110,   116,
     122,   128,   134,   140,   155,   173,   181,   187,     0,   217,
     211,     0,    21,    26,     0,   258,   255,   207,   208,    16,
      18,     0,     0,    67,    62,     0,     0,    69,   209,   210,
       1,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,   215,   216,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     0,     0,     0,   252,     0,     0,   251,   197,
     198,   196,   256,   255,   199,   200,    78,    85,    86,     0,
      81,     0,    84,     0,   201,   202,   212,   213,     0,     0,
     248,     0,     0,   247,     0,     0,     0,     0,   226,   106,
     112,   118,   124,   130,   136,   145,   161,     0,   219,   211,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,     0,     0,     0,    20,     0,
       0,    25,     0,   267,    17,    19,   103,    68,    63,    70,
       0,    64,   115,     0,   121,   127,   133,   139,   151,   152,
     153,   154,   171,   170,   172,   168,   169,   178,   179,   180,
     185,   186,   192,   194,   193,   222,   230,   231,   268,   270,
       0,     0,   254,     0,   266,   263,    79,     0,     0,    99,
       0,   250,     0,   262,     0,     0,     0,    23,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,   117,   123,   129,   135,   141,   142,   143,
     144,   159,   158,   160,   156,   157,   174,   175,   176,   182,
     183,   188,   190,   189,   218,   224,   225,    22,    29,     0,
       0,    91,    65,     0,    71,     0,     0,   269,   253,   265,
      80,    82,    83,   249,   261,    36,     0,     0,     0,     0,
      27,     0,     0,     0,   113,     0,   119,   125,   131,   137,
     146,   147,   148,   149,   165,   164,   166,   162,   163,     0,
       0,   220,   227,   228,    34,     0,    94,     0,     0,    66,
      72,   109,   271,     0,     0,     0,    24,    30,    48,     0,
       0,     0,     0,     0,     0,     0,     0,   105,    93,     0,
      92,    94,    35,     0,     0,     0,    47,    46,     0,   107,
      43,     0,     0,     0,    33,    88,     0,    44,     0,     0,
       0,    45,    41,    39,     0,    87,    42,    40,     0,    37,
      38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -332,  -332,   304,   -28,   195,  -332,  -332,  -332,  -332,  -332,
      46,   -82,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,
    -332,  -332,  -332,    88,    45,  -332,   147,    24,   171,    64,
    -332,  -332,     6,  -332,     4,  -332,  -332,  -332,  -124,     0,
    -332,  -332,  -332,  -332,  -332,  -332,  -332,  -332,  -125,    -1,
    -332,  -121,    -5,  -332,  -120,     3,  -332,  -119,     5,  -332,
    -116,    -4,  -332,  -113,  -150,  -332,   496,  -332,  -144,  -332,
    -141,  -332,   785,  -332,  -332,  -332,   482,  -332,  -332,   -22,
    -331,  -332,  -118,   543,  -332,  -332,  -332,   -10,  -332,    -8,
    -332,   -64,  -332
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,   438,    30,    31,    32,   131,    33,   121,   316,
     122,   317,   261,   390,    34,    35,    36,    37,    38,    39,
      40,    80,    41,    81,   135,   136,    82,    83,    84,    85,
      86,   199,   200,   201,    87,    48,    88,   370,   439,    89,
      90,    50,   106,   218,    51,   107,   219,    52,   108,   220,
      53,   109,   221,    54,   110,   222,    55,   111,   223,    56,
     112,   224,    57,   113,   225,    58,   114,    59,   115,    60,
     116,    61,   117,    62,    92,    63,   118,   227,    64,   119,
     228,    65,   181,    93,    66,    94,    67,    95,    68,    96,
      69,   185,   300
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      49,   141,   257,   137,    47,   188,   411,   412,   413,   125,
      49,   126,    99,   287,   288,   289,   123,   272,   124,   290,
     291,   142,    49,   274,    44,   275,   231,   276,   103,    49,
     210,   277,   213,    47,    44,   278,   279,   280,   281,     1,
       2,     3,     4,     5,     2,   148,    44,   321,   149,   150,
     151,   270,   255,    44,     2,   266,   271,   182,   427,   183,
     140,   255,   263,   192,    46,   193,   378,   152,   153,   182,
     184,   186,   154,   143,    46,   306,   202,   307,   232,    17,
      18,    73,   187,   101,   241,   242,    46,    76,    42,   243,
     331,   332,    77,    46,    25,   333,   104,   369,    42,   322,
     197,   449,   356,   357,   358,   102,   341,   144,   359,   360,
      42,   339,   343,   269,   344,   146,   345,    42,   155,   156,
     346,   273,   147,   255,   347,   348,   349,   350,   379,   305,
     182,    49,   208,   160,   161,   244,   245,     1,     2,     3,
     198,   334,   335,   209,   295,   165,   166,    43,     1,     2,
       3,   182,   145,   211,   215,    44,   255,    43,   296,   297,
     299,   383,   237,   255,   212,   238,   239,   240,   384,    43,
     327,    45,   233,   328,   329,   330,    43,   400,   401,   402,
     403,    45,   255,   234,   302,   309,   196,   304,   235,   255,
     236,   255,   314,    45,   340,    46,   376,   380,   417,   377,
      45,   418,   162,   163,   164,   100,   260,   167,   168,   311,
     342,   262,   313,   206,   207,   255,   318,   130,   423,    42,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   249,   250,   364,   365,   366,   255,   255,   368,   429,
     448,   255,   255,   255,   451,   458,   464,   255,   374,   323,
     468,   308,   180,   157,   158,   159,   246,   247,   248,   123,
     254,   255,   371,   251,   252,   253,   258,   259,     1,     2,
       3,     4,     5,   336,   337,    70,    71,    72,    43,   387,
     388,   393,   255,   435,   255,   315,   382,   445,   255,   324,
     416,   436,   389,   441,   325,   375,   326,   442,   415,   455,
     395,   465,    45,   432,    29,   367,   426,   202,    17,    18,
      73,    74,    75,   381,    49,   373,    76,   456,   396,   133,
     394,    77,   399,    25,   134,     0,   265,   397,     0,     0,
     398,   197,    78,    79,     0,     0,     0,     0,    44,     0,
      49,     1,     2,     3,     4,     5,     0,     0,    70,    71,
      72,   420,     0,   421,   422,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,     0,     0,     0,     0,
       0,   198,     0,     0,     0,     0,     0,     0,    46,     0,
       0,    17,    18,    73,    74,    75,     0,     0,   318,    76,
       0,    49,   267,   437,    77,     0,    25,   268,     0,     0,
       0,     0,    42,     0,    46,    78,    79,     0,     0,     0,
     141,     0,     0,     0,     0,    44,    49,   440,     0,     0,
      47,     0,     0,     0,     0,     0,     0,     0,    42,    49,
      49,     0,     0,    49,     0,     0,    49,     0,    49,     0,
      44,    49,    47,    49,     0,    47,     0,     0,    49,     0,
       0,    49,    49,    44,    44,    46,     0,    44,    49,    49,
      44,    43,    44,     0,    49,    44,     0,    44,    49,     0,
       0,     0,    44,     0,     0,    44,    44,     0,     0,    42,
      46,     0,    44,    44,     0,    45,     0,    43,    44,     0,
       0,     0,    44,    46,    46,     0,     0,    46,     0,     0,
      46,     0,    46,     0,    42,    46,   132,    46,     0,   385,
       0,    45,    46,     0,     0,    46,    46,    42,    42,     0,
       0,    42,    46,    46,    42,     0,    42,     0,    46,    42,
       0,    42,    46,     0,     0,   414,    42,     0,    43,    42,
      42,     0,     0,     0,     0,     0,    42,    42,     0,     0,
       0,     0,    42,     0,     0,     0,    42,     0,   120,   203,
       0,     0,    45,    43,     0,     0,     0,   120,   120,     0,
       0,     0,     0,     0,     0,     0,    43,    43,     0,     0,
      43,   214,     0,    43,   230,    43,   428,    45,    43,     0,
      43,     0,     0,     0,     0,    43,     0,   226,    43,    43,
      45,    45,     0,     0,    45,    43,    43,    45,     0,    45,
       0,    43,    45,     0,    45,    43,     0,     0,     0,    45,
     120,     0,    45,    45,   446,   447,     0,     0,   450,    45,
      45,   454,     0,     0,     0,    45,     0,     0,   457,    45,
       0,     0,   120,   461,   229,   120,   462,   463,   282,   283,
     284,   285,   286,   466,   467,     0,     0,     0,     0,   469,
       0,     0,     0,   470,     0,   301,     0,     0,   303,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     0,   120,     0,     0,     0,
     310,     0,     0,   312,     0,     0,     0,     0,     0,   320,
       0,     0,     0,     0,     1,     2,     3,     4,     5,   120,
       0,    70,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   120,   120,   120,   120,     0,     0,   120,
       0,     0,     0,     0,     0,     0,     0,   351,   352,   353,
     354,   355,     0,     0,    17,    18,    73,    74,    75,     0,
       0,   120,    76,     0,   120,     0,     0,    77,   298,    25,
     120,     0,     0,   206,   207,     0,     0,     0,    78,    79,
       0,     0,     0,     0,     0,   120,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,     0,     0,     0,
       0,    91,    97,    98,     0,     0,     0,   386,   120,   120,
     120,   392,     0,   120,     0,   127,   128,     0,   256,     0,
       0,   138,   139,   120,     0,     0,     0,   226,   410,   226,
     226,   226,   226,   226,   226,   226,   226,   404,   405,   406,
     407,   408,     0,   226,   226,   226,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,   189,   190,   191,   120,   194,
     195,     0,   120,   204,   205,   120,     0,     0,     0,   425,
       0,     0,     0,     0,     0,   431,     0,     0,     0,   120,
     229,   229,   229,     0,     0,   226,     0,     0,     0,     0,
       0,   434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   444,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   453,   120,   120,
       0,     0,     0,     0,     0,     0,     0,   460,   226,     0,
     120,     0,   229,     0,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   292,   293,   294,
       0,     0,   120,     1,     2,     3,     4,     5,   120,     0,
       6,     7,     8,     0,     0,     0,     0,   120,     0,     0,
       0,     0,     0,     0,     0,   229,     0,     0,   120,     0,
       0,     0,     0,     0,     9,    10,    11,    12,   120,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,    22,     0,    23,     0,     0,    24,     0,    25,     0,
       0,     0,     1,     2,     3,     4,     5,    26,    27,     6,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   361,   362,   363,     0,
       0,     0,     0,     9,    10,    11,    12,     0,    13,    14,
      15,    16,    17,     0,    19,    20,    21,     0,     0,     0,
      22,   129,    23,     0,     0,    24,     0,    25,     0,     0,
       0,     1,     2,     3,     4,     5,    26,    27,     6,     7,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,    11,    12,     0,    13,    14,    15,
      16,    17,     0,    19,    20,    21,     0,     0,     0,    22,
     264,    23,     0,     0,    24,     0,    25,     0,     0,     0,
       1,     2,     3,     4,     5,    26,    27,     6,     7,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     0,     0,    70,    71,    72,     0,     0,
       0,     9,    10,    11,    12,     0,    13,    14,    15,    16,
      17,     0,    19,    20,    21,     0,     0,     0,    22,     0,
      23,     0,     0,    24,     0,    25,     0,   216,    17,    18,
      73,    74,    75,     0,    26,    27,    76,     0,   217,     0,
       0,    77,     0,    25,     0,     0,     0,     1,     2,     3,
       4,     5,    78,    79,    70,    71,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       0,     0,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    73,
      74,    75,     0,     0,     0,    76,     0,     0,   133,     0,
      77,     0,    25,   372,     0,    17,    18,    73,    74,    75,
       0,    78,    79,    76,     0,     0,   267,     0,    77,     0,
      25,   419,     0,     0,     1,     2,     3,     4,     5,    78,
      79,    70,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     0,     0,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    73,    74,    75,     0,
       0,     0,    76,     0,   105,     0,     0,    77,     0,    25,
       0,     0,    17,    18,    73,    74,    75,     0,    78,    79,
      76,     0,   319,     0,     0,    77,     0,    25,     0,     0,
       0,     1,     2,     3,     4,     5,    78,    79,    70,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     0,     0,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    73,    74,    75,     0,     0,     0,    76,
       0,     0,     0,     0,    77,   391,    25,     0,     0,    17,
      18,    73,    74,    75,     0,    78,    79,    76,     0,   409,
       0,     0,    77,     0,    25,     0,     0,     0,     1,     2,
       3,     4,     5,    78,    79,    70,    71,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     0,     0,    70,    71,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      73,    74,    75,     0,     0,     0,    76,     0,   424,     0,
       0,    77,     0,    25,     0,     0,    17,    18,    73,    74,
      75,     0,    78,    79,    76,     0,     0,     0,     0,    77,
     430,    25,     0,     0,     0,     1,     2,     3,     4,     5,
      78,    79,    70,    71,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     0,     0,
      70,    71,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    73,    74,    75,
       0,     0,     0,    76,     0,     0,     0,     0,    77,   433,
      25,     0,     0,    17,    18,    73,    74,    75,     0,    78,
      79,    76,     0,     0,     0,     0,    77,   443,    25,     0,
       0,     0,     1,     2,     3,     4,     5,    78,    79,    70,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     0,     0,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    73,    74,    75,     0,     0,     0,
      76,     0,     0,     0,     0,    77,   452,    25,     0,     0,
      17,    18,    73,    74,    75,     0,    78,    79,    76,     0,
       0,     0,     0,    77,   459,    25,     0,     0,     0,     1,
       2,     3,     4,     5,    78,    79,    70,    71,    72,     0,
     206,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,     0,     0,     0,     0,     0,    17,
      18,    73,    74,    75,     0,     0,     0,    76,     0,     0,
       0,     0,    77,     0,    25,   338,     0,     0,     0,     0,
       0,     0,     0,    78,    79
};

static const yytype_int16 yycheck[] =
{
       0,    29,   120,    25,     0,    69,   337,   338,   339,    19,
      10,    19,    56,   157,   158,   159,    16,   142,    18,   160,
     161,     9,    22,   144,     0,   145,     9,   146,    53,    29,
      94,   147,    96,    29,    10,   148,   149,   150,   151,     3,
       4,     5,     6,     7,     4,    13,    22,     9,    16,    17,
      18,    54,    54,    29,     4,    57,    59,    56,   389,    58,
       0,    54,   126,    73,     0,    73,    59,    14,    15,    56,
      69,    58,    19,    61,    10,    52,    76,    54,    61,    43,
      44,    45,    69,    56,    14,    15,    22,    51,     0,    19,
      14,    15,    56,    29,    58,    19,    53,    57,    10,    61,
      76,   432,   246,   247,   248,    56,   231,     8,   249,   250,
      22,   229,   233,   135,   234,    63,   235,    29,    65,    66,
     236,   143,    64,    54,   237,   238,   239,   240,    59,   193,
      56,   131,    58,    46,    47,    65,    66,     3,     4,     5,
      76,    65,    66,    69,   166,    53,    54,     0,     3,     4,
       5,    56,    62,    58,    34,   131,    54,    10,   180,   181,
     182,    59,    13,    54,    69,    16,    17,    18,    59,    22,
      13,     0,     8,    16,    17,    18,    29,   327,   328,   329,
     330,    10,    54,    62,   184,    57,    52,   187,    63,    54,
      64,    54,    57,    22,    57,   131,    54,    52,    54,    57,
      29,    57,    48,    49,    50,    10,    55,    10,    11,   209,
     232,    56,   212,    10,    11,    54,   216,    22,    57,   131,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    46,    47,   255,   256,   257,    54,    54,   260,    57,
      57,    54,    54,    54,    57,    57,    57,    54,   270,     8,
      57,    60,    55,    20,    21,    22,    20,    21,    22,   259,
      53,    54,   262,    48,    49,    50,    53,    54,     3,     4,
       5,     6,     7,    53,    54,    10,    11,    12,   131,    53,
      54,    53,    54,    53,    54,    56,   308,    53,    54,    62,
      51,    38,    55,    51,    63,    60,    64,    53,    60,    52,
     322,    52,   131,    60,     0,   259,   388,   307,    43,    44,
      45,    46,    47,   307,   314,   270,    51,   441,   323,    54,
     321,    56,   326,    58,    59,    -1,   131,   324,    -1,    -1,
     325,   307,    67,    68,    -1,    -1,    -1,    -1,   314,    -1,
     340,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,   373,    -1,   375,   376,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   340,    -1,    -1,    -1,    -1,    -1,
      -1,   307,    -1,    -1,    -1,    -1,    -1,    -1,   314,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    -1,   388,    51,
      -1,   391,    54,   415,    56,    -1,    58,    59,    -1,    -1,
      -1,    -1,   314,    -1,   340,    67,    68,    -1,    -1,    -1,
     438,    -1,    -1,    -1,    -1,   391,   416,   417,    -1,    -1,
     416,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   340,   429,
     430,    -1,    -1,   433,    -1,    -1,   436,    -1,   438,    -1,
     416,   441,   438,   443,    -1,   441,    -1,    -1,   448,    -1,
      -1,   451,   452,   429,   430,   391,    -1,   433,   458,   459,
     436,   314,   438,    -1,   464,   441,    -1,   443,   468,    -1,
      -1,    -1,   448,    -1,    -1,   451,   452,    -1,    -1,   391,
     416,    -1,   458,   459,    -1,   314,    -1,   340,   464,    -1,
      -1,    -1,   468,   429,   430,    -1,    -1,   433,    -1,    -1,
     436,    -1,   438,    -1,   416,   441,    24,   443,    -1,   314,
      -1,   340,   448,    -1,    -1,   451,   452,   429,   430,    -1,
      -1,   433,   458,   459,   436,    -1,   438,    -1,   464,   441,
      -1,   443,   468,    -1,    -1,   340,   448,    -1,   391,   451,
     452,    -1,    -1,    -1,    -1,    -1,   458,   459,    -1,    -1,
      -1,    -1,   464,    -1,    -1,    -1,   468,    -1,    15,    77,
      -1,    -1,   391,   416,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   429,   430,    -1,    -1,
     433,    99,    -1,   436,   102,   438,   391,   416,   441,    -1,
     443,    -1,    -1,    -1,    -1,   448,    -1,   101,   451,   452,
     429,   430,    -1,    -1,   433,   458,   459,   436,    -1,   438,
      -1,   464,   441,    -1,   443,   468,    -1,    -1,    -1,   448,
      77,    -1,   451,   452,   429,   430,    -1,    -1,   433,   458,
     459,   436,    -1,    -1,    -1,   464,    -1,    -1,   443,   468,
      -1,    -1,    99,   448,   101,   102,   451,   452,   152,   153,
     154,   155,   156,   458,   459,    -1,    -1,    -1,    -1,   464,
      -1,    -1,    -1,   468,    -1,   183,    -1,    -1,   186,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,    -1,    -1,    -1,
     208,    -1,    -1,   211,    -1,    -1,    -1,    -1,    -1,   217,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,   166,
      -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,   183,    -1,    -1,   186,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   241,   242,   243,
     244,   245,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,   208,    51,    -1,   211,    -1,    -1,    56,    57,    58,
     217,    -1,    -1,    10,    11,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,   232,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,     6,     7,     8,    -1,    -1,    -1,   315,   255,   256,
     257,   319,    -1,   260,    -1,    20,    21,    -1,    55,    -1,
      -1,    26,    27,   270,    -1,    -1,    -1,   321,   336,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,    -1,   337,   338,   339,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,    -1,    70,    71,    72,   315,    74,
      75,    -1,   319,    78,    79,   322,    -1,    -1,    -1,   387,
      -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,   336,
     337,   338,   339,    -1,    -1,   389,    -1,    -1,    -1,    -1,
      -1,   409,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   373,   435,   375,   376,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   445,   432,    -1,
     387,    -1,   389,    -1,    -1,    -1,   393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,   164,
      -1,    -1,   409,     3,     4,     5,     6,     7,   415,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,   424,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,   435,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,   445,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    -1,    -1,
      -1,    51,    -1,    53,    -1,    -1,    56,    -1,    58,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    67,    68,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   251,   252,   253,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    -1,    39,    40,
      41,    42,    43,    -1,    45,    46,    47,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    56,    -1,    58,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    67,    68,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    -1,    39,    40,    41,
      42,    43,    -1,    45,    46,    47,    -1,    -1,    -1,    51,
      52,    53,    -1,    -1,    56,    -1,    58,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    67,    68,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    -1,    -1,
      -1,    34,    35,    36,    37,    -1,    39,    40,    41,    42,
      43,    -1,    45,    46,    47,    -1,    -1,    -1,    51,    -1,
      53,    -1,    -1,    56,    -1,    58,    -1,    42,    43,    44,
      45,    46,    47,    -1,    67,    68,    51,    -1,    53,    -1,
      -1,    56,    -1,    58,    -1,    -1,    -1,     3,     4,     5,
       6,     7,    67,    68,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      -1,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,
      56,    -1,    58,    59,    -1,    43,    44,    45,    46,    47,
      -1,    67,    68,    51,    -1,    -1,    54,    -1,    56,    -1,
      58,    59,    -1,    -1,     3,     4,     5,     6,     7,    67,
      68,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,
      -1,    -1,    51,    -1,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    67,    68,
      51,    -1,    53,    -1,    -1,    56,    -1,    58,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    67,    68,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    67,    68,    51,    -1,    53,
      -1,    -1,    56,    -1,    58,    -1,    -1,    -1,     3,     4,
       5,     6,     7,    67,    68,    10,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    -1,    -1,    -1,    51,    -1,    53,    -1,
      -1,    56,    -1,    58,    -1,    -1,    43,    44,    45,    46,
      47,    -1,    67,    68,    51,    -1,    -1,    -1,    -1,    56,
      57,    58,    -1,    -1,    -1,     3,     4,     5,     6,     7,
      67,    68,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    56,    57,
      58,    -1,    -1,    43,    44,    45,    46,    47,    -1,    67,
      68,    51,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    67,    68,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    56,    57,    58,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    67,    68,    51,    -1,
      -1,    -1,    -1,    56,    57,    58,    -1,    -1,    -1,     3,
       4,     5,     6,     7,    67,    68,    10,    11,    12,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    56,    -1,    58,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    10,    11,    12,    34,
      35,    36,    37,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    51,    53,    56,    58,    67,    68,    71,    72,
      73,    74,    75,    77,    84,    85,    86,    87,    88,    89,
      90,    92,    93,    96,    97,    98,    99,   104,   105,   109,
     111,   114,   117,   120,   123,   126,   129,   132,   135,   137,
     139,   141,   143,   145,   148,   151,   154,   156,   158,   160,
      10,    11,    12,    45,    46,    47,    51,    56,    67,    68,
      91,    93,    96,    97,    98,    99,   100,   104,   106,   109,
     110,   142,   144,   153,   155,   157,   159,   142,   142,    56,
      74,    56,    56,    53,    53,    53,   112,   115,   118,   121,
     124,   127,   130,   133,   136,   138,   140,   142,   146,   149,
     153,    78,    80,   109,   109,   157,   159,   142,   142,    52,
      74,    76,   146,    54,    59,    94,    95,   149,   142,   142,
       0,    73,     9,    61,     8,    62,    63,    64,    13,    16,
      17,    18,    14,    15,    19,    65,    66,    20,    21,    22,
      46,    47,    48,    49,    50,    53,    54,    10,    11,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      55,   152,    56,    58,    69,   161,    58,    69,   161,   142,
     142,   142,   157,   159,   142,   142,    52,    97,    99,   101,
     102,   103,   109,   146,   142,   142,    10,    11,    58,    69,
     161,    58,    69,   161,   146,    34,    42,    53,   113,   116,
     119,   122,   125,   128,   131,   134,   136,   147,   150,   153,
     146,     9,    61,     8,    62,    63,    64,    13,    16,    17,
      18,    14,    15,    19,    65,    66,    20,    21,    22,    46,
      47,    48,    49,    50,    53,    54,    55,   152,    53,    54,
      55,    82,    56,   161,    52,    74,    57,    54,    59,   149,
      54,    59,   118,   149,   121,   124,   127,   130,   133,   133,
     133,   133,   136,   136,   136,   136,   136,   138,   138,   138,
     140,   140,   142,   142,   142,   149,   149,   149,    57,   149,
     162,   146,   109,   146,   109,   161,    52,    54,    60,    57,
     146,   109,   146,   109,    57,    56,    79,    81,   109,    53,
     146,     9,    61,     8,    62,    63,    64,    13,    16,    17,
      18,    14,    15,    19,    65,    66,    53,    54,    55,   152,
      57,   118,   149,   121,   124,   127,   130,   133,   133,   133,
     133,   136,   136,   136,   136,   136,   138,   138,   138,   140,
     140,   142,   142,   142,   149,   149,   149,    80,   149,    57,
     107,   109,    59,    94,   149,    60,    54,    57,    59,    59,
      52,   102,   149,    59,    59,    74,   146,    53,    54,    55,
      83,    57,   146,    53,   119,   149,   122,   125,   128,   131,
     134,   134,   134,   134,   136,   136,   136,   136,   136,    53,
     146,   150,   150,   150,    74,    60,    51,    54,    57,    59,
     149,   149,   149,    57,    53,   146,    81,   150,    74,    57,
      57,   146,    60,    57,   146,    53,    38,   149,    72,   108,
     109,    51,    53,    57,   146,    53,    74,    74,    57,   150,
      74,    57,    57,   146,    74,    52,   108,    74,    57,    57,
     146,    74,    74,    74,    57,    52,    74,    74,    57,    74,
      74
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      83,    84,    85,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    88,
      89,    90,    90,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    95,    95,    96,    96,    97,    98,    99,   100,   100,
     100,   101,   101,   102,   103,   103,   103,   104,   104,   105,
     106,   107,   107,   108,   108,   109,   110,   110,   110,   110,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     130,   130,   130,   130,   130,   131,   131,   131,   131,   131,
     132,   132,   132,   132,   132,   133,   133,   133,   133,   133,
     133,   134,   134,   134,   134,   134,   134,   135,   135,   135,
     135,   135,   135,   136,   136,   136,   136,   137,   137,   137,
     137,   138,   138,   138,   139,   139,   139,   140,   140,   140,
     140,   141,   141,   141,   141,   142,   142,   142,   142,   142,
     142,   142,   142,   143,   143,   143,   143,   143,   143,   143,
     143,   144,   144,   144,   145,   145,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   149,   150,   150,   150,   151,
     151,   151,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   153,   153,   154,   154,   155,   155,   155,
     155,   156,   156,   156,   156,   157,   157,   158,   158,   159,
     159,   159,   159,   159,   160,   160,   160,   160,   161,   161,
     162,   162
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     2,
       3,     1,     3,     1,     3,     2,     1,     2,     1,     2,
       2,     1,     2,     7,     5,     7,     5,     9,    10,     8,
       9,     8,     9,     7,     8,     8,     7,     7,     6,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     3,     4,     5,     1,     2,     1,
       2,     3,     4,     1,     1,     1,     1,     1,     2,     3,
       4,     1,     3,     3,     1,     1,     1,     8,     7,     1,
       1,     1,     3,     1,     0,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     5,     1,     5,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     1,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       3,     2,     2,     4,     3,     1,     2,     1,     2,     1,
       1,     4,     3,     3,     1,     4,     3,     3,     2,     3,
       1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 245 "js_parser.y" /* yacc.c:1661  */
    { root = (yyvsp[0].node); }
#line 2127 "y.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 249 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_SRCLST((yyvsp[0].node), NULL); }
#line 2133 "y.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 251 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_SRCLST((yyvsp[0].node), (yyvsp[-1].node)); }
#line 2139 "y.tab.c" /* yacc.c:1661  */
    break;

  case 5:
#line 255 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2145 "y.tab.c" /* yacc.c:1661  */
    break;

  case 6:
#line 257 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2151 "y.tab.c" /* yacc.c:1661  */
    break;

  case 7:
#line 261 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2157 "y.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 263 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2163 "y.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 265 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2169 "y.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 267 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2175 "y.tab.c" /* yacc.c:1661  */
    break;

  case 11:
#line 269 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2181 "y.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 271 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2187 "y.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 273 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2193 "y.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 275 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2199 "y.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 277 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2205 "y.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 291 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_BLOCK(NULL); }
#line 2211 "y.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 293 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_BLOCK((yyvsp[-1].node)); }
#line 2217 "y.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 297 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_STMTLST((yyvsp[0].node), NULL); }
#line 2223 "y.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 299 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_STMTLST((yyvsp[0].node), (yyvsp[-1].node)); }
#line 2229 "y.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 303 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARSTMT((yyvsp[-1].node)); }
#line 2235 "y.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 307 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARDECLST((yyvsp[0].node), NULL); }
#line 2241 "y.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 309 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARDECLST((yyvsp[0].node), (yyvsp[-2].node)); }
#line 2247 "y.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 313 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARDECLST((yyvsp[0].node), NULL); }
#line 2253 "y.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 315 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARDECLST((yyvsp[0].node), (yyvsp[-2].node)); }
#line 2259 "y.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 319 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARDEC((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2265 "y.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 321 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARDEC((yyvsp[0].node), NULL); }
#line 2271 "y.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 325 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARDEC((yyvsp[-1].node), (yyvsp[0].node)); }
#line 2277 "y.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 327 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_VARDEC((yyvsp[0].node), NULL); }
#line 2283 "y.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 331 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2289 "y.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 335 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2295 "y.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 339 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EMPTSTMT(); }
#line 2301 "y.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 343 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXPSTMT((yyvsp[-1].node)); }
#line 2307 "y.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 347 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_IF((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2313 "y.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 349 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_IF((yyvsp[-2].node), (yyvsp[0].node), NULL); }
#line 2319 "y.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 353 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_DOWHILE((yyvsp[-5].node), (yyvsp[-2].node)); }
#line 2325 "y.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 355 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_WHILE((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2331 "y.tab.c" /* yacc.c:1661  */
    break;

  case 37:
#line 367 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node)); }
#line 2337 "y.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 369 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node)); }
#line 2343 "y.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 371 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP((yyvsp[-5].node), (yyvsp[-3].node), NULL), (yyvsp[0].node)); }
#line 2349 "y.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 373 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP((yyvsp[-5].node), (yyvsp[-3].node), NULL), (yyvsp[0].node)); }
#line 2355 "y.tab.c" /* yacc.c:1661  */
    break;

  case 41:
#line 375 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP((yyvsp[-5].node), NULL, (yyvsp[-2].node)), (yyvsp[0].node)); }
#line 2361 "y.tab.c" /* yacc.c:1661  */
    break;

  case 42:
#line 377 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP((yyvsp[-5].node), NULL, (yyvsp[-2].node)), (yyvsp[0].node)); }
#line 2367 "y.tab.c" /* yacc.c:1661  */
    break;

  case 43:
#line 379 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP((yyvsp[-4].node), NULL, NULL), (yyvsp[0].node)); }
#line 2373 "y.tab.c" /* yacc.c:1661  */
    break;

  case 44:
#line 381 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP((yyvsp[-4].node), NULL, NULL), (yyvsp[0].node)); }
#line 2379 "y.tab.c" /* yacc.c:1661  */
    break;

  case 45:
#line 383 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP(NULL, (yyvsp[-4].node), (yyvsp[-2].node)), (yyvsp[0].node)); }
#line 2385 "y.tab.c" /* yacc.c:1661  */
    break;

  case 46:
#line 385 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP(NULL, (yyvsp[-3].node), NULL), (yyvsp[0].node)); }
#line 2391 "y.tab.c" /* yacc.c:1661  */
    break;

  case 47:
#line 387 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP(NULL, NULL, (yyvsp[-2].node)), (yyvsp[0].node)); }
#line 2397 "y.tab.c" /* yacc.c:1661  */
    break;

  case 48:
#line 389 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FOR(NEW_EXPGRP(NULL, NULL, NULL), (yyvsp[0].node)); }
#line 2403 "y.tab.c" /* yacc.c:1661  */
    break;

  case 49:
#line 393 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CONT(); }
#line 2409 "y.tab.c" /* yacc.c:1661  */
    break;

  case 50:
#line 397 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_BREAK(); }
#line 2415 "y.tab.c" /* yacc.c:1661  */
    break;

  case 51:
#line 401 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_RETURN(NULL); }
#line 2421 "y.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 403 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_RETURN((yyvsp[-1].node)); }
#line 2427 "y.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 466 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2433 "y.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 468 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2439 "y.tab.c" /* yacc.c:1661  */
    break;

  case 55:
#line 470 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2445 "y.tab.c" /* yacc.c:1661  */
    break;

  case 56:
#line 472 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2451 "y.tab.c" /* yacc.c:1661  */
    break;

  case 57:
#line 474 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2457 "y.tab.c" /* yacc.c:1661  */
    break;

  case 58:
#line 480 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2463 "y.tab.c" /* yacc.c:1661  */
    break;

  case 59:
#line 482 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2469 "y.tab.c" /* yacc.c:1661  */
    break;

  case 60:
#line 484 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2475 "y.tab.c" /* yacc.c:1661  */
    break;

  case 61:
#line 486 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2481 "y.tab.c" /* yacc.c:1661  */
    break;

  case 62:
#line 492 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ARR(NULL); }
#line 2487 "y.tab.c" /* yacc.c:1661  */
    break;

  case 63:
#line 494 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ARR(NULL); }
#line 2493 "y.tab.c" /* yacc.c:1661  */
    break;

  case 64:
#line 496 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ARR((yyvsp[-1].node)); }
#line 2499 "y.tab.c" /* yacc.c:1661  */
    break;

  case 65:
#line 498 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ARR((yyvsp[-2].node)); }
#line 2505 "y.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 500 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ARR((yyvsp[-3].node)); }
#line 2511 "y.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 504 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ELISION(); }
#line 2517 "y.tab.c" /* yacc.c:1661  */
    break;

  case 68:
#line 506 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ELISION(); }
#line 2523 "y.tab.c" /* yacc.c:1661  */
    break;

  case 69:
#line 510 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ELLST((yyvsp[0].node), NULL); }
#line 2529 "y.tab.c" /* yacc.c:1661  */
    break;

  case 70:
#line 512 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ELLST((yyvsp[0].node), NULL); }
#line 2535 "y.tab.c" /* yacc.c:1661  */
    break;

  case 71:
#line 514 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ELLST((yyvsp[0].node), (yyvsp[-2].node)); }
#line 2541 "y.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 516 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ELLST((yyvsp[0].node), (yyvsp[-3].node)); }
#line 2547 "y.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 520 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_BOOL(1); }
#line 2553 "y.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 522 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_BOOL(0); }
#line 2559 "y.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 526 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_STR((yyvsp[0].val)); }
#line 2565 "y.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 530 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_NULL(); }
#line 2571 "y.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 534 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_NUM((yyvsp[0].floatval)); }
#line 2577 "y.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 538 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_OBJ(NULL); }
#line 2583 "y.tab.c" /* yacc.c:1661  */
    break;

  case 79:
#line 540 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_OBJ((yyvsp[-1].node)); }
#line 2589 "y.tab.c" /* yacc.c:1661  */
    break;

  case 80:
#line 542 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_OBJ((yyvsp[-2].node)); }
#line 2595 "y.tab.c" /* yacc.c:1661  */
    break;

  case 81:
#line 546 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_PROPLST((yyvsp[0].node), NULL); }
#line 2601 "y.tab.c" /* yacc.c:1661  */
    break;

  case 82:
#line 548 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_PROPLST((yyvsp[0].node), (yyvsp[-2].node)); }
#line 2607 "y.tab.c" /* yacc.c:1661  */
    break;

  case 83:
#line 552 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_PROP((yyvsp[-2].node), (yyvsp[0].node)); }
#line 2613 "y.tab.c" /* yacc.c:1661  */
    break;

  case 84:
#line 556 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2619 "y.tab.c" /* yacc.c:1661  */
    break;

  case 85:
#line 558 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2625 "y.tab.c" /* yacc.c:1661  */
    break;

  case 86:
#line 560 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2631 "y.tab.c" /* yacc.c:1661  */
    break;

  case 87:
#line 570 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FUNC((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-6].node)); }
#line 2637 "y.tab.c" /* yacc.c:1661  */
    break;

  case 88:
#line 572 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_FUNC(NULL, (yyvsp[-1].node), (yyvsp[-5].node)); }
#line 2643 "y.tab.c" /* yacc.c:1661  */
    break;

  case 89:
#line 583 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2649 "y.tab.c" /* yacc.c:1661  */
    break;

  case 90:
#line 587 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2655 "y.tab.c" /* yacc.c:1661  */
    break;

  case 91:
#line 593 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_PARAMLST((yyvsp[0].node), NULL); }
#line 2661 "y.tab.c" /* yacc.c:1661  */
    break;

  case 92:
#line 595 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_PARAMLST((yyvsp[0].node), (yyvsp[-2].node)); }
#line 2667 "y.tab.c" /* yacc.c:1661  */
    break;

  case 93:
#line 599 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2673 "y.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 601 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NULL; }
#line 2679 "y.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 605 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_IDENT((yyvsp[0].val)); }
#line 2685 "y.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 609 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2691 "y.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 613 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2697 "y.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 615 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2703 "y.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 617 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2709 "y.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 621 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2715 "y.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 625 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2721 "y.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 627 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2727 "y.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 629 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 2733 "y.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 633 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2739 "y.tab.c" /* yacc.c:1661  */
    break;

  case 105:
#line 635 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_TERN((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2745 "y.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 639 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2751 "y.tab.c" /* yacc.c:1661  */
    break;

  case 107:
#line 641 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_TERN((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2757 "y.tab.c" /* yacc.c:1661  */
    break;

  case 108:
#line 645 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2763 "y.tab.c" /* yacc.c:1661  */
    break;

  case 109:
#line 647 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_TERN((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node)); }
#line 2769 "y.tab.c" /* yacc.c:1661  */
    break;

  case 110:
#line 651 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2775 "y.tab.c" /* yacc.c:1661  */
    break;

  case 111:
#line 653 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "||"); }
#line 2781 "y.tab.c" /* yacc.c:1661  */
    break;

  case 112:
#line 657 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2787 "y.tab.c" /* yacc.c:1661  */
    break;

  case 113:
#line 659 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "||"); }
#line 2793 "y.tab.c" /* yacc.c:1661  */
    break;

  case 114:
#line 663 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2799 "y.tab.c" /* yacc.c:1661  */
    break;

  case 115:
#line 665 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "||"); }
#line 2805 "y.tab.c" /* yacc.c:1661  */
    break;

  case 116:
#line 669 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2811 "y.tab.c" /* yacc.c:1661  */
    break;

  case 117:
#line 671 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "&&"); }
#line 2817 "y.tab.c" /* yacc.c:1661  */
    break;

  case 118:
#line 675 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2823 "y.tab.c" /* yacc.c:1661  */
    break;

  case 119:
#line 677 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "&&"); }
#line 2829 "y.tab.c" /* yacc.c:1661  */
    break;

  case 120:
#line 681 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2835 "y.tab.c" /* yacc.c:1661  */
    break;

  case 121:
#line 683 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "&&"); }
#line 2841 "y.tab.c" /* yacc.c:1661  */
    break;

  case 122:
#line 687 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2847 "y.tab.c" /* yacc.c:1661  */
    break;

  case 123:
#line 689 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "|"); }
#line 2853 "y.tab.c" /* yacc.c:1661  */
    break;

  case 124:
#line 693 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2859 "y.tab.c" /* yacc.c:1661  */
    break;

  case 125:
#line 695 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "|"); }
#line 2865 "y.tab.c" /* yacc.c:1661  */
    break;

  case 126:
#line 699 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2871 "y.tab.c" /* yacc.c:1661  */
    break;

  case 127:
#line 701 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "|"); }
#line 2877 "y.tab.c" /* yacc.c:1661  */
    break;

  case 128:
#line 705 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2883 "y.tab.c" /* yacc.c:1661  */
    break;

  case 129:
#line 707 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "^"); }
#line 2889 "y.tab.c" /* yacc.c:1661  */
    break;

  case 130:
#line 711 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2895 "y.tab.c" /* yacc.c:1661  */
    break;

  case 131:
#line 713 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "^"); }
#line 2901 "y.tab.c" /* yacc.c:1661  */
    break;

  case 132:
#line 717 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2907 "y.tab.c" /* yacc.c:1661  */
    break;

  case 133:
#line 719 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "^"); }
#line 2913 "y.tab.c" /* yacc.c:1661  */
    break;

  case 134:
#line 723 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2919 "y.tab.c" /* yacc.c:1661  */
    break;

  case 135:
#line 725 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "&"); }
#line 2925 "y.tab.c" /* yacc.c:1661  */
    break;

  case 136:
#line 729 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2931 "y.tab.c" /* yacc.c:1661  */
    break;

  case 137:
#line 731 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "&"); }
#line 2937 "y.tab.c" /* yacc.c:1661  */
    break;

  case 138:
#line 735 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2943 "y.tab.c" /* yacc.c:1661  */
    break;

  case 139:
#line 737 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "&"); }
#line 2949 "y.tab.c" /* yacc.c:1661  */
    break;

  case 140:
#line 741 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2955 "y.tab.c" /* yacc.c:1661  */
    break;

  case 141:
#line 743 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "=="); }
#line 2961 "y.tab.c" /* yacc.c:1661  */
    break;

  case 142:
#line 745 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "!="); }
#line 2967 "y.tab.c" /* yacc.c:1661  */
    break;

  case 143:
#line 747 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "==="); }
#line 2973 "y.tab.c" /* yacc.c:1661  */
    break;

  case 144:
#line 749 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "!=="); }
#line 2979 "y.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 753 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2985 "y.tab.c" /* yacc.c:1661  */
    break;

  case 146:
#line 755 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "=="); }
#line 2991 "y.tab.c" /* yacc.c:1661  */
    break;

  case 147:
#line 757 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "!="); }
#line 2997 "y.tab.c" /* yacc.c:1661  */
    break;

  case 148:
#line 759 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "==="); }
#line 3003 "y.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 761 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "!=="); }
#line 3009 "y.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 765 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3015 "y.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 767 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "=="); }
#line 3021 "y.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 769 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "!="); }
#line 3027 "y.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 771 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "==="); }
#line 3033 "y.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 773 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "!=="); }
#line 3039 "y.tab.c" /* yacc.c:1661  */
    break;

  case 155:
#line 777 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3045 "y.tab.c" /* yacc.c:1661  */
    break;

  case 156:
#line 779 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "<"); }
#line 3051 "y.tab.c" /* yacc.c:1661  */
    break;

  case 157:
#line 781 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">"); }
#line 3057 "y.tab.c" /* yacc.c:1661  */
    break;

  case 158:
#line 783 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "<="); }
#line 3063 "y.tab.c" /* yacc.c:1661  */
    break;

  case 159:
#line 785 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">="); }
#line 3069 "y.tab.c" /* yacc.c:1661  */
    break;

  case 160:
#line 787 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "instanceof"); }
#line 3075 "y.tab.c" /* yacc.c:1661  */
    break;

  case 161:
#line 793 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3081 "y.tab.c" /* yacc.c:1661  */
    break;

  case 162:
#line 795 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "<"); }
#line 3087 "y.tab.c" /* yacc.c:1661  */
    break;

  case 163:
#line 797 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">"); }
#line 3093 "y.tab.c" /* yacc.c:1661  */
    break;

  case 164:
#line 799 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "<="); }
#line 3099 "y.tab.c" /* yacc.c:1661  */
    break;

  case 165:
#line 801 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">="); }
#line 3105 "y.tab.c" /* yacc.c:1661  */
    break;

  case 166:
#line 803 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "instanceof"); }
#line 3111 "y.tab.c" /* yacc.c:1661  */
    break;

  case 167:
#line 807 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3117 "y.tab.c" /* yacc.c:1661  */
    break;

  case 168:
#line 809 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "<"); }
#line 3123 "y.tab.c" /* yacc.c:1661  */
    break;

  case 169:
#line 811 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">"); }
#line 3129 "y.tab.c" /* yacc.c:1661  */
    break;

  case 170:
#line 813 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "<="); }
#line 3135 "y.tab.c" /* yacc.c:1661  */
    break;

  case 171:
#line 815 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">="); }
#line 3141 "y.tab.c" /* yacc.c:1661  */
    break;

  case 172:
#line 817 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "instanceof"); }
#line 3147 "y.tab.c" /* yacc.c:1661  */
    break;

  case 173:
#line 821 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3153 "y.tab.c" /* yacc.c:1661  */
    break;

  case 174:
#line 823 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "<<"); }
#line 3159 "y.tab.c" /* yacc.c:1661  */
    break;

  case 175:
#line 825 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">>"); }
#line 3165 "y.tab.c" /* yacc.c:1661  */
    break;

  case 176:
#line 827 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">>>"); }
#line 3171 "y.tab.c" /* yacc.c:1661  */
    break;

  case 177:
#line 831 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3177 "y.tab.c" /* yacc.c:1661  */
    break;

  case 178:
#line 833 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "<<"); }
#line 3183 "y.tab.c" /* yacc.c:1661  */
    break;

  case 179:
#line 835 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">>"); }
#line 3189 "y.tab.c" /* yacc.c:1661  */
    break;

  case 180:
#line 837 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), ">>>"); }
#line 3195 "y.tab.c" /* yacc.c:1661  */
    break;

  case 181:
#line 841 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3201 "y.tab.c" /* yacc.c:1661  */
    break;

  case 182:
#line 843 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "+"); }
#line 3207 "y.tab.c" /* yacc.c:1661  */
    break;

  case 183:
#line 845 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "-"); }
#line 3213 "y.tab.c" /* yacc.c:1661  */
    break;

  case 184:
#line 849 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3219 "y.tab.c" /* yacc.c:1661  */
    break;

  case 185:
#line 851 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "+"); }
#line 3225 "y.tab.c" /* yacc.c:1661  */
    break;

  case 186:
#line 853 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "-"); }
#line 3231 "y.tab.c" /* yacc.c:1661  */
    break;

  case 187:
#line 857 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3237 "y.tab.c" /* yacc.c:1661  */
    break;

  case 188:
#line 859 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "*"); }
#line 3243 "y.tab.c" /* yacc.c:1661  */
    break;

  case 189:
#line 861 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "/"); }
#line 3249 "y.tab.c" /* yacc.c:1661  */
    break;

  case 190:
#line 863 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "%"); }
#line 3255 "y.tab.c" /* yacc.c:1661  */
    break;

  case 191:
#line 867 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3261 "y.tab.c" /* yacc.c:1661  */
    break;

  case 192:
#line 869 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "*"); }
#line 3267 "y.tab.c" /* yacc.c:1661  */
    break;

  case 193:
#line 871 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "/"); }
#line 3273 "y.tab.c" /* yacc.c:1661  */
    break;

  case 194:
#line 873 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_EXP((yyvsp[-2].node), (yyvsp[0].node), "%"); }
#line 3279 "y.tab.c" /* yacc.c:1661  */
    break;

  case 195:
#line 877 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3285 "y.tab.c" /* yacc.c:1661  */
    break;

  case 196:
#line 883 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "typeof"); }
#line 3291 "y.tab.c" /* yacc.c:1661  */
    break;

  case 197:
#line 885 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "++"); }
#line 3297 "y.tab.c" /* yacc.c:1661  */
    break;

  case 198:
#line 887 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "--"); }
#line 3303 "y.tab.c" /* yacc.c:1661  */
    break;

  case 199:
#line 889 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "+"); }
#line 3309 "y.tab.c" /* yacc.c:1661  */
    break;

  case 200:
#line 891 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "-"); }
#line 3315 "y.tab.c" /* yacc.c:1661  */
    break;

  case 201:
#line 893 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "!"); }
#line 3321 "y.tab.c" /* yacc.c:1661  */
    break;

  case 202:
#line 895 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "~"); }
#line 3327 "y.tab.c" /* yacc.c:1661  */
    break;

  case 203:
#line 899 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3333 "y.tab.c" /* yacc.c:1661  */
    break;

  case 204:
#line 905 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "typeof"); }
#line 3339 "y.tab.c" /* yacc.c:1661  */
    break;

  case 205:
#line 907 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "++"); }
#line 3345 "y.tab.c" /* yacc.c:1661  */
    break;

  case 206:
#line 909 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "--"); }
#line 3351 "y.tab.c" /* yacc.c:1661  */
    break;

  case 207:
#line 911 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "+"); }
#line 3357 "y.tab.c" /* yacc.c:1661  */
    break;

  case 208:
#line 913 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "-"); }
#line 3363 "y.tab.c" /* yacc.c:1661  */
    break;

  case 209:
#line 915 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "!"); }
#line 3369 "y.tab.c" /* yacc.c:1661  */
    break;

  case 210:
#line 917 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPRE((yyvsp[0].node), "~"); }
#line 3375 "y.tab.c" /* yacc.c:1661  */
    break;

  case 211:
#line 921 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3381 "y.tab.c" /* yacc.c:1661  */
    break;

  case 212:
#line 923 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPOST((yyvsp[-1].node), "++"); }
#line 3387 "y.tab.c" /* yacc.c:1661  */
    break;

  case 213:
#line 925 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPOST((yyvsp[-1].node), "--"); }
#line 3393 "y.tab.c" /* yacc.c:1661  */
    break;

  case 214:
#line 929 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3399 "y.tab.c" /* yacc.c:1661  */
    break;

  case 215:
#line 931 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPOST((yyvsp[-1].node), "++"); }
#line 3405 "y.tab.c" /* yacc.c:1661  */
    break;

  case 216:
#line 933 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_UNPOST((yyvsp[-1].node), "--"); }
#line 3411 "y.tab.c" /* yacc.c:1661  */
    break;

  case 217:
#line 937 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3417 "y.tab.c" /* yacc.c:1661  */
    break;

  case 218:
#line 939 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), 0); }
#line 3423 "y.tab.c" /* yacc.c:1661  */
    break;

  case 219:
#line 943 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3429 "y.tab.c" /* yacc.c:1661  */
    break;

  case 220:
#line 945 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), 0); }
#line 3435 "y.tab.c" /* yacc.c:1661  */
    break;

  case 221:
#line 949 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3441 "y.tab.c" /* yacc.c:1661  */
    break;

  case 222:
#line 951 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), 0); }
#line 3447 "y.tab.c" /* yacc.c:1661  */
    break;

  case 223:
#line 955 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3453 "y.tab.c" /* yacc.c:1661  */
    break;

  case 224:
#line 957 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), "="); }
#line 3459 "y.tab.c" /* yacc.c:1661  */
    break;

  case 225:
#line 959 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].val)); }
#line 3465 "y.tab.c" /* yacc.c:1661  */
    break;

  case 226:
#line 963 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3471 "y.tab.c" /* yacc.c:1661  */
    break;

  case 227:
#line 965 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), "="); }
#line 3477 "y.tab.c" /* yacc.c:1661  */
    break;

  case 228:
#line 967 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].val)); }
#line 3483 "y.tab.c" /* yacc.c:1661  */
    break;

  case 229:
#line 971 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3489 "y.tab.c" /* yacc.c:1661  */
    break;

  case 230:
#line 973 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), "="); }
#line 3495 "y.tab.c" /* yacc.c:1661  */
    break;

  case 231:
#line 975 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ASGN((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].val)); }
#line 3501 "y.tab.c" /* yacc.c:1661  */
    break;

  case 232:
#line 979 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "+="; }
#line 3507 "y.tab.c" /* yacc.c:1661  */
    break;

  case 233:
#line 981 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "-="; }
#line 3513 "y.tab.c" /* yacc.c:1661  */
    break;

  case 234:
#line 983 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "*="; }
#line 3519 "y.tab.c" /* yacc.c:1661  */
    break;

  case 235:
#line 985 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "/="; }
#line 3525 "y.tab.c" /* yacc.c:1661  */
    break;

  case 236:
#line 987 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "%="; }
#line 3531 "y.tab.c" /* yacc.c:1661  */
    break;

  case 237:
#line 989 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "<<="; }
#line 3537 "y.tab.c" /* yacc.c:1661  */
    break;

  case 238:
#line 991 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = ">>="; }
#line 3543 "y.tab.c" /* yacc.c:1661  */
    break;

  case 239:
#line 993 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = ">>>="; }
#line 3549 "y.tab.c" /* yacc.c:1661  */
    break;

  case 240:
#line 995 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "&="; }
#line 3555 "y.tab.c" /* yacc.c:1661  */
    break;

  case 241:
#line 997 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "^="; }
#line 3561 "y.tab.c" /* yacc.c:1661  */
    break;

  case 242:
#line 999 "js_parser.y" /* yacc.c:1661  */
    { (yyval.val) = "|="; }
#line 3567 "y.tab.c" /* yacc.c:1661  */
    break;

  case 243:
#line 1003 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3573 "y.tab.c" /* yacc.c:1661  */
    break;

  case 244:
#line 1005 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3579 "y.tab.c" /* yacc.c:1661  */
    break;

  case 245:
#line 1009 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3585 "y.tab.c" /* yacc.c:1661  */
    break;

  case 246:
#line 1011 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3591 "y.tab.c" /* yacc.c:1661  */
    break;

  case 247:
#line 1015 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CALL((yyvsp[-1].node), (yyvsp[0].node)); }
#line 3597 "y.tab.c" /* yacc.c:1661  */
    break;

  case 248:
#line 1017 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CALL((yyvsp[-1].node), (yyvsp[0].node)); }
#line 3603 "y.tab.c" /* yacc.c:1661  */
    break;

  case 249:
#line 1019 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 3609 "y.tab.c" /* yacc.c:1661  */
    break;

  case 250:
#line 1021 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CALL((yyvsp[-2].node), (yyvsp[0].node)); }
#line 3615 "y.tab.c" /* yacc.c:1661  */
    break;

  case 251:
#line 1025 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CALL((yyvsp[-1].node), (yyvsp[0].node)); }
#line 3621 "y.tab.c" /* yacc.c:1661  */
    break;

  case 252:
#line 1027 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CALL((yyvsp[-1].node), (yyvsp[0].node)); }
#line 3627 "y.tab.c" /* yacc.c:1661  */
    break;

  case 253:
#line 1029 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 3633 "y.tab.c" /* yacc.c:1661  */
    break;

  case 254:
#line 1031 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_CALL((yyvsp[-2].node), (yyvsp[0].node)); }
#line 3639 "y.tab.c" /* yacc.c:1661  */
    break;

  case 255:
#line 1035 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3645 "y.tab.c" /* yacc.c:1661  */
    break;

  case 256:
#line 1037 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_NEW((yyvsp[0].node)); }
#line 3651 "y.tab.c" /* yacc.c:1661  */
    break;

  case 257:
#line 1041 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3657 "y.tab.c" /* yacc.c:1661  */
    break;

  case 258:
#line 1043 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_NEW((yyvsp[0].node)); }
#line 3663 "y.tab.c" /* yacc.c:1661  */
    break;

  case 259:
#line 1047 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3669 "y.tab.c" /* yacc.c:1661  */
    break;

  case 260:
#line 1049 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3675 "y.tab.c" /* yacc.c:1661  */
    break;

  case 261:
#line 1051 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_MEMBER((yyvsp[-1].node), (yyvsp[-3].node), 42); }
#line 3681 "y.tab.c" /* yacc.c:1661  */
    break;

  case 262:
#line 1053 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_MEMBER((yyvsp[0].node), (yyvsp[-2].node), false); }
#line 3687 "y.tab.c" /* yacc.c:1661  */
    break;

  case 263:
#line 1055 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_NEW(NEW_MEMBER((yyvsp[0].node), (yyvsp[-1].node), false)); }
#line 3693 "y.tab.c" /* yacc.c:1661  */
    break;

  case 264:
#line 1059 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[0].node); }
#line 3699 "y.tab.c" /* yacc.c:1661  */
    break;

  case 265:
#line 1061 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_MEMBER((yyvsp[-1].node), (yyvsp[-3].node), 42); }
#line 3705 "y.tab.c" /* yacc.c:1661  */
    break;

  case 266:
#line 1063 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_MEMBER((yyvsp[0].node), (yyvsp[-2].node), false); }
#line 3711 "y.tab.c" /* yacc.c:1661  */
    break;

  case 267:
#line 1065 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_NEW(NEW_MEMBER((yyvsp[0].node), (yyvsp[-1].node), false)); }
#line 3717 "y.tab.c" /* yacc.c:1661  */
    break;

  case 268:
#line 1069 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ARGLST(NULL, NULL); }
#line 3723 "y.tab.c" /* yacc.c:1661  */
    break;

  case 269:
#line 1071 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 3729 "y.tab.c" /* yacc.c:1661  */
    break;

  case 270:
#line 1075 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ARGLST((yyvsp[0].node), NULL); }
#line 3735 "y.tab.c" /* yacc.c:1661  */
    break;

  case 271:
#line 1077 "js_parser.y" /* yacc.c:1661  */
    { (yyval.node) = NEW_ARGLST((yyvsp[0].node), (yyvsp[-2].node)); }
#line 3741 "y.tab.c" /* yacc.c:1661  */
    break;


#line 3745 "y.tab.c" /* yacc.c:1661  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1080 "js_parser.y" /* yacc.c:1906  */


void
yyerror(const char *s)
{
  eval_state *state = js_new_state(yylloc.first_line, yylloc.first_column);
  js_push_state(state);
  // Show the offending line.
  if (yyin) {
    char buf[1000];
    int i = 1;
    rewind(yyin);
    while (fgets(buf, sizeof buf, yyin) != NULL) {
      if (yylloc.first_line == i++) {
        cfprintf(stderr, ANSI_RED, "%s", buf);
        cfprintf(stderr, ANSI_GRAY, "%*s\n", yylloc.first_column + 1, "^");
      }
    }
  }
  // Trim the "syntax error: " prefix so we can use `js_throw`.
  js_throw(state, js_new_error(E_SYNTAX, strlen(s) >= 14 ? s + 14 : s));
}

// This is our replacement function when we redefine YY_INPUT
int
js_get_input(char *buf, int size)
{
  // For the REPL:
  if (js->opt_interactive) {
#ifdef JS_NO_REPL
    fprintf(stderr, "Error: REPL not available. Build with readline.");
    exit(1);
#else
    if (js->opt_keep_history_file) {
      read_history(js->opt_history_filename);
    }

    char *line;
    line = readline("> ");
    if (!line)
      return 0;
    if ((int)strlen(line) > size - 3) {
      js_throw(NULL, js_new_error(E_ERROR, "input line too long"));
      return 0;
    }
    strcpy(buf, line);

    add_history(buf);

    // Use the file
    if (js->opt_keep_history_file) {
      write_history(js->opt_history_filename);
      history_truncate_file(js->opt_history_filename, 1000);
      clear_history();
    }

    // Poor man's ASI:
    if (!strchr(buf, ';')) strcat(buf, ";");

    strcat(buf, "\n");
    free(line);
#endif
  }
  // For file or stdin:
  else {
    if (!yyin)
      js_throw(NULL, js_new_error(E_ERROR, "invalid input file"));
    int result = fread(buf, sizeof(char), size, yyin);
    if (result == 0 && ferror(yyin))
      js_throw(NULL, js_new_error(E_ERROR, "error while reading input file"));
    return result;
  }
  return strlen(buf);
}

js_val *
js_eval_file(FILE *file, js_val *ctx)
{
  yyrestart(file);
  yyparse();

  if (js->opt_print_ast)
    node_print(root, true, 0);

  return js_eval(ctx, root);
}

js_val *
js_eval_string(char *string, js_val *ctx)
{
  // Save the current interactive setting and set it to false.
  bool tmp = js->opt_interactive;
  js->opt_interactive = false;

  eval_state *prior_state = js_new_state(yylloc.first_line, yylloc.last_line);
  yycolumn = 0;
  yylineno = 1;

  YY_BUFFER_STATE buffer = yy_scan_string(string);
  yyparse();

  if (js->opt_print_ast)
    node_print(root, true, 0);

  js_val *res = js_eval(ctx, root);
  yy_delete_buffer(buffer);
  js->opt_interactive = tmp;
  yylineno = prior_state->line;
  yycolumn = prior_state->column;
  return res;
}

int
main(int argc, char **argv)
{
  // Create the global state object
  js = js_new_global_state();

  int c = 0, fakeind = 0, optind = 1;
  static struct option long_options[] = {
    {"version", no_argument, NULL, 'v'},
    {"help", no_argument, NULL, 'h'},
    {"interactive", no_argument, NULL, 'i'},
    {"nodes", no_argument, NULL, 'n'},
    {"tokens", no_argument, NULL, 't'},
    {NULL, 0, NULL, 0}
  };

  while ((c = getopt_long(argc, argv, "vhint", long_options, &fakeind)) != -1) {
    switch (c) {
      case 0: break;
      // case 'v': js_print_version(); return 0;
      case 'h': js_print_help(); return 0;
      case 'i': js->opt_interactive = true; break;
      case 'n': js->opt_print_ast = true; break;
      case 't': js->opt_print_tokens = true; break;
      default: break;
    }
    optind++;
  }

  static FILE *source = NULL;
  if (optind < argc) {
    source = fopen(argv[optind], "r");
    js->script_name = argv[optind];
  }
  else if (!isatty(fileno(stdin)) && !js->opt_interactive) {
    source = stdin;
  }
  else {
    js->opt_interactive = true;
    js->script_name = "(repl)";
  }

  // Bootstrap our runtime
  js->global = js_bootstrap();

  // We can operate as a REPL or in file/stdin mode.
  if (js->opt_interactive) {
    js_print_startup();
    while (true) {
      // Normally errors cause the program to exit, but we'd like the REPL to
      // continue. Use setjmp here and longjmp in `js_throw` to simulate
      // exception handling.
      if (!setjmp(js->repl_jmp))
        DEBUG(js_eval_file(source, js->global));
    }
  }
  else
    js_eval_file(source, js->global);

  return 0;
}
