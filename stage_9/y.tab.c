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
#line 1 "tree_9.y" /* yacc.c:339  */

	
	#include<stdio.h>
	#include<stdlib.h> 
  	#include"exptree_9.h"
	//int yylex(void);
	FILE *yyin, *fp;
	void yyerror(char *);
	int machinecode(struct tnode *tree);
	int glob_type ;
	int arg_glob_type ;
	int codegen(struct tnode *);
	int getlabel(void);
	int getreg(void);
	void freereg(int );
	int getbind(struct tnode *);
	int getlocbind(struct tnode *);
	int reg_count = -1;
	int lab_count = 0;
	struct tnode *arg_head = NULL, *arg_tail = NULL;
	void arg_make(struct tnode *arg_entry);
	int typecheck(struct tnode *arg1, struct tnode *arg2);
	void param_check(struct tnode *arg1,struct tnode *arg2);
	int func_params_count = 0;
	int file_open = 0;
	int loc_bind_count = 1;
	struct lsymbol *lfirst = NULL, *llast = NULL, *ltemp,*ltemp2 ;
	int loc_type = 0;
	extern int bind_count;	
	struct tnode *call_head = NULL,*call_tail = NULL;
	void make_call_list(struct tnode *newnode);
	
	

#line 101 "y.tab.c" /* yacc.c:339  */

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
    NE = 283,
    RETURN = 284,
    BEGINN = 285,
    END = 286,
    MAIN = 287
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
#define RETURN 284
#define BEGINN 285
#define END 286
#define MAIN 287

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

#line 216 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   370

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       2,     2,     2,     2,     2,     2,     2,    40,    47,     2,
      45,    46,    38,    36,    42,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    77,    79,    83,    85,    89,    93,    97,
     101,   103,   107,   112,   119,   127,   137,   139,   144,   149,
     153,   157,   159,   163,   170,   178,   178,   182,   210,   236,
     254,   274,   281,   283,   288,   293,   297,   301,   303,   307,
     314,   324,   328,   330,   334,   338,   342,   347,   349,   353,
     365,   375,   377,   381,   389,   394,   397,   429,   455,   482,
     511,   520,   522,   528,   530,   535,   540,   542,   550,   558,
     566,   574,   582,   590,   598,   606,   614,   622,   630,   655,
     678,   680,   682,   690,   698,   706,   728,   750,   760
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
  "GT", "LE", "GE", "NE", "RETURN", "BEGINN", "END", "MAIN", "\"[\"",
  "\"]\"", "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "','", "'['",
  "']'", "'('", "')'", "'&'", "'{'", "'}'", "$accept", "Start", "global",
  "glist", "gstmt", "type", "gdecl", "gid", "arglist", "arg_stmt",
  "arg_type", "arg_decl", "arg_id", "funclist", "funcdef", "func_name",
  "mainblock", "type_main", "arglist2", "arg_stmt2", "arg_type2",
  "arg_decl2", "arg_id2", "local_def", "lc_list", "lstmt", "ltype",
  "ldecl", "lid", "body", "BSlist", "retstmt", "Slist", "stmt", "cond",
  "expr", "expr_list", YY_NULLPTR
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
     285,   286,   287,   288,   289,    61,    43,    45,    42,    47,
      37,    59,    44,    91,    93,    40,    41,    38,   123,   125
};
# endif

#define YYPACT_NINF -161

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-161)))

#define YYTABLE_NINF -32

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-32)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,  -161,    46,  -161,   117,  -161,    67,  -161,  -161,  -161,
    -161,    43,    39,    82,  -161,  -161,    90,    97,    45,  -161,
    -161,    84,   106,   137,    -1,  -161,    43,    10,   119,   111,
    -161,  -161,  -161,   -35,  -161,    41,  -161,  -161,  -161,   127,
     -21,  -161,    52,   128,  -161,    94,  -161,  -161,   160,   136,
    -161,   169,   104,   132,  -161,   167,   148,  -161,   169,  -161,
    -161,    41,  -161,   161,  -161,   169,  -161,    52,   161,  -161,
     130,   350,   143,   161,  -161,   144,  -161,  -161,  -161,  -161,
     180,   155,   156,   -19,   157,   162,   175,   350,  -161,  -161,
     168,  -161,  -161,   126,  -161,   191,   109,   109,   109,   109,
     109,   109,   187,  -161,  -161,  -161,   180,    54,   109,  -161,
    -161,   121,  -161,   109,    24,   211,   133,    55,    81,   237,
    -161,  -161,   109,   165,   282,   109,     8,   107,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   178,  -161,   181,   203,   205,  -161,   159,  -161,   185,
    -161,   289,    23,  -161,   282,   282,   307,   307,   307,   307,
     307,   307,   110,   110,  -161,  -161,  -161,  -161,   109,   350,
     350,   182,  -161,   109,  -161,   263,   341,   336,   186,   289,
    -161,   350,   212,   189,  -161,   350,   192,  -161,  -161
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     6,     0,    25,     0,     1,     0,     9,     8,     3,
       5,     0,     8,     0,    26,     2,     0,    13,     0,    11,
      29,     0,     0,     0,     0,     7,     0,     0,     0,     0,
      20,    19,    15,     0,    17,     0,    10,    36,    35,     0,
       0,    33,     0,     0,    12,     0,    14,    23,     0,    18,
      22,     0,     0,     0,    39,     0,    34,    38,     0,    16,
      24,     0,    43,     0,    32,     0,    40,     0,     0,    21,
       0,    52,     0,     0,    37,     0,    46,    45,    41,    42,
       0,     0,     0,     0,     0,     0,     0,    51,    55,    28,
       0,    30,    49,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    27,    44,     0,     0,     0,    80,
      81,    78,    65,     0,     0,     0,     0,     0,     0,     0,
      50,    47,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    56,     0,     0,     0,    53,     0,    58,     0,
      86,    88,     0,    66,    82,    83,    77,    73,    72,    74,
      75,    76,    67,    68,    69,    70,    71,    60,     0,     0,
       0,     0,    79,     0,    85,     0,    64,     0,     0,    87,
      57,     0,     0,     0,    59,    63,     0,    62,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,  -161,  -161,   226,  -161,   216,  -161,   198,
    -161,  -161,   183,  -161,  -161,  -161,  -161,  -161,  -161,   193,
    -161,  -161,   179,     9,  -161,  -161,  -161,  -161,   147,     0,
    -161,  -161,  -160,   -87,  -161,   -96,  -161
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    11,    18,    19,    33,    34,
      35,    49,    50,     6,    14,    21,    15,    16,    40,    41,
      42,    56,    57,    63,    70,    79,    80,    93,    94,    72,
      86,   102,    87,    88,   182,   114,   152
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,   115,   116,   117,   118,   119,    45,    30,    31,   176,
     177,    46,   124,   108,   109,   110,    97,   127,    37,    38,
      52,   185,   111,   112,    98,    53,   147,   128,   129,   149,
     151,     1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,    32,     5,   130,   131,   132,
     133,   134,   135,   113,   150,    47,    39,    17,   128,   129,
     136,   137,   138,   139,   140,   173,    54,    68,    75,   174,
     141,   -31,   175,    90,    73,     7,    12,   179,   130,   131,
     132,   133,   134,   135,   128,   129,    25,    26,    48,   103,
     103,   136,   137,   138,   139,   140,    20,   122,   103,    55,
     123,   144,    30,    31,   130,   131,   132,   133,   134,   135,
     128,   129,    37,    38,   108,   109,   110,   136,   137,   138,
     139,   140,    22,   111,   112,     7,     8,   145,     9,    27,
     130,   131,   132,   133,   134,   135,   128,   129,    76,    77,
      23,    78,    24,   136,   137,   138,   139,   140,   138,   139,
     140,    28,    29,   153,   113,    44,   130,   131,   132,   133,
     134,   135,   128,   129,   125,    43,   126,   105,   106,   136,
     137,   138,   139,   140,    60,    51,    58,   143,    61,    62,
      65,    66,   130,   131,   132,   133,   134,   135,   128,   129,
      67,    71,    89,    91,    92,   136,   137,   138,   139,   140,
      95,    96,    99,   171,   101,   107,   148,   100,   130,   131,
     132,   133,   134,   135,   128,   129,   168,   104,   120,   167,
     169,   136,   137,   138,   139,   140,   170,   184,   178,   172,
     187,   186,    13,   188,   130,   131,   132,   133,   134,   135,
     128,   129,    36,    59,    69,    64,    74,   136,   137,   138,
     139,   140,   142,   121,     0,     0,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   128,   129,     0,     0,
       0,     0,     0,   136,   137,   138,   139,   140,   146,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   128,   129,     0,     0,     0,     0,     0,   136,
     137,   138,   139,   140,   180,   130,   131,   132,   133,   134,
     135,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   136,   137,   138,   139,   140,
     -32,   -32,   -32,   -32,   -32,   -32,     0,     0,     0,     0,
       0,     0,     0,   136,   137,   138,   139,   140,    81,    82,
      83,     0,    84,    81,    82,    83,    85,    84,   183,   181,
       0,    85,    81,    82,    83,     0,    84,     0,     0,     0,
      85
};

static const yytype_int16 yycheck[] =
{
      87,    97,    98,    99,   100,   101,    41,     8,     9,   169,
     170,    46,   108,     5,     6,     7,    35,   113,     8,     9,
      41,   181,    14,    15,    43,    46,   122,     3,     4,   125,
     126,    10,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,    46,     0,    23,    24,    25,
      26,    27,    28,    45,    46,    14,    46,    14,     3,     4,
      36,    37,    38,    39,    40,    42,    14,    58,    68,    46,
      46,    32,   168,    73,    65,     8,     9,   173,    23,    24,
      25,    26,    27,    28,     3,     4,    41,    42,    47,   176,
     177,    36,    37,    38,    39,    40,    14,    43,   185,    47,
      46,    46,     8,     9,    23,    24,    25,    26,    27,    28,
       3,     4,     8,     9,     5,     6,     7,    36,    37,    38,
      39,    40,    32,    14,    15,     8,     9,    46,    11,    45,
      23,    24,    25,    26,    27,    28,     3,     4,     8,     9,
      43,    11,    45,    36,    37,    38,    39,    40,    38,    39,
      40,    45,    15,    46,    45,    44,    23,    24,    25,    26,
      27,    28,     3,     4,    43,    46,    45,    41,    42,    36,
      37,    38,    39,    40,    14,    48,    48,    44,    42,    10,
      48,    14,    23,    24,    25,    26,    27,    28,     3,     4,
      42,    30,    49,    49,    14,    36,    37,    38,    39,    40,
      45,    45,    45,    44,    29,    14,    41,    45,    23,    24,
      25,    26,    27,    28,     3,     4,    35,    49,    31,    41,
      17,    36,    37,    38,    39,    40,    21,    41,    46,    44,
      41,    19,     6,    41,    23,    24,    25,    26,    27,    28,
       3,     4,    26,    45,    61,    52,    67,    36,    37,    38,
      39,    40,    41,   106,    -1,    -1,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,     3,     4,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,     3,     4,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    23,    24,    25,    26,    27,
      28,    -1,    23,    24,    25,    26,    27,    28,    36,    37,
      38,    39,    40,    -1,    -1,    36,    37,    38,    39,    40,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    40,    12,    13,
      14,    -1,    16,    12,    13,    14,    20,    16,    22,    18,
      -1,    20,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    51,    52,    53,     0,    63,     8,     9,    11,
      54,    55,     9,    55,    64,    66,    67,    14,    56,    57,
      14,    65,    32,    43,    45,    41,    42,    45,    45,    15,
       8,     9,    46,    58,    59,    60,    57,     8,     9,    46,
      68,    69,    70,    46,    44,    41,    46,    14,    47,    61,
      62,    48,    41,    46,    14,    47,    71,    72,    48,    59,
      14,    42,    10,    73,    69,    48,    14,    42,    73,    62,
      74,    30,    79,    73,    72,    79,     8,     9,    11,    75,
      76,    12,    13,    14,    16,    20,    80,    82,    83,    49,
      79,    49,    14,    77,    78,    45,    45,    35,    43,    45,
      45,    29,    81,    83,    49,    41,    42,    14,     5,     6,
       7,    14,    15,    45,    85,    85,    85,    85,    85,    85,
      31,    78,    43,    46,    85,    43,    45,    85,     3,     4,
      23,    24,    25,    26,    27,    28,    36,    37,    38,    39,
      40,    46,    41,    44,    46,    46,    41,    85,    41,    85,
      46,    85,    86,    46,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    41,    35,    17,
      21,    44,    44,    42,    46,    85,    82,    82,    46,    85,
      41,    18,    84,    22,    41,    82,    19,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      66,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      72,    73,    74,    74,    75,    76,    76,    77,    77,    78,
      79,    80,    80,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     2,     0,     3,     1,     1,
       3,     1,     4,     1,     4,     3,     3,     1,     2,     1,
       1,     3,     1,     1,     2,     0,     2,     9,     8,     1,
       8,     1,     3,     1,     2,     1,     1,     3,     1,     1,
       2,     3,     2,     0,     3,     1,     1,     3,     1,     1,
       4,     1,     0,     3,     2,     1,     4,     7,     5,     8,
       5,     9,     8,     2,     0,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     4,
       1,     1,     3,     3,     2,     4,     3,     3,     1
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
#line 73 "tree_9.y" /* yacc.c:1646  */
    {exit(1);}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "tree_9.y" /* yacc.c:1646  */
    {printf("global decl\n"); }
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 93 "tree_9.y" /* yacc.c:1646  */
    {	glob_type = 0;
					//printf("chk_int\n");
				}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 97 "tree_9.y" /* yacc.c:1646  */
    {glob_type = 2;}
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 107 "tree_9.y" /* yacc.c:1646  */
    { 	
						(yyvsp[-3])->type = glob_type + 1 ;
						ginstall((yyvsp[-3])->name,(yyvsp[-3])->type,(yyvsp[-1])->value,NULL,"-2");
					}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 112 "tree_9.y" /* yacc.c:1646  */
    { 	
						(yyvsp[0])->type = glob_type + 0 ;
						//printf("type %d\n",$1->type);
						ginstall((yyvsp[0])->name,(yyvsp[0])->type,1,NULL,"-2");
						//printf("chk_glob_id %s\n",$1->name);
					}
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 119 "tree_9.y" /* yacc.c:1646  */
    {
						(yyvsp[-3])->type = glob_type + 0;
						(yyvsp[-3])->arglist = arg_head;
						ginstall((yyvsp[-3])->name,(yyvsp[-3])->type,0,arg_head,(yyvsp[-3])->name);
						arg_head = NULL;
						arg_tail = NULL;
					}
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 127 "tree_9.y" /* yacc.c:1646  */
    {
						(yyvsp[-2])->type = glob_type + 0;
						(yyvsp[-2])->arglist = NULL;
						ginstall((yyvsp[-2])->name,(yyvsp[-2])->type,0,NULL,(yyvsp[-2])->name);
						arg_head = NULL;
						arg_tail = NULL;
					}
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 149 "tree_9.y" /* yacc.c:1646  */
    {	arg_glob_type = 0;
					//printf("chk_int\n");
				}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 153 "tree_9.y" /* yacc.c:1646  */
    {arg_glob_type = 2;}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 163 "tree_9.y" /* yacc.c:1646  */
    {
					(yyvsp[0])->type = arg_glob_type;
					(yyvsp[0])->is_pointer = 0;
					arg_make((yyvsp[0]));
					
				}
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 170 "tree_9.y" /* yacc.c:1646  */
    {
					(yyvsp[0])->type = arg_glob_type;
					(yyvsp[0])->is_pointer = 1;
					arg_make((yyvsp[0]));
				}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 182 "tree_9.y" /* yacc.c:1646  */
    {
									  (yyvsp[-7])->gentry = glookup((yyvsp[-7])->name);
									  if((yyvsp[-7])->gentry == NULL)
										yyerror("function not declared");
									  (yyvsp[-7])->type = (yyvsp[-7])->gentry->type;
									  if((yyvsp[-7])->gentry->func_redef == 1)
										yyerror("function redefined");
									  else if((yyvsp[-7])->gentry->func_redef == 0)
										(yyvsp[-7])->gentry->func_redef = 1;
									  if( gettype((yyvsp[-7])) != glob_type )
									    yyerror("function return type not matched in decln nd defn");

									   
									   (yyvsp[-7])->arglist = arg_head;
									   (yyvsp[-7])->nodetype = 12;
									  if( typecheck((yyvsp[-7])->arglist,(yyvsp[-7])->gentry->garg_list) == 0)
									    yyerror("No of arguments are not matched in fn dec n def");
										(yyvsp[-7])->ptr1 = (yyvsp[-1]);
										
									  machinecode((yyvsp[-7]));
										printf("funcdef\n");
									  loc_bind_count = 1;
									  arg_head = NULL;
									  arg_tail = NULL;
									  lfirst = NULL; llast = NULL; //loc symb head n tail
							
									}
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 210 "tree_9.y" /* yacc.c:1646  */
    {
									  (yyvsp[-6])->gentry = glookup((yyvsp[-6])->name);
									  if((yyvsp[-6])->gentry == NULL)
										yyerror("function not declared");
									  (yyvsp[-6])->type = (yyvsp[-6])->gentry->type;
									  if( gettype((yyvsp[-6])) != glob_type )
									    yyerror("function return type not matched in decln nd defn");

									   
									   (yyvsp[-6])->arglist = arg_head;
									   (yyvsp[-6])->nodetype = 12;
									   if( typecheck((yyvsp[-6])->arglist,(yyvsp[-6])->gentry->garg_list) == 0)
									    yyerror("No of arguments are not matched in fn dec n def");
										(yyvsp[-6])->ptr1 = (yyvsp[-1]);
										
									  machinecode((yyvsp[-6]));
										printf("funcdef\n");
									  loc_bind_count = 1;
									  arg_head = NULL;
									  arg_tail = NULL;
									  lfirst = NULL; llast = NULL; //loc symb head n tail
							
									}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 236 "tree_9.y" /* yacc.c:1646  */
    {
						(yyvsp[0])->gentry = glookup((yyvsp[0])->name);
						if((yyvsp[0])->gentry == NULL)
								yyerror("function not declared");
						struct tnode *find_count = glookup((yyvsp[0])->name)->garg_list;
						func_params_count = 0;
						while(find_count != NULL)
						{
							func_params_count += 1;
							find_count = find_count->arg_next;
						}
						loc_bind_count = -2+(-1*func_params_count);
						(yyval) = (yyvsp[0]);
					}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 254 "tree_9.y" /* yacc.c:1646  */
    { ginstall((yyvsp[-6])->name,0,0,NULL,"-1");
									  (yyvsp[-6])->gentry = glookup((yyvsp[-6])->name);
									  (yyvsp[-6])->type = (yyvsp[-6])->gentry->type;
									  if( gettype((yyvsp[-6])) != glob_type )
									    yyerror("function return type not matched in decln nd defn");

									   printf("in main\n");
									   (yyvsp[-6])->arglist = arg_head;
									   (yyvsp[-6])->nodetype = 12;
										(yyvsp[-6])->ptr1 = (yyvsp[-1]);
										
									  machinecode((yyvsp[-6]));
									  loc_bind_count = 1;
									  arg_head = NULL;
									  arg_tail = NULL;
									  lfirst = NULL; llast = NULL; //loc symb head n tail
									}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 274 "tree_9.y" /* yacc.c:1646  */
    {glob_type = 0;
					printf("main type\n");				
				}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 293 "tree_9.y" /* yacc.c:1646  */
    {	arg_glob_type = 0;
					printf("arg_type2\n");
				}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 297 "tree_9.y" /* yacc.c:1646  */
    {arg_glob_type = 2;}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 307 "tree_9.y" /* yacc.c:1646  */
    {
					(yyvsp[0])->type = arg_glob_type;
					(yyvsp[0])->is_pointer = 0;
					arg_make((yyvsp[0]));
					linstall((yyvsp[0])->name,(yyvsp[0])->type,(yyvsp[0])->is_pointer);
				}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 314 "tree_9.y" /* yacc.c:1646  */
    {
					(yyvsp[0])->type = arg_glob_type;
					(yyvsp[0])->is_pointer = 1;
					arg_make((yyvsp[0]));
					linstall((yyvsp[0])->name,(yyvsp[0])->type,(yyvsp[0])->is_pointer);
				}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 324 "tree_9.y" /* yacc.c:1646  */
    {printf("local def\n");}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 328 "tree_9.y" /* yacc.c:1646  */
    {printf("lilist\n");}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 330 "tree_9.y" /* yacc.c:1646  */
    {printf("empty lclist\n");}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 334 "tree_9.y" /* yacc.c:1646  */
    {printf("lstmt\n");}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 338 "tree_9.y" /* yacc.c:1646  */
    {	loc_type = 0;
					//printf("chk_int\n");
				}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 342 "tree_9.y" /* yacc.c:1646  */
    {loc_type = 2;}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 353 "tree_9.y" /* yacc.c:1646  */
    { 	
					(yyvsp[0])->type = loc_type + 0 ;
					(yyvsp[0])->is_pointer = 0;
					
					linstall((yyvsp[0])->name,(yyvsp[0])->type,(yyvsp[0])->is_pointer);
					printf("in local id\n");
					
		
				}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 365 "tree_9.y" /* yacc.c:1646  */
    { printf("body\n");
							(yyval) = (struct tnode *)malloc(sizeof(struct tnode));
					  (yyval)->nodetype = 14;
					  (yyval)->ptr1 = (yyvsp[-2]);
					  (yyval)->ptr2 = NULL; (yyval)->ptr3 = (yyvsp[-1]);
					  //machinecode($$);	
					}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 375 "tree_9.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 377 "tree_9.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 381 "tree_9.y" /* yacc.c:1646  */
    {
					if(gettype((yyvsp[-1])) != glob_type)
						yyerror("return type not matched");
					(yyvsp[-2])->ptr1 = (yyvsp[-1]);(yyval) = (yyvsp[-2]);
				}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 389 "tree_9.y" /* yacc.c:1646  */
    {(yyval)=(struct tnode *)malloc(sizeof(struct tnode));
			(yyval)->nodetype=6;
			(yyval)->ptr1=(yyvsp[-1]);
			(yyval)->ptr3=(yyvsp[0]);}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 394 "tree_9.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 397 "tree_9.y" /* yacc.c:1646  */
    { printf("ch_assgn %s\n",(yyvsp[-3])->name);
						(yyvsp[-3])->lentry = llookup((yyvsp[-3])->name);
						 printf("assgn\n");
						
						printf("type\n");
						if((yyvsp[-3])->lentry == NULL )
						{
							(yyvsp[-3])->gentry = glookup((yyvsp[-3])->name);
							if((yyvsp[-3])->gentry == NULL )
							{
								yyerror("variable not declared");

							}
							else if((yyvsp[-3])->gentry->func_redef == 1)
								yyerror("assigning variable is a function");
							(yyvsp[-3])->type = (yyvsp[-3])->gentry->type;

						}
						else
							(yyvsp[-3])->type = (yyvsp[-3])->lentry->type;
						
						if(gettype((yyvsp[-3])) != gettype((yyvsp[-1])))
							yyerror("type conflicts in assignment");

						if((yyvsp[-3])->type == 1 || (yyvsp[-3])->type == 3 )
							yyerror("variable declared is an array");			
						(yyvsp[-2])->ptr1=(yyvsp[-3]);(yyvsp[-2])->ptr3=(yyvsp[-1]);(yyval)=(yyvsp[-2]);
					 
						
					}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 429 "tree_9.y" /* yacc.c:1646  */
    { 
						
						
						(yyvsp[-6])->gentry = glookup((yyvsp[-6])->name);
						if((yyvsp[-6])->gentry == NULL )
						{
							yyerror("variable not declared");

						}
						else if((yyvsp[-6])->gentry->func_redef == 1)
								yyerror("assigning variable is a function");
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
#line 1866 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 455 "tree_9.y" /* yacc.c:1646  */
    { 	
						//printf("in read token\n");
						(yyvsp[-2])->lentry = llookup((yyvsp[-2])->name);
						
						if((yyvsp[-2])->lentry == NULL )
						{
							(yyvsp[-2])->gentry = glookup((yyvsp[-2])->name);
							if((yyvsp[-2])->gentry == NULL )
							{
								yyerror("variable not declared");

							}
							else if((yyvsp[-2])->gentry->func_redef == 1)
								yyerror("reading variable is a function");
							(yyvsp[-2])->type = (yyvsp[-2])->gentry->type;

						}
						else
							(yyvsp[-2])->type = (yyvsp[-2])->lentry->type;
						if(gettype((yyvsp[-2])) != 0)
							yyerror("variable used in READ is not int type");
						if((yyvsp[-2])->type == 1 || (yyvsp[-2])->type == 3 )
							yyerror("variable declared is an array");			
						
						(yyvsp[-4])->ptr1=(yyvsp[-2]);(yyvsp[-4])->ptr3=NULL;(yyval)=(yyvsp[-4]);
					}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 482 "tree_9.y" /* yacc.c:1646  */
    { 	
								//printf("in read token\n");
								
							
								(yyvsp[-5])->gentry = glookup((yyvsp[-5])->name);
							
								if((yyvsp[-5])->gentry == NULL)
									yyerror("variable not declared");
								else if((yyvsp[-5])->gentry->func_redef == 1)
									yyerror("reading variable is a function");

								else
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
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 511 "tree_9.y" /* yacc.c:1646  */
    { 	printf("ch1\n");
						if(gettype((yyvsp[-2])) != 0)
						{	//printf("gettype %d\n",gettype($3));
							yyerror("expression in READ is not int type");			
						}
						(yyvsp[-4])->ptr1=(yyvsp[-2]);(yyvsp[-4])->ptr3=NULL;(yyval)=(yyvsp[-4]);
						//printf("ch1\n");
					}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 520 "tree_9.y" /* yacc.c:1646  */
    {(yyvsp[-8])->ptr1=(yyvsp[-6]);(yyvsp[-8])->ptr2=(yyvsp[-3]);(yyvsp[-8])->ptr3=(yyvsp[-2]);(yyval)=(yyvsp[-8]);}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 522 "tree_9.y" /* yacc.c:1646  */
    {(yyvsp[-7])->ptr1=(yyvsp[-5]);(yyvsp[-7])->ptr3=(yyvsp[-2]);(yyval)=(yyvsp[-7]);}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 528 "tree_9.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 530 "tree_9.y" /* yacc.c:1646  */
    {(yyval) = NULL;}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 535 "tree_9.y" /* yacc.c:1646  */
    {
						(yyval)=(yyvsp[0]);
						//printf("chk_dig\n");
					}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 540 "tree_9.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 542 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in addition operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 550 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in subtraction operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 558 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in multiplication operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 566 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in division operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 574 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in modulo operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 582 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 590 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 598 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 606 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 614 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 622 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 0  || gettype((yyvsp[0])) != 0)
							yyerror("type conflicts in relational operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 630 "tree_9.y" /* yacc.c:1646  */
    {	printf("expr_ID %s\n",(yyvsp[0])->name);
						(yyvsp[0])->lentry = llookup((yyvsp[0])->name);
						
						if((yyvsp[0])->lentry == NULL )
						{
							(yyvsp[0])->gentry = glookup((yyvsp[0])->name);
							
							if((yyvsp[0])->gentry == NULL)
								yyerror("variable not declared");
							else if((yyvsp[0])->gentry->func_redef == 1)
								yyerror("passing function format is wrong");
							else
								(yyvsp[0])->type = (yyvsp[0])->gentry->type;

						}
						
						else
							(yyvsp[0])->type = (yyvsp[0])->lentry->type;
						
						if((yyvsp[0])->type == 1 || (yyvsp[0])->type == 3 )
							yyerror("variable declared is an array");
						
						(yyval) = (yyvsp[0]);
					}
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 655 "tree_9.y" /* yacc.c:1646  */
    {
						
							(yyvsp[-3])->gentry = glookup((yyvsp[-3])->name);
							
							if((yyvsp[-3])->gentry == NULL)
								yyerror("variable not declared");
							else if((yyvsp[-3])->gentry->func_redef == 1)
								yyerror("passing function format is wrong");

							else
								(yyvsp[-3])->type = (yyvsp[-3])->gentry->type;

						if( ((yyvsp[-3])->type == 0) || ((yyvsp[-3])->type == 2) )
							yyerror("variable is not an array");

						if(gettype((yyvsp[-1]))!=0)
							yyerror("array index is not an integer");

						(yyvsp[-3])->ptr1 = (yyvsp[-1]);
						(yyvsp[-3])->ptr3 = NULL;
						(yyval) = (yyvsp[-3]);
					}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 678 "tree_9.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 680 "tree_9.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 682 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 2  || gettype((yyvsp[0])) != 2)
							yyerror("type conflicts in logical operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 690 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[-2])) != 2  || gettype((yyvsp[0])) != 2)
							yyerror("type conflicts in logical operation");
						(yyvsp[-1])->ptr1=(yyvsp[-2]);
					 	(yyvsp[-1])->ptr3=(yyvsp[0]);
					 	(yyval)=(yyvsp[-1]);
					}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 698 "tree_9.y" /* yacc.c:1646  */
    {
						if(gettype((yyvsp[0])) != 2)
							yyerror("type conflicts in logical operation");
						(yyvsp[-1])->ptr1=(yyvsp[0]);
					 	(yyvsp[-1])->ptr3=NULL;
					 	(yyval)=(yyvsp[-1]);
					}
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 706 "tree_9.y" /* yacc.c:1646  */
    {	
						(yyvsp[-3])->gentry = glookup((yyvsp[-3])->name);
						if((yyvsp[-3])->gentry == NULL )
						{
							yyerror("function not declared");

						}
						(yyvsp[-3])->type = (yyvsp[-3])->gentry->type;
						(yyvsp[-3])->nodetype = 15;
						if( ((yyvsp[-3])->type == 1) || ((yyvsp[-3])->type == 3) )
							yyerror("function name is declared as an array type");
						(yyvsp[-1])->arg_previous = NULL;
						param_check((yyvsp[-1]),(yyvsp[-3])->gentry->garg_list);
						printf("func call1\n");
						(yyvsp[-3])->ptr1 = (yyvsp[-1]);
						(yyvsp[-3])->ptr3 = NULL;
						(yyval) = (yyvsp[-3]);
						call_head = NULL; call_tail = NULL;
						
						
					}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 728 "tree_9.y" /* yacc.c:1646  */
    {
						(yyvsp[-2])->gentry = glookup((yyvsp[-2])->name);
						if((yyvsp[-2])->gentry == NULL )
						{
							yyerror("function not declared");

						}
						(yyvsp[-2])->type = (yyvsp[-2])->gentry->type;
						(yyvsp[-2])->nodetype = 15;
						if( ((yyvsp[-2])->type == 1) || ((yyvsp[-2])->type == 3) )
							yyerror("function name is declared as an array type");

						if((yyvsp[-2])->gentry->garg_list != NULL)
							yyerror("no of arguments not matched in fuction call");

						(yyvsp[-2])->ptr1 = NULL;
						(yyvsp[-2])->ptr3 = NULL;
						(yyval) = (yyvsp[-2]);
					}
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 750 "tree_9.y" /* yacc.c:1646  */
    {	//make_call_list($3);
						
        
        						(yyvsp[0])->arg_next = (yyvsp[-2]);
       							 (yyvsp[-2])->arg_previous = (yyvsp[0]);(yyvsp[-2]) = (yyvsp[0]);
        						(yyval)= (yyvsp[-2]);
   						 
						printf("expr_list1\n");
					}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 760 "tree_9.y" /* yacc.c:1646  */
    {
						//make_call_list($1);
						(yyvsp[0])->arg_next = NULL;
						(yyvsp[0])->arg_previous = NULL;
						(yyval) = (yyvsp[0]);
						printf("expr_list2\n");
					}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2298 "y.tab.c" /* yacc.c:1646  */
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
#line 770 "tree_9.y" /* yacc.c:1906  */


void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	exit(0);
}

int machinecode(struct tnode *tree)
{
    int r,r1;
    if(file_open == 0)
	{
		fp = fopen("mach.asm","w+");
		fprintf(fp,"START\n");
		fprintf(fp,"MOV SP, %d\n",bind_count-1);
		fprintf(fp,"MOV BP, SP\n");
		r = getreg();
		fprintf(fp,"PUSH R%d\n",r);
		freereg(r);
		fprintf(fp,"CALL MAIN\n");
		r = getreg();
		fprintf(fp,"POP R%d\n",r);
		freereg(r);
		fprintf(fp,"HALT\n");
		file_open = 1;
	}
	printf("machcode\n");
     codegen(tree);
     if( strcmp(tree->name, "main") == 0 )
	{
		
		fclose(fp);
		exit(0);
	}

	return 0;

}

int codegen(struct tnode *nd){
	int r, r1, r2, l,l1,l2,loc_var_count=0, i=0, call_var_count = 0, param_count =0,ret_reg;
	int loc ;
	struct tnode *find_count;
	struct lsymbol *find_count2;

	if(nd->nodetype == 12)
	{
	   	if( strcmp(nd->name, "main") == 0 )
			fprintf(fp,"MAIN:\n");
		else
			fprintf(fp,"L%s:\n",nd->gentry->func_label);
		fprintf(fp,"PUSH BP\n");
		fprintf(fp,"MOV BP, SP\n");
		
		find_count2 = lfirst;
		while(find_count2 != NULL)
		{
			loc_var_count += 1;
			find_count2 = find_count2->next;
		}

		find_count = nd->gentry->garg_list;
		func_params_count =0;
		while(find_count != NULL)
		{
			func_params_count += 1;
			find_count = find_count->arg_next;
		}

		printf("func_params_count %d\n",func_params_count);
		loc_var_count = loc_var_count - func_params_count ; 
		r = getreg();
		r1 = getreg();
		fprintf(fp,"MOV R%d, %d\n",r1,loc_var_count);
		fprintf(fp,"MOV R%d, SP\n",r);
		fprintf(fp,"ADD R%d, R%d\n",r,r1);
		fprintf(fp,"MOV SP, R%d\n",r);
		freereg(r1);
		freereg(r);
		
		r = codegen(nd->ptr1);
		printf("node 12\n");

	}

	if(nd->nodetype == 14)
	{	if(nd->ptr1 != NULL)
			codegen(nd->ptr1);
		//printf("node 14\n");
		if(nd->ptr3 != NULL)
			codegen(nd->ptr3);
		return 1;
	}

	if(nd->nodetype == 11)
	{	printf("node 11\n");
		r = codegen(nd->ptr1);
		r1 = getreg();
		r2 = getreg();
		fprintf(fp,"MOV R%d, BP\n",r1);
		fprintf(fp,"MOV R%d, 2\n",r2);
		fprintf(fp,"SUB R%d, R%d\n",r1,r2);
		freereg(r2);
		fprintf(fp,"MOV [R%d], R%d\n",r1,r);
		freereg(r1);
		freereg(r);
		fprintf(fp,"MOV SP, BP\n");
		fprintf(fp,"POP BP\n");
		fprintf(fp,"RET\n");
		return 1;
		//for return
	}

	if(nd->nodetype == 15)
	{
		for(i=0; i <= reg_count ; i++)
			fprintf(fp,"PUSH R%d\n",i);

		if(nd->ptr1 != NULL)
		{
			struct tnode *push_params = nd->ptr1;
			struct tnode *temp;
			while(push_params->arg_next != NULL)
			{
				temp = push_params;
				push_params = push_params->arg_next;
				push_params->arg_previous = temp;

			}
			
		   while(push_params != NULL)
		   {
			if(push_params->refer_pointer == 1)
			{
				loc = getbind(push_params);
				if(push_params->lentry != NULL)
				{
					r2 = getreg();
					r1 = getreg();
				
					fprintf(fp,"MOV R%d, %d\n",r1,loc);
					fprintf(fp,"MOV R%d, BP\n",r2);
					fprintf(fp,"ADD R%d, R%d\n",r2,r1);
					if(push_params->lentry->pointer_type == 1)
					{
						fprintf(fp,"MOV R%d, [R%d]\n",r1,r2);
						fprintf(fp,"PUSH R%d\n",r1);
					}
					else
						fprintf(fp,"PUSH R%d\n",r2);
					freereg(r1);
					freereg(r2);
				}

				else
				{
				   if(push_params->ptr1 == NULL) // normal id
				   {	r1 = getreg();
					fprintf(fp,"MOV R%d, %d\n",r1,loc);
					fprintf(fp,"PUSH R%d\n",r1);
					freereg(r1);
				   }

				   else 			// array id
				   {	r1 = getreg();
					r2 = codegen(push_params->ptr1);
					fprintf(fp,"MOV R%d, %d\n",r1,loc);
					fprintf(fp,"ADD R%d, R%d\n",r1,r2);
					fprintf(fp,"PUSH R%d\n",r1);
					freereg(r1);
					freereg(r2);
				   }	
			
				}
				
			}

			else
			{	
				r = codegen(push_params);
				fprintf(fp,"PUSH R%d\n",r);
				freereg(r);
			}

			push_params = push_params->arg_previous;
		  }
		}
		
		r = getreg();
		fprintf(fp,"PUSH R%d\n",r);  //space for return value
		freereg(r);
		fprintf(fp,"CALL L%s\n",nd->gentry->func_label);
		r= getreg();
		fprintf(fp,"POP R%d\n",r);
		ret_reg = r;
		find_count = nd->gentry->garg_list;
		while(find_count != NULL)
		{
			param_count += 1;
			find_count = find_count->arg_next;
		}
		
		r = getreg();
		r1 = getreg();
		fprintf(fp,"MOV R%d, %d\n",r1,param_count);
		fprintf(fp,"MOV R%d, SP\n",r);
		fprintf(fp,"SUB R%d, R%d\n",r,r1);
		fprintf(fp,"MOV SP, R%d\n",r);
		freereg(r1);
		freereg(r);

		for(i=reg_count-1; i >= 0 ; i--)    //reg_count-1 is because 1 reg we added for ret val
			fprintf(fp,"POP R%d\n",i);

		return ret_reg; // equals to reg_count only
		
		//func call
	}

	if(nd->nodetype==0)
	{
		r = getreg();
		fprintf(fp,"MOV R%d, %d\n",r,nd->value);
		printf("node digit\n");
		return r;
		//return nd->value;
	}

	if((nd->type==0 || nd->type == 2) && nd->nodetype ==2 )
	{
		r = getreg();
		loc = getbind(nd) ;
		if(nd->lentry != NULL)
		{
			
			r1 = getreg();
			r2 = getreg();
			fprintf(fp,"MOV R%d, %d\n",r2,loc);
			fprintf(fp,"MOV R%d, BP\n",r1);
			fprintf(fp,"ADD R%d, R%d\n",r1,r2);
			fprintf(fp,"MOV R%d, [R%d]\n",r,r1);
			if(nd->lentry->pointer_type == 1)
			{
				fprintf(fp,"MOV R%d, [R%d]\n",r2,r);
				fprintf(fp,"MOV R%d, R%d\n",r,r2);
			}
			
			freereg(r1);
			freereg(r2);
			return r;
				
		}
		else
			fprintf(fp,"MOV R%d, [%d]\n",r,loc);

		printf("node norm id\n");
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
		printf("node array id\n");
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
				if(nd->ptr1->lentry != NULL)
				{	
					r1 = getreg();
					r2 = getreg();
					fprintf(fp,"MOV R%d, %d\n",r2,loc);
					fprintf(fp,"MOV R%d, BP\n",r1);
					fprintf(fp,"ADD R%d, R%d\n",r1,r2);

					//fprintf(fp,"MOV R%d, [R%d]\n",r,r1);
					if(nd->ptr1->lentry->pointer_type == 1)
					{
						fprintf(fp,"MOV R%d, [R%d]\n",r2,r1);
						fprintf(fp,"MOV [R%d], R%d\n",r2,r);
					}
					else
						fprintf(fp,"MOV [R%d], R%d\n",r1,r);
						
					freereg(r1);
					freereg(r2);
					
				}
				else
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
			printf("node assgn\n");

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

		else if(strcmp(nd->name,"%") == 0)
		{
			r1 = codegen(nd->ptr1);
			r2 = codegen(nd->ptr3);
			fprintf(fp,"MOD R%d, R%d\n",r1,r2);
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
			if(nd->ptr1->lentry != NULL)
			{
				r1 = getreg();
				r2 = getreg();
				fprintf(fp,"MOV R%d, %d\n",r2,loc);
				fprintf(fp,"MOV R%d, BP\n",r1);
				fprintf(fp,"ADD R%d, R%d\n",r1,r2);
				fprintf(fp,"MOV [R%d], R%d\n",r1,r);
				freereg(r2);
				freereg(r1);
			}
			else
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
		printf("node 4 write\n");
		return 1;
			

	}

	if(nd->nodetype==6)
	{ 	
		codegen(nd->ptr1);
		printf("node 6\n");
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

	if(addr->lentry != NULL)
		return(addr->lentry->binding[0]);
	else
		return(addr->gentry->binding[0]);

}

void arg_make(struct tnode *arg_entry)
{
	struct tnode *arg_temp;
	if(arg_head == arg_tail && arg_head == NULL)
	{
		arg_head = arg_entry;
		arg_tail = arg_entry;
		arg_head->arg_next = NULL;
		arg_tail->arg_next = NULL;
	}

	else
	{
		arg_temp = arg_head;
		arg_head = arg_entry;
		arg_head->arg_next = arg_temp;
	}

	return;
}

int typecheck(struct tnode *arg1, struct tnode *arg2)
{
	while( (arg1 != NULL) && (arg2 != NULL))
	{
		if(arg1->type != arg2->type)
			yyerror("argmnts type not matched in function decln and defn");
		if( strcmp(arg1->name, arg2->name) !=0 )
		{
			printf("argnames %s %s\n",arg1->name,arg2->name);
			yyerror("argmnts name not matched or no of args not equal in function decln and defn ");
		}
		printf("argnames %s %s\n",arg1->name,arg2->name);
		if(arg1->is_pointer != arg2->is_pointer)
			yyerror("pointer argmnts  name not matched in function decln and defn");
		arg1 = arg1->arg_next;
		arg2 = arg2->arg_next;
	}

	if((arg1 == NULL) && (arg2 == NULL))	//----- both are null
		return 1;
	else
		return 0;
}

void param_check(struct tnode *arg1,struct tnode *arg2)
{
	while(arg1 != NULL && arg2 != NULL)
	{
		if( gettype(arg1) != gettype(arg2) )
			
		{	printf("gettype %d %d\n",gettype(arg1),gettype(arg2));
			yyerror("argments passing types not matched or unequal args are passing in fuction call");
			
			//printf("paramcheck %d %d\n",arg1->ptr3->type,arg2->type);
		}
		printf("param name %s %s\n",arg1->name,arg2->name);

		if( arg2->is_pointer == 1 )
		{
			if(arg1->nodetype != 2)
				yyerror("pass by reference not matched in function call");

			arg1->refer_pointer = 1;
			
		}

		arg1 = arg1->arg_next;
		arg2 = arg2->arg_next;
	}

	if(arg1 != NULL || arg2 != NULL)
		yyerror("number of argmnts not matched in function call ");
	return;
}

void make_call_list(struct tnode *newnode)
{
    if (call_head == NULL)
    {
        
        call_head = newnode;
        call_tail = call_head;
    }
    else
    {
        
        newnode->arg_next = call_head;
        call_head->arg_previous = newnode;
        call_head = newnode;
    }
    return;
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

