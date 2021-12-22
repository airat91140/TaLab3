/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_END = 3,                        /* END  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_BOOL = 5,                       /* BOOL  */
  YYSYMBOL_id = 6,                         /* id  */
  YYSYMBOL_SWITCH = 7,                     /* SWITCH  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_PRINT = 9,                      /* PRINT  */
  YYSYMBOL_BOUNDARY = 10,                  /* BOUNDARY  */
  YYSYMBOL_STEP = 11,                      /* STEP  */
  YYSYMBOL_MOVE = 12,                      /* MOVE  */
  YYSYMBOL_ROTATE = 13,                    /* ROTATE  */
  YYSYMBOL_LEFT = 14,                      /* LEFT  */
  YYSYMBOL_RIGHT = 15,                     /* RIGHT  */
  YYSYMBOL_GET = 16,                       /* GET  */
  YYSYMBOL_ENVIRONMENT = 17,               /* ENVIRONMENT  */
  YYSYMBOL_TASK = 18,                      /* TASK  */
  YYSYMBOL_RESULT = 19,                    /* RESULT  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_PLEASE = 21,                    /* PLEASE  */
  YYSYMBOL_VAR = 22,                       /* VAR  */
  YYSYMBOL_PLSX = 23,                      /* PLSX  */
  YYSYMBOL_THANKS = 24,                    /* THANKS  */
  YYSYMBOL_SWITCHX = 25,                   /* SWITCHX  */
  YYSYMBOL_HIGHSWITCHX = 26,               /* HIGHSWITCHX  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_DIGITIZE = 32,                  /* DIGITIZE  */
  YYSYMBOL_REDUCE = 33,                    /* REDUCE  */
  YYSYMBOL_EXTEND = 34,                    /* EXTEND  */
  YYSYMBOL_SIZE = 35,                      /* SIZE  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_LOGITIZE = 37,                  /* LOGITIZE  */
  YYSYMBOL_MXEQ = 38,                      /* MXEQ  */
  YYSYMBOL_MXLT = 39,                      /* MXLT  */
  YYSYMBOL_MXGT = 40,                      /* MXGT  */
  YYSYMBOL_MXLTE = 41,                     /* MXLTE  */
  YYSYMBOL_MXGTE = 42,                     /* MXGTE  */
  YYSYMBOL_ELEQ = 43,                      /* ELEQ  */
  YYSYMBOL_ELLT = 44,                      /* ELLT  */
  YYSYMBOL_ELGT = 45,                      /* ELGT  */
  YYSYMBOL_ELLTE = 46,                     /* ELLTE  */
  YYSYMBOL_ELGTE = 47,                     /* ELGTE  */
  YYSYMBOL_MXFALSE = 48,                   /* MXFALSE  */
  YYSYMBOL_MXTRUE = 49,                    /* MXTRUE  */
  YYSYMBOL_50_n_ = 50,                     /* '\n'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '('  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* '='  */
  YYSYMBOL_55_ = 55,                       /* '['  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_program = 58,                   /* program  */
  YYSYMBOL_functions = 59,                 /* functions  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_ids = 61,                       /* ids  */
  YYSYMBOL_indexes = 62,                   /* indexes  */
  YYSYMBOL_stmtsGroup = 63,                /* stmtsGroup  */
  YYSYMBOL_stmts = 64,                     /* stmts  */
  YYSYMBOL_stmt = 65,                      /* stmt  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_expr = 67,                      /* expr  */
  YYSYMBOL_arith = 68,                     /* arith  */
  YYSYMBOL_logic = 69                      /* logic  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      50,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,    30,    28,    51,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    58,    59,    62,    76,    77,    79,    80,
      81,    83,    85,    86,    88,    89,    90,    91,    95,    99,
     103,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   126,   127,   128,
     129,   134,   135,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "END", "INTEGER",
  "BOOL", "id", "SWITCH", "FOR", "PRINT", "BOUNDARY", "STEP", "MOVE",
  "ROTATE", "LEFT", "RIGHT", "GET", "ENVIRONMENT", "TASK", "RESULT", "DO",
  "PLEASE", "VAR", "PLSX", "THANKS", "SWITCHX", "HIGHSWITCHX", "AND",
  "'+'", "'-'", "'*'", "'/'", "DIGITIZE", "REDUCE", "EXTEND", "SIZE",
  "NOT", "LOGITIZE", "MXEQ", "MXLT", "MXGT", "MXLTE", "MXGTE", "ELEQ",
  "ELLT", "ELGT", "ELLTE", "ELGTE", "MXFALSE", "MXTRUE", "'\\n'", "','",
  "'('", "')'", "'='", "'['", "']'", "$accept", "program", "functions",
  "function", "ids", "indexes", "stmtsGroup", "stmts", "stmt",
  "parameters", "expr", "arith", "logic", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-77)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -109,    14,    10,  -109,    65,  -109,    74,  -109,    -1,  -109,
      38,   199,  -109,    28,   151,    88,   103,    64,    78,   112,
     117,   199,   118,  -109,    31,    98,   103,   103,  -109,    70,
     120,   121,   151,   122,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,   151,   151,   151,   -19,   124,  -109,
      99,     3,   160,   161,   162,   163,   103,   125,    71,   143,
    -109,   126,   127,   128,   173,   -18,    50,  -109,    98,   130,
     131,   -39,  -109,   103,   146,   154,  -109,  -109,   155,   176,
     177,    63,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,  -109,  -109,   -20,   151,   181,   207,   103,  -109,
    -109,  -109,   159,   167,  -109,    58,  -109,    63,    63,    63,
      63,  -109,  -109,  -109,   168,     4,  -109,   108,   103,  -109,
    -109,   103,   170,   -38,   211,   212,   103,   171,   172,  -109,
    -109,   152,   206,   -30,   221,   224,  -109,    86,    86,  -109,
    -109,   103,   174,  -109,   180,   182,   -27,  -109,   103,  -109,
     175,   178,   -26,   229,   231,   186,    -9,   232,   210,   183,
     184,    17,   103,  -109,  -109,   187,   192,  -109,  -109,  -109,
     188,   189,   238,   241,   152,   220,   223,  -109,    21,   116,
    -109,  -109,  -109,   152,   152,   198,    -8,  -109,   201,   202,
     203,    -5,  -109,    24,  -109,  -109,  -109,  -109,  -109,  -109,
    -109
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     3,     0,     7,     0,     6,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,    13,     0,    10,    58,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      59,     0,     0,     0,     0,     0,     0,     0,    41,    42,
      31,     0,     0,     0,     0,     0,     0,    11,    12,     0,
       0,     0,     9,    10,     0,     0,    61,    62,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,     0,     0,    10,    55,
      54,    48,     0,     0,    49,     0,    35,     0,     0,     0,
       0,    29,    30,    36,    39,     0,    33,     0,    10,    34,
      15,     0,     0,     0,     0,     0,    10,     0,     0,    56,
      57,     0,     0,     0,     0,     0,    44,    50,    51,    52,
      53,    10,    37,    32,     0,     0,     0,     8,     0,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    45,     0,
       0,     0,    10,    19,    17,     0,     0,    75,    76,    45,
       0,     0,    26,    23,     0,    46,    47,    40,     0,     0,
      16,    46,    47,     0,     0,     0,     0,    38,     0,     0,
       0,     0,    25,     0,    21,    22,    20,    18,    28,    27,
      24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -109,  -109,  -109,  -109,  -109,   -71,  -108,  -109,   -21,  -109,
     -15,    22,   -10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     5,     8,    71,    12,    24,    25,   115,
      72,    58,    59
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    57,   123,    68,    47,     9,    69,    95,    95,    99,
     142,    70,   121,   121,     3,    69,    69,   122,   149,    69,
     100,   121,    76,   155,   121,   121,   158,   133,     4,   165,
     169,    96,   116,   129,    92,    93,    94,    13,    14,    15,
      16,   173,   195,    17,    18,   199,    94,   146,    69,    10,
      19,    20,    21,    22,   143,   152,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   185,    49,   121,    78,
     161,     6,   121,   177,   200,   190,   192,   187,   105,    51,
       7,    23,    26,    27,    67,   130,   107,   108,   109,   110,
      11,   178,    61,    62,    48,    52,    79,    80,    55,   107,
     108,   109,   110,   105,   117,   118,   147,    49,    28,    50,
     156,   136,   144,   145,    60,    81,   109,   110,    63,    51,
     188,   189,    69,    64,    66,    73,    74,    75,    77,   137,
     138,   139,   140,   166,    97,    52,    53,    54,    55,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,   186,    98,    56,    28,    29,    13,    14,
      15,    16,   191,   193,    17,    18,   101,   102,   103,   104,
      95,    19,    20,    21,    22,   106,   111,   112,   113,   114,
     119,   120,   127,   128,    30,    31,   131,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,   124,    23,    46,    11,    13,    14,    15,    16,   125,
     126,    17,    18,   132,   134,   150,   151,   157,    19,    20,
      21,    22,   135,   141,   148,   159,   153,   154,   160,   162,
     163,   167,   164,   170,   168,   171,   172,   -60,   174,   175,
     176,   179,   180,   183,   181,   182,   184,   -75,   194,    23,
     -76,   196,   197,   198
};

static const yytype_uint8 yycheck[] =
{
      21,    16,    73,    24,    14,     6,    24,    27,    27,     6,
       6,    26,    51,    51,     0,    24,    24,    56,    56,    24,
      17,    51,    32,   131,    51,    51,    56,    98,    18,    56,
      56,    50,    50,    53,    44,    45,    46,     6,     7,     8,
       9,    50,    50,    12,    13,    50,    56,   118,    24,    50,
      19,    20,    21,    22,    50,   126,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   174,     4,    51,     6,
     141,     6,    51,    56,    50,   183,   184,    56,    56,    16,
       6,    50,    54,    55,    53,    95,    28,    29,    30,    31,
      52,   162,    14,    15,     6,    32,    33,    34,    35,    28,
      29,    30,    31,    81,    54,    55,   121,     4,     5,     6,
     131,    53,     4,     5,    50,    52,    30,    31,     6,    16,
       4,     5,    24,     6,     6,    55,     6,     6,     6,   107,
     108,   109,   110,   148,    10,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,   174,    55,    52,     5,     6,     6,     7,
       8,     9,   183,   184,    12,    13,     6,     6,     6,     6,
      27,    19,    20,    21,    22,    50,    50,    50,    50,     6,
      50,    50,     6,     6,    33,    34,     5,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    55,    50,    52,    52,     6,     7,     8,     9,    55,
      55,    12,    13,     6,    55,     4,     4,    11,    19,    20,
      21,    22,    55,    55,    54,     4,    55,    55,     4,    55,
      50,    56,    50,     4,    56,     4,    50,    27,     6,    56,
      56,    54,    50,     5,    56,    56,     5,    27,    50,    50,
      27,    50,    50,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    58,    59,     0,    18,    60,     6,     6,    61,     6,
      50,    52,    63,     6,     7,     8,     9,    12,    13,    19,
      20,    21,    22,    50,    64,    65,    54,    55,     5,     6,
      33,    34,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    52,    69,     6,     4,
       6,    16,    32,    33,    34,    35,    52,    67,    68,    69,
      50,    14,    15,     6,     6,    65,     6,    53,    65,    24,
      67,    62,    67,    55,     6,     6,    69,     6,     6,    33,
      34,    52,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    69,    27,    50,    10,    55,     6,
      17,     6,     6,     6,     6,    68,    50,    28,    29,    30,
      31,    50,    50,    50,     6,    66,    50,    54,    55,    50,
      50,    51,    56,    62,    55,    55,    55,     6,     6,    53,
      69,     5,     6,    62,    55,    55,    53,    68,    68,    68,
      68,    55,     6,    50,     4,     5,    62,    67,    54,    56,
       4,     4,    62,    55,    55,    63,    65,    11,    56,     4,
       4,    62,    55,    50,    50,    56,    67,    56,    56,    56,
       4,     4,    50,    50,     6,    56,    56,    56,    62,    54,
      50,    56,    56,     5,     5,    63,    65,    56,     4,     5,
      63,    65,    63,    65,    50,    50,    50,    50,    50,    50,
      50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    61,    61,    62,    62,
      62,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     5,     2,     1,     3,     1,
       0,     3,     2,     1,     1,     4,     7,     5,     8,     5,
       8,     8,     8,     6,     9,     8,     6,     9,     9,     3,
       3,     2,     4,     3,     3,     3,     3,     2,     5,     1,
       4,     1,     1,     1,     3,     4,     5,     5,     2,     2,
       3,     3,     3,     3,     2,     2,     3,     3,     1,     1,
       4,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     5,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: functions  */
#line 48 "parser.y"
              { if (!functionsTable.contains("FINDEXIT"))
                    throw std::runtime_error("Could not find FINDEXIT function");

                functionsTable.at("FINDEXIT")->exec(new lab3::BoolConstNode(true));
                for (const auto &[key, value] : functionsTable)
                    delete value;
                exit(0);
               }
#line 1264 "parser.tab.c"
    break;

  case 3: /* functions: functions function  */
#line 58 "parser.y"
                       {functionsTable.insert({((lab3::FunctionNode *)(yyvsp[0].nPtr))->getName(), (yyvsp[0].nPtr)}); lastCall.insert({((lab3::FunctionNode *)(yyvsp[0].nPtr))->getName(), nullptr});}
#line 1270 "parser.tab.c"
    break;

  case 4: /* functions: %empty  */
#line 59 "parser.y"
             {(yyval.nPtr) = nullptr;}
#line 1276 "parser.tab.c"
    break;

  case 5: /* function: TASK id ids '\n' stmtsGroup  */
#line 62 "parser.y"
                                {auto tmp = new lab3::FunctionNode(*(yyvsp[-3].name), (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                 for (const auto &it : varTable)
                                     tmp->addVar(it.first, (lab3::AbstractVariableNode *)it.second);
                                 auto iter = (yyvsp[-2].nPtr);
                                     while (iter->nodeType == lab3::OPERATION) {
                                         tmp->addVar(((lab3::AbstractVariableNode *)(*(lab3::OperationNode *)iter)[1])->getName(), ((lab3::AbstractVariableNode *)(*(lab3::OperationNode *)iter)[1]));
                                         iter = (*(lab3::OperationNode *)iter)[0];
                                     }
                                 tmp->addVar(((lab3::AbstractVariableNode *)iter)->getName(), ((lab3::AbstractVariableNode *)iter));
                                 varTable.clear();
                                 lastCall.insert({*(yyvsp[-3].name), lastResult});
                                 (yyval.nPtr) = tmp;
                                 }
#line 1294 "parser.tab.c"
    break;

  case 6: /* ids: ids id  */
#line 76 "parser.y"
            {(yyval.nPtr) = new lab3::OperationNode(' ', 2, (yyvsp[-1].nPtr), new lab3::ParameterNode(*(yyvsp[0].name)));}
#line 1300 "parser.tab.c"
    break;

  case 7: /* ids: id  */
#line 77 "parser.y"
         {(yyval.nPtr) = new lab3::ParameterNode(*(yyvsp[0].name));}
#line 1306 "parser.tab.c"
    break;

  case 8: /* indexes: indexes ',' expr  */
#line 79 "parser.y"
                          {(yyval.nPtr) = new lab3::OperationNode(',', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1312 "parser.tab.c"
    break;

  case 9: /* indexes: expr  */
#line 80 "parser.y"
               { (yyval.nPtr) = new lab3::OperationNode(',', 1, (yyvsp[0].nPtr)); }
#line 1318 "parser.tab.c"
    break;

  case 10: /* indexes: %empty  */
#line 81 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(',', 0);}
#line 1324 "parser.tab.c"
    break;

  case 11: /* stmtsGroup: '(' stmts ')'  */
#line 83 "parser.y"
                          {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1330 "parser.tab.c"
    break;

  case 12: /* stmts: stmts stmt  */
#line 85 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode('\n', 2, (yyvsp[-1].nPtr), (yyvsp[0].nPtr));}
#line 1336 "parser.tab.c"
    break;

  case 13: /* stmts: stmt  */
#line 86 "parser.y"
            {(yyvsp[0].nPtr)->print(std::cout); (yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1342 "parser.tab.c"
    break;

  case 14: /* stmt: '\n'  */
#line 88 "parser.y"
            {new lab3::OperationNode('e', 0);}
#line 1348 "parser.tab.c"
    break;

  case 15: /* stmt: id '=' expr '\n'  */
#line 89 "parser.y"
                        {(yyval.nPtr) = new lab3::OperationNode('=', 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1354 "parser.tab.c"
    break;

  case 16: /* stmt: id '[' indexes ']' '=' expr '\n'  */
#line 90 "parser.y"
                                        {(yyval.nPtr) = new lab3::OperationNode('=', 3, varTable.at(*(yyvsp[-6].name)), (yyvsp[-4].nPtr), (yyvsp[-1].nPtr));}
#line 1360 "parser.tab.c"
    break;

  case 17: /* stmt: VAR id '=' BOOL '\n'  */
#line 91 "parser.y"
                            {if (!varTable.insert({*(yyvsp[-3].name), new lab3::BoolVariableNode(*(yyvsp[-3].name), (yyvsp[-1].boolVal)->getVal())}).second)
                                throw std::runtime_error("Variable already defined");
                             delete (yyvsp[-1].boolVal);
                             (yyval.nPtr) = new lab3::OperationNode(VAR, 0);}
#line 1369 "parser.tab.c"
    break;

  case 18: /* stmt: VAR id '[' indexes ']' '=' BOOL '\n'  */
#line 95 "parser.y"
                                            {if (!varTable.insert({*(yyvsp[-6].name), new lab3::BoolArrayVariableNode(*(yyvsp[-6].name), (yyvsp[-1].boolVal)->getVal(), lab3::AbstractVariableNode::makeDims((yyvsp[-4].nPtr)))}).second)
                                                throw std::runtime_error("Variable already defined");
                                             delete (yyvsp[-1].boolVal);
                                             (yyval.nPtr) = new lab3::OperationNode(VAR, 0);}
#line 1378 "parser.tab.c"
    break;

  case 19: /* stmt: VAR id '=' INTEGER '\n'  */
#line 99 "parser.y"
                               {if (!varTable.insert({*(yyvsp[-3].name), new lab3::IntVariableNode(*(yyvsp[-3].name), (yyvsp[-1].intVal)->getVal())}).second)
                                    throw std::runtime_error("Variable already defined");
                                delete (yyvsp[-1].intVal);
                                (yyval.nPtr) = new lab3::OperationNode(VAR, 0);}
#line 1387 "parser.tab.c"
    break;

  case 20: /* stmt: VAR id '[' indexes ']' '=' INTEGER '\n'  */
#line 103 "parser.y"
                                               {if (!varTable.insert({*(yyvsp[-6].name), new lab3::IntArrayVariableNode(*(yyvsp[-6].name), (yyvsp[-1].intVal)->getVal(), lab3::AbstractVariableNode::makeDims((yyvsp[-4].nPtr)))}).second)
                                                    throw std::runtime_error("Variable already defined");
                                                delete (yyvsp[-1].intVal);
                                                (yyval.nPtr) = new lab3::OperationNode(VAR, 0);}
#line 1396 "parser.tab.c"
    break;

  case 21: /* stmt: FOR id BOUNDARY id STEP id stmtsGroup '\n'  */
#line 107 "parser.y"
                                                  {(yyval.nPtr) = new lab3::OperationNode(FOR, 4, varTable.at(*(yyvsp[-6].name)), varTable.at(*(yyvsp[-4].name)), varTable.at(*(yyvsp[-2].name)), (yyvsp[-1].nPtr));}
#line 1402 "parser.tab.c"
    break;

  case 22: /* stmt: FOR id BOUNDARY id STEP id stmt '\n'  */
#line 108 "parser.y"
                                            {(yyval.nPtr) = new lab3::OperationNode(FOR, 4, varTable.at(*(yyvsp[-6].name)), varTable.at(*(yyvsp[-4].name)), varTable.at(*(yyvsp[-2].name)), (yyvsp[-1].nPtr));}
#line 1408 "parser.tab.c"
    break;

  case 23: /* stmt: SWITCH logic '\n' BOOL stmt '\n'  */
#line 109 "parser.y"
                                                      {(yyval.nPtr) = new lab3::OperationNode(SWITCH, 3, (yyvsp[-4].nPtr), (yyvsp[-2].boolVal), (yyvsp[-1].nPtr));}
#line 1414 "parser.tab.c"
    break;

  case 24: /* stmt: SWITCH logic '\n' BOOL stmt '\n' BOOL stmt '\n'  */
#line 110 "parser.y"
                                                                         {(yyval.nPtr) = new lab3::OperationNode(SWITCH, 5, (yyvsp[-7].nPtr), (yyvsp[-5].boolVal), (yyvsp[-4].nPtr), (yyvsp[-2].boolVal), (yyvsp[-1].nPtr));}
#line 1420 "parser.tab.c"
    break;

  case 25: /* stmt: SWITCH logic '\n' BOOL stmt '\n' BOOL stmtsGroup  */
#line 111 "parser.y"
                                                                         {(yyval.nPtr) = new lab3::OperationNode(SWITCH, 5, (yyvsp[-6].nPtr), (yyvsp[-4].boolVal), (yyvsp[-3].nPtr), (yyvsp[-1].boolVal), (yyvsp[0].nPtr));}
#line 1426 "parser.tab.c"
    break;

  case 26: /* stmt: SWITCH logic '\n' BOOL stmtsGroup '\n'  */
#line 112 "parser.y"
                                                            {(yyval.nPtr) = new lab3::OperationNode(SWITCH, 3, (yyvsp[-4].nPtr), (yyvsp[-2].boolVal), (yyvsp[-1].nPtr));}
#line 1432 "parser.tab.c"
    break;

  case 27: /* stmt: SWITCH logic '\n' BOOL stmtsGroup '\n' BOOL stmt '\n'  */
#line 113 "parser.y"
                                                                               {(yyval.nPtr) = new lab3::OperationNode(SWITCH, 5, (yyvsp[-7].nPtr), (yyvsp[-5].boolVal), (yyvsp[-4].nPtr), (yyvsp[-2].boolVal), (yyvsp[-1].nPtr));}
#line 1438 "parser.tab.c"
    break;

  case 28: /* stmt: SWITCH logic '\n' BOOL stmtsGroup '\n' BOOL stmtsGroup '\n'  */
#line 114 "parser.y"
                                                                                    {(yyval.nPtr) = new lab3::OperationNode(SWITCH, 5, (yyvsp[-7].nPtr), (yyvsp[-5].boolVal), (yyvsp[-4].nPtr), (yyvsp[-2].boolVal), (yyvsp[-1].nPtr));}
#line 1444 "parser.tab.c"
    break;

  case 29: /* stmt: ROTATE LEFT '\n'  */
#line 115 "parser.y"
                        {(yyval.nPtr) = new lab3::OperationNode(LEFT, 0);}
#line 1450 "parser.tab.c"
    break;

  case 30: /* stmt: ROTATE RIGHT '\n'  */
#line 116 "parser.y"
                         {(yyval.nPtr) = new lab3::OperationNode(RIGHT, 0);}
#line 1456 "parser.tab.c"
    break;

  case 31: /* stmt: MOVE '\n'  */
#line 117 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(MOVE, 0);}
#line 1462 "parser.tab.c"
    break;

  case 32: /* stmt: DO id parameters '\n'  */
#line 118 "parser.y"
                             {(yyval.nPtr) = new lab3::OperationNode('DO', 2, new lab3::ParameterNode(*(yyvsp[-2].name)), (yyvsp[-1].nPtr));}
#line 1468 "parser.tab.c"
    break;

  case 35: /* stmt: PRINT expr '\n'  */
#line 121 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode(PRINT, 1, (yyvsp[-1].nPtr));}
#line 1474 "parser.tab.c"
    break;

  case 36: /* stmt: RESULT id '\n'  */
#line 122 "parser.y"
                      {(yyval.nPtr) = new lab3::OperationNode(RESULT, 1, varTable.at(*(yyvsp[-1].name)));
                        lastResult = (lab3::AbstractVariableNode *)varTable.at(*(yyvsp[-1].name));
                        }
#line 1482 "parser.tab.c"
    break;

  case 37: /* parameters: parameters id  */
#line 126 "parser.y"
                          {(yyval.nPtr) = new lab3::OperationNode(' ', 2, (yyvsp[-1].nPtr), varTable.at(*(yyvsp[0].name)));}
#line 1488 "parser.tab.c"
    break;

  case 38: /* parameters: parameters id '[' indexes ']'  */
#line 127 "parser.y"
                                         {(yyval.nPtr) = new lab3::OperationNode(' ', 3, (yyvsp[-4].nPtr), varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1494 "parser.tab.c"
    break;

  case 39: /* parameters: id  */
#line 128 "parser.y"
              { (yyval.nPtr) = varTable.at(*(yyvsp[0].name)); }
#line 1500 "parser.tab.c"
    break;

  case 40: /* parameters: id '[' indexes ']'  */
#line 129 "parser.y"
                              {(yyval.nPtr) = new lab3::OperationNode('[', 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1506 "parser.tab.c"
    break;

  case 41: /* expr: arith  */
#line 134 "parser.y"
            {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1512 "parser.tab.c"
    break;

  case 42: /* expr: logic  */
#line 135 "parser.y"
            {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1518 "parser.tab.c"
    break;

  case 44: /* arith: '(' arith ')'  */
#line 138 "parser.y"
                     {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1524 "parser.tab.c"
    break;

  case 45: /* arith: id '[' indexes ']'  */
#line 139 "parser.y"
                          {(yyval.nPtr) = new lab3::OperationNode('[', 1, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1530 "parser.tab.c"
    break;

  case 46: /* arith: REDUCE id '[' INTEGER ']'  */
#line 140 "parser.y"
                                 {(yyval.nPtr) = new lab3::OperationNode(REDUCE, 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].intVal));}
#line 1536 "parser.tab.c"
    break;

  case 47: /* arith: EXTEND id '[' INTEGER ']'  */
#line 141 "parser.y"
                                 {(yyval.nPtr) = new lab3::OperationNode(EXTEND, 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].intVal));}
#line 1542 "parser.tab.c"
    break;

  case 48: /* arith: DIGITIZE id  */
#line 142 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(DIGITIZE, 1, varTable.at(*(yyvsp[0].name)));}
#line 1548 "parser.tab.c"
    break;

  case 49: /* arith: SIZE id  */
#line 143 "parser.y"
               {(yyval.nPtr) = new lab3::OperationNode(SIZE, 1, varTable.at(*(yyvsp[0].name)));}
#line 1554 "parser.tab.c"
    break;

  case 50: /* arith: arith '+' arith  */
#line 144 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode('+', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1560 "parser.tab.c"
    break;

  case 51: /* arith: arith '-' arith  */
#line 145 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode('-', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1566 "parser.tab.c"
    break;

  case 52: /* arith: arith '*' arith  */
#line 146 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode('*', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1572 "parser.tab.c"
    break;

  case 53: /* arith: arith '/' arith  */
#line 147 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode('/', 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1578 "parser.tab.c"
    break;

  case 54: /* arith: GET ENVIRONMENT  */
#line 148 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode(ENVIRONMENT, 0);}
#line 1584 "parser.tab.c"
    break;

  case 55: /* arith: GET id  */
#line 149 "parser.y"
              {(yyval.nPtr) = lastCall.at(*(yyvsp[0].name));}
#line 1590 "parser.tab.c"
    break;

  case 56: /* logic: '(' logic ')'  */
#line 151 "parser.y"
                     {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1596 "parser.tab.c"
    break;

  case 57: /* logic: logic AND logic  */
#line 152 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode(AND, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1602 "parser.tab.c"
    break;

  case 58: /* logic: BOOL  */
#line 153 "parser.y"
            {(yyval.nPtr) = (yyvsp[0].boolVal);}
#line 1608 "parser.tab.c"
    break;

  case 59: /* logic: id  */
#line 154 "parser.y"
          {(yyval.nPtr) = varTable.at(*(yyvsp[0].name));}
#line 1614 "parser.tab.c"
    break;

  case 60: /* logic: id '[' indexes ']'  */
#line 155 "parser.y"
                          {(yyval.nPtr) = new lab3::OperationNode('[', 1, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1620 "parser.tab.c"
    break;

  case 61: /* logic: NOT logic  */
#line 156 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(NOT, 1, (yyvsp[0].nPtr));}
#line 1626 "parser.tab.c"
    break;

  case 62: /* logic: LOGITIZE id  */
#line 157 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(LOGITIZE, 1, varTable.at(*(yyvsp[0].name)));}
#line 1632 "parser.tab.c"
    break;

  case 63: /* logic: MXEQ arith  */
#line 158 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(MXEQ, 1, (yyvsp[0].nPtr));}
#line 1638 "parser.tab.c"
    break;

  case 64: /* logic: MXLT arith  */
#line 159 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(MXLT, 1, (yyvsp[0].nPtr));}
#line 1644 "parser.tab.c"
    break;

  case 65: /* logic: MXGT arith  */
#line 160 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(MXGT, 1, (yyvsp[0].nPtr));}
#line 1650 "parser.tab.c"
    break;

  case 66: /* logic: MXLTE arith  */
#line 161 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(MXLTE, 1, (yyvsp[0].nPtr));}
#line 1656 "parser.tab.c"
    break;

  case 67: /* logic: MXGTE arith  */
#line 162 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(MXGTE, 1, (yyvsp[0].nPtr));}
#line 1662 "parser.tab.c"
    break;

  case 68: /* logic: ELEQ arith  */
#line 163 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(ELEQ, 1, (yyvsp[0].nPtr));}
#line 1668 "parser.tab.c"
    break;

  case 69: /* logic: ELLT arith  */
#line 164 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(ELLT, 1, (yyvsp[0].nPtr));}
#line 1674 "parser.tab.c"
    break;

  case 70: /* logic: ELGT arith  */
#line 165 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(ELGT, 1, (yyvsp[0].nPtr));}
#line 1680 "parser.tab.c"
    break;

  case 71: /* logic: ELLTE arith  */
#line 166 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(ELLTE, 1, (yyvsp[0].nPtr));}
#line 1686 "parser.tab.c"
    break;

  case 72: /* logic: ELGTE arith  */
#line 167 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(ELGTE, 1, (yyvsp[0].nPtr));}
#line 1692 "parser.tab.c"
    break;

  case 73: /* logic: MXFALSE logic  */
#line 168 "parser.y"
                     {(yyval.nPtr) = new lab3::OperationNode(MXFALSE, 1, (yyvsp[0].nPtr));}
#line 1698 "parser.tab.c"
    break;

  case 74: /* logic: MXTRUE logic  */
#line 169 "parser.y"
                    {(yyval.nPtr) = new lab3::OperationNode(MXTRUE, 1, (yyvsp[0].nPtr));}
#line 1704 "parser.tab.c"
    break;

  case 75: /* logic: REDUCE id '[' INTEGER ']'  */
#line 170 "parser.y"
                                 {(yyval.nPtr) = new lab3::OperationNode(REDUCE, 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].intVal));}
#line 1710 "parser.tab.c"
    break;

  case 76: /* logic: EXTEND id '[' INTEGER ']'  */
#line 171 "parser.y"
                                 {(yyval.nPtr) = new lab3::OperationNode(EXTEND, 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].intVal));}
#line 1716 "parser.tab.c"
    break;


#line 1720 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

