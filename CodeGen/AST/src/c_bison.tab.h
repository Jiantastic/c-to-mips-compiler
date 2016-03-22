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
    INT_NUM = 258,
    HEX_NUM = 259,
    FLOAT_NUM = 260,
    IDENTIFIER = 261,
    CHAR_CONST = 262,
    STRINGLITERAL = 263,
    SIZEOF = 264,
    AUTO = 265,
    DOUBLE = 266,
    INT = 267,
    STRUCT = 268,
    BREAK = 269,
    ELSE = 270,
    LONG = 271,
    SWITCH = 272,
    CASE = 273,
    ENUM = 274,
    REGISTER = 275,
    TYPEDEF = 276,
    CHAR = 277,
    EXTERN = 278,
    RETURN = 279,
    UNION = 280,
    CONST = 281,
    FLOAT = 282,
    SHORT = 283,
    UNSIGNED = 284,
    CONTINUE = 285,
    FOR = 286,
    SIGNED = 287,
    VOID = 288,
    DEFAULT = 289,
    GOTO = 290,
    VOLATILE = 291,
    DO = 292,
    IF = 293,
    STATIC = 294,
    WHILE = 295,
    ELLIPSIS = 296,
    PTR_OPERATOR = 297,
    INC_OPERATOR = 298,
    DEC_OPERATOR = 299,
    LEFT_OPERATOR = 300,
    RIGHT_OPERATOR = 301,
    LE_OPERATOR = 302,
    GE_OPERATOR = 303,
    EQ_OPERATOR = 304,
    NE_OPERATOR = 305,
    AND_OPERATOR = 306,
    OR_OPERATOR = 307,
    MUL_ASSIGNMENT = 308,
    DIV_ASSIGNMENT = 309,
    MOD_ASSIGNMENT = 310,
    ADD_ASSIGNMENT = 311,
    SUB_ASSIGNMENT = 312,
    LEFT_ASSIGNMENT = 313,
    RIGHT_ASSIGNMENT = 314,
    AND_ASSIGNMENT = 315,
    XOR_ASSIGNMENT = 316,
    OR_ASSIGNMENT = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "src/c_bison.y" /* yacc.c:1909  */

        int number;
        float float_num;
        char* str;
        class Expression* exp;
        class AssignmentOperator* assign_op;

#line 125 "c_bison.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_BISON_TAB_H_INCLUDED  */
