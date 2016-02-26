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

int yylex();
int yyerror(const char* s);
char* identifier_value;
int scope_counter = 0;
int is_function = 0;

#line 77 "c_bison.tab.c" /* yacc.c:339  */

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
#line 13 "src/c_bison.y" /* yacc.c:355  */

        int number;
        float float_num;
        char* str;

#line 185 "c_bison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "c_bison.tab.c" /* yacc.c:358  */

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
#define YYLAST   888

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

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
      62,    63,    72,    73,    65,    74,    70,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    83,
      79,    64,    80,    66,     2,     2,     2,     2,     2,     2,
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
       0,    66,    66,    67,    70,    71,    82,    83,    84,    85,
      88,    89,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   108,   115,   116,   121,   122,   128,   129,
     132,   133,   134,   135,   136,   137,   143,   144,   148,   149,
     150,   151,   152,   153,   154,   155,   158,   159,   160,   161,
     162,   163,   166,   167,   174,   175,   178,   179,   187,   188,
     193,   194,   199,   200,   205,   206,   207,   212,   213,   214,
     215,   216,   221,   222,   223,   228,   229,   230,   235,   236,
     237,   238,   248,   252,   253,   254,   255,   267,   268,   269,
     270,   271,   272,   278,   279,   280,   285,   286,   287,   288,
     293,   294,   299,   300,   301,   306,   307,   308,   309,   314,
     315,   316,   317,   318,   323,   324,   327,   328,   335,   336,
     346,   347,   348,   349,   350,   351,   354,   355,   356,   357,
     358,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     382,   383,   388,   389,   392,   393,   399,   400,   403,   404,
     405,   406,   409,   410,   413,   414,   415,   416,   417,   418,
     419,   424,   425,   428,   429,   440,   446,   449,   450,   456,
     457,   458,   461,   462,   468,   469,   470,   471,   477,   485,
     489
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
  "XOR_ASSIGNMENT", "OR_ASSIGNMENT", "'('", "')'", "'='", "','", "'?'",
  "':'", "'['", "']'", "'.'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'|'", "'^'", "'<'", "'>'", "'/'", "'%'", "';'", "'{'", "'}'", "$accept",
  "translation_unit", "external_declaration", "primary_expression",
  "CONSTANT", "assignment_operator", "constant_expression", "expression",
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
     315,   316,    40,    41,    61,    44,    63,    58,    91,    93,
      46,    38,    42,    43,    45,   126,    33,   124,    94,    60,
      62,    47,    37,    59,   123,   125
};
# endif

#define YYPACT_NINF -132

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-132)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     815,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,     4,   -11,
     783,  -132,  -132,    11,   157,   157,   157,   495,    34,    39,
    -132,   -23,  -132,  -132,   -11,  -132,  -132,  -132,   -32,  -132,
     465,  -132,  -132,  -132,  -132,  -132,   495,  -132,    11,   231,
      39,     5,   573,   157,  -132,  -132,  -132,     4,  -132,   287,
    -132,   495,  -132,  -132,   -57,  -132,  -132,   -17,  -132,   665,
     -20,    10,   688,   154,    -4,    27,    42,    94,   379,    64,
      87,   706,   706,   531,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,   -30,  -132,  -132,   371,    -9,   257,
     688,  -132,   102,    78,    82,    99,   116,    23,   136,   113,
     -35,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   305,   231,
    -132,  -132,  -132,    -1,  -132,  -132,   121,  -132,  -132,     4,
     131,   133,  -132,  -132,  -132,  -132,   287,  -132,   379,   531,
    -132,  -132,   688,   139,  -132,   -27,  -132,   396,   379,   125,
     180,   688,   688,   688,  -132,  -132,    19,   159,  -132,   691,
     691,   688,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,
    -132,  -132,  -132,  -132,   688,   688,   688,   219,  -132,  -132,
     591,   688,   227,  -132,   688,   688,   688,   688,   688,   688,
     688,   688,   688,   688,   688,   688,   688,   688,   688,   688,
     688,  -132,  -132,   305,  -132,  -132,   238,  -132,  -132,  -132,
     848,  -132,   -42,  -132,   182,    45,   379,  -132,   396,  -132,
    -132,   187,    56,    57,  -132,   688,  -132,  -132,  -132,  -132,
     102,    60,  -132,  -132,  -132,   106,    35,  -132,    78,    82,
      99,   116,    23,    23,   136,   136,   136,   136,   113,   113,
     -35,   -35,  -132,  -132,  -132,  -132,  -132,  -132,  -132,   281,
    -132,  -132,   379,  -132,   614,   688,   379,   379,  -132,   688,
    -132,   688,  -132,  -132,  -132,  -132,   379,   128,   142,   241,
    -132,  -132,  -132,  -132,   379,   192,   379,  -132,  -132,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   154,   129,   137,   134,   135,   130,   126,   132,   127,
     140,   136,   133,   139,   138,   131,   141,   128,     0,   148,
       0,     2,     4,     0,   120,   122,   124,     0,     0,   147,
       5,     0,   152,   150,   149,     1,     3,   118,     0,   142,
     144,   121,   123,   125,   178,   177,     0,   116,     0,     0,
     146,   180,     0,     0,   155,   153,   151,     0,   119,     0,
     175,     0,   176,   117,   144,    10,    11,     6,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,    49,    50,    51,
     100,   179,    38,     7,     0,    24,    26,    52,    28,    30,
       0,    78,    36,    54,    58,    60,    62,    64,    67,    72,
      75,   114,    87,    88,    89,    90,    91,    92,     0,     0,
      96,   167,   160,     0,     6,   157,     0,    23,    52,   166,
       0,   161,   163,   143,   169,   145,     0,   174,     0,     0,
      34,   111,     0,     0,   112,     0,   110,     0,     0,     0,
       0,     0,     0,     0,    31,    32,     0,     0,    82,    84,
      86,     0,   101,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    12,     0,     0,     0,     0,    44,    45,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,    97,     0,    98,   159,     0,   156,   165,   158,
       0,   172,     0,    93,     0,     0,     0,   113,     0,    95,
     109,     0,     0,     0,     9,     0,    83,    85,    25,    27,
      37,     0,    43,    40,    56,     0,     0,    42,    55,    59,
      61,    63,    65,    66,    70,    71,    68,    69,    73,    74,
      76,    77,    79,    80,    81,    99,   168,   162,   164,     0,
     170,    35,     0,    94,     0,     0,     0,     0,    53,     0,
      41,     0,    39,   173,   171,   104,     0,     0,     0,   102,
     105,    29,    57,   108,     0,     0,     0,   107,   106,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,   256,  -132,  -132,  -132,   205,   -65,   -56,   -51,
     -52,  -132,  -132,  -132,   -69,   103,  -132,    95,    96,    97,
      93,    13,   -78,    16,    24,   143,   112,   -53,  -132,    14,
    -128,  -132,  -132,  -132,   168,    18,    32,     2,  -132,   -68,
      15,  -132,   239,   -12,    25,  -132,   269,  -132,  -132,    91,
    -132,  -131,  -132,  -132,   -55,  -106,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    92,    93,   174,   126,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   235,   103,   104,   105,
     106,   107,   108,   109,   110,   157,   158,   111,   112,   113,
     114,   115,   116,   117,   118,    46,    47,    48,    24,    25,
      26,    38,    39,    27,    28,    34,    29,   130,   131,   132,
     123,   135,   212,    30,    49,   120,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     128,   127,    23,   134,   136,   211,    31,    59,   145,     1,
     121,    40,   202,   204,    10,   159,     1,   140,   156,   218,
     128,   127,    23,   259,    16,   150,    41,    42,    43,   154,
     155,   183,    22,    57,    32,   161,    64,   198,   161,     1,
      54,    45,   175,    91,    33,    64,   199,   200,   128,    55,
     138,    58,    22,   162,    60,   129,   217,   176,    61,    56,
      62,    19,   205,   141,   206,   201,    18,   119,   122,   190,
     191,   159,   142,    18,   156,   137,    19,   215,    63,   146,
     134,   136,   224,    19,   161,   213,   222,   223,   156,   147,
     264,   159,   159,    63,    37,   219,    18,   255,   160,   149,
     161,    51,   192,   193,   272,   228,   260,    52,   262,   148,
     161,   231,   244,   245,   246,   247,   236,   208,   229,   266,
     267,   161,   161,   128,   234,   161,   151,   269,   273,   252,
     253,   254,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   152,
     201,    63,   184,   274,   160,   185,   268,    65,    66,   124,
     186,    68,    69,   263,   188,   189,     2,     3,     4,   270,
     187,   271,     5,   128,   160,   160,     6,     7,     8,     9,
     194,   195,    10,    11,    12,    13,   196,   197,    14,    15,
     207,   284,    16,   161,   209,    17,    81,    82,   210,   277,
     278,   242,   243,   134,   136,   285,   216,   161,   220,   275,
     248,   249,   129,   279,   280,   282,    83,   128,   281,   221,
     250,   251,   225,   283,   232,    84,    85,    86,    87,    88,
      89,   287,   237,   289,    65,    66,    67,   144,    68,    69,
       2,     3,     4,   256,    70,   261,     5,    71,    72,   265,
       6,     7,     8,     9,    73,   286,    10,    11,    12,    13,
      74,    75,    14,    15,    76,    77,    16,    78,    79,    17,
      80,   226,   227,    81,    82,   288,    36,   143,   230,   238,
     241,   239,   214,   240,    65,    66,   124,   203,    68,    69,
      65,    66,   124,    83,    68,    69,   133,    50,   177,   178,
     179,   258,    84,    85,    86,    87,    88,    89,    65,    66,
      67,     0,    68,    69,    90,    44,    91,     0,    70,   180,
       0,    71,    72,    81,    82,   181,     0,   182,    73,    81,
      82,     0,     0,     0,    74,    75,     0,     0,    76,    77,
       0,    78,    79,    83,    80,     0,     0,    81,    82,    83,
       0,     0,    84,    85,    86,    87,    88,    89,    84,    85,
      86,    87,    88,    89,     0,    44,    91,    83,     0,     0,
       0,    44,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    65,    66,    67,     0,    68,    69,    90,    44,
      91,     0,    70,     0,     0,    71,    72,     0,     0,    65,
      66,   124,    73,    68,    69,     0,     0,     0,    74,    75,
       0,     0,    76,    77,     0,    78,    79,     0,    80,     0,
       0,    81,    82,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,     0,     0,   173,     0,     0,    81,    82,
       0,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,    87,    88,    89,     0,     0,    83,     0,
       0,     0,    90,    44,     0,     0,     0,    84,    85,    86,
      87,    88,    89,     0,     2,     3,     4,     0,     0,    90,
       5,     0,     0,     0,     6,     7,     8,     9,     0,     0,
      10,    11,    12,    13,     0,     0,    14,    15,     0,     0,
      16,     0,     0,    17,     2,     3,     4,     0,     0,     0,
       5,     0,     0,     0,     6,     7,     8,     9,     0,     0,
      10,    11,    12,    13,     0,     0,    14,    15,     0,    59,
      16,     0,     0,    17,    65,    66,   124,     0,    68,    69,
       0,     3,     4,     0,     0,     0,     5,     0,     0,    44,
       0,     0,     8,     0,     0,     0,    10,    11,    12,    13,
       0,     0,    14,    15,     0,     0,    16,     0,     0,     0,
       0,     0,     0,    81,    82,     0,    65,    66,   124,    44,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,    65,    66,   124,     0,    68,    69,
       0,     0,    84,    85,    86,    87,    88,    89,     0,     0,
       0,     0,     0,     0,     0,    81,    82,    65,    66,   124,
       0,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,    82,    83,     0,     0,     0,     0,
       0,     0,   125,     0,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    83,   233,     0,    81,    82,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    65,    66,
     124,     0,    68,    69,     0,     0,    83,   276,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    65,    66,   124,     0,    68,    69,     0,     0,     0,
       0,     3,     4,     0,     0,     0,     5,    81,    82,    65,
      66,   124,     8,    68,    69,     0,    10,    11,    12,    13,
       0,     0,    14,    15,     0,     0,    16,   139,     0,     0,
      81,    82,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,     0,     0,     0,   153,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    35,     0,     0,     0,     0,     1,     0,
       0,     0,     2,     3,     4,     0,     0,     0,     5,     0,
       0,     0,     6,     7,     8,     9,     0,     0,    10,    11,
      12,    13,     0,     0,    14,    15,     0,     0,    16,     0,
       1,    17,     0,     0,     2,     3,     4,     0,     0,     0,
       5,     0,     0,     0,     6,     7,     8,     9,     0,     0,
      10,    11,    12,    13,     0,    18,    14,    15,     0,     0,
      16,     0,     0,    17,     0,    19,     0,     2,     3,     4,
       0,     0,     0,     5,     0,     0,     0,     6,     7,     8,
       9,     0,     0,    10,    11,    12,    13,    18,     0,    14,
      15,     0,     0,    16,     0,     0,    17,    19,   257
};

static const yytype_int16 yycheck[] =
{
      52,    52,     0,    59,    59,   136,    18,    64,    73,     5,
       5,    23,   118,   119,    25,    83,     5,    69,    83,   147,
      72,    72,    20,    65,    35,    78,    24,    25,    26,    81,
      82,   100,     0,    65,    19,    65,    48,    72,    65,     5,
      63,    27,    51,    85,    19,    57,    81,    82,   100,    34,
      67,    83,    20,    83,    40,    53,    83,    66,    40,    34,
      46,    72,    63,    83,    65,   118,    62,    49,    63,    46,
      47,   139,    62,    62,   139,    61,    72,   142,    46,    83,
     136,   136,    63,    72,    65,   138,   151,   152,   153,    62,
     218,   159,   160,    61,    83,   148,    62,   203,    83,     5,
      65,    62,    79,    80,    69,   161,   212,    68,    63,    67,
      65,   176,   190,   191,   192,   193,   181,   129,   174,    63,
      63,    65,    65,   175,   180,    65,    62,    67,   259,   198,
     199,   200,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,    62,
     203,   119,    50,   259,   139,    77,   225,     3,     4,     5,
      78,     7,     8,   216,    48,    49,     9,    10,    11,    63,
      71,    65,    15,   225,   159,   160,    19,    20,    21,    22,
      44,    45,    25,    26,    27,    28,    73,    74,    31,    32,
      69,    63,    35,    65,    63,    38,    42,    43,    65,   264,
     265,   188,   189,   259,   259,    63,    67,    65,    83,   262,
     194,   195,   210,   266,   267,   271,    62,   269,   269,    39,
     196,   197,    63,   276,     5,    71,    72,    73,    74,    75,
      76,   284,     5,   286,     3,     4,     5,    83,     7,     8,
       9,    10,    11,     5,    13,    63,    15,    16,    17,    62,
      19,    20,    21,    22,    23,    14,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   159,   160,    42,    43,    83,    20,    72,   175,   184,
     187,   185,   139,   186,     3,     4,     5,   119,     7,     8,
       3,     4,     5,    62,     7,     8,    57,    28,    41,    42,
      43,   210,    71,    72,    73,    74,    75,    76,     3,     4,
       5,    -1,     7,     8,    83,    84,    85,    -1,    13,    62,
      -1,    16,    17,    42,    43,    68,    -1,    70,    23,    42,
      43,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    62,    39,    -1,    -1,    42,    43,    62,
      -1,    -1,    71,    72,    73,    74,    75,    76,    71,    72,
      73,    74,    75,    76,    -1,    84,    85,    62,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,     3,     4,     5,    -1,     7,     8,    83,    84,
      85,    -1,    13,    -1,    -1,    16,    17,    -1,    -1,     3,
       4,     5,    23,     7,     8,    -1,    -1,    -1,    29,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    -1,    39,    -1,
      -1,    42,    43,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    64,    -1,    -1,    42,    43,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    -1,    62,    -1,
      -1,    -1,    83,    84,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,     9,    10,    11,    -1,    -1,    83,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    31,    32,    -1,    -1,
      35,    -1,    -1,    38,     9,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
      25,    26,    27,    28,    -1,    -1,    31,    32,    -1,    64,
      35,    -1,    -1,    38,     3,     4,     5,    -1,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    15,    -1,    -1,    84,
      -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,    28,
      -1,    -1,    31,    32,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    -1,     3,     4,     5,    84,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,     3,     4,     5,
      -1,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    62,    63,    -1,    42,    43,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,
      76,     3,     4,     5,    -1,     7,     8,    -1,    -1,    -1,
      -1,    10,    11,    -1,    -1,    -1,    15,    42,    43,     3,
       4,     5,    21,     7,     8,    -1,    25,    26,    27,    28,
      -1,    -1,    31,    32,    -1,    -1,    35,    62,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,     0,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,    26,
      27,    28,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,
       5,    38,    -1,    -1,     9,    10,    11,    -1,    -1,    -1,
      15,    -1,    -1,    -1,    19,    20,    21,    22,    -1,    -1,
      25,    26,    27,    28,    -1,    62,    31,    32,    -1,    -1,
      35,    -1,    -1,    38,    -1,    72,    -1,     9,    10,    11,
      -1,    -1,    -1,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    25,    26,    27,    28,    62,    -1,    31,
      32,    -1,    -1,    35,    -1,    -1,    38,    72,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     9,    10,    11,    15,    19,    20,    21,    22,
      25,    26,    27,    28,    31,    32,    35,    38,    62,    72,
      87,    88,   122,   123,   124,   125,   126,   129,   130,   132,
     139,   129,   126,   130,   131,     0,    88,    83,   127,   128,
     129,   123,   123,   123,    84,   115,   121,   122,   123,   140,
     132,    62,    68,   142,    63,   126,   130,    65,    83,    64,
     115,   121,   115,   122,   129,     3,     4,     5,     7,     8,
      13,    16,    17,    23,    29,    30,    33,    34,    36,    37,
      39,    42,    43,    62,    71,    72,    73,    74,    75,    76,
      83,    85,    89,    90,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   103,   104,   105,   106,   107,   108,   109,
     110,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     141,     5,    63,   136,     5,    69,    92,    95,    96,   123,
     133,   134,   135,   128,    94,   137,   140,   115,    67,    62,
      96,    83,    62,    92,    83,    93,    83,    62,    67,     5,
     113,    62,    62,    62,    96,    96,    93,   111,   112,   125,
     126,    65,    83,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    64,    91,    51,    66,    41,    42,    43,
      62,    68,    70,   100,    50,    77,    78,    71,    48,    49,
      46,    47,    79,    80,    44,    45,    73,    74,    72,    81,
      82,   113,   141,   120,   141,    63,    65,    69,   129,    63,
      65,   137,   138,   113,   111,    93,    67,    83,   116,   113,
      83,    39,    93,    93,    63,    63,   112,   112,    94,    94,
     101,    93,     5,    63,    94,   102,    93,     5,   103,   104,
     105,   106,   107,   107,   108,   108,   108,   108,   109,   109,
     110,   110,   100,   100,   100,   141,     5,    40,   135,    65,
     141,    63,    63,   113,   116,    62,    63,    63,   100,    67,
      63,    65,    69,   137,   141,   113,    63,    93,    93,   113,
     113,    95,    94,   113,    63,    63,    14,   113,    83,   113
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    88,    88,    89,    89,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    96,    96,    96,    96,    97,    97,    98,    98,
      98,    98,    98,    98,    98,    98,    99,    99,    99,    99,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   106,   106,   106,   107,   107,   107,
     107,   107,   108,   108,   108,   109,   109,   109,   110,   110,
     110,   110,   111,   112,   112,   112,   112,   113,   113,   113,
     113,   113,   113,   114,   114,   114,   115,   115,   115,   115,
     116,   116,   117,   117,   117,   118,   118,   118,   118,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   123,   123,   123,   123,   124,   124,   124,   124,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   126,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     132,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   137,   138,   138,   139,   139,   139,   139,   140,   141,
     142
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     5,
       1,     2,     2,     2,     2,     4,     1,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     3,     4,
       1,     2,     5,     7,     5,     5,     7,     7,     6,     3,
       2,     2,     2,     3,     1,     2,     1,     2,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     2,     1,     1,     2,
       2,     3,     1,     2,     1,     3,     4,     3,     4,     4,
       3,     1,     3,     1,     3,     2,     1,     1,     3,     1,
       3,     4,     1,     3,     4,     3,     3,     2,     1,     1,
       1
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
        case 119:
#line 336 "src/c_bison.y" /* yacc.c:1646  */
    {
                                                                      for(int i=0;i<scope_counter;i++){
                                                                        std::cout << "    " ;
                                                                      }
                                                                      std::cout << "VARIABLE : " << identifier_value << std::endl;
                                                                   }
#line 1640 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 413 "src/c_bison.y" /* yacc.c:1646  */
    { identifier_value = (yyvsp[0].str); }
#line 1646 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 440 "src/c_bison.y" /* yacc.c:1646  */
    {
                                                                              for(int i=0;i<scope_counter;i++){
                                                                                std::cout << "    " ;
                                                                              }
                                                                              std::cout << "    PARAMS : " << (yyvsp[0].str) << std::endl;
                                                                          }
#line 1657 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 477 "src/c_bison.y" /* yacc.c:1646  */
    {
                            for(int i=0;i<scope_counter;i++){
                              std::cout << "    " ;
                            }
                            scope_counter++; std::cout << "SCOPE" << std::endl;
                         }
#line 1668 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 485 "src/c_bison.y" /* yacc.c:1646  */
    {scope_counter--;}
#line 1674 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 489 "src/c_bison.y" /* yacc.c:1646  */
    {
                        for(int i=0;i<scope_counter;i++){
                          std::cout << "    " ;
                        }
                        std::cout << "FUNCTION : " << identifier_value << std::endl;
                      }
#line 1685 "c_bison.tab.c" /* yacc.c:1646  */
    break;


#line 1689 "c_bison.tab.c" /* yacc.c:1646  */
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
#line 499 "src/c_bison.y" /* yacc.c:1906  */


int yyerror(const char* s){ 
    std::cout << s << std::endl;
    yyparse();
}

int main(void) {
  yyparse();
}
