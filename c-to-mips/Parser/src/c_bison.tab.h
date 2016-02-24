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

#ifndef YY_YY_C_BISON_TAB_H_INCLUDED
# define YY_YY_C_BISON_TAB_H_INCLUDED
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
    NUM = 258,
    FLOAT_NUMBER = 259,
    IDENTIFIER = 260,
    CONSTANT = 261,
    STRINGLITERAL = 262,
    SIZEOF = 263,
    AUTO = 264,
    DOUBLE = 265,
    INT = 266,
    STRUCT = 267,
    BREAK = 268,
    ELSE = 269,
    LONG = 270,
    SWITCH = 271,
    CASE = 272,
    ENUM = 273,
    REGISTER = 274,
    TYPEDEF = 275,
    CHAR = 276,
    EXTERN = 277,
    RETURN = 278,
    UNION = 279,
    CONST = 280,
    FLOAT = 281,
    SHORT = 282,
    UNSIGNED = 283,
    CONTINUE = 284,
    FOR = 285,
    SIGNED = 286,
    VOID = 287,
    DEFAULT = 288,
    GOTO = 289,
    VOLATILE = 290,
    DO = 291,
    IF = 292,
    STATIC = 293,
    WHILE = 294,
    LROUNDBRACKET = 295,
    RROUNDBRACKET = 296,
    EOLINE = 297,
    LCURLYBRACE = 298,
    RCURLYBRACE = 299,
    SEMICOLON = 300,
    COMMA = 301,
    ELLIPSIS = 302,
    PTR_OPERATOR = 303,
    INC_OPERATOR = 304,
    DEC_OPERATOR = 305,
    LEFT_OPERATOR = 306,
    RIGHT_OPERATOR = 307,
    LE_OPERATOR = 308,
    GE_OPERATOR = 309,
    EQ_OPERATOR = 310,
    NE_OPERATOR = 311,
    AND_OPERATOR = 312,
    OR_OPERATOR = 313,
    MUL_ASSIGNMENT = 314,
    DIV_ASSIGNMENT = 315,
    MOD_ASSIGNMENT = 316,
    ADD_ASSIGNMENT = 317,
    SUB_ASSIGNMENT = 318,
    LEFT_ASSIGNMENT = 319,
    RIGHT_ASSIGNMENT = 320,
    AND_ASSIGNMENT = 321,
    XOR_ASSIGNMENT = 322,
    OR_ASSIGNMENT = 323
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "src/c_bison.y" /* yacc.c:1909  */

        int number;
        float float_num;
        char* str;

#line 129 "c_bison.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_BISON_TAB_H_INCLUDED  */
