/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 48 "js_parser.y" /* yacc.c:1915  */

  int ival;
  float fval;
  char *sval;
  char *id;
  void *nval;
  struct Node *node;

#line 135 "js_parser.tab.h" /* yacc.c:1915  */
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
