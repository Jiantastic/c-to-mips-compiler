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


#line 75 "c_bison.tab.c" /* yacc.c:339  */

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
#line 11 "src/c_bison.y" /* yacc.c:355  */

        int number;
        float float_num;
        char* str;

#line 183 "c_bison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "c_bison.tab.c" /* yacc.c:358  */

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1004

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  289

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
       2,     2,     2,     2,     2,     2,     2,     2,    67,    85,
      79,    64,    80,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    77,    84,    75,     2,     2,     2,
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
       0,    62,    62,    65,    66,    70,    71,    80,    81,    82,
      83,    86,    87,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   107,   114,   115,   120,   121,   127,
     128,   131,   132,   133,   134,   135,   136,   142,   143,   147,
     148,   149,   150,   151,   152,   153,   154,   157,   158,   159,
     160,   161,   162,   165,   166,   173,   174,   177,   178,   186,
     187,   192,   193,   198,   199,   204,   205,   206,   211,   212,
     213,   214,   215,   220,   221,   222,   227,   228,   229,   234,
     235,   236,   237,   247,   251,   252,   253,   254,   266,   267,
     268,   269,   270,   271,   277,   278,   279,   284,   285,   286,
     287,   292,   293,   298,   299,   300,   305,   306,   307,   308,
     313,   314,   315,   316,   317,   318,   319,   324,   325,   328,
     329,   336,   337,   343,   344,   345,   346,   347,   348,   352,
     353,   354,   355,   356,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   382,   383,   389,   390,   394,   395,   402,
     403,   406,   407,   408,   409,   413,   414,   417,   420,   421,
     422,   423,   424,   425,   429,   430,   433,   434,   445,   446,
     450,   451,   457,   458,   459,   462,   463,   471,   472,   473,
     474
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
  "'|'", "'^'", "'<'", "'>'", "'/'", "'%'", "'{'", "'}'", "';'", "$accept",
  "file", "translation_unit", "external_declaration", "primary_expression",
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
  "initializer", "initializer_list", "function_definition", YY_NULLPTR
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
      62,    47,    37,   123,   125,    59
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     911,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,     2,     9,
       6,   911,  -139,  -139,    16,   943,   943,   943,   652,     0,
      -1,  -139,    -5,  -139,  -139,     9,  -139,  -139,  -139,   -22,
    -139,   612,  -139,  -139,  -139,   228,  -139,   652,  -139,    16,
      -1,   156,   704,  -139,  -139,  -139,     2,  -139,   583,  -139,
     652,  -139,  -139,   -28,  -139,   792,   -20,    13,   798,   361,
      26,    21,    24,   111,   533,    58,    67,   839,   839,   689,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,   -19,  -139,  -139,   220,   -16,    56,   798,  -139,   113,
      72,   102,   129,   110,   -24,   124,   100,   -40,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,   385,   311,  -139,  -139,   106,
    -139,  -139,     2,   132,   136,  -139,    37,  -139,  -139,   134,
    -139,  -139,  -139,   583,  -139,  -139,  -139,   533,   689,  -139,
    -139,   798,   137,  -139,   -17,  -139,   435,   533,   120,   168,
     798,   798,   798,  -139,  -139,    40,   145,  -139,   969,   969,
     798,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,  -139,   798,   798,   798,   207,  -139,  -139,   745,
     798,   208,  -139,   798,   798,   798,   798,   798,   798,   798,
     798,   798,   798,   798,   798,   798,   798,   798,   798,   798,
    -139,  -139,  -139,   459,  -139,  -139,   868,  -139,   210,  -139,
    -139,   -47,  -139,   155,    43,   533,  -139,   435,  -139,  -139,
     159,    44,    49,  -139,   798,  -139,  -139,  -139,  -139,   113,
      54,  -139,  -139,  -139,    62,    15,  -139,    72,   102,   129,
     110,   -24,   -24,   124,   124,   124,   124,   100,   100,   -40,
     -40,  -139,  -139,  -139,  -139,  -139,  -139,  -139,   509,  -139,
    -139,   533,  -139,   751,   798,   533,   533,  -139,   798,  -139,
     798,  -139,  -139,  -139,  -139,   533,    92,    99,   209,  -139,
    -139,  -139,  -139,   533,   139,   533,  -139,  -139,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   157,   132,   140,   137,   138,   133,   129,   135,   130,
     143,   139,   136,   142,   141,   134,   144,   131,     0,   151,
       0,     2,     3,     6,     0,   123,   125,   127,     0,     0,
     150,     5,     0,   155,   153,   152,     1,     4,   121,     0,
     145,   147,   124,   126,   128,     0,   180,     0,   119,     0,
     149,     0,     0,   158,   156,   154,     0,   122,     0,   178,
       0,    11,    12,     7,     9,     0,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,    47,    48,    49,    50,    51,    52,    97,   101,    39,
       8,     0,    25,    27,    53,    29,    31,     0,    79,    37,
      55,    59,    61,    63,    65,    68,    73,    76,   117,    88,
      89,    90,    91,    92,    93,     0,     0,   179,   120,   147,
     170,   163,   169,     0,   164,   166,     0,     7,   160,     0,
      24,    53,   146,     0,   172,   148,   177,     0,     0,    35,
     112,     0,     0,   113,     0,   111,     0,     0,     0,     0,
       0,     0,     0,    32,    33,     0,     0,    83,    85,    87,
       0,   102,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    13,     0,     0,     0,     0,    45,    46,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,   118,    99,     0,   168,   161,     0,   162,     0,   159,
     175,     0,    94,     0,     0,     0,   114,     0,    96,   110,
       0,     0,     0,    10,     0,    84,    86,    26,    28,    38,
       0,    44,    41,    57,     0,     0,    43,    56,    60,    62,
      64,    66,    67,    71,    72,    69,    70,    74,    75,    77,
      78,    80,    81,    82,   100,   165,   167,   171,     0,   173,
      36,     0,    95,     0,     0,     0,     0,    54,     0,    42,
       0,    40,   174,   176,   105,     0,     0,     0,   103,   106,
      30,    58,   108,     0,     0,     0,   109,   107,   104
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,   201,  -139,  -139,  -139,   157,   -65,   -56,
     -51,   -52,  -139,  -139,  -139,   -45,    52,  -139,    46,    50,
      42,    60,    -2,   -96,    -4,    -3,   104,    38,   -55,  -139,
      10,  -138,  -139,  -139,  -139,   152,     8,    12,     3,  -139,
     -69,    -8,  -139,   184,    -9,     1,  -139,   223,  -139,  -139,
      63,  -139,  -102,  -139,  -139
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    89,    90,   173,   129,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   234,   100,   101,
     102,   103,   104,   105,   106,   107,   156,   157,   108,   109,
     110,   111,   112,   113,   114,   115,    47,    48,    49,    25,
      26,    27,    39,    40,    28,    29,    35,    30,   123,   124,
     125,   126,   135,   211,    31
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     131,   130,   134,    24,   144,     1,    36,     1,   217,    32,
     158,    33,    23,   139,   155,    41,   131,   130,   258,   149,
      34,     1,   189,   190,    24,   153,   154,    54,    42,    43,
      44,   210,   197,    23,    10,   174,    55,   259,    46,   137,
     119,   198,   199,    56,    16,   131,   160,   119,   160,    60,
     175,    59,   182,   116,   122,   191,   192,   117,    53,   118,
     201,    51,    18,    57,    18,   140,   161,    52,   216,   158,
     136,   159,   118,   155,    19,   141,   214,   134,    18,   263,
     160,    19,   212,   146,   271,   221,   222,   155,    19,   158,
     158,   147,   218,   243,   244,   245,   246,   176,   177,   178,
     207,    38,   208,   223,   227,   160,   261,   265,   160,   160,
     230,   145,   266,   204,   160,   235,   148,   228,   179,   160,
     150,   268,   131,   233,   180,   269,   181,   270,   118,   151,
     159,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   201,   184,
     159,   159,   251,   252,   253,   283,   273,   160,   187,   188,
     262,   120,   284,   183,   160,     2,     3,     4,   193,   194,
      58,     5,   131,   195,   196,     6,     7,     8,     9,   267,
     185,    10,    11,    12,    13,   241,   242,    14,    15,   247,
     248,    16,   249,   250,    17,   205,   225,   226,   276,   277,
     186,   206,   134,   209,   215,   219,   274,   220,   224,   122,
     278,   279,   231,   236,   281,   257,   131,   280,   260,   121,
     282,   264,    37,   285,   287,   142,   229,   239,   286,   237,
     288,    61,    62,    63,   238,    64,    65,     2,     3,     4,
     132,    66,   213,     5,    67,    68,   240,     6,     7,     8,
       9,    69,    50,    10,    11,    12,    13,    70,    71,    14,
      15,    72,    73,    16,    74,    75,    17,    76,   203,   256,
      77,    78,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,     0,     0,   172,     0,     0,     0,     0,     0,
      79,    80,     0,     0,     0,     0,     0,     0,     0,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
       0,    45,    87,    88,    61,    62,    63,     0,    64,    65,
       2,     3,     4,     0,    66,     0,     5,    67,    68,     0,
       6,     7,     8,     9,    69,     0,    10,    11,    12,    13,
      70,    71,    14,    15,    72,    73,    16,    74,    75,    17,
      76,     0,     0,    77,    78,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    62,   127,     0,    64,    65,
       0,     0,     0,    79,    80,     0,     0,     0,     0,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    61,    62,
      63,     0,    64,    65,    45,   202,    88,     0,    66,     0,
       0,    67,    68,    77,    78,     0,     0,     0,    69,     0,
       0,     0,     0,     0,    70,    71,     0,     0,    72,    73,
       0,    74,    75,    79,    76,     0,     0,    77,    78,     0,
       0,     0,    81,    82,    83,    84,    85,    86,    61,    62,
     127,     0,    64,    65,     0,     0,   143,    79,    80,     0,
       0,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    61,    62,    63,     0,    64,    65,    45,   200,
      88,     0,    66,     0,     0,    67,    68,    77,    78,     0,
       0,     0,    69,     0,     0,     0,     0,     0,    70,    71,
       0,     0,    72,    73,     0,    74,    75,    79,    76,     0,
       0,    77,    78,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    61,    62,   127,     0,    64,    65,     0,     0,
      88,    79,    80,     0,     0,     0,     0,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    61,    62,    63,     0,
      64,    65,    45,   254,    88,     0,    66,     0,     0,    67,
      68,    77,    78,     0,     0,     0,    69,     0,     0,     0,
       0,     0,    70,    71,     0,     0,    72,    73,     0,    74,
      75,    79,    76,     0,     0,    77,    78,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    61,    62,   127,     0,
      64,    65,   133,   272,     0,    79,    80,     0,     0,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,    45,     0,    88,     0,
       0,     2,     3,     4,     0,    77,    78,     5,     0,     0,
       0,     6,     7,     8,     9,     0,     0,    10,    11,    12,
      13,     0,     0,    14,    15,    79,     0,    16,     0,     0,
      17,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,     2,     3,     4,     0,     0,   133,     5,     0,     0,
       0,     6,     7,     8,     9,     0,    58,    10,    11,    12,
      13,     0,     0,    14,    15,     0,     0,    16,     0,     0,
      17,     0,    61,    62,   127,    45,    64,    65,     0,     3,
       4,     0,     0,     0,     5,     0,     0,    61,    62,   127,
       8,    64,    65,     0,    10,    11,    12,    13,     0,     0,
      14,    15,     0,     0,    16,     0,     0,     0,     0,     0,
       0,    77,    78,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    61,    62,
     127,    79,    64,    65,    61,    62,   127,     0,    64,    65,
      81,    82,    83,    84,    85,    86,    79,     0,     0,     0,
       0,     0,     0,   128,     0,    81,    82,    83,    84,    85,
      86,     0,     0,     0,     0,     0,     0,    77,    78,     0,
       0,     0,     0,    77,    78,    61,    62,   127,     0,    64,
      65,    61,    62,   127,     0,    64,    65,    79,   232,     0,
       0,     0,     0,    79,   275,     0,    81,    82,    83,    84,
      85,    86,    81,    82,    83,    84,    85,    86,     0,     0,
       0,     0,     0,     0,    77,    78,     0,     0,     0,     0,
      77,    78,    61,    62,   127,     0,    64,    65,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
      79,     0,     0,    81,    82,    83,    84,    85,    86,    81,
      82,    83,    84,    85,    86,     0,     0,     2,     3,     4,
       0,    77,    78,     5,     0,     0,     0,     6,     7,     8,
       9,     0,     0,    10,    11,    12,    13,     0,     0,    14,
      15,   152,     0,    16,     0,     0,    17,     0,   255,     0,
      81,    82,    83,    84,    85,    86,     1,     0,     0,     0,
       2,     3,     4,     0,     0,     0,     5,     0,     0,     0,
       6,     7,     8,     9,     0,     0,    10,    11,    12,    13,
       0,     0,    14,    15,     0,     0,    16,     0,     0,    17,
       0,     0,     2,     3,     4,     0,     0,     0,     5,     0,
       0,     0,     6,     7,     8,     9,     0,     0,    10,    11,
      12,    13,     0,    18,    14,    15,     0,     0,    16,     3,
       4,    17,     0,    19,     5,     0,     0,     0,     0,     0,
       8,     0,     0,     0,    10,    11,    12,    13,     0,     0,
      14,    15,     0,     0,    16
};

static const yytype_int16 yycheck[] =
{
      52,    52,    58,     0,    69,     5,     0,     5,   146,    18,
      79,    19,     0,    65,    79,    24,    68,    68,    65,    74,
      19,     5,    46,    47,    21,    77,    78,    35,    25,    26,
      27,   133,    72,    21,    25,    51,    35,    84,    28,    67,
      49,    81,    82,    65,    35,    97,    65,    56,    65,    41,
      66,    41,    97,    45,    51,    79,    80,    47,    63,    47,
     115,    62,    62,    85,    62,    85,    85,    68,    85,   138,
      60,    79,    60,   138,    72,    62,   141,   133,    62,   217,
      65,    72,   137,    62,    69,   150,   151,   152,    72,   158,
     159,    67,   147,   189,   190,   191,   192,    41,    42,    43,
      63,    85,    65,    63,   160,    65,    63,    63,    65,    65,
     175,    85,    63,   122,    65,   180,     5,   173,    62,    65,
      62,    67,   174,   179,    68,    63,    70,    65,   116,    62,
     138,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   203,    77,
     158,   159,   197,   198,   199,    63,   258,    65,    48,    49,
     215,     5,    63,    50,    65,     9,    10,    11,    44,    45,
      64,    15,   224,    73,    74,    19,    20,    21,    22,   224,
      78,    25,    26,    27,    28,   187,   188,    31,    32,   193,
     194,    35,   195,   196,    38,    63,   158,   159,   263,   264,
      71,    65,   258,    69,    67,    85,   261,    39,    63,   206,
     265,   266,     5,     5,   270,     5,   268,   268,    63,    63,
     275,    62,    21,    14,    85,    68,   174,   185,   283,   183,
     285,     3,     4,     5,   184,     7,     8,     9,    10,    11,
      56,    13,   138,    15,    16,    17,   186,    19,    20,    21,
      22,    23,    29,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   116,   206,
      42,    43,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,     3,     4,
       5,    -1,     7,     8,    83,    84,    85,    -1,    13,    -1,
      -1,    16,    17,    42,    43,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    -1,    -1,    29,    30,    -1,    -1,    33,    34,
      -1,    36,    37,    62,    39,    -1,    -1,    42,    43,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,     3,     4,
       5,    -1,     7,     8,    -1,    -1,    85,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,     3,     4,     5,    -1,     7,     8,    83,    84,
      85,    -1,    13,    -1,    -1,    16,    17,    42,    43,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    33,    34,    -1,    36,    37,    62,    39,    -1,
      -1,    42,    43,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      85,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,     3,     4,     5,    -1,
       7,     8,    83,    84,    85,    -1,    13,    -1,    -1,    16,
      17,    42,    43,    -1,    -1,    -1,    23,    -1,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    33,    34,    -1,    36,
      37,    62,    39,    -1,    -1,    42,    43,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,     3,     4,     5,    -1,
       7,     8,    83,    84,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    85,    -1,
      -1,     9,    10,    11,    -1,    42,    43,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    -1,    31,    32,    62,    -1,    35,    -1,    -1,
      38,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,     9,    10,    11,    -1,    -1,    83,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    -1,    64,    25,    26,    27,
      28,    -1,    -1,    31,    32,    -1,    -1,    35,    -1,    -1,
      38,    -1,     3,     4,     5,    83,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    15,    -1,    -1,     3,     4,     5,
      21,     7,     8,    -1,    25,    26,    27,    28,    -1,    -1,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,     3,     4,
       5,    62,     7,     8,     3,     4,     5,    -1,     7,     8,
      71,    72,    73,    74,    75,    76,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    -1,    71,    72,    73,    74,    75,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    -1,    42,    43,     3,     4,     5,    -1,     7,
       8,     3,     4,     5,    -1,     7,     8,    62,    63,    -1,
      -1,    -1,    -1,    62,    63,    -1,    71,    72,    73,    74,
      75,    76,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,    -1,
      42,    43,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      62,    -1,    -1,    71,    72,    73,    74,    75,    76,    71,
      72,    73,    74,    75,    76,    -1,    -1,     9,    10,    11,
      -1,    42,    43,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,
      32,    62,    -1,    35,    -1,    -1,    38,    -1,    40,    -1,
      71,    72,    73,    74,    75,    76,     5,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    -1,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    -1,    25,    26,    27,    28,
      -1,    -1,    31,    32,    -1,    -1,    35,    -1,    -1,    38,
      -1,    -1,     9,    10,    11,    -1,    -1,    -1,    15,    -1,
      -1,    -1,    19,    20,    21,    22,    -1,    -1,    25,    26,
      27,    28,    -1,    62,    31,    32,    -1,    -1,    35,    10,
      11,    38,    -1,    72,    15,    -1,    -1,    -1,    -1,    -1,
      21,    -1,    -1,    -1,    25,    26,    27,    28,    -1,    -1,
      31,    32,    -1,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     9,    10,    11,    15,    19,    20,    21,    22,
      25,    26,    27,    28,    31,    32,    35,    38,    62,    72,
      87,    88,    89,   123,   124,   125,   126,   127,   130,   131,
     133,   140,   130,   127,   131,   132,     0,    89,    85,   128,
     129,   130,   124,   124,   124,    83,   116,   122,   123,   124,
     133,    62,    68,    63,   127,   131,    65,    85,    64,   116,
     122,     3,     4,     5,     7,     8,    13,    16,    17,    23,
      29,    30,    33,    34,    36,    37,    39,    42,    43,    62,
      63,    71,    72,    73,    74,    75,    76,    84,    85,    90,
      91,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     104,   105,   106,   107,   108,   109,   110,   111,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   116,   123,   130,
       5,    63,   124,   134,   135,   136,   137,     5,    69,    93,
      96,    97,   129,    83,    95,   138,   116,    67,    62,    97,
      85,    62,    93,    85,    94,    85,    62,    67,     5,   114,
      62,    62,    62,    97,    97,    94,   112,   113,   126,   127,
      65,    85,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    64,    92,    51,    66,    41,    42,    43,    62,
      68,    70,   101,    50,    77,    78,    71,    48,    49,    46,
      47,    79,    80,    44,    45,    73,    74,    72,    81,    82,
      84,   114,    84,   121,   130,    63,    65,    63,    65,    69,
     138,   139,   114,   112,    94,    67,    85,   117,   114,    85,
      39,    94,    94,    63,    63,   113,   113,    95,    95,   102,
      94,     5,    63,    95,   103,    94,     5,   104,   105,   106,
     107,   108,   108,   109,   109,   109,   109,   110,   110,   111,
     111,   101,   101,   101,    84,    40,   136,     5,    65,    84,
      63,    63,   114,   117,    62,    63,    63,   101,    67,    63,
      65,    69,    84,   138,   114,    63,    94,    94,   114,   114,
      96,    95,   114,    63,    63,    14,   114,    85,   114
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    90,    90,    90,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   106,   106,   107,   107,   107,   108,   108,
     108,   108,   108,   109,   109,   109,   110,   110,   110,   111,
     111,   111,   111,   112,   113,   113,   113,   113,   114,   114,
     114,   114,   114,   114,   115,   115,   115,   116,   116,   116,
     116,   117,   117,   118,   118,   118,   119,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   124,   124,   124,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   131,   131,   132,   132,   133,   133,   133,
     133,   133,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   138,   139,   139,   140,   140,   140,
     140
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       5,     1,     2,     2,     2,     2,     4,     1,     3,     1,
       4,     3,     4,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     3,
       4,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     1,     1,     2,     1,
       2,     2,     3,     1,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     2,
       1,     1,     2,     2,     3,     1,     2,     1,     3,     4,
       3,     4,     4,     3,     1,     3,     1,     3,     2,     1,
       1,     3,     1,     3,     4,     1,     3,     4,     3,     3,
       2
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
        case 7:
#line 80 "src/c_bison.y" /* yacc.c:1646  */
    { std::cout << "ASSIGNMENSST" << (yyvsp[0].str) << std::endl ;}
#line 1656 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 285 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "compound_test1" << std::endl;}
#line 1662 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 286 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "compound_test2" << std::endl;}
#line 1668 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 287 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "compound_test3" << std::endl;}
#line 1674 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 305 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout<<"test"<<std::endl;}
#line 1680 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 318 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "ewasadasdasd" << std::endl;}
#line 1686 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 319 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "ewasadasdasd" << std::endl;}
#line 1692 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 324 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "doI?" << std::endl;}
#line 1698 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 325 "src/c_bison.y" /* yacc.c:1646  */
    {std::cout << "doI?" << std::endl;}
#line 1704 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 417 "src/c_bison.y" /* yacc.c:1646  */
    { 
                                                                                        std::cout << "VARIABLEZZZ : " << (yyvsp[0].str) << std:: endl;
                                                                                    }
#line 1712 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 450 "src/c_bison.y" /* yacc.c:1646  */
    { std::cout << "VARIABLE2 : " << (yyvsp[0].str) << std::endl;}
#line 1718 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 451 "src/c_bison.y" /* yacc.c:1646  */
    { std::cout << "VARIABLE3 : " << (yyvsp[0].str) << std::endl;}
#line 1724 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 471 "src/c_bison.y" /* yacc.c:1646  */
    { std::cout << "FUNCTION : " << std::endl;}
#line 1730 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 472 "src/c_bison.y" /* yacc.c:1646  */
    { std::cout << "FUNCTION : " << std::endl;}
#line 1736 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 473 "src/c_bison.y" /* yacc.c:1646  */
    { std::cout << "function3 end" << std::endl;}
#line 1742 "c_bison.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 474 "src/c_bison.y" /* yacc.c:1646  */
    { std::cout << "function4 end" << std::endl;}
#line 1748 "c_bison.tab.c" /* yacc.c:1646  */
    break;


#line 1752 "c_bison.tab.c" /* yacc.c:1646  */
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
#line 480 "src/c_bison.y" /* yacc.c:1906  */


int yyerror(const char* s){ 
    std::cout << s << std::endl;
    return -1;
}

int main(void) {
  yyparse();
}
