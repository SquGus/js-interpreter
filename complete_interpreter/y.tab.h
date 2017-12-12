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
#line 126 "js_parser.y" /* yacc.c:1915  */

    char *val;
    int intval;
    double floatval;
    struct ast_node *node;

#line 151 "y.tab.h" /* yacc.c:1915  */
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
