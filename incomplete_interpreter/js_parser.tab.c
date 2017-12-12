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
#line 8 "js_parser.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
  #include "js_types.h"
  #include "js_symbol_table.h"
	#include "js_tree.h"
	#define YYDEBUG 1

  int yylex(void);
  void yyerror(const char *s);
	
	int errors;

	// /* Install identifier in table */
	// void install(char *sym_name) {
	// 	Symbol *s;
	// 	s = get_symbol(sym_name);
	// 	if (s == 0) {
	// 		s = put_symbol(sym_name);
	// 	} else {
	// 		errors++;
	// 		printf("%s is already defined\n", sym_name);
	// 	}
	// }

	//  If identifier is defined, generate code 
	// void context_check(char *sym_name) {
	// 	Symbol *identifier;
	// 	identifier = get_symbol(sym_name);
	// 	if (identifier == 0) {
	// 		errors++;
	// 		printf("%s is an undeclared identifier\n", sym_name);
	// 	} else {
	// 		//gen_code(operation, identifier->offset);
	// 	}
	// }

#line 105 "js_parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "js_parser.tab.h".  */
#ifndef YY_YY_JS_PARSER_TAB_H_INCLUDED
# define YY_YY_JS_PARSER_TAB_H_INCLUDED
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
    END = 0,
    ID = 258,
    NULL_V = 259,
    TRUE_V = 260,
    FALSE_V = 261,
    FLT_V = 262,
    INT_V = 263,
    STRING_V = 264,
    CLOSE_C = 265,
    OPEN_C = 266,
    CLOSE_B = 267,
    OPEN_B = 268,
    CLOSE_P = 269,
    OPEN_P = 270,
    TERNARY_OP = 271,
    LOGIC_OR_OP = 272,
    SHORT_BIT_OR_OP = 273,
    BIT_OR_OP = 274,
    SHORT_BIT_XOR_OP = 275,
    BIT_XOR_OP = 276,
    SHORT_BIT_SHIFT_Z_R_OP = 277,
    BIT_SHIFT_Z_R_OP = 278,
    SHORT_BIT_SHIFT_S_R_OP = 279,
    BIT_SHIFT_S_R_OP = 280,
    GE_OP = 281,
    G_OP = 282,
    EQ_VT_OP = 283,
    EQ_V_OP = 284,
    VA_OP = 285,
    LE_OP = 286,
    SHORT_BIT_SHIFT_L_OP = 287,
    BIT_SHIFT_L_OP = 288,
    L_OP = 289,
    STMT_TER_OP = 290,
    PA_OP = 291,
    SHORT_DIV_OP = 292,
    DIV_OP = 293,
    MEM_ACC_OP = 294,
    SHORT_SUB_OP = 295,
    UNIT_SUB_OP = 296,
    SUB_OP = 297,
    SEP_OP = 298,
    SHORT_ADD_OP = 299,
    UNIT_ADD_OP = 300,
    ADD_OP = 301,
    SHORT_MUL_OP = 302,
    MUL_OP = 303,
    SHORT_BIT_AND_OP = 304,
    LOGIC_AND_OP = 305,
    BIT_AND_OP = 306,
    SHORT_MOD_OP = 307,
    MOD_OP = 308,
    NEG_VT_OP = 309,
    NEG_V_OP = 310,
    LOGIC_NOT_OP = 311,
    BREAK = 312,
    CASE = 313,
    CONTINUE = 314,
    DEFAULT = 315,
    DO = 316,
    ELSE = 317,
    FOR = 318,
    FUNCTION = 319,
    IF = 320,
    INSTANCEOF = 321,
    NEW = 322,
    RETURN = 323,
    VAR = 324,
    WHILE = 325
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "js_parser.y" /* yacc.c:355  */

  int ival;
  float fval;
  char *sval;
  char *id;
  void *nval;
  struct Node *node;

#line 226 "js_parser.tab.c" /* yacc.c:355  */
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

#endif /* !YY_YY_JS_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "js_parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  104
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   599

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  242

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   184,   184,   188,   189,   193,   194,   199,   200,   201,
     203,   204,   205,   206,   207,   208,   212,   213,   223,   229,
     235,   236,   275,   279,   283,   287,   288,   289,   293,   297,
     301,   302,   306,   310,   321,   322,   326,   330,   335,   336,
     340,   344,   348,   352,   353,   357,   358,   362,   371,   372,
     376,   377,   381,   384,   387,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   407,   413,   423,   424,
     433,   434,   438,   441,   444,   447,   450,   452,   454,   460,
     464,   468,   469,   470,   474,   475,   479,   480,   481,   485,
     489,   490,   494,   495,   499,   503,   509,   518,   527,   536,
     545,   554,   563,   566,   569,   584,   588,   594,   595,   599,
     600,   604,   608,   609,   613,   614,   618,   622,   623,   627,
     628,   632,   633,   637,   638,   642,   643,   647,   648,   649,
     650,   651,   655,   656,   657,   658,   659,   660,   664,   665,
     666,   667,   671,   672,   673,   677,   680,   681,   682,   686,
     689,   702,   715,   733,   751
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "ID", "NULL_V", "TRUE_V",
  "FALSE_V", "FLT_V", "INT_V", "STRING_V", "CLOSE_C", "OPEN_C", "CLOSE_B",
  "OPEN_B", "CLOSE_P", "OPEN_P", "TERNARY_OP", "LOGIC_OR_OP",
  "SHORT_BIT_OR_OP", "BIT_OR_OP", "SHORT_BIT_XOR_OP", "BIT_XOR_OP",
  "SHORT_BIT_SHIFT_Z_R_OP", "BIT_SHIFT_Z_R_OP", "SHORT_BIT_SHIFT_S_R_OP",
  "BIT_SHIFT_S_R_OP", "GE_OP", "G_OP", "EQ_VT_OP", "EQ_V_OP", "VA_OP",
  "LE_OP", "SHORT_BIT_SHIFT_L_OP", "BIT_SHIFT_L_OP", "L_OP", "STMT_TER_OP",
  "PA_OP", "SHORT_DIV_OP", "DIV_OP", "MEM_ACC_OP", "SHORT_SUB_OP",
  "UNIT_SUB_OP", "SUB_OP", "SEP_OP", "SHORT_ADD_OP", "UNIT_ADD_OP",
  "ADD_OP", "SHORT_MUL_OP", "MUL_OP", "SHORT_BIT_AND_OP", "LOGIC_AND_OP",
  "BIT_AND_OP", "SHORT_MOD_OP", "MOD_OP", "NEG_VT_OP", "NEG_V_OP",
  "LOGIC_NOT_OP", "BREAK", "CASE", "CONTINUE", "DEFAULT", "DO", "ELSE",
  "FOR", "FUNCTION", "IF", "INSTANCEOF", "NEW", "RETURN", "VAR", "WHILE",
  "\"then\"", "$accept", "Program", "Statements", "Statement",
  "CodeStatement", "Definition", "ExpressionStatement", "Block",
  "IfStatement", "DoStatement", "WhileStatement", "ForStatement",
  "ForInitializer", "ContinueStatement", "BreakStatement", "OptionalLabel",
  "ReturnStatement", "VariableDefinition", "VariableBindingList",
  "VariableBinding", "TypedIdentifier", "VariableInitializer",
  "FunctionDefinition", "FunctionSignature", "ParameterSignature",
  "Parameters", "RequiredParameters", "RequiredParameter", "Expression",
  "OptionalExpression", "AssignmentExpression", "CompoundAssignment",
  "ParenthesizedExpression", "Identifier", "ConditionalExpression",
  "PostfixExpression", "FullPostfixExpression", "FullNewExpression",
  "ShortNewExpression", "FullNewSubexpression", "ShortNewSubexpression",
  "MemberOperator", "Arguments", "ArgumentList", "ArgumentListPrefix",
  "PrimaryExpression", "SimpleExpression", "NamedFunction",
  "QualifiedIdentifier", "ObjectLiteral", "FieldList", "LiteralField",
  "ArrayLiteral", "ElementList", "LiteralElement", "LogicalOrExpression",
  "LogicalAndExpression", "BitwiseOrExpression", "BitwiseXorExpression",
  "BitwiseAndExpression", "EqualityExpression", "RelationalExpression",
  "ShiftExpression", "AdditiveExpression", "MultiplicativeExpression",
  "UnaryExpression", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

#define YYPACT_NINF -203

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-203)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     325,  -203,  -203,  -203,  -203,  -203,  -203,  -203,   189,   477,
     532,   532,   532,   532,   532,   532,    38,    38,   393,    44,
      38,    55,   134,   532,    38,    55,    94,    21,  -203,  -203,
    -203,    60,  -203,  -203,    62,  -203,  -203,    64,    71,    74,
      85,  -203,    81,  -203,  -203,  -203,  -203,   535,    18,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,     6,    76,   106,
     107,    78,    10,    27,    75,    14,     2,  -203,  -203,   257,
      95,     1,  -203,    73,  -203,  -203,    25,  -203,     0,    51,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,    63,   461,
     117,   393,  -203,  -203,    18,  -203,  -203,    81,  -203,    91,
    -203,   105,  -203,   393,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,   532,  -203,  -203,  -203,  -203,   532,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,   532,
     532,   532,    66,  -203,  -203,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,  -203,   532,
    -203,    38,    95,  -203,   532,  -203,    55,    38,   101,    81,
      38,   133,  -203,    84,  -203,  -203,    38,   532,  -203,  -203,
    -203,  -203,  -203,  -203,   138,   109,   139,  -203,  -203,   118,
      76,   106,   107,    78,    10,    27,    27,    27,    27,    75,
      75,    75,    75,    75,    14,    14,    14,     2,     2,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,   532,  -203,   143,
     120,  -203,   325,  -203,   393,  -203,  -203,  -203,   532,  -203,
     532,   130,  -203,    38,  -203,  -203,  -203,   532,  -203,   152,
     393,  -203
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    67,    96,    97,    98,   100,    99,   101,     0,     0,
       0,     0,     0,     0,     0,     0,    30,    30,     0,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     4,     5,
       6,     0,     8,     9,     0,    11,    12,     0,     0,     0,
       0,    17,    18,    48,   103,   106,    52,   149,    70,    73,
      71,    72,    94,    40,   102,    95,   104,    68,   117,   119,
     121,   123,   125,   127,   132,   138,   142,   145,   107,     0,
     102,     0,   109,     0,   112,   116,     0,   114,     0,   149,
     151,   153,   150,   152,   154,    29,    31,    28,     0,    25,
       0,     0,    83,    85,    84,    80,    81,    50,    32,    33,
      34,    38,    37,     0,     1,     2,     3,     7,    10,    13,
      14,    15,    16,     0,    65,    64,    62,    61,     0,    60,
      56,    59,    77,    58,    76,    55,    63,    57,    78,     0,
      90,    90,     0,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
     108,     0,     0,   113,     0,    66,     0,     0,     0,    26,
      43,     0,    41,    20,    82,    79,     0,     0,    36,    23,
      49,    53,    54,    92,     0,    91,     0,    88,    87,     0,
     118,   120,   122,   124,   126,   130,   128,   131,   129,   136,
     134,   135,   133,   137,   141,   140,   139,   144,   143,   147,
     146,   148,   111,   110,   115,    22,    27,    51,    47,     0,
      44,    45,     0,   105,     0,    35,    39,    86,     0,    89,
       0,     0,    42,     0,    21,    93,    69,    51,    46,     0,
       0,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,   167,   -17,   -16,  -203,  -203,    -3,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,   186,  -203,  -203,  -203,  -125,
    -161,  -203,  -203,  -203,  -203,  -203,  -203,   -28,   -10,  -202,
      -8,  -203,   -18,   -12,  -203,    34,  -203,   184,   187,  -203,
    -203,   116,   119,    80,  -203,   190,  -203,  -203,    -2,  -203,
    -203,    53,  -203,  -203,    52,  -203,    79,    82,    87,    89,
      77,   -40,   -30,   -39,   -80,     5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    69,    28,    29,    30,    31,    32,    33,    34,
      35,    36,   168,    37,    38,    85,    39,    40,    99,   100,
     101,   178,    41,   171,   172,   219,   220,   221,    42,    98,
      43,   129,    44,    45,    46,    47,    48,    49,    50,    94,
      95,   133,   134,   184,   185,    51,    52,    53,    54,    55,
      71,    72,    56,    76,    77,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,    75,    88,    91,    86,    86,    70,   103,    90,   218,
     106,   160,   102,    97,   165,   231,    80,    81,    82,    83,
      84,   105,   135,   136,     1,     2,     3,     4,     5,     6,
       7,   130,     8,   131,     9,   239,    10,   163,   141,   142,
     155,     1,   216,   113,   161,    79,    79,    79,    79,    79,
     156,   225,   106,   145,   146,   157,   153,   132,   147,    89,
     154,   148,    11,    12,   143,   144,    13,    14,   164,     1,
      10,   162,   218,   207,   208,   173,     1,    15,    16,   169,
      17,    10,    18,    68,    19,    20,    21,   179,    22,    23,
      24,    25,   122,   149,   104,   107,   124,   108,   150,   109,
     151,   195,   196,   197,   198,   180,   110,   128,   152,   111,
     181,   204,   205,   206,   187,   199,   200,   201,   202,   203,
     112,   182,   183,   183,   113,   138,   137,   189,   139,   140,
     188,   159,   170,   166,   176,   177,   217,     1,     2,     3,
       4,     5,     6,     7,   222,    73,   224,     9,   215,    10,
     227,   212,   228,   229,   230,   102,    75,   232,   102,   162,
     209,   210,   211,   233,   102,   237,   240,    27,   223,   226,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,     1,     2,     3,     4,     5,     6,     7,    68,
       8,    22,     9,    87,    10,   238,    92,    97,   234,    93,
     174,   186,    96,   175,   213,   190,   214,   194,     0,   191,
     235,   102,   236,     0,   241,   192,     0,    97,   193,     0,
      11,    12,     0,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,     0,    17,     0,
      18,     0,    19,    20,    21,     0,    22,    23,    24,    25,
       1,     2,     3,     4,     5,     6,     7,   158,     8,     0,
       9,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    12,
       0,     0,    13,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,     0,    17,     0,    18,     0,
      19,    20,    21,     0,    22,    23,    24,    25,     1,     2,
       3,     4,     5,     6,     7,     0,     8,     0,     9,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    12,     0,     0,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,    17,     0,    18,     0,    19,    20,
      21,     0,    22,    23,    24,    25,     1,     2,     3,     4,
       5,     6,     7,     0,     8,     0,     9,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,     0,     0,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,     0,    17,     0,    18,     0,    19,     0,    21,     0,
      22,    23,     0,    25,     1,     2,     3,     4,     5,     6,
       7,     0,    73,     0,     9,     0,    10,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     0,    73,    74,
       9,     0,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,     0,     0,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,    11,    12,
       0,     0,    13,    14,     0,     0,     0,     0,    22,     0,
     167,     0,     0,    15,     0,     1,     2,     3,     4,     5,
       6,     7,     0,    73,    22,     9,     0,    10,     0,     0,
       0,     0,     0,   114,     0,   115,     0,   116,     0,   117,
       0,     0,     0,     0,     0,   118,     0,   119,     0,     0,
       0,     0,   120,    11,    12,   121,   122,    13,    14,   123,
     124,     0,   125,     0,   126,     0,     0,   127,    15,     0,
       0,   128,     0,     0,     0,     0,     0,     0,     0,    22
};

static const yytype_int16 yycheck[] =
{
      10,     9,    18,    21,    16,    17,     8,    25,    20,   170,
      27,    10,    24,    23,    14,   217,    11,    12,    13,    14,
      15,     0,    16,    17,     3,     4,     5,     6,     7,     8,
       9,    13,    11,    15,    13,   237,    15,    12,    28,    29,
      38,     3,   167,    43,    43,    11,    12,    13,    14,    15,
      48,   176,    69,    26,    27,    53,    42,    39,    31,    15,
      46,    34,    41,    42,    54,    55,    45,    46,    43,     3,
      15,    73,   233,   153,   154,    91,     3,    56,    57,    89,
      59,    15,    61,    10,    63,    64,    65,   103,    67,    68,
      69,    70,    41,    66,     0,    35,    45,    35,    23,    35,
      25,   141,   142,   143,   144,   113,    35,    56,    33,    35,
     118,   150,   151,   152,   132,   145,   146,   147,   148,   149,
      35,   129,   130,   131,    43,    19,    50,   135,    21,    51,
     132,    36,    15,    70,    43,    30,    35,     3,     4,     5,
       6,     7,     8,     9,    11,    11,    62,    13,   166,    15,
      12,   159,    43,    14,    36,   167,   164,    14,   170,   161,
     155,   156,   157,    43,   176,    35,    14,     0,   171,   177,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    67,    13,    17,    15,   233,    22,   217,   224,    22,
      94,   131,    22,    94,   161,   136,   164,   140,    -1,   137,
     228,   233,   230,    -1,   240,   138,    -1,   237,   139,    -1,
      41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    59,    -1,
      61,    -1,    63,    64,    65,    -1,    67,    68,    69,    70,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    57,    -1,    59,    -1,    61,    -1,
      63,    64,    65,    -1,    67,    68,    69,    70,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    -1,    13,    -1,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    57,    -1,    59,    -1,    61,    -1,    63,    64,
      65,    -1,    67,    68,    69,    70,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    -1,    13,    -1,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      57,    -1,    59,    -1,    61,    -1,    63,    -1,    65,    -1,
      67,    68,    -1,    70,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    41,    42,
      -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    67,    -1,
      69,    -1,    -1,    56,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    67,    13,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    20,    -1,    22,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,    -1,
      -1,    -1,    37,    41,    42,    40,    41,    45,    46,    44,
      45,    -1,    47,    -1,    49,    -1,    -1,    52,    56,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    11,    13,
      15,    41,    42,    45,    46,    56,    57,    59,    61,    63,
      64,    65,    67,    68,    69,    70,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    85,    86,    88,
      89,    94,   100,   102,   104,   105,   106,   107,   108,   109,
     110,   117,   118,   119,   120,   121,   124,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,    10,    74,
     120,   122,   123,    11,    12,   102,   125,   126,   100,   107,
     137,   137,   137,   137,   137,    87,   105,    87,    76,    15,
     105,   104,   109,   110,   111,   112,   117,   100,   101,    90,
      91,    92,   105,   104,     0,     0,    75,    35,    35,    35,
      35,    35,    35,    43,    18,    20,    22,    24,    30,    32,
      37,    40,    41,    44,    45,    47,    49,    52,    56,   103,
      13,    15,    39,   113,   114,    16,    17,    50,    19,    21,
      51,    28,    29,    54,    55,    26,    27,    31,    34,    66,
      23,    25,    33,    42,    46,    38,    48,    53,    10,    36,
      10,    43,   120,    12,    43,    14,    70,    69,    84,   100,
      15,    95,    96,    76,   113,   114,    43,    30,    93,    76,
     102,   102,   102,   102,   115,   116,   115,   104,   120,   102,
     128,   129,   130,   131,   132,   133,   133,   133,   133,   134,
     134,   134,   134,   134,   135,   135,   135,   136,   136,   137,
     137,   137,   102,   123,   126,   104,    91,    35,    92,    97,
      98,    99,    11,    79,    62,    91,   102,    12,    43,    14,
      36,   101,    14,    43,    76,   102,   102,    35,    99,   101,
      14,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    78,    79,
      80,    80,    81,    82,    83,    84,    84,    84,    85,    86,
      87,    87,    88,    89,    90,    90,    91,    92,    93,    93,
      94,    95,    96,    97,    97,    98,    98,    99,   100,   100,
     101,   101,   102,   102,   102,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   104,   105,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   109,
     110,   111,   111,   111,   112,   112,   113,   113,   113,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   119,   120,   121,   121,   122,
     122,   123,   124,   124,   125,   125,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   132,
     132,   132,   133,   133,   133,   133,   133,   133,   134,   134,
     134,   134,   135,   135,   135,   136,   136,   136,   136,   137,
     137,   137,   137,   137,   137
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     2,     1,     1,
       2,     1,     1,     2,     2,     2,     2,     1,     1,     3,
       3,     5,     4,     3,     9,     0,     1,     2,     2,     2,
       0,     1,     2,     2,     1,     3,     2,     1,     0,     2,
       1,     1,     3,     0,     1,     1,     3,     1,     1,     3,
       1,     0,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     5,
       1,     1,     1,     1,     2,     2,     2,     2,     2,     3,
       2,     1,     2,     1,     1,     1,     3,     2,     2,     3,
       0,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     2,     3,     1,
       3,     3,     2,     3,     1,     3,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     2
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
        case 18:
#line 223 "js_parser.y" /* yacc.c:1661  */
    {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1711 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 229 "js_parser.y" /* yacc.c:1661  */
    {
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1719 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 236 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1727 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 52:
#line 381 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1735 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 53:
#line 384 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1743 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 54:
#line 387 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1751 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 66:
#line 407 "js_parser.y" /* yacc.c:1661  */
    {
    (yyval.node) = (yyvsp[-1].node);
  }
#line 1759 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 67:
#line 413 "js_parser.y" /* yacc.c:1661  */
    {
    strcpy((yyval.id), (yyvsp[0].id));
  }
#line 1767 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 72:
#line 438 "js_parser.y" /* yacc.c:1661  */
    {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1775 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 73:
#line 441 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1783 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 74:
#line 444 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1791 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 75:
#line 447 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1799 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 76:
#line 450 "js_parser.y" /* yacc.c:1661  */
    {
  }
#line 1806 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 77:
#line 452 "js_parser.y" /* yacc.c:1661  */
    {
  }
#line 1813 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 78:
#line 454 "js_parser.y" /* yacc.c:1661  */
    {
  }
#line 1820 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 94:
#line 499 "js_parser.y" /* yacc.c:1661  */
    {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1828 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 95:
#line 503 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1836 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 96:
#line 509 "js_parser.y" /* yacc.c:1661  */
    {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->nval = (void *)0;
    l->literal_type = VOID_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    (yyval.node) = node;
  }
#line 1850 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 97:
#line 518 "js_parser.y" /* yacc.c:1661  */
    {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->ival = (yyvsp[0].ival);
    l->literal_type = INTEGER_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    (yyval.node) = node;
  }
#line 1864 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 98:
#line 527 "js_parser.y" /* yacc.c:1661  */
    {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->ival = (yyvsp[0].ival);
    l->literal_type = INTEGER_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    (yyval.node) = node;
  }
#line 1878 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 99:
#line 536 "js_parser.y" /* yacc.c:1661  */
    {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->ival = (yyvsp[0].ival);
    l->literal_type = INTEGER_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    (yyval.node) = node;
  }
#line 1892 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 100:
#line 545 "js_parser.y" /* yacc.c:1661  */
    {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->fval = (yyvsp[0].fval);
    l->literal_type = FLOAT_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    (yyval.node) = node;
  }
#line 1906 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 101:
#line 554 "js_parser.y" /* yacc.c:1661  */
    {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    strcpy(l->sval, (yyvsp[0].sval));
    l->literal_type = STRING_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    (yyval.node) = node;
  }
#line 1920 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 102:
#line 563 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1928 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 103:
#line 566 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1936 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 104:
#line 569 "js_parser.y" /* yacc.c:1661  */
    {

  }
#line 1944 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 106:
#line 588 "js_parser.y" /* yacc.c:1661  */
    {
    strcpy((yyval.id), (yyvsp[0].id));
  }
#line 1952 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 145:
#line 677 "js_parser.y" /* yacc.c:1661  */
    {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1960 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 149:
#line 686 "js_parser.y" /* yacc.c:1661  */
    {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1968 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 150:
#line 689 "js_parser.y" /* yacc.c:1661  */
    {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = INCREMENT_T;
    if ((yyvsp[0].node)->type != INTEGER_T) {
      // TO-DO
      yyerror("An INT type is expected, must cast.");
      exit(0);
    }
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    node->type = INTEGER_T;
    (yyval.node) = node;
  }
#line 1986 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 151:
#line 702 "js_parser.y" /* yacc.c:1661  */
    {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = DECREMENT_T;
    if ((yyvsp[0].node)->type != INTEGER_T) {
      // TO-DO
      yyerror("An INT type is expected, must cast.");
      exit(0);
    }
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    node->type = INTEGER_T;
    (yyval.node) = node;
  }
#line 2004 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 152:
#line 715 "js_parser.y" /* yacc.c:1661  */
    {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = ADDITION_UNARY_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    if ((yyvsp[0].node)->type == INTEGER_T) {
      node->type = INTEGER_T;
    } else if ((yyvsp[0].node)->type == FLOAT_T) {
      node->type = FLOAT_T;
    } else if ((yyvsp[0].node)->type == STRING_T) {
      node->type = STRING_T;
    } else {
      // TO-DO
      yyerror("Cannot cast type");
      exit(0);
    }
    (yyval.node) = node;
  }
#line 2027 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 153:
#line 733 "js_parser.y" /* yacc.c:1661  */
    {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = SUBTRACTION_UNARY_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    if ((yyvsp[0].node)->type == INTEGER_T) {
      node->type = INTEGER_T;
    } else if ((yyvsp[0].node)->type == FLOAT_T) {
      node->type = FLOAT_T;
    } else {
      // TO-DO
      yyerror("NaN");
      exit(0);
    }
    (yyval.node) = node;
  }
#line 2048 "js_parser.tab.c" /* yacc.c:1661  */
    break;

  case 154:
#line 751 "js_parser.y" /* yacc.c:1661  */
    {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = LOGIC_NOT_T;
    if ((yyvsp[0].node)->type != INTEGER_T) {
      yyerror("An INT type is expected, must cast.");
      exit(0);
    }
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    node->type = INTEGER_T;
    (yyval.node) = node;
  }
#line 2065 "js_parser.tab.c" /* yacc.c:1661  */
    break;


#line 2069 "js_parser.tab.c" /* yacc.c:1661  */
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
#line 764 "js_parser.y" /* yacc.c:1906  */


// Main
int main(int argc, char *argv[]) {
	extern FILE *yyin;
	++argv; --argc;
	yyin = fopen( argv[0], "r");
	errors = 0;
	yyparse();
	printf("Parse completed\n");
	if (errors == 0) {
		printf("Must generate code\n");
	}
}

void yyerror(const char *s) {
	errors++;
	printf("%s\n", s);
}
