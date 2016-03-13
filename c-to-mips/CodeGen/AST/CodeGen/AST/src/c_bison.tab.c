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
#line 1 "src/c_bison.y" /* yacc.c:339  */

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include "ast.h"
#include "ast.cpp"
  std::stringstream ss;

int yylex();
int yyerror(const char* s);
char* identifier_value;
int scope_counter = 0;
int is_function = 0;
std::stack<Expression*> mystack;
mipsRegisters mips32;


#line 86 "c_bison.tab.c" /* yacc.c:339  */

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
   by #include "c_bison.tab.h".  */
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
    FLOAT_NUM = 259,
    IDENTIFIER = 260,
    CHAR_CONST = 261,
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
    ELLIPSIS = 295,
    PTR_OPERATOR = 296,
    INC_OPERATOR = 297,
    DEC_OPERATOR = 298,
    LEFT_OPERATOR = 299,
    RIGHT_OPERATOR = 300,
    LE_OPERATOR = 301,
    GE_OPERATOR = 302,
    EQ_OPERATOR = 303,
    NE_OPERATOR = 304,
    AND_OPERATOR = 305,
    OR_OPERATOR = 306,
    MUL_ASSIGNMENT = 307,
    DIV_ASSIGNMENT = 308,
    MOD_ASSIGNMENT = 309,
    ADD_ASSIGNMENT = 310,
    SUB_ASSIGNMENT = 311,
    LEFT_ASSIGNMENT = 312,
    RIGHT_ASSIGNMENT = 313,
    AND_ASSIGNMENT = 314,
    XOR_ASSIGNMENT = 315,
    OR_ASSIGNMENT = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "src/c_bison.y" /* yacc.c:355  */

        int number;
        float float_num;
        char* str;
        class Expression* exp;

#line 195 "c_bison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 212 "c_bison.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   956

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  288

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    82,    71,     2,
      63,    64,    72,    73,    65,    74,    70,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    83,
      79,    62,    80,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    84,    77,    85,    75,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    91,    94,    95,   104,   105,   106,   107,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   131,   138,   142,   147,   148,   154,   155,   158,   159,
     160,   161,   162,   163,   169,   170,   174,   175,   176,   177,
     178,   179,   180,   181,   184,   185,   186,   187,   188,   189,
     192,   193,   200,   201,   204,   205,   213,   214,   219,   220,
     225,   226,   231,   232,   233,   238,   239,   240,   241,   242,
     247,   248,   249,   254,   255,   258,   267,   268,   269,   270,
     279,   283,   284,   285,   286,   298,   299,   300,   301,   302,
     303,   309,   310,   311,   316,   317,   318,   319,   324,   325,
     330,   331,   332,   339,   340,   341,   342,   347,   348,   349,
     350,   351,   356,   357,   360,   361,   368,   369,   379,   380,
     381,   382,   383,   384,   387,   388,   389,   390,   391,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   415,   416,
     421,   422,   425,   426,   508,   509,   512,   513,   514,   515,
     518,   519,   522,   534,   535,   536,   537,   538,   539,   544,
     545,   548,   549,   560,   569,   572,   573,   579,   580,   581,
     584,   585,   591,   592,   593,   594,   600,   608,   612
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_NUM", "FLOAT_NUM", "IDENTIFIER",
  "CHAR_CONST", "STRINGLITERAL", "SIZEOF", "AUTO", "DOUBLE", "INT",
  "STRUCT", "BREAK", "ELSE", "LONG", "SWITCH", "CASE", "ENUM", "REGISTER",
  "TYPEDEF", "CHAR", "EXTERN", "RETURN", "UNION", "CONST", "FLOAT",
  "SHORT", "UNSIGNED", "CONTINUE", "FOR", "SIGNED", "VOID", "DEFAULT",
  "GOTO", "VOLATILE", "DO", "IF", "STATIC", "WHILE", "ELLIPSIS",
  "PTR_OPERATOR", "INC_OPERATOR", "DEC_OPERATOR", "LEFT_OPERATOR",
  "RIGHT_OPERATOR", "LE_OPERATOR", "GE_OPERATOR", "EQ_OPERATOR",
  "NE_OPERATOR", "AND_OPERATOR", "OR_OPERATOR", "MUL_ASSIGNMENT",
  "DIV_ASSIGNMENT", "MOD_ASSIGNMENT", "ADD_ASSIGNMENT", "SUB_ASSIGNMENT",
  "LEFT_ASSIGNMENT", "RIGHT_ASSIGNMENT", "AND_ASSIGNMENT",
  "XOR_ASSIGNMENT", "OR_ASSIGNMENT", "'='", "'('", "')'", "','", "'?'",
  "':'", "'['", "']'", "'.'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'|'", "'^'", "'<'", "'>'", "'/'", "'%'", "';'", "'{'", "'}'", "$accept",
  "translation_unit", "external_declaration", "primary_expression",
  "assignment_operator", "constant_expression", "expression",
  "assignment_expression", "conditional_expression", "unary_expression",
  "logical_or_expression", "postfix_expression", "unary_operator",
  "cast_expression", "logical_and_expression", "argument_expression_list",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "type_name",
  "specifier_qualifier_list", "statement", "labeled_statement",
  "compound_statement", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "statement_list",
  "declaration_list", "declaration", "declaration_specifiers",
  "storage_class_specifier", "type_specifier", "type_qualifier",
  "init_declarator_list", "init_declarator", "declarator", "pointer",
  "type_qualifier_list", "direct_declarator", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "initializer", "initializer_list", "function_definition", "start_scope",
  "end_scope", "function_name", YY_NULLPTR
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
     315,   316,    61,    40,    41,    44,    63,    58,    91,    93,
      46,    38,    42,    43,    45,   126,    33,   124,    94,    60,
      62,    47,    37,    59,   123,   125
};
# endif

#define YYPACT_NINF -131

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-131)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     817,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,    28,   -14,
     778,  -131,  -131,     7,   918,   918,   918,   508,    10,     8,
    -131,   -50,  -131,  -131,   -14,  -131,  -131,  -131,   -47,  -131,
     476,  -131,  -131,  -131,  -131,  -131,   508,  -131,     7,   216,
       8,  -131,   583,   856,  -131,  -131,  -131,    28,  -131,   273,
    -131,   508,  -131,  -131,    -9,  -131,   -12,  -131,   640,    16,
      31,   686,   381,    21,    45,     2,    69,   364,    49,    52,
     701,   701,   542,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,   -38,  -131,  -131,   665,   -10,    -3,   686,  -131,
      76,    74,    75,    88,    58,     1,    66,    55,   -18,  -131,
    -131,  -131,  -131,  -131,  -131,  -131,   290,   216,  -131,  -131,
    -131,   108,  -131,  -131,  -131,  -131,    28,    98,   118,  -131,
      91,  -131,  -131,  -131,   273,  -131,   364,   542,  -131,  -131,
     686,   132,  -131,   -22,  -131,   407,   364,   119,   166,   686,
     686,   686,  -131,  -131,    93,   145,  -131,   153,   153,   686,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,   686,   686,   686,   209,  -131,  -131,   599,   686,
     212,  -131,   686,   686,   686,   686,   686,   686,   686,   686,
     686,   686,   686,   686,   686,   686,   686,   686,   686,  -131,
    -131,   290,  -131,  -131,  -131,  -131,   886,  -131,   213,  -131,
     -43,  -131,   158,   101,   364,  -131,   407,  -131,  -131,   171,
     105,   111,  -131,   686,  -131,  -131,  -131,  -131,    76,   -15,
    -131,  -131,  -131,   122,    36,  -131,    74,    75,    88,    58,
       1,     1,    66,    66,    66,    66,    55,    55,   -18,   -18,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,   267,  -131,  -131,
     364,  -131,   624,   686,   364,   364,  -131,   686,  -131,   686,
    -131,  -131,  -131,  -131,   364,   125,   127,   226,  -131,  -131,
    -131,  -131,   364,   173,   364,  -131,  -131,  -131
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   152,   127,   135,   132,   133,   128,   124,   130,   125,
     138,   134,   131,   137,   136,   129,   139,   126,     0,   146,
       0,     2,     4,     0,   118,   120,   122,     0,     0,   145,
       5,     0,   150,   148,   147,     1,     3,   116,     0,   140,
     142,   119,   121,   123,   176,   175,     0,   114,     0,     0,
     144,   178,     0,     0,   153,   151,   149,     0,   117,     0,
     173,     0,   174,   115,   142,     7,     6,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,    46,    47,    48,    49,    98,
     177,    36,     0,    22,    24,    50,    26,    28,     0,    76,
      34,    52,    56,    58,    60,    62,    65,    70,    73,   112,
      85,    86,    87,    88,    89,    90,     0,     0,    94,     6,
     155,     0,    21,    50,   165,   158,   164,     0,   159,   161,
       0,   141,   167,   143,     0,   172,     0,     0,    32,   109,
       0,     0,   110,     0,   108,     0,     0,     0,     0,     0,
       0,     0,    29,    30,     0,     0,    80,    82,    84,     0,
      99,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    10,     0,     0,     0,     0,    42,    43,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
      95,     0,    96,   154,   163,   156,     0,   157,     0,   170,
       0,    91,     0,     0,     0,   111,     0,    93,   107,     0,
       0,     0,     9,     0,    81,    83,    23,    25,    35,     0,
      41,    38,    54,     0,     0,    40,    53,    57,    59,    61,
      63,    64,    68,    69,    66,    67,    71,    72,    74,    75,
      77,    78,    79,    97,   160,   162,   166,     0,   168,    33,
       0,    92,     0,     0,     0,     0,    51,     0,    39,     0,
      37,   171,   169,   102,     0,     0,     0,   100,   103,    27,
      55,   106,     0,     0,     0,   105,   104,   101
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,   237,  -131,  -131,   189,   -65,   -56,   -51,   -52,
    -131,  -131,  -131,   -73,    89,  -131,    79,    80,    81,    82,
       9,   -71,    11,    -1,   129,    50,   -54,  -131,   121,  -121,
    -131,  -131,  -131,   147,    47,    37,     6,  -131,   -69,    15,
    -131,   211,   -13,    32,  -131,   241,  -131,  -131,    65,  -131,
    -130,  -131,  -131,   -57,  -108,  -131
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    91,   172,   121,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   233,   101,   102,   103,   104,
     105,   106,   107,   108,   155,   156,   109,   110,   111,   112,
     113,   114,   115,   116,    46,    47,    48,    24,    25,    26,
      38,    39,    27,    28,    34,    29,   127,   128,   129,   130,
     133,   210,    30,    49,   118,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     123,   122,   134,   132,   209,    31,    23,   143,   200,   202,
      40,    10,     1,   157,    54,     1,   138,   154,    57,   123,
     122,    16,   257,   148,   216,   181,    23,   159,   152,   153,
      41,    42,    43,     1,    32,    64,    58,    22,   175,   176,
     177,   173,    90,   159,    64,   160,   123,   188,   189,    55,
     159,    33,   267,    59,   196,   136,   174,    22,    19,   126,
     178,   215,   199,   197,   198,   179,    56,   180,   157,   146,
      18,    51,   154,    18,   147,   213,    52,   134,   132,    19,
     190,   191,   211,    63,   220,   221,   154,    61,   157,   157,
      37,    18,   217,   253,   140,   262,   117,   158,    63,   139,
      19,   159,   258,   226,   144,   270,   186,   187,   145,   229,
     192,   193,   149,   204,   234,   150,   227,   242,   243,   244,
     245,   123,   232,   250,   251,   252,   182,   271,   194,   195,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   199,    45,   272,
     266,   183,   158,   184,    63,   207,   208,   222,   159,   185,
     261,    60,   205,     3,     4,   260,   159,    62,     5,   264,
     159,   123,   158,   158,     8,   265,   159,   203,    10,    11,
      12,    13,   135,   206,    14,    15,   268,   269,    16,   282,
     159,   283,   159,   248,   249,   240,   241,   275,   276,   214,
     134,   132,   218,   246,   247,   219,   273,   224,   225,   223,
     277,   278,   126,   280,   230,   123,   279,   235,   256,    65,
     281,    66,   259,    67,    68,     2,     3,     4,   285,    69,
     287,     5,    70,    71,   263,     6,     7,     8,     9,    72,
     284,    10,    11,    12,    13,    73,    74,    14,    15,    75,
      76,    16,    77,    78,    17,    79,   286,    36,    80,    81,
     141,   236,   228,   237,   201,   238,   212,   239,   131,    50,
      65,   255,   119,     0,    67,    68,    65,     0,   119,    82,
      67,    68,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,    65,     0,    66,     0,    67,    68,    89,
      44,    90,     0,    69,     0,     0,    70,    71,     0,    80,
      81,     0,     0,    72,     0,    80,    81,     0,     0,    73,
      74,     0,     0,    75,    76,     0,    77,    78,     0,    79,
      82,     0,    80,    81,     0,     0,    82,     0,    83,    84,
      85,    86,    87,    88,    83,    84,    85,    86,    87,    88,
       0,    44,    90,    82,     0,     0,     0,    44,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    65,     0,    66,
       0,    67,    68,    89,    44,    90,     0,    69,     0,     0,
      70,    71,     0,     0,    65,     0,   119,    72,    67,    68,
       0,     0,     0,    73,    74,     0,     0,    75,    76,     0,
      77,    78,     0,    79,     0,     0,    80,    81,     0,     0,
      65,     0,   119,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,    86,    87,
      88,     0,     0,     0,    82,     0,     0,    89,    44,    80,
      81,     0,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
      82,     0,     0,     0,     0,     0,     0,     0,    83,    84,
      85,    86,    87,    88,     0,     2,     3,     4,     0,     0,
      89,     5,     0,     0,     0,     6,     7,     8,     9,     0,
       0,    10,    11,    12,    13,     0,     0,    14,    15,     0,
       0,    16,     0,     0,    17,     0,     0,     2,     3,     4,
       0,     0,     0,     5,     0,     0,     0,     6,     7,     8,
       9,     0,     0,    10,    11,    12,    13,     0,    59,    14,
      15,     0,     0,    16,     0,    65,    17,   119,     0,    67,
      68,     0,     3,     4,     0,     0,     0,     5,     0,     0,
      44,     0,     0,     8,     0,     0,     0,    10,    11,    12,
      13,     0,     0,    14,    15,     0,     0,    16,     0,     0,
       0,     0,     0,     0,    80,    81,    65,     0,   119,     0,
      67,    68,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,   119,    82,    67,    68,     0,     0,
       0,     0,     0,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,    80,    81,    65,     0,   119,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    65,     0,   119,    82,    67,    68,     0,
       0,     0,   120,     0,    83,    84,    85,    86,    87,    88,
       0,     0,    82,   231,     0,     0,    80,    81,     0,     0,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,    80,    81,     0,     0,     0,    82,   274,    65,
       0,   119,     0,    67,    68,    83,    84,    85,    86,    87,
      88,     0,     0,   137,    65,     0,   119,     0,    67,    68,
       0,    83,    84,    85,    86,    87,    88,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,     0,   151,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    35,     0,
       0,     0,     0,     1,     0,     0,     0,     2,     3,     4,
       0,     0,     0,     5,     0,     0,     0,     6,     7,     8,
       9,     0,     0,    10,    11,    12,    13,     0,     0,    14,
      15,     0,     0,    16,     0,     0,    17,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     2,     3,     4,     0,
       0,     0,     5,     0,     0,     0,     6,     7,     8,     9,
       0,    18,    10,    11,    12,    13,     0,     0,    14,    15,
      19,     0,    16,     0,     0,    17,     0,     0,     0,     0,
       0,   124,     0,     0,     0,     2,     3,     4,     0,     0,
       0,     5,     0,     0,     0,     6,     7,     8,     9,     0,
      18,    10,    11,    12,    13,     0,     0,    14,    15,    19,
       0,    16,     0,     0,    17,     2,     3,     4,     0,     0,
       0,     5,     0,     0,     0,     6,     7,     8,     9,     0,
       0,    10,    11,    12,    13,     0,     0,    14,    15,     0,
     125,    16,     0,     0,    17,     0,   254,     2,     3,     4,
       0,     0,     0,     5,     0,     0,     0,     6,     7,     8,
       9,     0,     0,    10,    11,    12,    13,     0,     0,    14,
      15,     0,     0,    16,     0,     0,    17
};

static const yytype_int16 yycheck[] =
{
      52,    52,    59,    59,   134,    18,     0,    72,   116,   117,
      23,    25,     5,    82,    64,     5,    68,    82,    65,    71,
      71,    35,    65,    77,   145,    98,    20,    65,    80,    81,
      24,    25,    26,     5,    19,    48,    83,     0,    41,    42,
      43,    51,    85,    65,    57,    83,    98,    46,    47,    34,
      65,    19,    67,    62,    72,    67,    66,    20,    72,    53,
      63,    83,   116,    81,    82,    68,    34,    70,   137,    67,
      63,    63,   137,    63,     5,   140,    68,   134,   134,    72,
      79,    80,   136,    46,   149,   150,   151,    40,   157,   158,
      83,    63,   146,   201,    63,   216,    49,    82,    61,    83,
      72,    65,   210,   159,    83,    69,    48,    49,    63,   174,
      44,    45,    63,   126,   179,    63,   172,   188,   189,   190,
     191,   173,   178,   196,   197,   198,    50,   257,    73,    74,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   201,    27,   257,
     223,    77,   137,    78,   117,    64,    65,    64,    65,    71,
     214,    40,    64,    10,    11,    64,    65,    46,    15,    64,
      65,   223,   157,   158,    21,    64,    65,    69,    25,    26,
      27,    28,    61,    65,    31,    32,    64,    65,    35,    64,
      65,    64,    65,   194,   195,   186,   187,   262,   263,    67,
     257,   257,    83,   192,   193,    39,   260,   157,   158,    64,
     264,   265,   206,   269,     5,   267,   267,     5,     5,     3,
     274,     5,    64,     7,     8,     9,    10,    11,   282,    13,
     284,    15,    16,    17,    63,    19,    20,    21,    22,    23,
      14,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    83,    20,    42,    43,
      71,   182,   173,   183,   117,   184,   137,   185,    57,    28,
       3,   206,     5,    -1,     7,     8,     3,    -1,     5,    63,
       7,     8,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,     3,    -1,     5,    -1,     7,     8,    83,
      84,    85,    -1,    13,    -1,    -1,    16,    17,    -1,    42,
      43,    -1,    -1,    23,    -1,    42,    43,    -1,    -1,    29,
      30,    -1,    -1,    33,    34,    -1,    36,    37,    -1,    39,
      63,    -1,    42,    43,    -1,    -1,    63,    -1,    71,    72,
      73,    74,    75,    76,    71,    72,    73,    74,    75,    76,
      -1,    84,    85,    63,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,     3,    -1,     5,
      -1,     7,     8,    83,    84,    85,    -1,    13,    -1,    -1,
      16,    17,    -1,    -1,     3,    -1,     5,    23,     7,     8,
      -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,    -1,
      36,    37,    -1,    39,    -1,    -1,    42,    43,    -1,    -1,
       3,    -1,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    63,    -1,    -1,    83,    84,    42,
      43,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    -1,     9,    10,    11,    -1,    -1,
      83,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    31,    32,    -1,
      -1,    35,    -1,    -1,    38,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    25,    26,    27,    28,    -1,    62,    31,
      32,    -1,    -1,    35,    -1,     3,    38,     5,    -1,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    15,    -1,    -1,
      84,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,     3,    -1,     5,    -1,
       7,     8,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,     5,    63,     7,     8,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,     3,    -1,     5,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,     3,    -1,     5,    63,     7,     8,    -1,
      -1,    -1,    69,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    63,    64,    -1,    -1,    42,    43,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    63,    64,     3,
      -1,     5,    -1,     7,     8,    71,    72,    73,    74,    75,
      76,    -1,    -1,    63,     3,    -1,     5,    -1,     7,     8,
      -1,    71,    72,    73,    74,    75,    76,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    42,    43,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,     0,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,     5,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      -1,    63,    25,    26,    27,    28,    -1,    -1,    31,    32,
      72,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,     9,    10,    11,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      63,    25,    26,    27,    28,    -1,    -1,    31,    32,    72,
      -1,    35,    -1,    -1,    38,     9,    10,    11,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,
      -1,    25,    26,    27,    28,    -1,    -1,    31,    32,    -1,
      64,    35,    -1,    -1,    38,    -1,    40,     9,    10,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     9,    10,    11,    15,    19,    20,    21,    22,
      25,    26,    27,    28,    31,    32,    35,    38,    63,    72,
      87,    88,   121,   122,   123,   124,   125,   128,   129,   131,
     138,   128,   125,   129,   130,     0,    88,    83,   126,   127,
     128,   122,   122,   122,    84,   114,   120,   121,   122,   139,
     131,    63,    68,   141,    64,   125,   129,    65,    83,    62,
     114,   120,   114,   121,   128,     3,     5,     7,     8,    13,
      16,    17,    23,    29,    30,    33,    34,    36,    37,    39,
      42,    43,    63,    71,    72,    73,    74,    75,    76,    83,
      85,    89,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   102,   103,   104,   105,   106,   107,   108,   109,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   140,     5,
      69,    91,    94,    95,     5,    64,   122,   132,   133,   134,
     135,   127,    93,   136,   139,   114,    67,    63,    95,    83,
      63,    91,    83,    92,    83,    63,    67,     5,   112,    63,
      63,    63,    95,    95,    92,   110,   111,   124,   125,    65,
      83,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    90,    51,    66,    41,    42,    43,    63,    68,
      70,    99,    50,    77,    78,    71,    48,    49,    46,    47,
      79,    80,    44,    45,    73,    74,    72,    81,    82,   112,
     140,   119,   140,    69,   128,    64,    65,    64,    65,   136,
     137,   112,   110,    92,    67,    83,   115,   112,    83,    39,
      92,    92,    64,    64,   111,   111,    93,    93,   100,    92,
       5,    64,    93,   101,    92,     5,   102,   103,   104,   105,
     106,   106,   107,   107,   107,   107,   108,   108,   109,   109,
      99,    99,    99,   140,    40,   134,     5,    65,   140,    64,
      64,   112,   115,    63,    64,    64,    99,    67,    64,    65,
      69,   136,   140,   112,    64,    92,    92,   112,   112,    94,
      93,   112,    64,    64,    14,   112,    83,   112
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    88,    88,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      95,    95,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   106,   106,   106,   106,   106,
     107,   107,   107,   108,   108,   108,   109,   109,   109,   109,
     110,   111,   111,   111,   111,   112,   112,   112,   112,   112,
     112,   113,   113,   113,   114,   114,   114,   114,   115,   115,
     116,   116,   116,   117,   117,   117,   117,   118,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   123,   123,   123,   123,   123,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   129,   129,
     130,   130,   131,   131,   131,   131,   131,   131,   131,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   136,
     137,   137,   138,   138,   138,   138,   139,   140,   141
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     5,     1,     2,
       2,     2,     2,     4,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     3,     2,     3,     3,     4,     1,     2,
       5,     7,     5,     5,     7,     7,     6,     3,     2,     2,
       2,     3,     1,     2,     1,     2,     2,     3,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     2,     1,     1,     2,     2,     3,
       1,     2,     1,     3,     4,     3,     4,     4,     3,     1,
       3,     1,     3,     2,     1,     1,     3,     1,     3,     4,
       1,     3,     4,     3,     3,     2,     1,     1,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 104 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.exp) = new IdentifierExpression((yyvsp[0].str));mystack.push((yyval.exp));}
#line 1656 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 105 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.exp) = new ConstantExpression((yyvsp[0].number));mystack.push((yyval.exp));}
#line 1662 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1668 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 117 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1674 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 118 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1680 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 119 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1686 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 120 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1692 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 121 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1698 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 122 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1704 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 123 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1710 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 124 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1716 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 125 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1722 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 126 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1728 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 138 "src/c_bison.y" /* yacc.c:1646  */
    { 
                                                            (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"assignment_expression");

                                                          }
#line 1737 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 147 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"conditional_expression"); mystack.push((yyval.exp));}
#line 1743 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 148 "src/c_bison.y" /* yacc.c:1646  */
    { std::cout << "testing" << std::endl;}
#line 1749 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 154 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"logical_or_expression");mystack.push((yyval.exp));}
#line 1755 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 158 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"postfix_expression");mystack.push((yyval.exp));}
#line 1761 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 161 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "TODO - UNARY EXPRESSION " << std::endl;}
#line 1767 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 169 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"logical_and_expression");mystack.push((yyval.exp));}
#line 1773 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 174 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"primary_expression");mystack.push((yyval.exp));}
#line 1779 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 192 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"unary_expression");mystack.push((yyval.exp));}
#line 1785 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 200 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"inclusive_or_expression");mystack.push((yyval.exp));}
#line 1791 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 213 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"exclusive_or_expression");mystack.push((yyval.exp));}
#line 1797 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 219 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"and_expression");mystack.push((yyval.exp));}
#line 1803 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 225 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"equality_expression");mystack.push((yyval.exp));}
#line 1809 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 231 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"relational_expression");mystack.push((yyval.exp));}
#line 1815 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 238 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"shift_expression");mystack.push((yyval.exp));}
#line 1821 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 247 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"additive_expression");mystack.push((yyval.exp));}
#line 1827 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 254 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"multiplicative_expression");mystack.push((yyval.exp));}
#line 1833 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 255 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"+",(yyvsp[0].exp));mystack.push((yyval.exp));
                                                                              std::cout << "ADDITION COMPLETE,recursive testing" << std::endl;
                                                                           }
#line 1841 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 258 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"-",(yyvsp[0].exp));mystack.push((yyval.exp));



                    }
#line 1851 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 267 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"cast_expression");mystack.push((yyval.exp));}
#line 1857 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 268 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"*",(yyvsp[0].exp));mystack.push((yyval.exp));std::cout << "MULT" << std::endl;}
#line 1863 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 269 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"/",(yyvsp[0].exp));mystack.push((yyval.exp));}
#line 1869 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 270 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"%",(yyvsp[0].exp));mystack.push((yyval.exp));}
#line 1875 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 369 "src/c_bison.y" /* yacc.c:1646  */
    {
                                                                      for(int i=0;i<scope_counter;i++){
                                                                        std::cout << "    " ;
                                                                      }
                                                                      std::cout << "VARIABLE : " << identifier_value << std::endl;
                                                                   }
#line 1886 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 421 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "times of number" << std::endl;}
#line 1892 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 422 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "number of times" << std::endl;}
#line 1898 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 426 "src/c_bison.y" /* yacc.c:1646  */
    { 
                                                                                          std::cout << "hohohoohoh" << std::endl;
                                                                                          std::string strOp;
                                                                                          std::vector<int> vec1;
                                                                                          std::vector<std::string> operations;

                                                                                          /* store initialization of register variable */
                                                                                          int reg = mips32.findEmptyRegister();
                                                                                          mips32.Bind(0,reg,(yyvsp[-2].str));
                                                                                          while (!mystack.empty()){
                                                                                              mystack.top()->printer();
                                                                                            if(mystack.top()->getType() == "+" || mystack.top()->getType() == "*" || mystack.top()->getType() == "-" || mystack.top()->getType() == "/"){
                                                                                              strOp = mystack.top()->getType();
                                                                                              operations.push_back(strOp);
                                                                                              for(int i=0;i<operations.size();i++){
                                                                                                std::cout << "this works " << operations[i] << std::endl;
                                                                                              }
                                                                                            }
                                                                                            else if(mystack.top()->getType() == "Identifier"){
                                                                                              /* check if identifier exists prior to this */
                                                                                              int check = mips32.registerLookup(mystack.top()->getName());
                                                                                              if(check == -1){
                                                                                                std::cout << "variable " << mystack.top()->getName() << " is undeclared" << std::endl;
                                                                                                return -1;
                                                                                              }
                                                                                              else{
                                                                                                Register reg1 = mips32.getValue(check);
                                                                                                int val = reg1.value;
                                                                                                vec1.push_back(val);
                                                                                              }
                                                                                            }
                                                                                            else if(mystack.top()->getType() == "Constant"){
                                                                                              vec1.push_back(mystack.top()->getConstant());
                                                                                            }
                                                                                            mystack.pop();
                                                                                          }
                                                                                          /* after collecting all necessary data, combine them */
                                                                                          for(int i=0;i<vec1.size();i++){
                                                                                            std::cout << "COLLECTION : " << vec1[i] << std::endl;
                                                                                          }
                                                                                          for(int i=0;i<operations.size();i++){
                                                                                            std::cout << "OPERATORSSSS : " << operations[i] << std::endl;
                                                                                          }
                                                                                          int sum = 0;
                                                                                          std::cout << "OPERATIONS SIZE : " <<operations.size() << std::endl;
                                                                                          for(int i=0;i<operations.size();i++){
                                                                                            std::cout << "inside the loop" << std::endl;
                                                                                            if(operations[i] == "+"){
                                                                                              std::cout << "VALUE : " << vec1[vec1.size()-1] << std::endl;
                                                                                              sum += vec1[vec1.size()-1];

                                                                                              vec1.pop_back();
                                                                                            }
                                                                                            else if(operations[i] == "*"){
                                                                                              std::cout << "VALUES : " << vec1[vec1.size()-1] << " " << vec1[vec1.size()-2] << std::endl;
                                                                                              sum += (vec1[vec1.size()-2] * vec1[vec1.size()-1]);
                                                                                              std::cout << "MULT is this working?" << std::endl;
                                                                                              vec1.pop_back();
                                                                                              vec1.pop_back();
                                                                                            }
                                                                                            else if(operations[i] == "-"){
                                                                                              std::cout << "MINUS : " << vec1[0] << std::endl;
                                                                                              sum = sum - vec1[0];
                                                                                              vec1.pop_back();
                                                                                            }
                                                                                            else if(operations[i] == "/"){
                                                                                              sum += (vec1[1] / vec1[0]);
                                                                                              vec1.erase(vec1.begin());
                                                                                              vec1.erase(vec1.begin());
                                                                                            }
                                                                                          }
                                                                                          /* add remaining components */

                                                                                          std::cout << "FINAL ANSWER : " << (yyvsp[-2].str) << " = " << sum << std::endl;
                                                                                          mips32.Bind(sum,reg,(yyvsp[-2].str));
                                                                                          std::cout << std::endl;
                                                                                        }
#line 1980 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 522 "src/c_bison.y" /* yacc.c:1646  */
    { identifier_value = (yyvsp[0].str);
                                                                                      int x = mips32.findEmptyRegister();
                                                                                      if(x == -1){
                                                                                        std::cout << "redeclaration of variable / registers are filled with existing data" << std::endl;
                                                                                        return -1;
                                                                                      }
                                                                                      else{

                                                                                        mips32.Bind(0,x,(yyvsp[0].str));
                                                                                        mips32.printAllRegisters();
                                                                                      }
                                                                                    }
#line 1997 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 537 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "asdasdasdasdsa" << std::endl;}
#line 2003 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 538 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "sqqqqqqqq" << std::endl;}
#line 2009 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 539 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "pppppppppppppppp" << std::endl;}
#line 2015 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 560 "src/c_bison.y" /* yacc.c:1646  */
    {
                                                                              int reg = mips32.findEmptyRegister();
                                                                              mips32.Bind(0,reg,(yyvsp[0].str));
                                                                              mips32.printAllRegisters();
                                                                              for(int i=0;i<scope_counter;i++){
                                                                                std::cout << "    " ;
                                                                              }
                                                                              std::cout << "    PARAMS : " << (yyvsp[0].str) << std::endl;
                                                                          }
#line 2029 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 579 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"assignment_expression");}
#line 2035 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 592 "src/c_bison.y" /* yacc.c:1646  */
    {mips32.clearRegisters();  std::cout << "IMPORTANT : " << ss.str() << std::endl;std::cout << "function definition compound statemnet end" << std::endl;}
#line 2041 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 600 "src/c_bison.y" /* yacc.c:1646  */
    {
                            for(int i=0;i<scope_counter;i++){
                              std::cout << "    " ;
                            }
                            scope_counter++; std::cout << "SCOPE" << std::endl;
                         }
#line 2052 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 608 "src/c_bison.y" /* yacc.c:1646  */
    {scope_counter--;}
#line 2058 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 612 "src/c_bison.y" /* yacc.c:1646  */
    {
                        for(int i=0;i<scope_counter;i++){
                          std::cout << "    " ;
                        }
                        std::cout << "FUNCTION : " << identifier_value << std::endl;
                      }
#line 2069 "c_bison.tab.c" /* yacc.c:1646  */
    break;


#line 2073 "c_bison.tab.c" /* yacc.c:1646  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 622 "src/c_bison.y" /* yacc.c:1906  */



int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {

  ss << yyparse();
}


