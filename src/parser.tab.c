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
  YYSYMBOL_SWITCHX = 23,                   /* SWITCHX  */
  YYSYMBOL_PLSX = 24,                      /* PLSX  */
  YYSYMBOL_THANKS = 25,                    /* THANKS  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_27_ = 27,                       /* '+'  */
  YYSYMBOL_28_ = 28,                       /* '-'  */
  YYSYMBOL_29_ = 29,                       /* '*'  */
  YYSYMBOL_30_ = 30,                       /* '/'  */
  YYSYMBOL_DIGITIZE = 31,                  /* DIGITIZE  */
  YYSYMBOL_REDUCE = 32,                    /* REDUCE  */
  YYSYMBOL_EXTEND = 33,                    /* EXTEND  */
  YYSYMBOL_SIZE = 34,                      /* SIZE  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_LOGITIZE = 36,                  /* LOGITIZE  */
  YYSYMBOL_MXEQ = 37,                      /* MXEQ  */
  YYSYMBOL_MXLT = 38,                      /* MXLT  */
  YYSYMBOL_MXGT = 39,                      /* MXGT  */
  YYSYMBOL_MXLTE = 40,                     /* MXLTE  */
  YYSYMBOL_MXGTE = 41,                     /* MXGTE  */
  YYSYMBOL_ELEQ = 42,                      /* ELEQ  */
  YYSYMBOL_ELLT = 43,                      /* ELLT  */
  YYSYMBOL_ELGT = 44,                      /* ELGT  */
  YYSYMBOL_ELLTE = 45,                     /* ELLTE  */
  YYSYMBOL_ELGTE = 46,                     /* ELGTE  */
  YYSYMBOL_MXFALSE = 47,                   /* MXFALSE  */
  YYSYMBOL_MXTRUE = 48,                    /* MXTRUE  */
  YYSYMBOL_49_n_ = 49,                     /* '\n'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_54_ = 54,                       /* '['  */
  YYSYMBOL_55_ = 55,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_program = 57,                   /* program  */
  YYSYMBOL_functions = 58,                 /* functions  */
  YYSYMBOL_function = 59,                  /* function  */
  YYSYMBOL_ids = 60,                       /* ids  */
  YYSYMBOL_indexes = 61,                   /* indexes  */
  YYSYMBOL_inds = 62,                      /* inds  */
  YYSYMBOL_stmtsGroup = 63,                /* stmtsGroup  */
  YYSYMBOL_stmts = 64,                     /* stmts  */
  YYSYMBOL_stmt = 65,                      /* stmt  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_expr = 67                       /* expr  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   197

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      49,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,    52,    29,    27,    50,    28,     2,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
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
      25,    26,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    80,    81,    82,    83,    84,    87,    97,
      98,   100,   101,   103,   104,   106,   108,   109,   110,   111,
     112,   113,   114,   118,   122,   126,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   147,   148,   149,   150,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184
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
  "PLEASE", "VAR", "SWITCHX", "PLSX", "THANKS", "AND", "'+'", "'-'", "'*'",
  "'/'", "DIGITIZE", "REDUCE", "EXTEND", "SIZE", "NOT", "LOGITIZE", "MXEQ",
  "MXLT", "MXGT", "MXLTE", "MXGTE", "ELEQ", "ELLT", "ELGT", "ELLTE",
  "ELGTE", "MXFALSE", "MXTRUE", "'\\n'", "','", "'('", "')'", "'='", "'['",
  "']'", "$accept", "program", "functions", "function", "ids", "indexes",
  "inds", "stmtsGroup", "stmts", "stmt", "parameters", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-71)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -71,    14,   -71,    42,    -2,   -71,    43,   -71,     6,
     -71,    -1,   -71,   -71,   -71,     4,    11,   -71,   139,    24,
      35,    91,    71,    91,   -71,    76,    87,    97,   156,   102,
      50,    -6,   -71,    91,    91,   -71,   -71,    56,    33,   135,
     138,   150,   151,    91,   160,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    57,   145,
     -18,   -71,   -71,   -71,   161,   146,    65,   121,   -71,    -3,
     -71,   -71,   -18,   117,   123,   -18,    91,   -71,   -71,   -71,
     125,   126,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -12,    91,    91,
      91,    91,    91,   169,   175,   128,   177,   116,    91,   -71,
     -71,   131,    91,   130,    91,    91,   -71,    37,   120,   120,
     -71,   -71,    92,   176,    91,   132,   -71,   -71,   133,    91,
     -18,   -71,   134,   136,   185,    36,   186,   140,    91,   141,
     -18,   -71,   -71,    92,    92,    92,   -71,   142,   149,   -71,
     146,   -71,   146,   -71,   146,   -71,   -71,   -71
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,     0,     6,     0,     2,     5,     0,     1,     0,
      10,     0,     4,     3,     9,     0,     0,     8,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,    19,     0,    12,    46,    61,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      40,    34,    35,    41,     0,    38,     0,     0,    15,     0,
      39,    17,    20,     0,    11,    14,    12,    59,    58,    52,
       0,     0,    53,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,     0,     0,     0,
       0,     0,     0,     0,     0,    44,    37,     0,    12,    18,
      16,     0,     0,     0,    12,    12,    47,    60,    54,    55,
      56,    57,     0,     0,    12,    42,    24,    22,     0,     0,
      13,    49,     0,     0,    31,    28,     0,     0,    12,     0,
      21,    50,    51,     0,     0,     0,    45,     0,     0,    33,
      32,    30,    29,    26,    27,    43,    25,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   -71,   184,   -71,   -70,   -71,   -69,   -71,   -28,
     -71,   -20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    11,    73,    74,    17,    30,    31,
     106,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      65,    58,    69,    60,     1,    14,   113,    12,    98,    99,
     100,   101,   102,    72,    98,    99,   100,   101,   102,    70,
       7,     2,    70,    83,     2,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   128,    77,
     116,   144,     8,    71,   132,   133,   110,     9,    15,    10,
      78,    67,     3,   134,   137,    16,    20,    21,    22,    23,
      18,    70,    24,    25,    99,   100,   101,   102,   147,    26,
      27,    28,    29,    32,   149,   151,   153,    59,   117,   118,
     119,   120,   121,    98,    99,   100,   101,   102,    33,    34,
      61,    62,   130,    63,   135,    35,    36,    37,    20,    21,
      22,    23,    68,    64,    24,    25,   103,    38,    66,   140,
      76,    26,    27,    28,    29,   150,   152,   154,   107,   108,
     126,   127,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      19,    79,    57,    16,    80,    20,    21,    22,    23,   101,
     102,    24,    25,   156,   157,   104,    81,    82,    26,    27,
      28,    29,    20,    21,    22,    23,    84,   105,    24,    25,
     109,    70,   111,   112,   122,    26,    27,    28,    29,   114,
     115,   123,   124,   125,   129,   131,   138,   136,   139,   141,
     143,   142,   145,    13,   148,   146,     0,   155
};

static const yytype_int16 yycheck[] =
{
      28,    21,    30,    23,     1,     6,    76,     1,    26,    27,
      28,    29,    30,    33,    26,    27,    28,    29,    30,    25,
       6,    18,    25,    43,    18,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,   108,     6,
      52,     5,     0,    49,   114,   115,    49,    49,    49,     6,
      17,     1,    49,   122,   124,    51,     6,     7,     8,     9,
      49,    25,    12,    13,    27,    28,    29,    30,   138,    19,
      20,    21,    22,    49,   143,   144,   145,     6,    98,    99,
     100,   101,   102,    26,    27,    28,    29,    30,    53,    54,
      14,    15,   112,     6,   122,     4,     5,     6,     6,     7,
       8,     9,    52,     6,    12,    13,    49,    16,     6,   129,
      54,    19,    20,    21,    22,   143,   144,   145,    53,    54,
       4,     5,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       1,     6,    51,    51,     6,     6,     7,     8,     9,    29,
      30,    12,    13,     4,     5,    10,     6,     6,    19,    20,
      21,    22,     6,     7,     8,     9,     6,     6,    12,    13,
      49,    25,    55,    50,     5,    19,    20,    21,    22,    54,
      54,     6,    54,     6,    53,    55,    54,    11,    55,    55,
       5,    55,     6,     9,    53,    55,    -1,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    49,    57,    58,    59,     6,     0,    49,
       6,    60,     1,    59,     6,    49,    51,    63,    49,     1,
       6,     7,     8,     9,    12,    13,    19,    20,    21,    22,
      64,    65,    49,    53,    54,     4,     5,     6,    16,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    51,    67,     6,
      67,    14,    15,     6,     6,    65,     6,     1,    52,    65,
      25,    49,    67,    61,    62,    67,    54,     6,    17,     6,
       6,     6,     6,    67,     6,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    26,    27,
      28,    29,    30,    49,    10,     6,    66,    53,    54,    49,
      49,    55,    50,    61,    54,    54,    52,    67,    67,    67,
      67,    67,     5,     6,    54,     6,     4,     5,    61,    53,
      67,    55,    61,    61,    63,    65,    11,    61,    54,    55,
      67,    55,    55,     5,     5,     6,    55,    61,    53,    63,
      65,    63,    65,    63,    65,    55,     4,     5
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    58,    59,    60,
      60,    61,    61,    62,    62,    63,    64,    64,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     1,     1,     1,     5,     2,
       1,     1,     0,     3,     1,     4,     3,     2,     3,     2,
       3,     6,     4,     7,     4,     7,     7,     7,     5,     7,
       7,     5,     7,     7,     2,     2,     1,     3,     2,     2,
       2,     2,     2,     5,     1,     4,     1,     3,     1,     4,
       5,     5,     2,     2,     3,     3,     3,     3,     2,     2,
       3,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: functions  */
#line 61 "parser.y"
              { try {
                    if (!functionsTable.contains("FINDEXIT")) {
                        hasError = true;
                        throw std::runtime_error("Could not find FINDEXIT function");
                    }
                    if (!hasError)
                        functionsTable.at("FINDEXIT")->exec(new lab3::BoolVariableNode("tmp", true));
                } catch (std::exception &ex) {
                }
                for (const auto &[key, value] : functionsTable)
                    delete value;
                if (exitPos == currentPos)
                    std::cout << "Congratulations!! your Robot survived!!" << std:: endl;
                else
                    std::cout << "Your robot died in labyrinth(((" << std::endl;
                return 0;
               }
#line 1358 "parser.tab.c"
    break;

  case 4: /* functions: functions '\n' error  */
#line 81 "parser.y"
                           {hasError = true; std::cout << "Some error on line " << (yylsp[0]).first_line << std::endl; yyerrok;}
#line 1364 "parser.tab.c"
    break;

  case 6: /* functions: '\n'  */
#line 83 "parser.y"
           {(yyval.nPtr) = nullptr;}
#line 1370 "parser.tab.c"
    break;

  case 7: /* functions: error  */
#line 84 "parser.y"
             {hasError = true; std::cout << "Some error on line " << (yylsp[0]).first_line << std::endl; yyerrok;}
#line 1376 "parser.tab.c"
    break;

  case 8: /* function: TASK id ids '\n' stmtsGroup  */
#line 87 "parser.y"
                                {auto tmp = new lab3::FunctionNode(*(yyvsp[-3].name), (yyvsp[-2].nPtr), (yyvsp[0].nPtr));
                                 for (const auto &it : varTable)
                                     tmp->addVar(it.first, (lab3::AbstractVariableNode *)it.second);
                                 varTable.clear();
                                 lastCall.insert({*(yyvsp[-3].name), lastResult});
                                 functionsTable.insert({*(yyvsp[-3].name), tmp});
                                 lastResult = new lab3::ParameterNode("");
                                 (yyval.nPtr) = tmp;
                                 }
#line 1390 "parser.tab.c"
    break;

  case 9: /* ids: ids id  */
#line 97 "parser.y"
            {auto res = new lab3::ParameterNode(*(yyvsp[0].name)); varTable.insert({*(yyvsp[0].name), res}); (yyval.nPtr) = new lab3::OperationNode(' ', (yylsp[-1]).first_line, 2, (yyvsp[-1].nPtr), res);}
#line 1396 "parser.tab.c"
    break;

  case 10: /* ids: id  */
#line 98 "parser.y"
         {auto res = new lab3::ParameterNode(*(yyvsp[0].name)); varTable.insert({*(yyvsp[0].name), res}); (yyval.nPtr) = res;}
#line 1402 "parser.tab.c"
    break;

  case 11: /* indexes: inds  */
#line 100 "parser.y"
              {(yyval.nPtr) = (yyvsp[0].nPtr);}
#line 1408 "parser.tab.c"
    break;

  case 12: /* indexes: %empty  */
#line 101 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(',', 0, 0);}
#line 1414 "parser.tab.c"
    break;

  case 13: /* inds: inds ',' expr  */
#line 103 "parser.y"
                    {(yyval.nPtr) = new lab3::OperationNode(',', (yylsp[-2]).first_line, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr)); }
#line 1420 "parser.tab.c"
    break;

  case 14: /* inds: expr  */
#line 104 "parser.y"
           { (yyval.nPtr) = new lab3::OperationNode(',', (yylsp[0]).first_line, 1, (yyvsp[0].nPtr)); }
#line 1426 "parser.tab.c"
    break;

  case 15: /* stmtsGroup: '(' '\n' stmts ')'  */
#line 106 "parser.y"
                               {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1432 "parser.tab.c"
    break;

  case 16: /* stmts: stmts stmt '\n'  */
#line 108 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode('\n', (yylsp[-2]).first_line, 2, (yyvsp[-2].nPtr), (yyvsp[-1].nPtr));}
#line 1438 "parser.tab.c"
    break;

  case 17: /* stmts: stmt '\n'  */
#line 109 "parser.y"
                 {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1444 "parser.tab.c"
    break;

  case 18: /* stmts: stmts error '\n'  */
#line 110 "parser.y"
                        {hasError = true; std::cout << "Some error on line " << (yylsp[-1]).first_line << std::endl; yyerrok;}
#line 1450 "parser.tab.c"
    break;

  case 19: /* stmts: error '\n'  */
#line 111 "parser.y"
                  {hasError = true; std::cout << "Some error on line " << (yylsp[-1]).first_line << std::endl; yyerrok;}
#line 1456 "parser.tab.c"
    break;

  case 20: /* stmt: id '=' expr  */
#line 112 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode('=', (yylsp[-2]).first_line, 2, varTable.at(*(yyvsp[-2].name)), (yyvsp[0].nPtr));}
#line 1462 "parser.tab.c"
    break;

  case 21: /* stmt: id '[' indexes ']' '=' expr  */
#line 113 "parser.y"
                                   {(yyval.nPtr) = new lab3::OperationNode('=', (yylsp[-5]).first_line, 3, varTable.at(*(yyvsp[-5].name)), (yyvsp[-3].nPtr), (yyvsp[0].nPtr));}
#line 1468 "parser.tab.c"
    break;

  case 22: /* stmt: VAR id '=' BOOL  */
#line 114 "parser.y"
                       {if (!varTable.insert({*(yyvsp[-2].name), new lab3::BoolVariableNode(*(yyvsp[-2].name), (yyvsp[0].boolVal)->getVal())}).second)
                                throw std::runtime_error("Variable already defined");
                             delete (yyvsp[0].boolVal);
                             (yyval.nPtr) = new lab3::OperationNode(VAR, (yylsp[-3]).first_line, 0);}
#line 1477 "parser.tab.c"
    break;

  case 23: /* stmt: VAR id '[' indexes ']' '=' BOOL  */
#line 118 "parser.y"
                                       {if (!varTable.insert({*(yyvsp[-5].name), new lab3::BoolArrayVariableNode(*(yyvsp[-5].name), (yyvsp[0].boolVal)->getVal(), lab3::AbstractVariableNode::makeDims((yyvsp[-3].nPtr)))}).second)
                                                throw std::runtime_error("Variable already defined");
                                             delete (yyvsp[0].boolVal);
                                             (yyval.nPtr) = new lab3::OperationNode(VAR, (yylsp[-6]).first_line, 0);}
#line 1486 "parser.tab.c"
    break;

  case 24: /* stmt: VAR id '=' INTEGER  */
#line 122 "parser.y"
                           {if (!varTable.insert({*(yyvsp[-2].name), new lab3::IntVariableNode(*(yyvsp[-2].name), (yyvsp[0].intVal)->getVal())}).second)
                                    throw std::runtime_error("Variable already defined");
                                delete (yyvsp[0].intVal);
                                (yyval.nPtr) = new lab3::OperationNode(VAR, (yylsp[-3]).first_line, 0);}
#line 1495 "parser.tab.c"
    break;

  case 25: /* stmt: VAR id '[' indexes ']' '=' INTEGER  */
#line 126 "parser.y"
                                          {if (!varTable.insert({*(yyvsp[-5].name), new lab3::IntArrayVariableNode(*(yyvsp[-5].name), (yyvsp[0].intVal)->getVal(), lab3::AbstractVariableNode::makeDims((yyvsp[-3].nPtr)))}).second)
                                                    throw std::runtime_error("Variable already defined");
                                                delete (yyvsp[0].intVal);
                                                (yyval.nPtr) = new lab3::OperationNode(VAR, (yylsp[-6]).first_line, 0);}
#line 1504 "parser.tab.c"
    break;

  case 26: /* stmt: FOR id BOUNDARY id STEP id stmtsGroup  */
#line 130 "parser.y"
                                             {(yyval.nPtr) = new lab3::OperationNode(FOR, (yylsp[-6]).first_line, 4, varTable.at(*(yyvsp[-5].name)), varTable.at(*(yyvsp[-3].name)), varTable.at(*(yyvsp[-1].name)), (yyvsp[0].nPtr));}
#line 1510 "parser.tab.c"
    break;

  case 27: /* stmt: FOR id BOUNDARY id STEP id stmt  */
#line 131 "parser.y"
                                       {(yyval.nPtr) = new lab3::OperationNode(FOR, (yylsp[-6]).first_line, 4, varTable.at(*(yyvsp[-5].name)), varTable.at(*(yyvsp[-3].name)), varTable.at(*(yyvsp[-1].name)), (yyvsp[0].nPtr));}
#line 1516 "parser.tab.c"
    break;

  case 28: /* stmt: SWITCH expr '\n' BOOL stmt  */
#line 132 "parser.y"
                                                {(yyval.nPtr) = new lab3::OperationNode(SWITCH, (yylsp[-4]).first_line, 3, (yyvsp[-3].nPtr), (yyvsp[-1].boolVal), (yyvsp[0].nPtr));}
#line 1522 "parser.tab.c"
    break;

  case 29: /* stmt: SWITCH expr '\n' BOOL stmt BOOL stmt  */
#line 133 "parser.y"
                                            {(yyval.nPtr) = new lab3::OperationNode(SWITCH, (yylsp[-6]).first_line, 5, (yyvsp[-5].nPtr), (yyvsp[-3].boolVal), (yyvsp[-2].nPtr), (yyvsp[-1].boolVal), (yyvsp[0].nPtr));}
#line 1528 "parser.tab.c"
    break;

  case 30: /* stmt: SWITCH expr '\n' BOOL stmt BOOL stmtsGroup  */
#line 134 "parser.y"
                                                  {(yyval.nPtr) = new lab3::OperationNode(SWITCH, (yylsp[-6]).first_line, 5, (yyvsp[-5].nPtr), (yyvsp[-3].boolVal), (yyvsp[-2].nPtr), (yyvsp[-1].boolVal), (yyvsp[0].nPtr));}
#line 1534 "parser.tab.c"
    break;

  case 31: /* stmt: SWITCH expr '\n' BOOL stmtsGroup  */
#line 135 "parser.y"
                                                      {(yyval.nPtr) = new lab3::OperationNode(SWITCH, (yylsp[-4]).first_line, 3, (yyvsp[-3].nPtr), (yyvsp[-1].boolVal), (yyvsp[0].nPtr));}
#line 1540 "parser.tab.c"
    break;

  case 32: /* stmt: SWITCH expr '\n' BOOL stmtsGroup BOOL stmt  */
#line 136 "parser.y"
                                                  {(yyval.nPtr) = new lab3::OperationNode(SWITCH, (yylsp[-6]).first_line, 5, (yyvsp[-5].nPtr), (yyvsp[-3].boolVal), (yyvsp[-2].nPtr), (yyvsp[-1].boolVal), (yyvsp[0].nPtr));}
#line 1546 "parser.tab.c"
    break;

  case 33: /* stmt: SWITCH expr '\n' BOOL stmtsGroup BOOL stmtsGroup  */
#line 137 "parser.y"
                                                        {(yyval.nPtr) = new lab3::OperationNode(SWITCH, (yylsp[-6]).first_line, 5, (yyvsp[-5].nPtr), (yyvsp[-3].boolVal), (yyvsp[-2].nPtr), (yyvsp[-1].boolVal), (yyvsp[0].nPtr));}
#line 1552 "parser.tab.c"
    break;

  case 34: /* stmt: ROTATE LEFT  */
#line 138 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(LEFT, (yylsp[-1]).first_line, 0);}
#line 1558 "parser.tab.c"
    break;

  case 35: /* stmt: ROTATE RIGHT  */
#line 139 "parser.y"
                    {(yyval.nPtr) = new lab3::OperationNode(RIGHT, (yylsp[-1]).first_line, 0);}
#line 1564 "parser.tab.c"
    break;

  case 36: /* stmt: MOVE  */
#line 140 "parser.y"
             {(yyval.nPtr) = new lab3::OperationNode(MOVE, (yylsp[0]).first_line, 0);}
#line 1570 "parser.tab.c"
    break;

  case 37: /* stmt: DO id parameters  */
#line 141 "parser.y"
                        {(yyval.nPtr) = new lab3::OperationNode(DO, (yylsp[-2]).first_line, 2, new lab3::ParameterNode(*(yyvsp[-1].name)), (yyvsp[0].nPtr));}
#line 1576 "parser.tab.c"
    break;

  case 38: /* stmt: PLEASE stmt  */
#line 142 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(PLEASE, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1582 "parser.tab.c"
    break;

  case 39: /* stmt: stmt THANKS  */
#line 143 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(THANKS, (yylsp[-1]).first_line, 1, (yyvsp[-1].nPtr));}
#line 1588 "parser.tab.c"
    break;

  case 40: /* stmt: PRINT expr  */
#line 144 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(PRINT, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1594 "parser.tab.c"
    break;

  case 41: /* stmt: RESULT id  */
#line 145 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(RESULT, (yylsp[-1]).first_line, 2, varTable.at(*(yyvsp[0].name)), lastResult);}
#line 1600 "parser.tab.c"
    break;

  case 42: /* parameters: parameters id  */
#line 147 "parser.y"
                          {(yyval.nPtr) = new lab3::OperationNode(' ', (yylsp[-1]).first_line, 2, (yyvsp[-1].nPtr), varTable.at(*(yyvsp[0].name)));}
#line 1606 "parser.tab.c"
    break;

  case 43: /* parameters: parameters id '[' indexes ']'  */
#line 148 "parser.y"
                                         {(yyval.nPtr) = new lab3::OperationNode(' ', (yylsp[-4]).first_line, 3, (yyvsp[-4].nPtr), varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1612 "parser.tab.c"
    break;

  case 44: /* parameters: id  */
#line 149 "parser.y"
              { (yyval.nPtr) = varTable.at(*(yyvsp[0].name)); }
#line 1618 "parser.tab.c"
    break;

  case 45: /* parameters: id '[' indexes ']'  */
#line 150 "parser.y"
                              {(yyval.nPtr) = new lab3::OperationNode('[', (yylsp[-3]).first_line, 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1624 "parser.tab.c"
    break;

  case 47: /* expr: '(' expr ')'  */
#line 156 "parser.y"
                    {(yyval.nPtr) = (yyvsp[-1].nPtr);}
#line 1630 "parser.tab.c"
    break;

  case 48: /* expr: id  */
#line 157 "parser.y"
          {(yyval.nPtr) = varTable.at(*(yyvsp[0].name));}
#line 1636 "parser.tab.c"
    break;

  case 49: /* expr: id '[' indexes ']'  */
#line 158 "parser.y"
                          {(yyval.nPtr) = new lab3::OperationNode('[', (yylsp[-3]).first_line, 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1642 "parser.tab.c"
    break;

  case 50: /* expr: REDUCE id '[' indexes ']'  */
#line 159 "parser.y"
                                 {(yyval.nPtr) = new lab3::OperationNode(REDUCE, (yylsp[-4]).first_line, 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1648 "parser.tab.c"
    break;

  case 51: /* expr: EXTEND id '[' indexes ']'  */
#line 160 "parser.y"
                                 {(yyval.nPtr) = new lab3::OperationNode(EXTEND, (yylsp[-4]).first_line, 2, varTable.at(*(yyvsp[-3].name)), (yyvsp[-1].nPtr));}
#line 1654 "parser.tab.c"
    break;

  case 52: /* expr: DIGITIZE id  */
#line 161 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(DIGITIZE, (yylsp[-1]).first_line, 1, varTable.at(*(yyvsp[0].name)));}
#line 1660 "parser.tab.c"
    break;

  case 53: /* expr: SIZE id  */
#line 162 "parser.y"
               {(yyval.nPtr) = new lab3::OperationNode(SIZE, (yylsp[-1]).first_line, 1, varTable.at(*(yyvsp[0].name)));}
#line 1666 "parser.tab.c"
    break;

  case 54: /* expr: expr '+' expr  */
#line 163 "parser.y"
                     {(yyval.nPtr) = new lab3::OperationNode('+', (yylsp[-2]).first_line, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1672 "parser.tab.c"
    break;

  case 55: /* expr: expr '-' expr  */
#line 164 "parser.y"
                     {(yyval.nPtr) = new lab3::OperationNode('-', (yylsp[-2]).first_line, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1678 "parser.tab.c"
    break;

  case 56: /* expr: expr '*' expr  */
#line 165 "parser.y"
                     {(yyval.nPtr) = new lab3::OperationNode('*', (yylsp[-2]).first_line, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1684 "parser.tab.c"
    break;

  case 57: /* expr: expr '/' expr  */
#line 166 "parser.y"
                     {(yyval.nPtr) = new lab3::OperationNode('/', (yylsp[-2]).first_line, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1690 "parser.tab.c"
    break;

  case 58: /* expr: GET ENVIRONMENT  */
#line 167 "parser.y"
                       {(yyval.nPtr) = new lab3::OperationNode(ENVIRONMENT, (yylsp[-1]).first_line, 0);}
#line 1696 "parser.tab.c"
    break;

  case 59: /* expr: GET id  */
#line 168 "parser.y"
              {(yyval.nPtr) = new lab3::OperationNode(GET, (yylsp[-1]).first_line, 1, new lab3::ParameterNode(*(yyvsp[0].name)));}
#line 1702 "parser.tab.c"
    break;

  case 60: /* expr: expr AND expr  */
#line 169 "parser.y"
                     {(yyval.nPtr) = new lab3::OperationNode(AND, (yylsp[-2]).first_line, 2, (yyvsp[-2].nPtr), (yyvsp[0].nPtr));}
#line 1708 "parser.tab.c"
    break;

  case 61: /* expr: BOOL  */
#line 170 "parser.y"
            {(yyval.nPtr) = (yyvsp[0].boolVal);}
#line 1714 "parser.tab.c"
    break;

  case 62: /* expr: NOT expr  */
#line 171 "parser.y"
                {(yyval.nPtr) = new lab3::OperationNode(NOT, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1720 "parser.tab.c"
    break;

  case 63: /* expr: LOGITIZE id  */
#line 172 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(LOGITIZE, (yylsp[-1]).first_line, 1, varTable.at(*(yyvsp[0].name)));}
#line 1726 "parser.tab.c"
    break;

  case 64: /* expr: MXEQ expr  */
#line 173 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(MXEQ, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1732 "parser.tab.c"
    break;

  case 65: /* expr: MXLT expr  */
#line 174 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(MXLT, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1738 "parser.tab.c"
    break;

  case 66: /* expr: MXGT expr  */
#line 175 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(MXGT, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1744 "parser.tab.c"
    break;

  case 67: /* expr: MXLTE expr  */
#line 176 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(MXLTE, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1750 "parser.tab.c"
    break;

  case 68: /* expr: MXGTE expr  */
#line 177 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(MXGTE, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1756 "parser.tab.c"
    break;

  case 69: /* expr: ELEQ expr  */
#line 178 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(ELEQ, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1762 "parser.tab.c"
    break;

  case 70: /* expr: ELLT expr  */
#line 179 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(ELLT, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1768 "parser.tab.c"
    break;

  case 71: /* expr: ELGT expr  */
#line 180 "parser.y"
                 {(yyval.nPtr) = new lab3::OperationNode(ELGT, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1774 "parser.tab.c"
    break;

  case 72: /* expr: ELLTE expr  */
#line 181 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(ELLTE, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1780 "parser.tab.c"
    break;

  case 73: /* expr: ELGTE expr  */
#line 182 "parser.y"
                  {(yyval.nPtr) = new lab3::OperationNode(ELGTE, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1786 "parser.tab.c"
    break;

  case 74: /* expr: MXFALSE expr  */
#line 183 "parser.y"
                    {(yyval.nPtr) = new lab3::OperationNode(MXFALSE, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1792 "parser.tab.c"
    break;

  case 75: /* expr: MXTRUE expr  */
#line 184 "parser.y"
                   {(yyval.nPtr) = new lab3::OperationNode(MXTRUE, (yylsp[-1]).first_line, 1, (yyvsp[0].nPtr));}
#line 1798 "parser.tab.c"
    break;


#line 1802 "parser.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

