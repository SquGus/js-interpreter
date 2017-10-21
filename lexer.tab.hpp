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

#ifndef YY_YY_LEXER_TAB_HPP_INCLUDED
# define YY_YY_LEXER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    L_COMMENT = 1,
    B_COMMENT = 2,
    BIT_NOT = 3,
    CLOSE_C = 4,
    OPEN_C = 5,
    CLOSE_B = 6,
    OPEN_B = 7,
    CLOSE_P = 8,
    OPEN_P = 9,
    TERNARY_OP = 10,
    LOGIC_OR_OP = 11,
    SHORT_BIT_OR_OP = 12,
    BIT_OR_OP = 13,
    SHORT_BIT_XOR_OP = 14,
    BIT_XOR_OP = 15,
    SHORT_BIT_SHIFT_Z_R_OP = 16,
    BIT_SHIFT_Z_R_OP = 17,
    SHORT_BIT_SHIFT_S_R_OP = 18,
    BIT_SHIFT_S_R_OP = 19,
    GE_OP = 20,
    G_OP = 21,
    EQ_VT_OP = 22,
    EQ_V_OP = 23,
    VA_OP = 24,
    LE_OP = 25,
    SHORT_BIT_SHIFT_L_OP = 26,
    BIT_SHIFT_L_OP = 27,
    L_OP = 28,
    STMT_TER_OP = 29,
    PA_OP = 30,
    SHORT_DIV_OP = 31,
    DIV_OP = 32,
    MEM_ACC_OP = 33,
    SHORT_SUB_OP = 34,
    UNIT_SUB_OP = 35,
    SUB_OP = 36,
    SEP_OP = 37,
    SHORT_ADD_OP = 38,
    UNIT_ADD_OP = 39,
    ADD_OP = 40,
    SHORT_MUL_OP = 41,
    MUL_OP = 42,
    SHORT_BIT_AND_OP = 43,
    LOGIC_AND_OP = 44,
    BIT_AND_OP = 45,
    SHORT_MOD_OP = 46,
    MOD_OP = 47,
    NEG_VT_OP = 48,
    NEG_V_OP = 49,
    LOGIC_NOT_OP = 50,
    BREAK = 51,
    CASE = 52,
    CATCH = 53,
    CLASS = 54,
    CONS = 55,
    CONTINUE = 56,
    DEBUGGER = 57,
    DEFAULT = 58,
    DELETE = 59,
    DO = 60,
    ELSE = 61,
    ENUM = 62,
    EXPORT = 63,
    EXTENDS = 64,
    FINALLY = 65,
    FOR = 66,
    FUNCTION = 67,
    IF = 68,
    IMPLEMENTS = 69,
    IMPORT = 70,
    IN = 71,
    INSTANCEOF = 72,
    INTERFACE = 73,
    LET = 74,
    NEW = 75,
    PACKAGE = 76,
    PRIVATE = 77,
    PROTECTED = 78,
    PUBLIC = 79,
    RETURN = 80,
    STATIC = 81,
    SUPER = 82,
    SWITCH = 83,
    THIS = 84,
    THROW = 85,
    TRY = 86,
    TYPEOF = 87,
    VAR = 88,
    VOID = 89,
    WHILE = 90,
    WITH = 91,
    YIELD = 92,
    NULL_V = 93,
    UNDEFINED_V = 94,
    TRUE_V = 95,
    FALSE_V = 96,
    HEX_T = 97,
    OCT_T = 98,
    BIN_T = 99,
    FLT_T = 100,
    INT_T = 101,
    HEX_SEQ = 102,
    UNI_SEQ = 103,
    STRING = 104,
    ID = 105
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "lexer.ypp" /* yacc.c:1915  */

	int val;
	char sym;

#line 68 "lexer.tab.hpp" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_LEXER_TAB_HPP_INCLUDED  */
