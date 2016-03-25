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
#include <sstream>
#include <vector>
#include <stack>
#include "ast.h"
#include "ast.cpp"

int yylex();
int yyerror(const char* s);

char* identifier_value;
int scope_counter = 0;
int is_function = 0;
mips_stack mips32;
std::vector<Expression*> completeTree;
bool debugMode = false;
bool functionCall = false;
std::string functionName;
int paramCount = 0;


#line 91 "c_bison.tab.c" /* yacc.c:339  */

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
#line 27 "src/c_bison.y" /* yacc.c:355  */

        int number;
        float float_num;
        char* str;
        class Expression* exp;
        class AssignmentOperator* assign_op;

#line 202 "c_bison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 219 "c_bison.tab.c" /* yacc.c:358  */

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
#define YYLAST   1026

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  179
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  289

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,     2,     2,     2,    83,    72,     2,
      63,    64,    73,    74,    66,    75,    71,    82,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    84,
      80,    65,    81,    67,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    69,     2,    70,    79,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    85,    78,    86,    76,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,   100,   101,   110,   113,   117,   121,
     122,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   146,   153,   154,   159,   160,   191,   192,   195,
     196,   197,   198,   199,   200,   206,   207,   211,   212,   213,
     214,   215,   216,   217,   218,   221,   222,   223,   224,   225,
     226,   229,   230,   237,   238,   241,   242,   250,   251,   256,
     257,   262,   263,   268,   269,   270,   275,   276,   277,   278,
     279,   284,   285,   286,   291,   292,   293,   298,   299,   300,
     301,   310,   314,   315,   316,   317,   329,   330,   331,   332,
     333,   334,   340,   341,   342,   347,   348,   349,   350,   355,
     356,   361,   362,   363,   370,   371,   372,   373,   378,   379,
     380,   381,   382,   387,   388,   391,   392,   399,   400,   413,
     414,   415,   416,   417,   418,   421,   422,   423,   424,   425,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   449,
     450,   455,   456,   459,   464,   496,   497,   500,   501,   502,
     503,   506,   507,   510,   513,   514,   515,   516,   517,   518,
     523,   524,   527,   528,   539,   550,   553,   554,   560,   561,
     562,   565,   566,   572,   573,   574,   575,   581,   590,   601
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_NUM", "HEX_NUM", "FLOAT_NUM",
  "IDENTIFIER", "CHAR_CONST", "STRINGLITERAL", "SIZEOF", "AUTO", "DOUBLE",
  "INT", "STRUCT", "BREAK", "ELSE", "LONG", "SWITCH", "CASE", "ENUM",
  "REGISTER", "TYPEDEF", "CHAR", "EXTERN", "RETURN", "UNION", "CONST",
  "FLOAT", "SHORT", "UNSIGNED", "CONTINUE", "FOR", "SIGNED", "VOID",
  "DEFAULT", "GOTO", "VOLATILE", "DO", "IF", "STATIC", "WHILE", "ELLIPSIS",
  "PTR_OPERATOR", "INC_OPERATOR", "DEC_OPERATOR", "LEFT_OPERATOR",
  "RIGHT_OPERATOR", "LE_OPERATOR", "GE_OPERATOR", "EQ_OPERATOR",
  "NE_OPERATOR", "AND_OPERATOR", "OR_OPERATOR", "MUL_ASSIGNMENT",
  "DIV_ASSIGNMENT", "MOD_ASSIGNMENT", "ADD_ASSIGNMENT", "SUB_ASSIGNMENT",
  "LEFT_ASSIGNMENT", "RIGHT_ASSIGNMENT", "AND_ASSIGNMENT",
  "XOR_ASSIGNMENT", "OR_ASSIGNMENT", "'('", "')'", "'='", "','", "'?'",
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
     315,   316,   317,    40,    41,    61,    44,    63,    58,    91,
      93,    46,    38,    42,    43,    45,   126,    33,   124,    94,
      60,    62,    47,    37,    59,   123,   125
};
# endif

#define YYPACT_NINF -141

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-141)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     874,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,    27,    18,
     842,  -141,  -141,     8,   971,   971,   971,   552,    19,    -4,
    -141,   -49,  -141,  -141,    18,  -141,  -141,  -141,   -26,  -141,
     522,  -141,  -141,  -141,  -141,  -141,   552,  -141,     8,   216,
      -4,  -141,   630,   906,  -141,  -141,  -141,    27,  -141,   409,
    -141,   552,  -141,  -141,   -42,  -141,  -141,   -29,  -141,   722,
       0,     4,   747,   435,    46,     7,    34,    89,   392,    36,
      45,   764,   764,   586,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,   -23,  -141,  -141,   135,   -17,   115,   747,
    -141,   101,    86,    98,   113,   117,    -6,     6,    94,    23,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,   300,   216,  -141,
    -141,  -141,   131,  -141,  -141,  -141,  -141,    27,   123,   138,
    -141,    -2,  -141,  -141,  -141,   409,  -141,   392,   586,  -141,
    -141,   747,   137,  -141,   -18,  -141,   453,   392,   122,   168,
     747,   747,   747,  -141,  -141,    43,   146,  -141,   990,   990,
     747,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,   747,   747,   747,   207,  -141,  -141,   647,
     747,   209,  -141,   747,   747,   747,   747,   747,   747,   747,
     747,   747,   747,   747,   747,   747,   747,   747,   747,   747,
    -141,  -141,   300,  -141,  -141,  -141,  -141,   939,  -141,   212,
    -141,   -50,  -141,   159,    54,   392,  -141,   453,  -141,  -141,
     172,    55,    60,  -141,   747,  -141,  -141,  -141,  -141,   101,
      59,  -141,  -141,  -141,    85,    31,  -141,    86,    98,   113,
     117,    -6,    -6,     6,     6,     6,     6,    94,    94,    23,
      23,  -141,  -141,  -141,  -141,  -141,  -141,  -141,   317,  -141,
    -141,   392,  -141,   672,   747,   392,   392,  -141,   747,  -141,
     747,  -141,  -141,  -141,  -141,   392,    96,    99,   226,  -141,
    -141,  -141,  -141,   392,   173,   392,  -141,  -141,  -141
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   153,   128,   136,   133,   134,   129,   125,   131,   126,
     139,   135,   132,   138,   137,   130,   140,   127,     0,   147,
       0,     2,     4,     0,   119,   121,   123,     0,     0,   146,
       5,     0,   151,   149,   148,     1,     3,   117,     0,   141,
     143,   120,   122,   124,   177,   176,     0,   115,     0,     0,
     145,   179,     0,     0,   154,   152,   150,     0,   118,     0,
     174,     0,   175,   116,   143,     7,     8,     6,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    46,    47,    48,    49,    50,
      99,   178,    37,     0,    23,    25,    51,    27,    29,     0,
      77,    35,    53,    57,    59,    61,    63,    66,    71,    74,
     113,    86,    87,    88,    89,    90,    91,     0,     0,    95,
       6,   156,     0,    22,    51,   166,   159,   165,     0,   160,
     162,     0,   142,   168,   144,     0,   173,     0,     0,    33,
     110,     0,     0,   111,     0,   109,     0,     0,     0,     0,
       0,     0,     0,    30,    31,     0,     0,    81,    83,    85,
       0,   100,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    11,     0,     0,     0,     0,    43,    44,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,    96,     0,    97,   155,   164,   157,     0,   158,     0,
     171,     0,    92,     0,     0,     0,   112,     0,    94,   108,
       0,     0,     0,    10,     0,    82,    84,    24,    26,    36,
       0,    42,    39,    55,     0,     0,    41,    54,    58,    60,
      62,    64,    65,    69,    70,    67,    68,    72,    73,    75,
      76,    78,    79,    80,    98,   161,   163,   167,     0,   169,
      34,     0,    93,     0,     0,     0,     0,    52,     0,    40,
       0,    38,   172,   170,   103,     0,     0,     0,   101,   104,
      28,    56,   107,     0,     0,     0,   106,   105,   102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,   238,  -141,  -141,   189,   -65,   -56,   -51,   -52,
    -141,  -141,  -141,   -43,    88,  -141,    80,    81,    79,    82,
     -12,   -78,   -14,   -25,   128,    24,   -54,  -141,    -8,  -140,
    -141,  -141,  -141,   149,    29,    11,     2,  -141,   -70,    15,
    -141,   213,   -11,    26,  -141,   241,  -141,  -141,    64,  -141,
    -130,  -141,  -141,   -55,  -108,  -141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    92,   173,   122,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   234,   102,   103,   104,   105,
     106,   107,   108,   109,   156,   157,   110,   111,   112,   113,
     114,   115,   116,   117,    46,    47,    48,    24,    25,    26,
      38,    39,    27,    28,    34,    29,   128,   129,   130,   131,
     134,   211,    30,    49,   119,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     124,   123,    23,   133,   135,   210,   217,    31,   144,   201,
     203,    22,    40,   158,     1,    54,   258,   139,   155,    45,
     124,   123,    23,    59,   149,     1,    41,    42,    43,   153,
     154,    22,    60,     1,    32,   174,    91,    64,    62,   137,
      57,   189,   190,   160,    10,    33,    64,   124,   160,    55,
     175,   193,   194,   136,    16,   127,   182,    63,    58,    51,
      56,   161,   208,   200,   209,    52,   216,   141,   158,    61,
     146,    18,    63,   155,   191,   192,   214,   263,   118,   133,
     135,    19,    18,   212,   140,   221,   222,   155,   158,   158,
      18,    19,    37,   218,   254,   148,   197,   160,   159,   150,
      19,   271,   147,   259,   227,   198,   199,   223,   151,   160,
     230,   243,   244,   245,   246,   235,   205,   228,   261,   265,
     160,   160,   124,   233,   266,   160,   160,   268,   272,    63,
     145,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   200,   269,
     273,   270,   183,   159,   251,   252,   253,   176,   177,   178,
     283,   262,   160,   284,   184,   160,   187,   188,   195,   196,
     249,   250,   124,   159,   159,   241,   242,   185,   179,   247,
     248,   267,   225,   226,   180,   186,   181,   206,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   276,   277,
     172,   204,   133,   135,   207,   215,   219,   274,   220,   127,
     224,   278,   279,   231,   281,   236,   124,   280,   257,    65,
      66,   282,    67,   260,    68,    69,     2,     3,     4,   286,
      70,   288,     5,    71,    72,   264,     6,     7,     8,     9,
      73,   285,    10,    11,    12,    13,    74,    75,    14,    15,
      76,    77,    16,    78,    79,    17,    80,   287,    36,    81,
      82,   142,   229,   237,   239,   238,   213,   202,   240,    50,
     132,   256,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
      90,    44,    91,    65,    66,     0,    67,     0,    68,    69,
       0,     0,     0,     0,    70,     0,     0,    71,    72,     0,
      65,    66,     0,   120,    73,    68,    69,     0,     0,     0,
      74,    75,     0,     0,    76,    77,     0,    78,    79,     0,
      80,     0,     0,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    82,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,     0,     0,
      83,     0,     0,     0,    90,    44,    91,     0,     0,    84,
      85,    86,    87,    88,    89,    65,    66,     0,    67,     0,
      68,    69,    44,    91,     0,     0,    70,     0,     0,    71,
      72,     0,    65,    66,     0,   120,    73,    68,    69,     0,
       0,     0,    74,    75,     0,     0,    76,    77,     0,    78,
      79,     0,    80,     0,     0,    81,    82,     0,    65,    66,
       0,   120,     0,    68,    69,     0,     0,     0,     0,     0,
       0,     0,    81,    82,     0,    83,    65,    66,     0,   120,
       0,    68,    69,     0,    84,    85,    86,    87,    88,    89,
       0,     0,    83,     0,     0,     0,    90,    44,    81,    82,
       0,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,     0,     0,     0,    44,     0,    81,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    83,     0,     0,   143,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,     0,     2,     3,     4,     0,     0,    90,     5,     0,
       0,     0,     6,     7,     8,     9,     0,     0,    10,    11,
      12,    13,     0,     0,    14,    15,     0,     0,    16,     0,
       0,    17,     2,     3,     4,     0,     0,     0,     5,     0,
       0,     0,     6,     7,     8,     9,     0,     0,    10,    11,
      12,    13,     0,     0,    14,    15,     0,    59,    16,    65,
      66,    17,   120,     0,    68,    69,     0,     3,     4,     0,
       0,     0,     5,     0,     0,     0,     0,    44,     8,     0,
       0,     0,    10,    11,    12,    13,     0,     0,    14,    15,
       0,     0,    16,     0,     0,     0,     0,     0,     0,    81,
      82,     0,     0,    65,    66,     0,   120,    44,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
      65,    66,     0,   120,     0,    68,    69,     0,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,    65,    66,     0,   120,     0,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
      81,    82,     0,    83,     0,     0,     0,     0,     0,     0,
     121,     0,    84,    85,    86,    87,    88,    89,     0,     0,
      83,   232,     0,     0,     0,    81,    82,     0,     0,    84,
      85,    86,    87,    88,    89,    65,    66,     0,   120,     0,
      68,    69,     0,     0,     0,    83,   275,     0,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88,    89,
      65,    66,     0,   120,     0,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,    81,    82,    65,    66,     0,
     120,     0,    68,    69,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
      81,    82,     0,     0,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,    81,    82,     0,
      83,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,     0,     0,   152,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    35,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     2,     3,     4,     0,     0,     0,     5,     0,
       0,     0,     6,     7,     8,     9,     0,     0,    10,    11,
      12,    13,     0,     0,    14,    15,     0,     0,    16,     0,
       1,    17,     0,     0,     2,     3,     4,     0,     0,     0,
       5,     0,     0,     0,     6,     7,     8,     9,     0,     0,
      10,    11,    12,    13,     0,    18,    14,    15,     0,     0,
      16,     0,   125,    17,     0,    19,     2,     3,     4,     0,
       0,     0,     5,     0,     0,     0,     6,     7,     8,     9,
       0,     0,    10,    11,    12,    13,     0,    18,    14,    15,
       0,     0,    16,     0,     0,    17,     0,    19,     0,     2,
       3,     4,     0,     0,     0,     5,     0,     0,     0,     6,
       7,     8,     9,     0,     0,    10,    11,    12,    13,     0,
     126,    14,    15,     0,     0,    16,     0,     0,    17,     0,
     255,     2,     3,     4,     0,     0,     0,     5,     0,     0,
       0,     6,     7,     8,     9,     0,     0,    10,    11,    12,
      13,     3,     4,    14,    15,     0,     5,    16,     0,     0,
      17,     0,     8,     0,     0,     0,    10,    11,    12,    13,
       0,     0,    14,    15,     0,     0,    16
};

static const yytype_int16 yycheck[] =
{
      52,    52,     0,    59,    59,   135,   146,    18,    73,   117,
     118,     0,    23,    83,     6,    64,    66,    69,    83,    27,
      72,    72,    20,    65,    78,     6,    24,    25,    26,    81,
      82,    20,    40,     6,    19,    52,    86,    48,    46,    68,
      66,    47,    48,    66,    26,    19,    57,    99,    66,    34,
      67,    45,    46,    61,    36,    53,    99,    46,    84,    63,
      34,    84,    64,   117,    66,    69,    84,    63,   138,    40,
      63,    63,    61,   138,    80,    81,   141,   217,    49,   135,
     135,    73,    63,   137,    84,   150,   151,   152,   158,   159,
      63,    73,    84,   147,   202,     6,    73,    66,    83,    63,
      73,    70,    68,   211,   160,    82,    83,    64,    63,    66,
     175,   189,   190,   191,   192,   180,   127,   173,    64,    64,
      66,    66,   174,   179,    64,    66,    66,    68,   258,   118,
      84,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   202,    64,
     258,    66,    51,   138,   197,   198,   199,    42,    43,    44,
      64,   215,    66,    64,    78,    66,    49,    50,    74,    75,
     195,   196,   224,   158,   159,   187,   188,    79,    63,   193,
     194,   224,   158,   159,    69,    72,    71,    64,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,   263,   264,
      65,    70,   258,   258,    66,    68,    84,   261,    40,   207,
      64,   265,   266,     6,   270,     6,   268,   268,     6,     3,
       4,   275,     6,    64,     8,     9,    10,    11,    12,   283,
      14,   285,    16,    17,    18,    63,    20,    21,    22,    23,
      24,    15,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    84,    20,    43,
      44,    72,   174,   183,   185,   184,   138,   118,   186,    28,
      57,   207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,     3,     4,    -1,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    17,    18,    -1,
       3,     4,    -1,     6,    24,     8,     9,    -1,    -1,    -1,
      30,    31,    -1,    -1,    34,    35,    -1,    37,    38,    -1,
      40,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      63,    -1,    -1,    -1,    84,    85,    86,    -1,    -1,    72,
      73,    74,    75,    76,    77,     3,     4,    -1,     6,    -1,
       8,     9,    85,    86,    -1,    -1,    14,    -1,    -1,    17,
      18,    -1,     3,     4,    -1,     6,    24,     8,     9,    -1,
      -1,    -1,    30,    31,    -1,    -1,    34,    35,    -1,    37,
      38,    -1,    40,    -1,    -1,    43,    44,    -1,     3,     4,
      -1,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    63,     3,     4,    -1,     6,
      -1,     8,     9,    -1,    72,    73,    74,    75,    76,    77,
      -1,    -1,    63,    -1,    -1,    -1,    84,    85,    43,    44,
      -1,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    43,    44,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    63,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,
      77,    -1,    10,    11,    12,    -1,    -1,    84,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    -1,    36,    -1,
      -1,    39,    10,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    65,    36,     3,
       4,    39,     6,    -1,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    85,    22,    -1,
      -1,    -1,    26,    27,    28,    29,    -1,    -1,    32,    33,
      -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,     3,     4,    -1,     6,    85,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
       3,     4,    -1,     6,    -1,     8,     9,    -1,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,     3,     4,    -1,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    72,    73,    74,    75,    76,    77,    -1,    -1,
      63,    64,    -1,    -1,    -1,    43,    44,    -1,    -1,    72,
      73,    74,    75,    76,    77,     3,     4,    -1,     6,    -1,
       8,     9,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    73,    74,    75,    76,    77,
       3,     4,    -1,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,     3,     4,    -1,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      73,    74,    75,    76,    77,    -1,    -1,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    73,    74,    75,
      76,    77,     0,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    10,    11,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    -1,    -1,    26,    27,
      28,    29,    -1,    -1,    32,    33,    -1,    -1,    36,    -1,
       6,    39,    -1,    -1,    10,    11,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      26,    27,    28,    29,    -1,    63,    32,    33,    -1,    -1,
      36,    -1,     6,    39,    -1,    73,    10,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    26,    27,    28,    29,    -1,    63,    32,    33,
      -1,    -1,    36,    -1,    -1,    39,    -1,    73,    -1,    10,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    -1,    -1,    26,    27,    28,    29,    -1,
      64,    32,    33,    -1,    -1,    36,    -1,    -1,    39,    -1,
      41,    10,    11,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    -1,    -1,    26,    27,    28,
      29,    11,    12,    32,    33,    -1,    16,    36,    -1,    -1,
      39,    -1,    22,    -1,    -1,    -1,    26,    27,    28,    29,
      -1,    -1,    32,    33,    -1,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    10,    11,    12,    16,    20,    21,    22,    23,
      26,    27,    28,    29,    32,    33,    36,    39,    63,    73,
      88,    89,   122,   123,   124,   125,   126,   129,   130,   132,
     139,   129,   126,   130,   131,     0,    89,    84,   127,   128,
     129,   123,   123,   123,    85,   115,   121,   122,   123,   140,
     132,    63,    69,   142,    64,   126,   130,    66,    84,    65,
     115,   121,   115,   122,   129,     3,     4,     6,     8,     9,
      14,    17,    18,    24,    30,    31,    34,    35,    37,    38,
      40,    43,    44,    63,    72,    73,    74,    75,    76,    77,
      84,    86,    90,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   103,   104,   105,   106,   107,   108,   109,   110,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   141,
       6,    70,    92,    95,    96,     6,    64,   123,   133,   134,
     135,   136,   128,    94,   137,   140,   115,    68,    63,    96,
      84,    63,    92,    84,    93,    84,    63,    68,     6,   113,
      63,    63,    63,    96,    96,    93,   111,   112,   125,   126,
      66,    84,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    65,    91,    52,    67,    42,    43,    44,    63,
      69,    71,   100,    51,    78,    79,    72,    49,    50,    47,
      48,    80,    81,    45,    46,    74,    75,    73,    82,    83,
     113,   141,   120,   141,    70,   129,    64,    66,    64,    66,
     137,   138,   113,   111,    93,    68,    84,   116,   113,    84,
      40,    93,    93,    64,    64,   112,   112,    94,    94,   101,
      93,     6,    64,    94,   102,    93,     6,   103,   104,   105,
     106,   107,   107,   108,   108,   108,   108,   109,   109,   110,
     110,   100,   100,   100,   141,    41,   135,     6,    66,   141,
      64,    64,   113,   116,    63,    64,    64,   100,    68,    64,
      66,    70,   137,   141,   113,    64,    93,    93,   113,   113,
      95,    94,   113,    64,    64,    15,   113,    84,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   106,   107,   107,   107,   107,
     107,   108,   108,   108,   109,   109,   109,   110,   110,   110,
     110,   111,   112,   112,   112,   112,   113,   113,   113,   113,
     113,   113,   114,   114,   114,   115,   115,   115,   115,   116,
     116,   117,   117,   117,   118,   118,   118,   118,   119,   119,
     119,   119,   119,   120,   120,   121,   121,   122,   122,   123,
     123,   123,   123,   123,   123,   124,   124,   124,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   130,
     130,   131,   131,   132,   132,   132,   132,   132,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     137,   138,   138,   139,   139,   139,   139,   140,   141,   142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     5,     1,
       2,     2,     2,     2,     4,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     2,     3,     3,     4,     1,
       2,     5,     7,     5,     5,     7,     7,     6,     3,     2,
       2,     2,     3,     1,     2,     1,     2,     2,     3,     1,
       2,     1,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     2,     1,     1,     2,     2,
       3,     1,     2,     1,     3,     4,     3,     4,     4,     3,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     3,
       4,     1,     3,     4,     3,     3,     2,     1,     1,     1
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
#line 110 "src/c_bison.y" /* yacc.c:1646  */
    {
                                      (yyval.exp) = new IdentifierExpression((yyvsp[0].str));completeTree.push_back((yyval.exp));
                                    }
#line 1679 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 113 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new ConstantExpression((yyvsp[0].number));
                                      
                                      completeTree.push_back((yyval.exp));
                                    }
#line 1688 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 117 "src/c_bison.y" /* yacc.c:1646  */
    {
                                      (yyval.exp) = new ConstantExpression((yyvsp[0].number));
                                      completeTree.push_back((yyval.exp));
                                    }
#line 1697 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("=");}
#line 1703 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 132 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("*=");}
#line 1709 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 133 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("/=");}
#line 1715 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 134 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("%=");}
#line 1721 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 135 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("+=");}
#line 1727 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 136 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("-=");}
#line 1733 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 137 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("<<=");}
#line 1739 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 138 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator(">>=");}
#line 1745 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 139 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("&=");}
#line 1751 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 140 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("^=");}
#line 1757 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "src/c_bison.y" /* yacc.c:1646  */
    {(yyval.assign_op) = new AssignmentOperator("|=");}
#line 1763 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 153 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"assignment_expression"); }
#line 1769 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 154 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),",",(yyvsp[0].exp));}
#line 1775 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 159 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"conditional_expression"); completeTree.push_back((yyval.exp));}
#line 1781 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 160 "src/c_bison.y" /* yacc.c:1646  */
    { 
                                                                                            std::string iden="";
                                                                                            int single_case = 0;
                                                                                            for(int i=0;i<completeTree.size();i++){
                                                                                              if(completeTree[i]->getType() == "Constant"){
                                                                                                single_case++;
                                                                                              }
                                                                                              else if(completeTree[i]->getType() == "Identifier"){
                                                                                                iden = completeTree[i]->getName();
                                                                                                single_case++;
                                                                                              }
                                                                                            }
                                                                                            std::stack<Expression*> mystack;

                                                                                            /* handle single declaration, int x = 3, int x = a - ShuntingYard only works on Binary */

                                                                                            if(single_case == 2){
                                                                                              std::cout << "IDEN IDENTIFY " << iden << std::endl;
                                                                                              mips32.noDeclare_singleHandler(completeTree,iden);
                                                                                            }
                                                                                            else{
                                                                                              mips32.ShuntingYardAlgo(completeTree,mystack,debugMode,iden);
                                                                                            }
                                                                                            completeTree.clear();
                                                                                         }
#line 1811 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 191 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"logical_or_expression");completeTree.push_back((yyval.exp));}
#line 1817 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 195 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"postfix_expression");completeTree.push_back((yyval.exp));}
#line 1823 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 206 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"logical_and_expression");completeTree.push_back((yyval.exp));}
#line 1829 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 207 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"||",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1835 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 211 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"primary_expression");completeTree.push_back((yyval.exp));}
#line 1841 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 213 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new PostfixExpression((yyvsp[-2].exp)); (yyval.exp)->codeGen((yyvsp[-2].exp),mips32);functionCall = true;std::cout << "func call" << std::endl;}
#line 1847 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 217 "src/c_bison.y" /* yacc.c:1646  */
    {  }
#line 1853 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 224 "src/c_bison.y" /* yacc.c:1646  */
    { /*isMinus = true;*/}
#line 1859 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 229 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"unary_expression");completeTree.push_back((yyval.exp));}
#line 1865 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 237 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"inclusive_or_expression");completeTree.push_back((yyval.exp));}
#line 1871 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 238 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"&&",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1877 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 250 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"exclusive_or_expression");completeTree.push_back((yyval.exp));}
#line 1883 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 251 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"|",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1889 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 256 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"and_expression");completeTree.push_back((yyval.exp));}
#line 1895 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 257 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"^",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1901 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 262 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"equality_expression");completeTree.push_back((yyval.exp));}
#line 1907 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 263 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"&",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1913 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 268 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"relational_expression");completeTree.push_back((yyval.exp));}
#line 1919 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 269 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"==",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1925 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 270 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"!=",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1931 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 275 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"shift_expression");completeTree.push_back((yyval.exp));}
#line 1937 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 276 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"<",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1943 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 277 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),">",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1949 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 278 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"<=",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1955 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 279 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),">=",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1961 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 284 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"additive_expression");completeTree.push_back((yyval.exp));}
#line 1967 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 285 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"<<",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1973 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 286 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),">>",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1979 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 291 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"multiplicative_expression");completeTree.push_back((yyval.exp));}
#line 1985 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 292 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"+",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1991 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 293 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"-",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 1997 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 298 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new UnaryExpression((yyvsp[0].exp),"cast_expression");completeTree.push_back((yyval.exp));}
#line 2003 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 299 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"*",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 2009 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 300 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"/",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 2015 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 301 "src/c_bison.y" /* yacc.c:1646  */
    { (yyval.exp) = new BinaryExpression((yyvsp[-2].exp),"%",(yyvsp[0].exp));completeTree.push_back((yyval.exp));}
#line 2021 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 382 "src/c_bison.y" /* yacc.c:1646  */
    { mips32.returnHandler(completeTree); }
#line 2027 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 400 "src/c_bison.y" /* yacc.c:1646  */
    {
                                                                      if(debugMode){
                                                                        for(int i=0;i<scope_counter;i++){
                                                                          std::cout << "    " ;
                                                                        }
                                                                        std::cout << "VARIABLE : " << identifier_value << std::endl;
                                                                      }
                                                                      
                                                                   }
#line 2041 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 459 "src/c_bison.y" /* yacc.c:1646  */
    {
                                                                                          mips32.Insert((yyvsp[0].str));
                                                                                          completeTree.clear();
                                                                                        }
#line 2050 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 464 "src/c_bison.y" /* yacc.c:1646  */
    {
                                                                                          
                                                                                          int single_case = 0;
                                                                                          for(int i=0;i<completeTree.size();i++){
                                                                                            if(completeTree[i]->getType() == "Constant"){
                                                                                              single_case++;
                                                                                            }
                                                                                            else if(completeTree[i]->getType() == "Identifier"){
                                                                                              single_case++;
                                                                                            }
                                                                                          }
                                                                                          std::stack<Expression*> mystack;

                                                                                          /* handle single declaration, int x = 3, int x = a - ShuntingYard only works on Binary */
                                                                                          if(!functionCall){
                                                                                            if(single_case == 1){
                                                                                              std::cout << "hello world" << std::endl;
                                                                                              mips32.singleHandler(completeTree,(yyvsp[-2].str));
                                                                                            }
                                                                                            else{
                                                                                              mips32.ShuntingYardAlgo(completeTree,mystack,debugMode,(yyvsp[-2].str));
                                                                                            }
                                                                                            functionCall = false;
                                                                                          }
                                                                                          
                                                                                          completeTree.clear();
                                                                                        }
#line 2082 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 510 "src/c_bison.y" /* yacc.c:1646  */
    { 
                                                                                      identifier_value = (yyvsp[0].str);
                                                                                    }
#line 2090 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 539 "src/c_bison.y" /* yacc.c:1646  */
    { 
                                                                              int num = 0;
                                                                              mips32.InsertParams((yyvsp[0].str));
                                                                              if(debugMode){
                                                                                for(int i=0;i<scope_counter;i++){
                                                                                  std::cout << "    " ;
                                                                                }
                                                                                std::cout << "    PARAMS : " << (yyvsp[0].str) << std::endl;
                                                                              }
                                                                             completeTree.clear();
                                                                          }
#line 2106 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 573 "src/c_bison.y" /* yacc.c:1646  */
    {}
#line 2112 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 581 "src/c_bison.y" /* yacc.c:1646  */
    {  /*
                            for(int i=0;i<scope_counter;i++){
                              std::cout << "    " ;
                            }
                            scope_counter++; std::cout << "SCOPE" << std::endl;
                            */
                         }
#line 2124 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 590 "src/c_bison.y" /* yacc.c:1646  */
    {
                            scope_counter--;
                            std::cout << "      addiu $sp,$sp,1000" << std::endl;
                            std::cout << "      j     $31" << std::endl;
                            std::cout << "      nop" << std::endl;
                            std::cout << std::endl;
                            std::cout << "      .end  " << functionName << std::endl;
                          }
#line 2137 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 601 "src/c_bison.y" /* yacc.c:1646  */
    {
                        for(int i=0;i<scope_counter;i++){
                          std::cout << "    " ;
                        }
                          std::cout << "      .text" << std::endl;
                          std::cout << "      .align 2" << std::endl;
                          std::cout << "      .globl " << identifier_value << std::endl;
                          std::cout << "      .ent    " << identifier_value << std::endl;
                          std::cout << "      .type " << identifier_value << ",@function" << std::endl;
                          std::cout << identifier_value << ":" << std::endl;
                          std::cout << "       addiu  $sp,$sp,-1000" << std::endl;
                          if(debugMode){
                            std::cout << "FUNCTION : " << identifier_value << std::endl;  
                          }
                          functionName = identifier_value;
                      }
#line 2158 "c_bison.tab.c" /* yacc.c:1646  */
    break;


#line 2162 "c_bison.tab.c" /* yacc.c:1646  */
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
#line 621 "src/c_bison.y" /* yacc.c:1906  */



int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  std::stringstream ss;
  ss << yyparse();
}


