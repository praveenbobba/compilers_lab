/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "tree_7.y" /* yacc.c:339  */

	
	#include<stdio.h>
	#include<stdlib.h> 
  	#include"exptree_7.h"
	//int yylex(void);
	FILE *yyin, *fp;
	void yyerror(char *);
	int machinecode(struct tnode *tree);
	int glob_type ;
	int codegen(struct tnode *);
	int getlabel(void);
	int getreg(void);
	void freereg(int );
	int getbind(struct tnode *);
	int reg_count = -1;
	int lab_count = 0;
	

#line 86 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    AND = 258,
    OR = 259,
    NOT = 260,
    TRUE = 261,
    FALSE = 262,
    BOOLEAN = 263,
    INTEGER = 264,
    DECL = 265,
    ENDDECL = 266,
    READ = 267,
    WRITE = 268,
    ID = 269,
    DIGIT = 270,
    IF = 271,
    THEN = 272,
    ELSE = 273,
    ENDIF = 274,
    WHILE = 275,
    DO = 276,
    ENDWHILE = 277,
    EQU = 278,
    LT = 279,
    GT = 280,
    LE = 281,
    GE = 282,
    NE = 283
  };
#endif
/* Tokens.  */
#define AND 258
#define OR 259
#define NOT 260
#define TRUE 261
#define FALSE 262
#define BOOLEAN 263
#define INTEGER 264
#define DECL 265
#define ENDDECL 266
#define READ 267
#define WRITE 268
#define ID 269
#define DIGIT 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define WHILE 275
#define DO 276
#define ENDWHILE 277
#define EQU 278
#define LT 279
#define GT 280
#define LE 281
#define GE 282
#define NE 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 193 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      39,    40,    34,    32,    41,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    57,    57,    61,    66,    69,    87,   107,   124,   147,
     156,   158,   164,   166,   170,   172,   176,   178,   182,   186,
     188,   192,   196,   200,   205,   215,   220,   222,   230,   238,
     246,   254,   262,   270,   278,   286,   294,   302,   317,   337,
     339,   341,   349,   357
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AND", "OR", "NOT", "TRUE", "FALSE",
  "BOOLEAN", "INTEGER", "DECL", "ENDDECL", "READ", "WRITE", "ID", "DIGIT",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "EQU", "LT",
  "GT", "LE", "GE", "NE", "\"[\"", "\"]\"", "'='", "'+'", "'-'", "'*'",
  "'/'", "';'", "'['", "']'", "'('", "')'", "','", "$accept", "Start",
  "Slist", "stmt", "cond", "global", "glist", "gstmt", "gdecl", "type",
  "gid", "expr", YY_NULLPTR
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
     285,    61,    43,    45,    42,    47,    59,    91,    93,    40,
      41,    44
};
# endif

#define YYPACT_NINF -80

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-80)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -80,    12,   245,     9,   -80,   -25,   -20,   -26,    10,
      15,   245,   -80,   -80,   -80,   -80,   -80,    11,    14,   181,
     181,   181,   181,   181,   -80,    23,   -28,   -80,   -14,   181,
     -80,   -80,    25,   -80,   181,    18,   174,   114,    44,    70,
      49,   -80,    11,   181,    30,   203,   181,    88,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
      39,   -80,    54,    69,    66,    51,   -80,   130,   -80,   147,
     -80,   203,   203,   216,   216,   216,   216,   216,   216,    48,
      48,   -80,   -80,   -80,   181,   245,   245,   -80,    50,   -80,
     189,    43,   240,    63,   -80,   245,    81,    65,   -80,   245,
      71,   -80,   -80
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,    17,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     2,     4,    22,    21,    14,    16,     0,     0,     0,
       0,     0,     0,     0,     3,    24,     0,    20,     0,     0,
      39,    40,    37,    25,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,     0,     0,    19,     0,     7,     0,
      26,    41,    42,    36,    32,    31,    33,    34,    35,    27,
      28,    29,    30,     9,     0,     0,     0,    23,     0,    38,
       0,    13,     0,     0,     6,     0,     0,     0,     8,    12,
       0,    11,    10
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -79,   -11,   -80,   -80,   -80,   -80,   -80,   -80,
      64,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,    12,    96,     3,     4,    16,    26,    17,
      27,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,    36,    37,    38,    39,    20,    91,    92,    41,     1,
      45,    21,     5,    42,    18,    47,    99,    13,    14,    19,
      15,    48,    49,    43,    67,    25,    44,    69,    28,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    50,    51,    52,    53,    54,    55,    48,    49,    22,
      56,    57,    58,    59,    23,     6,     7,     8,    60,     9,
      40,    95,    46,    10,    65,    90,    68,    50,    51,    52,
      53,    54,    55,    48,    49,    83,    56,    57,    58,    59,
      24,    24,    58,    59,    63,    84,    85,    86,    24,    87,
      93,    48,    49,    50,    51,    52,    53,    54,    55,    98,
     100,   101,    56,    57,    58,    59,    66,   102,     0,     0,
      64,    50,    51,    52,    53,    54,    55,    48,    49,     0,
      56,    57,    58,    59,     0,     0,     0,     0,    70,     0,
       0,     0,     0,    48,    49,     0,     0,    50,    51,    52,
      53,    54,    55,     0,     0,     0,    56,    57,    58,    59,
      48,    49,    62,    50,    51,    52,    53,    54,    55,     0,
       0,     0,    56,    57,    58,    59,     0,     0,    88,     0,
      50,    51,    52,    53,    54,    55,     0,    48,    49,    56,
      57,    58,    59,     0,     0,    89,    29,    30,    31,     0,
       0,     0,    48,    49,     0,    32,    33,    50,    51,    52,
      53,    54,    55,     0,     0,     0,    56,    57,    58,    59,
      61,     0,    50,    51,    52,    53,    54,    55,     0,     0,
      34,    56,    57,    58,    59,    94,    50,    51,    52,    53,
      54,    55,     0,     0,     0,    56,    57,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     0,     0,    56,    57,
      58,    59,     6,     7,     8,     0,     9,     6,     7,     8,
      10,     9,    97,     0,     0,    10
};

static const yytype_int8 yycheck[] =
{
      11,    20,    21,    22,    23,    31,    85,    86,    36,    10,
      29,    37,     0,    41,    39,    34,    95,     8,     9,    39,
      11,     3,     4,    37,    43,    14,    40,    46,    14,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    23,    24,    25,    26,    27,    28,     3,     4,    39,
      32,    33,    34,    35,    39,    12,    13,    14,    40,    16,
      37,    18,    37,    20,    15,    84,    36,    23,    24,    25,
      26,    27,    28,     3,     4,    36,    32,    33,    34,    35,
      91,    92,    34,    35,    40,    31,    17,    21,    99,    38,
      40,     3,     4,    23,    24,    25,    26,    27,    28,    36,
      19,    36,    32,    33,    34,    35,    42,    36,    -1,    -1,
      40,    23,    24,    25,    26,    27,    28,     3,     4,    -1,
      32,    33,    34,    35,    -1,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,     3,     4,    -1,    -1,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    33,    34,    35,
       3,     4,    38,    23,    24,    25,    26,    27,    28,    -1,
      -1,    -1,    32,    33,    34,    35,    -1,    -1,    38,    -1,
      23,    24,    25,    26,    27,    28,    -1,     3,     4,    32,
      33,    34,    35,    -1,    -1,    38,     5,     6,     7,    -1,
      -1,    -1,     3,     4,    -1,    14,    15,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    -1,    23,    24,    25,    26,    27,    28,    -1,    -1,
      39,    32,    33,    34,    35,    36,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    32,    33,    34,    35,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    32,    33,
      34,    35,    12,    13,    14,    -1,    16,    12,    13,    14,
      20,    16,    22,    -1,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    43,    47,    48,     0,    12,    13,    14,    16,
      20,    44,    45,     8,     9,    11,    49,    51,    39,    39,
      31,    37,    39,    39,    45,    14,    50,    52,    14,     5,
       6,     7,    14,    15,    39,    53,    53,    53,    53,    53,
      37,    36,    41,    37,    40,    53,    37,    53,     3,     4,
      23,    24,    25,    26,    27,    28,    32,    33,    34,    35,
      40,    36,    38,    40,    40,    15,    52,    53,    36,    53,
      40,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    36,    31,    17,    21,    38,    38,    38,
      53,    44,    44,    40,    36,    18,    46,    22,    36,    44,
      19,    36,    36
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     4,     7,     5,     8,     5,
       9,     8,     2,     0,     3,     0,     2,     0,     3,     3,
       1,     1,     1,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     1,
       1,     3,     3,     2
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
#line 57 "tree_7.y" /* yacc.c:1646  */
    {machinecode((yyvsp[0]));exit(1);}
#line 1366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 61 "tree_7.y" /* yacc.c:1646  */
    {(yyval)=(struct tnode *)malloc(sizeof(struct tnode));
			(yyval)->nodetype=6;
			(yyval)->ptr1=(yyvsp[-1]);
			(yyval)->ptr3=(yyvsp[0]);}
#line 1375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 66 "tree_7.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 69 "tree_7.y" /* yacc.c:1646  */
    { //printf("ch_assgn %s\n",$1->name);
						(yyvsp[-3])->gentry = glookup((yyvsp[-3])->name);
						if((yyvsp[-3])->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						(yyvsp[-3])->type = (yyvsp[-3])->gentry->type;
						if(gettype((yyvsp[-3])) != gettype((yyvsp[-1])))
							yyerror("type conflicts in assignment");

						if((yyvsp[-3])->type == 1 || (yyvsp[-3])->type == 3 )
							yyerror("variable declared is an array");			
						(yyvsp[-2])->ptr1=(yyvsp[-3]);(yyvsp[-2])->ptr3=(yyvsp[-1]);(yyval)=(yyvsp[-2]);
						
					}
#line 1402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "tree_7.y" /* yacc.c:1646  */
    { 
						(yyvsp[-6])->gentry = glookup((yyvsp[-6])->name);
						if((yyvsp[-6])->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						(yyvsp[-6])->type = (yyvsp[-6])->gentry->type;
						if(gettype((yyvsp[-6])) != gettype((yyvsp[-1])))
							yyerror("type conflicts in assignment");
						if( ((yyvsp[-6])->type == 0) || ((yyvsp[-6])->type == 2) )
							yyerror("variable is not an array");
						if(gettype((yyvsp[-4])) != 0)
							yyerror("array index is not an integer");
						(yyvsp[-6])->ptr1 = (yyvsp[-4]); (yyvsp[-6])->ptr3 = NULL;			
						(yyvsp[-2])->ptr1=(yyvsp[-6]);(yyvsp[-2])->ptr3=(yyvsp[-1]);(yyval)=(yyvsp[-2]);
						//printf("arr_assgn\n");
						
					}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 107 "tree_7.y" /* yacc.c:1646  */
    { 	
						//printf("in read token\n");
						(yyvsp[-2])->gentry = glookup((yyvsp[-2])->name);
						if((yyvsp[-2])->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						(yyvsp[-2])->type = (yyvsp[-2])->gentry->type;
						if(gettype((yyvsp[-2])) != 0)
							yyerror("variable used in READ is not int type");
						if((yyvsp[-2])->type == 1 || (yyvsp[-2])->type == 3 )
							yyerror("variable declared is an array");			
						
						(yyvsp[-4])->ptr1=(yyvsp[-2]);(yyvsp[-4])->ptr3=NULL;(yyval)=(yyvsp[-4]);
					}
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "tree_7.y" /* yacc.c:1646  */
    { 	
								//printf("in read token\n");
								(yyvsp[-5])->gentry = glookup((yyvsp[-5])->name);
								if((yyvsp[-5])->gentry == NULL )
								{
								yyerror("variable not declared");

								}
							(yyvsp[-5])->type = (yyvsp[-5])->gentry->type;
							if(gettype((yyvsp[-5])) != 0 )
								yyerror("variable used in READ is not int type");

							if( ((yyvsp[-5])->type == 0) || ((yyvsp[-5])->type == 2) )
								yyerror("variable is not an array");

							if(gettype((yyvsp[-3])) != 0 )
								yyerror("array index type is not int");
							(yyvsp[-5])->ptr1 = (yyvsp[-3]); 
							(yyvsp[-5])->ptr3 = NULL;			
						
							(yyvsp[-7])->ptr1=(yyvsp[-5]);(yyvsp[-7])->ptr3=NULL;(yyval)=(yyvsp[-7]);
					}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 147 "tree_7.y" /* yacc.c:1646  */
    { 	//printf("ch1\n");
						if(gettype((yyvsp[-2])) != 0)
						{	//printf("gettype %d\n",gettype($3));
							yyerror("expression in READ is not int type");			
						}
						(yyvsp[-4])->ptr1=(yyvsp[-2]);(yyvsp[-4])->ptr3=NULL;(yyval)=(yyvsp[-4]);
						//printf("ch1\n");
					}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "tree_7.y" /* yacc.c:1646  */
    {(yyvsp[-8])->ptr1=(yyvsp[-6]);(yyvsp[-8])->ptr2=(yyvsp[-3]);(yyvsp[-8])->ptr3=(yyvsp[-2]);(yyval)=(yyvsp[-8]);}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 158 "tree_7.y" /* yacc.c:1646  */
    {(yyvsp[-7])->ptr1=(yyvsp[-5]);(yyvsp[-7])->ptr3=(yyvsp[-2]);(yyval)=(yyvsp[-7]);}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 164 "tree_7.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 166 "tree_7.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 192 "tree_7.y" /* yacc.c:1646  */
    {	glob_type = 0;
					//printf("chk_int\n");
				}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 196 "tree_7.y" /* yacc.c:1646  */
    {glob_type = 2;}
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 200 "tree_7.y" /* yacc.c:1646  */
    { 	
						(yyvsp[-3])->type = glob_type + 1 ;
						ginstall((yyvsp[-3])->name,(yyvsp[-3])->type,(yyvsp[-1])->value);
					}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 205 "tree_7.y" /* yacc.c:1646  */
    { 	
						(yyvsp[0])->type = glob_type + 0 ;
						//printf("type %d\n",$1->type);
						ginstall((yyvsp[0])->name,(yyvsp[0])->type,1);
						//printf("chk_glob_id %s\n",$1->name);
					}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 215 "tree_7.y" /* yacc.c:1646  */
    {
						(yyval)=(yyvsp[0]);
						//printf("chk_dig\n");
					}
#line 1554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 220 "tree_7.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 222 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in addition operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 230 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in subtraction operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 238 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in multiplication operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 246 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in division operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 254 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 262 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 270 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 278 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 286 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 294 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 302 "tree_7.y" /* yacc.c:1646  */
    {	//printf("expr_ID %s\n",$1->name);
						(yyvsp[0])->gentry = glookup((yyvsp[0])->name);
						if((yyvsp[0])->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						(yyvsp[0])->type = (yyvsp[0])->gentry->type;
						
						if((yyvsp[0])->type == 1 || (yyvsp[0])->type == 3 )
							yyerror("variable declared is an array");
						
						(yyval) = (yyvsp[0]);
					}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 317 "tree_7.y" /* yacc.c:1646  */
    {
						(yyvsp[-3])->gentry = glookup((yyvsp[-3])->name);
						if((yyvsp[-3])->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						(yyvsp[-3])->type = (yyvsp[-3])->gentry->type;

						if( ((yyvsp[-3])->type == 0) || ((yyvsp[-3])->type == 2) )
							yyerror("variable is not an array");

						if(gettype((yyvsp[-1]))!=0)
							yyerror("array index is not an integer");

						(yyvsp[-3])->ptr1 = (yyvsp[-1]);
						(yyvsp[-3])->ptr3 = NULL;
						(yyval) = (yyvsp[-3]);
					}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 337 "tree_7.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 339 "tree_7.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 341 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 2  || gettype((yyvsp[0])) != 2)
							yyerror("type conflicts in logical operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 349 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 2  || gettype((yyvsp[0])) != 2)
							yyerror("type conflicts in logical operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 357 "tree_7.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[0])) != 2)
							yyerror("type conflicts in logical operation");
						(yyvsp[-1])->ptr1=(yyvsp[0]);
					 	(yyvsp[-1])->ptr3=NULL;
					 	(yyval)=(yyvsp[-1]);
					}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1775 "y.tab.c" /* yacc.c:1646  */
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
#line 367 "tree_7.y" /* yacc.c:1906  */


void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	exit(0);
}

int machinecode(struct tnode *tree)
{
	fp = fopen("mach.asm","w+");
	fprintf(fp,"START\n");
	codegen(tree);
	fprintf(fp,"HALT\n");
	fclose(fp);

}

int codegen(struct tnode *nd){
	int r, r1, r2, l,l1,l2;
	int loc ;

	if(nd->nodetype==0)
	{
		r = getreg();
		fprintf(fp,"MOV R%d, %d\n",r,nd->value);
		return r;
		//return nd->value;
	}

	if((nd->type==0 || nd->type == 2) && nd->nodetype ==2 )
	{
		r = getreg();
		loc = getbind(nd) ;
		fprintf(fp,"MOV R%d, [%d]\n",r,loc);
		return r;
		//return (nd->gentry->binding[0]) ;
	}

	if((nd->type==1 || nd->type == 3) && nd->nodetype ==2 )
	{
		r1 = getreg();
		loc = getbind(nd) ;
		r2 = codegen(nd->ptr1);
		r = getreg();
		fprintf(fp,"MOV R%d, %d\n",r,loc);
		fprintf(fp,"ADD R%d, R%d\n",r2,r);
		freereg(r);
		fprintf(fp,"MOV R%d, [R%d]\n",r1,r2);
		freereg(r2);
		return r1;
		//return (nd->gentry->binding[evaltree(nd->ptr1)]) ;
	}

	if(nd->nodetype==1){
		if(strcmp(nd->name,"=") == 0)

		   {
			if(nd->ptr1->type == 0 || nd->ptr1->type == 2)
			{
				r = codegen(nd->ptr3);
				loc = getbind(nd->ptr1) ;
				fprintf(fp,"MOV [%d], R%d\n",loc,r);
				freereg(r);
				return 1;

		     		//nd->ptr1->gentry->binding[0]=evaltree(nd->ptr3);
		     		
			}
			//printf("=\n");

			if(nd->ptr1->type == 1 || nd->ptr1->type == 3)
			{
				//printf("=\n");
				r1 = codegen(nd->ptr3);
				r2 = codegen(nd->ptr1->ptr1);
				loc = getbind(nd->ptr1) ;
				r = getreg();
				fprintf(fp,"MOV R%d, %d\n",r,loc);
				fprintf(fp,"ADD R%d, R%d\n",r2,r);
				freereg(r);
				fprintf(fp,"MOV [R%d], R%d\n",r2,r1);
				freereg(r2);
				freereg(r1);
				return 1;

		     		//nd->ptr1->gentry->binding[evaltree(nd->ptr1->ptr1)]=evaltree(nd->ptr3);
		     	
			}

		   }	
	
		if(strcmp(nd->name,"+") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"ADD R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1)+evaltree(nd->ptr3));
		}

		else if(strcmp(nd->name,"-") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"SUB R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) - evaltree(nd->ptr3));
		}
		else if(strcmp(nd->name,"*") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"MUL R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) * evaltree(nd->ptr3));
		}
		else if(strcmp(nd->name,"/") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"DIV R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) / evaltree(nd->ptr3));
		}
	}
	if(nd->nodetype==3)
	{ 
		if(nd->ptr1->type == 0 )
		{
			r = getreg();
			loc = getbind(nd->ptr1);
			fprintf(fp,"IN R%d\n",r);
			fprintf(fp,"MOV [%d], R%d\n",loc,r);
			freereg(r);	     		
	     		return 1;
		}

		if(nd->ptr1->type == 1)
		{
			r1 = getreg();
			r2 = codegen(nd->ptr1->ptr1);
			loc = getbind(nd->ptr1);
			fprintf(fp,"IN R%d\n",r1);
			r = getreg();
			fprintf(fp,"MOV R%d, %d\n",r,loc);
			fprintf(fp,"ADD R%d, R%d\n",r2,r);
			freereg(r);
			fprintf(fp,"MOV [R%d], R%d\n",r2,r1);
			freereg(r1);
			freereg(r2);	     		
	     		return 1;
	     		//nd->ptr1->gentry->binding[evaltree(nd->ptr1->ptr1)]=c;
	     	
		}
		 
	}

	if(nd->nodetype==4)
	{	
		r = codegen(nd->ptr1);
		fprintf(fp,"OUT R%d\n",r);
		freereg(r);		
	     //printf("%d\n",evaltree(nd->ptr1));
		return 1;
			

	}

	if(nd->nodetype==6)
	{ codegen(nd->ptr1);
	  codegen(nd->ptr3);
	 return 1;
	}

	if(nd->type == 2 && nd->nodetype==10){
				
		if(strcmp (nd->name,"<") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"LT R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) < evaltree(nd->ptr3));
		}

		if(strcmp (nd->name,">") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"GT R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) > evaltree(nd->ptr3));
		}

		if(strcmp (nd->name,"<=") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"LE R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) <= evaltree(nd->ptr3));
		}
		if(strcmp (nd->name,">=") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"GE R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) >= evaltree(nd->ptr3));
		}
		if(strcmp (nd->name,"!=") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"NE R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
			//return (evaltree(nd->ptr1) != evaltree(nd->ptr3));
		}
		
	}

	if(nd->type == 2 && nd->nodetype==5){
				
		if(strcmp (nd->name,"AND") == 0)
		{
			r1 = codegen(nd->ptr1);
			l1 = getlabel() ;
			fprintf(fp,"JZ R%d, L%d\n",r1,l1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"JZ R%d, L%d\n",r2,l1);
			l2 = getlabel() ;
			fprintf(fp,"MOV R%d, 1\n",r1);
			fprintf(fp,"JMP L%d\n",l2);
			freereg(r2);
			fprintf(fp,"L%d:\n",l1);
			fprintf(fp,"MOV R%d, 0\n",r1);
			fprintf(fp,"L%d:\n",l2);
			return r1;
			//return (evaltree(nd->ptr1) && evaltree(nd->ptr3));
		}
		if(strcmp (nd->name,"OR") == 0)
		{
			r1 = codegen(nd->ptr1);
			l1 = getlabel() ;
			fprintf(fp,"JNZ R%d, L%d\n",r1,l1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"JNZ R%d, L%d\n",r2,l1);
			l2 = getlabel() ;
			fprintf(fp,"MOV R%d, 0\n",r1);
			fprintf(fp,"JMP L%d\n",l2);
			freereg(r2);
			fprintf(fp,"L%d:\n",l1);
			fprintf(fp,"MOV R%d, 1\n",r1);
			fprintf(fp,"L%d:\n",l2);
			return r1;
			//return (evaltree(nd->ptr1) || evaltree(nd->ptr3));
		}

		if(strcmp (nd->name,"NOT") == 0)
		{
			r = codegen(nd->ptr1);
			l1 = getlabel();
			fprintf(fp,"JZ R%d, L%d\n",r,l1);
			fprintf(fp,"MOV R%d, 0\n",r);
			l2 = getlabel() ;
			fprintf(fp,"JMP L%d\n",l2);
			fprintf(fp,"L%d:\n",l1);
			fprintf(fp,"MOV R%d\n, 1",r);
			fprintf(fp,"L%d:\n",l2);
			return r;
		}
		
	}

	if(nd->nodetype==7)
	{
	  if(nd->ptr3 != NULL )
	  {
		r = codegen(nd->ptr1);
		l1 = getlabel();
		l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l1);
		freereg(r);
		r = codegen(nd->ptr2);
		fprintf(fp,"JMP L%d\n",l2);
		fprintf(fp,"L%d:\n",l1);
		r = codegen(nd->ptr3);
		fprintf(fp,"L%d:\n",l2);
		
	  }

	  else
	  {

		r = codegen(nd->ptr1);
		l1 = getlabel();
		//l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l1);
		freereg(r);
		r = codegen(nd->ptr2);
		fprintf(fp,"L%d:\n",l1);

	  }
		/*if(evaltree(nd->ptr1))
			evaltree(nd->ptr2) ;
		else if(nd->ptr3 != NULL)
			evaltree(nd->ptr3) ;*/
		return 1;

	}

	if(nd->nodetype==8)
	{
		l1 = getlabel();
		fprintf(fp,"L%d:\n",l1);
		r = codegen(nd->ptr1);
		l2 = getlabel();
		fprintf(fp,"JZ R%d, L%d\n",r,l2);
		freereg(r);
		r = codegen(nd->ptr3);
		fprintf(fp,"JMP L%d\n",l1);

		fprintf(fp,"L%d:\n",l2);
		/*while(evaltree(nd->ptr1))
			evaltree(nd->ptr3) ;*/
		return 1;

	}

	if(nd->nodetype==9)
	{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"EQ R%d, R%d\n",r1,r2);
			freereg(r2);
			return r1;
		
		//return (evaltree(nd->ptr1) == evaltree(nd->ptr3));
	}

}

int getlabel(void)
{
	lab_count += 1;
}

int getreg(void)
{
	reg_count += 1;
	return reg_count;
}

void freereg(int free_count)
{

	reg_count -= 1 ;
	return ;
}

int getbind(struct tnode *addr)
{
	return(addr->gentry->binding[0]);

}

int main(int argc, char* argv[])
{
	if(argc > 1)
	{
		FILE *fin = fopen(argv[1], "r");
		if(fin)
			yyin = fin;
	}
	yyparse();
	return 0;
}

