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
#line 25 "scalix.y" /* yacc.c:339  */

#include "scalix.h"     /* les definition des types et les etiquettes des noeuds */

extern int yylex();	/* fournie par Flex */
extern void yyerror();  /* definie dans tp.c */

#line 73 "scalix_y.c" /* yacc.c:339  */

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
   by #include "scalix_y.h".  */
#ifndef YY_YY_SCALIX_Y_H_INCLUDED
# define YY_YY_SCALIX_Y_H_INCLUDED
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
    IF = 258,
    THEN = 259,
    ELSE = 260,
    ADD = 261,
    SUB = 262,
    MUL = 263,
    DIV = 264,
    AFFECT = 265,
    SCOL = 266,
    AND = 267,
    BRACO = 268,
    BRACC = 269,
    COMA = 270,
    CBRACO = 271,
    CBRACC = 272,
    CLASS = 273,
    EXT = 274,
    IS = 275,
    OBJ = 276,
    NEW = 277,
    OVR = 278,
    DEF = 279,
    STRG = 280,
    RETURN = 281,
    POINT = 282,
    VAR = 283,
    COL = 284,
    ID = 285,
    IDCLASS = 286,
    CST = 287,
    RELOP = 288,
    unary = 289
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SCALIX_Y_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 154 "scalix_y.c" /* yacc.c:358  */

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   228

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    65,    66,    69,    70,    73,    74,    77,
      81,    82,    85,    86,    89,    90,    93,    94,    97,   102,
     103,   106,   107,   109,   110,   113,   116,   117,   120,   121,
     127,   128,   131,   132,   135,   136,   139,   140,   141,   142,
     143,   144,   145,   147,   148,   149,   152,   153,   155,   156,
     158,   160,   161,   163,   164,   166,   167,   168,   169,   170,
     174,   181,   182,   183,   184,   185,   188,   189,   192,   193,
     196,   197,   200,   201,   204,   207,   208,   211,   212,   215,
     218
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "THEN", "ELSE", "ADD", "SUB",
  "MUL", "DIV", "AFFECT", "SCOL", "AND", "BRACO", "BRACC", "COMA",
  "CBRACO", "CBRACC", "CLASS", "EXT", "IS", "OBJ", "NEW", "OVR", "DEF",
  "STRG", "RETURN", "POINT", "VAR", "COL", "ID", "IDCLASS", "CST", "RELOP",
  "unary", "$accept", "programme", "listOptDef", "listDef", "Def",
  "defClasse", "listOptParam", "listParam", "param", "heritOpt",
  "defConst", "superClasseOpt", "listOptChamps", "listChamps", "champ",
  "listOptMeth", "listMeth", "overrideOpt", "methode", "nomClasseOpt", "E",
  "appel", "envoi", "selection", "listEOpt", "listE", "ELight",
  "instanciation", "inst", "bloc", "listOptInst", "listInst", "listDecl",
  "decl", "expOpt", "aff", "defObj", "defConstObj", YY_NULLPTR
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
     285,   286,   287,   288,   289
};
# endif

#define YYPACT_NINF -145

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-145)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -13,    -1,    10,    37,  -145,     2,  -145,  -145,    47,
      44,  -145,    49,  -145,  -145,    31,    50,   163,   163,   163,
     177,    36,  -145,    59,     9,    45,  -145,    18,  -145,  -145,
      63,    51,  -145,    79,  -145,    60,  -145,    56,    53,  -145,
      54,    62,    80,  -145,    78,    69,  -145,     7,  -145,  -145,
    -145,   150,    25,    86,  -145,   163,    71,    73,   163,   163,
     163,   163,  -145,   163,   163,    76,    97,  -145,  -145,    79,
      83,  -145,    96,    77,   111,    31,   102,   110,  -145,    69,
      79,   109,  -145,   163,   113,   130,   126,    27,    27,  -145,
    -145,    81,   120,   128,   134,   112,  -145,   115,   135,  -145,
     136,   127,    19,  -145,   154,  -145,   129,   152,  -145,  -145,
     163,   153,   163,  -145,   163,  -145,  -145,  -145,   151,   137,
     158,  -145,   156,  -145,   147,    19,    79,   163,  -145,   141,
    -145,   165,   172,    69,   176,   173,  -145,   161,  -145,  -145,
    -145,  -145,  -145,   168,  -145,    79,   183,   166,    19,   181,
      31,   187,   184,  -145,   189,    31,  -145,   175,   191,   179,
     186,   180,   202,    37,   200,   194,   163,  -145,   163,   199,
     141,   203,    79,  -145,   201,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     3,     5,     7,     8,     0,
       0,     1,    69,     2,     6,    11,     0,     0,     0,     0,
       0,     0,    58,     0,    55,     0,    56,     0,    57,    46,
      47,    42,    41,    71,    62,     0,    68,     0,    73,    64,
       0,     0,     0,    10,    12,    22,    55,     0,    47,    44,
      45,     0,     0,     0,    63,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,     0,    55,    70,    66,     0,
       0,    72,     0,     0,    17,     0,     0,     0,    21,    23,
       0,     0,    59,    52,     0,    76,     0,    37,    38,    39,
      40,    36,     0,    50,     0,     0,    14,     0,     0,    13,
       0,     0,    27,    24,     0,    43,    53,     0,    51,    78,
       0,     0,    52,    77,    52,    67,    15,    16,     0,     0,
       0,    30,     0,    26,     0,    28,     0,     0,    60,    75,
      74,     0,     0,    22,     0,     0,    79,     0,    29,    65,
      54,    49,    48,     0,    25,    69,     0,     0,    27,     0,
      11,     0,     0,    80,     0,    11,     9,    35,     0,     0,
       0,    20,    34,     0,     0,     0,     0,    33,    52,     0,
      32,     0,    69,    19,     0,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,  -145,   210,  -145,  -145,  -133,   144,  -145,  -145,
    -145,  -145,    87,   142,  -145,    74,    98,  -145,  -145,  -145,
     -14,  -145,  -145,   -12,  -105,    99,  -145,  -145,   -72,    -2,
    -144,   -21,   190,  -145,  -145,  -145,  -145,  -145
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    42,    43,    44,    98,
     148,   165,    77,    78,    79,   122,   123,   124,   125,   160,
      27,    28,    29,    48,   107,   108,    31,    32,    33,    34,
      35,    36,    37,    38,   111,    39,     8,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,   149,    13,    47,    49,    50,    52,   131,   104,   132,
      11,    80,    67,    58,    59,    60,    61,   154,     9,    55,
       1,    30,   158,     2,    58,    59,    60,    61,   174,    62,
      10,    58,    59,    60,    61,    60,    61,    81,    56,    82,
      63,    84,   121,   -31,    87,    88,    89,    90,    94,    91,
      92,    63,    17,    12,   139,    18,    19,    30,    63,    40,
      15,    41,    20,   171,    16,    12,    45,    53,    30,   106,
      54,    21,    57,    64,    22,    23,    69,    68,    65,    24,
      25,    26,    17,    70,    72,    18,    19,    58,    59,    60,
      61,    73,    20,    75,    74,    12,   129,    76,   106,    83,
     106,    21,    85,    86,    22,    23,    93,    55,    96,    66,
      25,    26,    56,   106,    30,    58,    59,    60,    61,    58,
      59,    60,    61,   105,   109,    95,    58,    59,    60,    61,
      97,   113,   100,    30,   101,    58,    59,    60,    61,   112,
     110,   114,    63,   116,   127,   117,    63,    58,    59,    60,
      61,   115,   170,    63,   106,   118,    18,    19,   120,   126,
      30,   167,    63,    20,   130,   119,   128,   133,   134,    18,
      19,   137,    21,   136,    63,    22,    20,    57,   135,   141,
      46,    25,    26,    18,    19,    21,   142,   144,    22,   145,
      20,   146,   147,    46,    25,    26,   150,   151,   153,    21,
     155,   156,    22,   157,   159,   161,   163,    46,    51,    26,
     162,   164,   166,   168,   169,   172,    14,   173,   175,    99,
     143,   103,   152,   138,     0,     0,   140,     0,    71
};

static const yytype_int16 yycheck[] =
{
      12,   145,     4,    17,    18,    19,    20,   112,    80,   114,
       0,     4,    33,     6,     7,     8,     9,   150,    31,    10,
      18,    33,   155,    21,     6,     7,     8,     9,   172,    11,
      31,     6,     7,     8,     9,     8,     9,    51,    29,    14,
      33,    55,    23,    24,    58,    59,    60,    61,    69,    63,
      64,    33,     3,    16,   126,     6,     7,    69,    33,    28,
      13,    30,    13,   168,    20,    16,    16,    31,    80,    83,
      11,    22,    27,    10,    25,    26,    20,    17,    27,    30,
      31,    32,     3,    30,    30,     6,     7,     6,     7,     8,
       9,    29,    13,    15,    14,    16,   110,    28,   112,    13,
     114,    22,    31,    30,    25,    26,    30,    10,    31,    30,
      31,    32,    29,   127,   126,     6,     7,     8,     9,     6,
       7,     8,     9,    14,    11,    29,     6,     7,     8,     9,
      19,    11,    30,   145,    24,     6,     7,     8,     9,    13,
      10,    13,    33,    31,    15,    30,    33,     6,     7,     8,
       9,    17,   166,    33,   168,    20,     6,     7,    31,     5,
     172,   163,    33,    13,    11,    29,    14,    16,    31,     6,
       7,    24,    22,    17,    33,    25,    13,    27,    20,    14,
      30,    31,    32,     6,     7,    22,    14,    11,    25,    16,
      13,    30,    24,    30,    31,    32,    13,    31,    17,    22,
      13,    17,    25,    14,    29,    14,    20,    30,    31,    32,
      31,    31,    10,    13,    20,    16,     6,    14,    17,    75,
     133,    79,   148,   125,    -1,    -1,   127,    -1,    38
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    21,    36,    37,    38,    39,    40,    71,    31,
      31,     0,    16,    64,    38,    13,    20,     3,     6,     7,
      13,    22,    25,    26,    30,    31,    32,    55,    56,    57,
      58,    61,    62,    63,    64,    65,    66,    67,    68,    70,
      28,    30,    41,    42,    43,    16,    30,    55,    58,    55,
      55,    31,    55,    31,    11,    10,    29,    27,     6,     7,
       8,     9,    11,    33,    10,    27,    30,    66,    17,    20,
      30,    67,    30,    29,    14,    15,    28,    47,    48,    49,
       4,    55,    14,    13,    55,    31,    30,    55,    55,    55,
      55,    55,    55,    30,    66,    29,    31,    19,    44,    42,
      30,    24,    72,    48,    63,    14,    55,    59,    60,    11,
      10,    69,    13,    11,    13,    17,    31,    30,    20,    29,
      31,    23,    50,    51,    52,    53,     5,    15,    14,    55,
      11,    59,    59,    16,    31,    20,    17,    24,    51,    63,
      60,    14,    14,    47,    11,    16,    30,    24,    45,    65,
      13,    31,    50,    17,    41,    13,    17,    14,    41,    29,
      54,    14,    31,    20,    31,    46,    10,    64,    13,    20,
      55,    59,    16,    14,    65,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    38,    39,    39,    40,
      41,    41,    42,    42,    43,    43,    44,    44,    45,    46,
      46,    47,    47,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      62,    63,    63,    63,    63,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    68,    69,    69,    70,    70,    71,
      72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     1,     2,     1,     1,    12,
       1,     0,     1,     3,     3,     4,     2,     0,    10,     4,
       0,     1,     0,     1,     2,     5,     1,     0,     1,     2,
       1,     0,    10,     9,     2,     0,     3,     3,     3,     3,
       3,     1,     1,     4,     2,     2,     1,     1,     6,     6,
       3,     1,     0,     1,     3,     1,     1,     1,     1,     3,
       5,     2,     1,     2,     1,     6,     3,     5,     1,     0,
       2,     1,     2,     1,     5,     2,     0,     4,     4,     8,
       6
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
        case 2:
#line 54 "scalix.y" /* yacc.c:1646  */
    { /* $1 represente le sous-arbre avec toutes les declarations,
   * S3 represente l'arbre pour l'expression finale.
   * lvar va etre la liste des couples (variable, valeur) resultant de
   * l'evaluation des declarations.
   */
  printAST((yyvsp[-1].T), (yyvsp[0].T));
  VarDeclP lvar = evalDecls((yyvsp[-1].T));
  evalMain((yyvsp[0].T), lvar);
}
#line 1367 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 3:
#line 65 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1373 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = NIL(Class); }
#line 1379 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T);/*$$ = makeTree(LIST, 1, $1);*/ }
#line 1385 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 6:
#line 70 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[-1].T), (yyvsp[0].T); }
#line 1391 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 7:
#line 73 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1397 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 8:
#line 74 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1403 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 9:
#line 78 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeClass((yyvsp[-10].S), (yyvsp[-8].T), (yyvsp[-3].T),(yyvsp[-2].T),(yyvsp[-1].T), (yyvsp[-6].T)); }
#line 1409 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 10:
#line 81 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1415 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = NIL(VarDecl); }
#line 1421 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1427 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeList((yyvsp[-2].T), (yyvsp[0].T)); }
#line 1433 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 14:
#line 89 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeVarDecl((yyvsp[-2].S), (yyvsp[0].S),PARAM, FALSE); }
#line 1439 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeVarDecl((yyvsp[-2].S), (yyvsp[0].S),PARAM, TRUE); }
#line 1445 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 16:
#line 93 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].S); }
#line 1451 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 17:
#line 94 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = ""; }
#line 1457 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 18:
#line 98 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeMethodes(FALSE, (yyvsp[-8].S),(yyvsp[-6].T), (yyvsp[-8].S), (yyvsp[-1].T)); }
#line 1463 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 19:
#line 102 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeMethodes(FALSE, (yyvsp[-3].S), (yyvsp[-1].T),(yyvsp[-3].S), NIL(Tree)); }
#line 1469 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 20:
#line 103 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = NIL(Methodes); }
#line 1475 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 21:
#line 106 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1481 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 22:
#line 107 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = NIL(VarDecl); }
#line 1487 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 23:
#line 109 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1493 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 24:
#line 110 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeList((yyvsp[-1].T), (yyvsp[0].T)); }
#line 1499 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 25:
#line 113 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeVarDecl((yyvsp[-3].S), (yyvsp[-1].S), CHAMP,TRUE); }
#line 1505 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 26:
#line 116 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1511 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 27:
#line 117 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = NIL(MethodesP); }
#line 1517 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 28:
#line 120 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1523 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 29:
#line 121 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeListMeth((yyvsp[-1].T), (yyvsp[0].T)); }
#line 1529 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 30:
#line 127 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = TRUE; }
#line 1535 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 31:
#line 128 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = FALSE; }
#line 1541 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 32:
#line 131 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeMethodes((yyvsp[-9].T), (yyvsp[-7].S),(yyvsp[-5].T), (yyvsp[-2].S),  (yyvsp[0].T)); }
#line 1547 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 33:
#line 132 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeMethodes((yyvsp[-8].T), (yyvsp[-6].S), (yyvsp[-4].T), (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1553 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 34:
#line 135 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].S); }
#line 1559 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 35:
#line 136 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = ""; }
#line 1565 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 36:
#line 139 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree((yyvsp[-1].C), 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1571 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 37:
#line 140 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Eadd, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1577 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 38:
#line 141 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Eminus, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1583 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 39:
#line 142 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Emult, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1589 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 40:
#line 143 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Ediv, 2, (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1595 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 41:
#line 144 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1601 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 42:
#line 145 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1607 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 43:
#line 147 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Ebrac, 2, makeLeafStr(IDVAR,(yyvsp[-2].S)), (yyvsp[-1].T)); }
#line 1613 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 44:
#line 148 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1619 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 45:
#line 149 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1625 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 46:
#line 152 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1631 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 47:
#line 153 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1637 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 48:
#line 155 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Eenvoi, 3,(yyvsp[-5].T),makeLeafStr(IDVAR,(yyvsp[-3].S)), (yyvsp[-1].T)); }
#line 1643 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 49:
#line 156 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Eenvoi, 3,makeLeafStr(IDVAR,(yyvsp[-5].S)),makeLeafStr(IDVAR,(yyvsp[-3].S)), (yyvsp[-1].T)); }
#line 1649 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 50:
#line 158 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(SELEC, 2,(yyvsp[-2].T),makeLeafStr(IDVAR,(yyvsp[0].S))); }
#line 1655 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 51:
#line 160 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1661 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 52:
#line 161 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = NIL(Tree); }
#line 1667 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 53:
#line 163 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1673 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 54:
#line 164 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Ecoma, 2,(yyvsp[-2].T),(yyvsp[0].T)); }
#line 1679 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 55:
#line 166 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeLeafStr(IDVAR, (yyvsp[0].S)); }
#line 1685 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 56:
#line 167 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeLeafInt(CONST, (yyvsp[0].I)); }
#line 1691 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 57:
#line 168 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1697 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 58:
#line 169 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeLeafStr(Estrg, "strg"); }
#line 1703 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 59:
#line 170 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[-1].T); }
#line 1709 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 60:
#line 174 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Enew, 2,makeLeafStr(IDVAR,(yyvsp[-3].S)), (yyvsp[-1].T)); }
#line 1715 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 61:
#line 181 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[-1].T); }
#line 1721 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 62:
#line 182 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1727 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 63:
#line 183 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeLeafStr(Ereturn, "Return"); }
#line 1733 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 64:
#line 184 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1739 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 65:
#line 185 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(ITE, 3, (yyvsp[-4].T), (yyvsp[-2].T), (yyvsp[0].T)); }
#line 1745 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 66:
#line 188 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[-1].T); }
#line 1751 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 67:
#line 189 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(Ebloc, 2,(yyvsp[-3].T),(yyvsp[-1].T)); }
#line 1757 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 68:
#line 192 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1763 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 69:
#line 193 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = NIL(Tree); }
#line 1769 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 70:
#line 196 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(LIST, 2,(yyvsp[-1].T),(yyvsp[0].T)); }
#line 1775 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 71:
#line 197 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1781 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 72:
#line 200 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(LIST, 2,(yyvsp[-1].T),(yyvsp[0].T)); }
#line 1787 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 73:
#line 201 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1793 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 74:
#line 204 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeVarDecl((yyvsp[-4].S), (yyvsp[-2].S), CHAMP, FALSE); }
#line 1799 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 75:
#line 207 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = (yyvsp[0].T); }
#line 1805 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 76:
#line 208 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = NIL(VarDecl); }
#line 1811 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 77:
#line 211 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(DECL, 2, (yyvsp[-3].T), (yyvsp[-1].T)); }
#line 1817 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 78:
#line 212 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeTree(DECL, 2, makeLeafStr(IDVAR, (yyvsp[-3].S)), (yyvsp[-1].T)); }
#line 1823 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 79:
#line 215 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeObj((yyvsp[-6].S), (yyvsp[-3].T),(yyvsp[-2].T),(yyvsp[-1].T)); }
#line 1829 "scalix_y.c" /* yacc.c:1646  */
    break;

  case 80:
#line 218 "scalix.y" /* yacc.c:1646  */
    { (yyval.T) = makeMethodes(FALSE, (yyvsp[-4].S),NIL(VarDecl),"",(yyvsp[-1].T) ); }
#line 1835 "scalix_y.c" /* yacc.c:1646  */
    break;


#line 1839 "scalix_y.c" /* yacc.c:1646  */
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
