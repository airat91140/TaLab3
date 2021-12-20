// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 4 "parser.y"

#include <string>
#include <map>
#include <stack>
#include <exception>
#include <variant>
#include "AbstractNode.h"
#include "BoolArrayVariableNode.h"
#include "BoolConstNode.h"
#include "BoolVariableNode.h"
#include "IntArrayVariableNode.h"
#include "IntConstNode.h"
#include "IntVariableNode.h"
#include "OperationNode.h"
#include "FunctionNode.h"
#include "ParameterNode.h"

enum dir {U, L, R, D};
extern FILE *yyin;
std::map<std::string, lab3::AbstractNode *> functionsTable;
std::map<std::string, lab3::AbstractNode *> lastCall;
std::vector<std::vector<bool> > labyrinth;
std::pair<int, int> position;
dir direction;
std::stack<lab3::FunctionNode *> functionStack;
class value_type;
int yylex (value_type* yylval);

#line 70 "parser.tab.cc"




# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 207 "parser.tab.cc"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // functions
      // function
      // ids
      // indexes
      // stmtsGroup
      // stmts
      // stmt
      // parameters
      // value
      // expr
      // arith
      // logic
      char dummy1[sizeof (lab3::AbstractNode *)];

      // BOOL
      char dummy2[sizeof (lab3::BoolConstNode *)];

      // INTEGER
      char dummy3[sizeof (lab3::IntConstNode *)];

      // id
      // FUNC_NAME
      char dummy4[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    INTEGER = 258,                 // INTEGER
    BOOL = 259,                    // BOOL
    id = 260,                      // id
    FUNC_NAME = 261,               // FUNC_NAME
    SWITCH = 262,                  // SWITCH
    FOR = 263,                     // FOR
    PRINT = 264,                   // PRINT
    BOUNDARY = 265,                // BOUNDARY
    STEP = 266,                    // STEP
    MOVE = 267,                    // MOVE
    ROTATE = 268,                  // ROTATE
    LEFT = 269,                    // LEFT
    RIGHT = 270,                   // RIGHT
    GET = 271,                     // GET
    ENVIRONMENT = 272,             // ENVIRONMENT
    TASK = 273,                    // TASK
    RESULT = 274,                  // RESULT
    DO = 275,                      // DO
    PLEASE = 276,                  // PLEASE
    VAR = 277,                     // VAR
    PLSX = 278,                    // PLSX
    THANKS = 279,                  // THANKS
    SWITCHX = 280,                 // SWITCHX
    HIGHSWITCHX = 281,             // HIGHSWITCHX
    AND = 282,                     // AND
    DIGITIZE = 283,                // DIGITIZE
    REDUCE = 284,                  // REDUCE
    EXTEND = 285,                  // EXTEND
    SIZE = 286,                    // SIZE
    NOT = 287,                     // NOT
    LOGITIZE = 288,                // LOGITIZE
    MXEQ = 289,                    // MXEQ
    MXLT = 290,                    // MXLT
    MXGT = 291,                    // MXGT
    MXLTE = 292,                   // MXLTE
    MXGTE = 293,                   // MXGTE
    ELEQ = 294,                    // ELEQ
    ELLT = 295,                    // ELLT
    ELGT = 296,                    // ELGT
    ELLTE = 297,                   // ELLTE
    ELGTE = 298,                   // ELGTE
    MXFALSE = 299,                 // MXFALSE
    MXTRUE = 300                   // MXTRUE
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 57, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_INTEGER = 3,                           // INTEGER
        S_BOOL = 4,                              // BOOL
        S_id = 5,                                // id
        S_FUNC_NAME = 6,                         // FUNC_NAME
        S_SWITCH = 7,                            // SWITCH
        S_FOR = 8,                               // FOR
        S_PRINT = 9,                             // PRINT
        S_BOUNDARY = 10,                         // BOUNDARY
        S_STEP = 11,                             // STEP
        S_MOVE = 12,                             // MOVE
        S_ROTATE = 13,                           // ROTATE
        S_LEFT = 14,                             // LEFT
        S_RIGHT = 15,                            // RIGHT
        S_GET = 16,                              // GET
        S_ENVIRONMENT = 17,                      // ENVIRONMENT
        S_TASK = 18,                             // TASK
        S_RESULT = 19,                           // RESULT
        S_DO = 20,                               // DO
        S_PLEASE = 21,                           // PLEASE
        S_VAR = 22,                              // VAR
        S_PLSX = 23,                             // PLSX
        S_THANKS = 24,                           // THANKS
        S_SWITCHX = 25,                          // SWITCHX
        S_HIGHSWITCHX = 26,                      // HIGHSWITCHX
        S_AND = 27,                              // AND
        S_28_ = 28,                              // '+'
        S_29_ = 29,                              // '-'
        S_30_ = 30,                              // '*'
        S_31_ = 31,                              // '/'
        S_DIGITIZE = 32,                         // DIGITIZE
        S_REDUCE = 33,                           // REDUCE
        S_EXTEND = 34,                           // EXTEND
        S_SIZE = 35,                             // SIZE
        S_NOT = 36,                              // NOT
        S_LOGITIZE = 37,                         // LOGITIZE
        S_MXEQ = 38,                             // MXEQ
        S_MXLT = 39,                             // MXLT
        S_MXGT = 40,                             // MXGT
        S_MXLTE = 41,                            // MXLTE
        S_MXGTE = 42,                            // MXGTE
        S_ELEQ = 43,                             // ELEQ
        S_ELLT = 44,                             // ELLT
        S_ELGT = 45,                             // ELGT
        S_ELLTE = 46,                            // ELLTE
        S_ELGTE = 47,                            // ELGTE
        S_MXFALSE = 48,                          // MXFALSE
        S_MXTRUE = 49,                           // MXTRUE
        S_50_n_ = 50,                            // '\n'
        S_51_ = 51,                              // ','
        S_52_ = 52,                              // '('
        S_53_ = 53,                              // ')'
        S_54_ = 54,                              // '='
        S_55_ = 55,                              // '['
        S_56_ = 56,                              // ']'
        S_YYACCEPT = 57,                         // $accept
        S_program = 58,                          // program
        S_functions = 59,                        // functions
        S_function = 60,                         // function
        S_ids = 61,                              // ids
        S_indexes = 62,                          // indexes
        S_stmtsGroup = 63,                       // stmtsGroup
        S_stmts = 64,                            // stmts
        S_stmt = 65,                             // stmt
        S_parameters = 66,                       // parameters
        S_value = 67,                            // value
        S_expr = 68,                             // expr
        S_arith = 69,                            // arith
        S_logic = 70                             // logic
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        value.move< lab3::AbstractNode * > (std::move (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< lab3::BoolConstNode * > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< lab3::IntConstNode * > (std::move (that.value));
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, lab3::AbstractNode *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const lab3::AbstractNode *& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, lab3::BoolConstNode *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const lab3::BoolConstNode *& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, lab3::IntConstNode *&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const lab3::IntConstNode *& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        value.template destroy< lab3::AbstractNode * > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.template destroy< lab3::BoolConstNode * > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.template destroy< lab3::IntConstNode * > ();
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

#if YYDEBUG || 0
      /// The user-facing name of this symbol.
      const char *name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }
#endif // #if YYDEBUG || 0


      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, lab3::BoolConstNode * v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const lab3::BoolConstNode *& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, lab3::IntConstNode * v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const lab3::IntConstNode *& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    parser ();
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

#if YYDEBUG || 0
    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static const char *symbol_name (symbol_kind_type yysymbol);
#endif // #if YYDEBUG || 0


    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#else
      static
      symbol_type
      make_YYerror ()
      {
        return symbol_type (token::YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#else
      static
      symbol_type
      make_YYUNDEF ()
      {
        return symbol_type (token::YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (lab3::IntConstNode * v)
      {
        return symbol_type (token::INTEGER, std::move (v));
      }
#else
      static
      symbol_type
      make_INTEGER (const lab3::IntConstNode *& v)
      {
        return symbol_type (token::INTEGER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (lab3::BoolConstNode * v)
      {
        return symbol_type (token::BOOL, std::move (v));
      }
#else
      static
      symbol_type
      make_BOOL (const lab3::BoolConstNode *& v)
      {
        return symbol_type (token::BOOL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_id (std::string v)
      {
        return symbol_type (token::id, std::move (v));
      }
#else
      static
      symbol_type
      make_id (const std::string& v)
      {
        return symbol_type (token::id, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FUNC_NAME (std::string v)
      {
        return symbol_type (token::FUNC_NAME, std::move (v));
      }
#else
      static
      symbol_type
      make_FUNC_NAME (const std::string& v)
      {
        return symbol_type (token::FUNC_NAME, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCH ()
      {
        return symbol_type (token::SWITCH);
      }
#else
      static
      symbol_type
      make_SWITCH ()
      {
        return symbol_type (token::SWITCH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR ()
      {
        return symbol_type (token::FOR);
      }
#else
      static
      symbol_type
      make_FOR ()
      {
        return symbol_type (token::FOR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT ()
      {
        return symbol_type (token::PRINT);
      }
#else
      static
      symbol_type
      make_PRINT ()
      {
        return symbol_type (token::PRINT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOUNDARY ()
      {
        return symbol_type (token::BOUNDARY);
      }
#else
      static
      symbol_type
      make_BOUNDARY ()
      {
        return symbol_type (token::BOUNDARY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STEP ()
      {
        return symbol_type (token::STEP);
      }
#else
      static
      symbol_type
      make_STEP ()
      {
        return symbol_type (token::STEP);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOVE ()
      {
        return symbol_type (token::MOVE);
      }
#else
      static
      symbol_type
      make_MOVE ()
      {
        return symbol_type (token::MOVE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ROTATE ()
      {
        return symbol_type (token::ROTATE);
      }
#else
      static
      symbol_type
      make_ROTATE ()
      {
        return symbol_type (token::ROTATE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT ()
      {
        return symbol_type (token::LEFT);
      }
#else
      static
      symbol_type
      make_LEFT ()
      {
        return symbol_type (token::LEFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT ()
      {
        return symbol_type (token::RIGHT);
      }
#else
      static
      symbol_type
      make_RIGHT ()
      {
        return symbol_type (token::RIGHT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GET ()
      {
        return symbol_type (token::GET);
      }
#else
      static
      symbol_type
      make_GET ()
      {
        return symbol_type (token::GET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENVIRONMENT ()
      {
        return symbol_type (token::ENVIRONMENT);
      }
#else
      static
      symbol_type
      make_ENVIRONMENT ()
      {
        return symbol_type (token::ENVIRONMENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TASK ()
      {
        return symbol_type (token::TASK);
      }
#else
      static
      symbol_type
      make_TASK ()
      {
        return symbol_type (token::TASK);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RESULT ()
      {
        return symbol_type (token::RESULT);
      }
#else
      static
      symbol_type
      make_RESULT ()
      {
        return symbol_type (token::RESULT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DO ()
      {
        return symbol_type (token::DO);
      }
#else
      static
      symbol_type
      make_DO ()
      {
        return symbol_type (token::DO);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLEASE ()
      {
        return symbol_type (token::PLEASE);
      }
#else
      static
      symbol_type
      make_PLEASE ()
      {
        return symbol_type (token::PLEASE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VAR ()
      {
        return symbol_type (token::VAR);
      }
#else
      static
      symbol_type
      make_VAR ()
      {
        return symbol_type (token::VAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLSX ()
      {
        return symbol_type (token::PLSX);
      }
#else
      static
      symbol_type
      make_PLSX ()
      {
        return symbol_type (token::PLSX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THANKS ()
      {
        return symbol_type (token::THANKS);
      }
#else
      static
      symbol_type
      make_THANKS ()
      {
        return symbol_type (token::THANKS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SWITCHX ()
      {
        return symbol_type (token::SWITCHX);
      }
#else
      static
      symbol_type
      make_SWITCHX ()
      {
        return symbol_type (token::SWITCHX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HIGHSWITCHX ()
      {
        return symbol_type (token::HIGHSWITCHX);
      }
#else
      static
      symbol_type
      make_HIGHSWITCHX ()
      {
        return symbol_type (token::HIGHSWITCHX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#else
      static
      symbol_type
      make_AND ()
      {
        return symbol_type (token::AND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIGITIZE ()
      {
        return symbol_type (token::DIGITIZE);
      }
#else
      static
      symbol_type
      make_DIGITIZE ()
      {
        return symbol_type (token::DIGITIZE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REDUCE ()
      {
        return symbol_type (token::REDUCE);
      }
#else
      static
      symbol_type
      make_REDUCE ()
      {
        return symbol_type (token::REDUCE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTEND ()
      {
        return symbol_type (token::EXTEND);
      }
#else
      static
      symbol_type
      make_EXTEND ()
      {
        return symbol_type (token::EXTEND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE ()
      {
        return symbol_type (token::SIZE);
      }
#else
      static
      symbol_type
      make_SIZE ()
      {
        return symbol_type (token::SIZE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#else
      static
      symbol_type
      make_NOT ()
      {
        return symbol_type (token::NOT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGITIZE ()
      {
        return symbol_type (token::LOGITIZE);
      }
#else
      static
      symbol_type
      make_LOGITIZE ()
      {
        return symbol_type (token::LOGITIZE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MXEQ ()
      {
        return symbol_type (token::MXEQ);
      }
#else
      static
      symbol_type
      make_MXEQ ()
      {
        return symbol_type (token::MXEQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MXLT ()
      {
        return symbol_type (token::MXLT);
      }
#else
      static
      symbol_type
      make_MXLT ()
      {
        return symbol_type (token::MXLT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MXGT ()
      {
        return symbol_type (token::MXGT);
      }
#else
      static
      symbol_type
      make_MXGT ()
      {
        return symbol_type (token::MXGT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MXLTE ()
      {
        return symbol_type (token::MXLTE);
      }
#else
      static
      symbol_type
      make_MXLTE ()
      {
        return symbol_type (token::MXLTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MXGTE ()
      {
        return symbol_type (token::MXGTE);
      }
#else
      static
      symbol_type
      make_MXGTE ()
      {
        return symbol_type (token::MXGTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELEQ ()
      {
        return symbol_type (token::ELEQ);
      }
#else
      static
      symbol_type
      make_ELEQ ()
      {
        return symbol_type (token::ELEQ);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLT ()
      {
        return symbol_type (token::ELLT);
      }
#else
      static
      symbol_type
      make_ELLT ()
      {
        return symbol_type (token::ELLT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELGT ()
      {
        return symbol_type (token::ELGT);
      }
#else
      static
      symbol_type
      make_ELGT ()
      {
        return symbol_type (token::ELGT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELLTE ()
      {
        return symbol_type (token::ELLTE);
      }
#else
      static
      symbol_type
      make_ELLTE ()
      {
        return symbol_type (token::ELLTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELGTE ()
      {
        return symbol_type (token::ELGTE);
      }
#else
      static
      symbol_type
      make_ELGTE ()
      {
        return symbol_type (token::ELGTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MXFALSE ()
      {
        return symbol_type (token::MXFALSE);
      }
#else
      static
      symbol_type
      make_MXFALSE ()
      {
        return symbol_type (token::MXFALSE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MXTRUE ()
      {
        return symbol_type (token::MXTRUE);
      }
#else
      static
      symbol_type
      make_MXTRUE ()
      {
        return symbol_type (token::MXTRUE);
      }
#endif


  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

#if YYDEBUG || 0
    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#endif // #if YYDEBUG || 0


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const signed char yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 252,     ///< Last index in yytable_.
      yynnts_ = 14,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };



  };


} // yy
#line 1959 "parser.tab.cc"








#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 2038 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        value.copy< lab3::AbstractNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< lab3::BoolConstNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< lab3::IntConstNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        value.move< lab3::AbstractNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< lab3::BoolConstNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< lab3::IntConstNode * > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        value.YY_MOVE_OR_COPY< lab3::AbstractNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.YY_MOVE_OR_COPY< lab3::BoolConstNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.YY_MOVE_OR_COPY< lab3::IntConstNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        value.move< lab3::AbstractNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< lab3::BoolConstNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< lab3::IntConstNode * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        value.copy< lab3::AbstractNode * > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.copy< lab3::BoolConstNode * > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.copy< lab3::IntConstNode * > (that.value);
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        value.move< lab3::AbstractNode * > (that.value);
        break;

      case symbol_kind::S_BOOL: // BOOL
        value.move< lab3::BoolConstNode * > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        value.move< lab3::IntConstNode * > (that.value);
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_functions: // functions
      case symbol_kind::S_function: // function
      case symbol_kind::S_ids: // ids
      case symbol_kind::S_indexes: // indexes
      case symbol_kind::S_stmtsGroup: // stmtsGroup
      case symbol_kind::S_stmts: // stmts
      case symbol_kind::S_stmt: // stmt
      case symbol_kind::S_parameters: // parameters
      case symbol_kind::S_value: // value
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_arith: // arith
      case symbol_kind::S_logic: // logic
        yylhs.value.emplace< lab3::AbstractNode * > ();
        break;

      case symbol_kind::S_BOOL: // BOOL
        yylhs.value.emplace< lab3::BoolConstNode * > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
        yylhs.value.emplace< lab3::IntConstNode * > ();
        break;

      case symbol_kind::S_id: // id
      case symbol_kind::S_FUNC_NAME: // FUNC_NAME
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: functions
#line 52 "parser.y"
              { if (!functionsTable.contains("FINDEXIT"))
                    throw std::runtime_error("Could not find FINDEXIT function");

                functionsTable.at("FINDEXIT")->exec(new lab3::BoolConstNode(true));
                for (const auto &[key, value] : functionsTable)
                    delete value;
                exit(0);
               }
#line 2715 "parser.tab.cc"
    break;

  case 3: // functions: functions function
#line 62 "parser.y"
                       {functionsTable.insert({((lab3::FunctionNode *)yystack_[0].value.as < lab3::AbstractNode * > ())->getName(), yystack_[0].value.as < lab3::AbstractNode * > ()}); lastCall.insert({((lab3::FunctionNode *)yystack_[0].value.as < lab3::AbstractNode * > ())->getName(), nullptr});}
#line 2721 "parser.tab.cc"
    break;

  case 5: // function: TASK FUNC_NAME ids '\n' stmtsGroup
#line 66 "parser.y"
                                       {yylhs.value.as < lab3::AbstractNode * > () = new lab3::FunctionNode(yystack_[3].value.as < std::string > (), yystack_[2].value.as < lab3::AbstractNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 2727 "parser.tab.cc"
    break;

  case 6: // ids: ids id
#line 68 "parser.y"
            {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(' ', 2, yystack_[1].value.as < lab3::AbstractNode * > (), new lab3::ParameterNode(yystack_[0].value.as < std::string > ()));}
#line 2733 "parser.tab.cc"
    break;

  case 7: // ids: id
#line 69 "parser.y"
         {yylhs.value.as < lab3::AbstractNode * > () = new lab3::ParameterNode(yystack_[0].value.as < std::string > ());}
#line 2739 "parser.tab.cc"
    break;

  case 8: // indexes: indexes ',' expr
#line 71 "parser.y"
                          {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(',', 2, yystack_[2].value.as < lab3::AbstractNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ()); }
#line 2745 "parser.tab.cc"
    break;

  case 9: // indexes: expr
#line 72 "parser.y"
               { yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(',', 1, yystack_[0].value.as < lab3::AbstractNode * > ()); }
#line 2751 "parser.tab.cc"
    break;

  case 10: // stmtsGroup: '(' stmts ')'
#line 74 "parser.y"
                          {yylhs.value.as < lab3::AbstractNode * > () = yystack_[1].value.as < lab3::AbstractNode * > ();}
#line 2757 "parser.tab.cc"
    break;

  case 11: // stmts: stmts stmt
#line 76 "parser.y"
                  {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('\n', 2, yystack_[1].value.as < lab3::AbstractNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 2763 "parser.tab.cc"
    break;

  case 12: // stmts: stmt
#line 77 "parser.y"
            {yylhs.value.as < lab3::AbstractNode * > () = yystack_[0].value.as < lab3::AbstractNode * > ();}
#line 2769 "parser.tab.cc"
    break;

  case 13: // stmt: '\n'
#line 79 "parser.y"
            { yylhs.value.as < lab3::AbstractNode * > () = nullptr;}
#line 2775 "parser.tab.cc"
    break;

  case 14: // stmt: id '=' expr '\n'
#line 80 "parser.y"
                        {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('=', 2, (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2781 "parser.tab.cc"
    break;

  case 15: // stmt: id '[' indexes ']' '=' expr '\n'
#line 81 "parser.y"
                                        {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('=', 3, (*functionStack.top())[yystack_[6].value.as < std::string > ()], yystack_[4].value.as < lab3::AbstractNode * > (), yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2787 "parser.tab.cc"
    break;

  case 16: // stmt: VAR id '=' value '\n'
#line 82 "parser.y"
                             {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::VAR, 2, new lab3::ParameterNode(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2793 "parser.tab.cc"
    break;

  case 17: // stmt: VAR id '[' indexes ']' '=' value '\n'
#line 83 "parser.y"
                                             {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::VAR, 3, new lab3::ParameterNode(yystack_[6].value.as < std::string > ()), yystack_[4].value.as < lab3::AbstractNode * > (), yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2799 "parser.tab.cc"
    break;

  case 18: // stmt: FOR id BOUNDARY id STEP id stmtsGroup '\n'
#line 84 "parser.y"
                                                  {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::FOR, 4, (*functionStack.top())[yystack_[6].value.as < std::string > ()], (*functionStack.top())[yystack_[4].value.as < std::string > ()], (*functionStack.top())[yystack_[2].value.as < std::string > ()], yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2805 "parser.tab.cc"
    break;

  case 19: // stmt: FOR id BOUNDARY id STEP id stmt '\n'
#line 85 "parser.y"
                                            {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::FOR, 4, (*functionStack.top())[yystack_[6].value.as < std::string > ()], (*functionStack.top())[yystack_[4].value.as < std::string > ()], (*functionStack.top())[yystack_[2].value.as < std::string > ()], yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2811 "parser.tab.cc"
    break;

  case 20: // stmt: SWITCH logic '\n' BOOL stmt '\n'
#line 86 "parser.y"
                                                      {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::SWITCH, 3, yystack_[4].value.as < lab3::AbstractNode * > (), yystack_[2].value.as < lab3::BoolConstNode * > (), yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2817 "parser.tab.cc"
    break;

  case 21: // stmt: SWITCH logic '\n' BOOL stmt '\n' BOOL stmt '\n'
#line 87 "parser.y"
                                                                         {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::SWITCH, 5, yystack_[7].value.as < lab3::AbstractNode * > (), yystack_[5].value.as < lab3::BoolConstNode * > (), yystack_[4].value.as < lab3::AbstractNode * > (), yystack_[2].value.as < lab3::BoolConstNode * > (), yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2823 "parser.tab.cc"
    break;

  case 22: // stmt: SWITCH logic '\n' BOOL stmt '\n' BOOL stmtsGroup
#line 88 "parser.y"
                                                                         {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::SWITCH, 5, yystack_[6].value.as < lab3::AbstractNode * > (), yystack_[4].value.as < lab3::BoolConstNode * > (), yystack_[3].value.as < lab3::AbstractNode * > (), yystack_[1].value.as < lab3::BoolConstNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 2829 "parser.tab.cc"
    break;

  case 23: // stmt: SWITCH logic '\n' BOOL stmtsGroup '\n'
#line 89 "parser.y"
                                                            {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::SWITCH, 3, yystack_[4].value.as < lab3::AbstractNode * > (), yystack_[2].value.as < lab3::BoolConstNode * > (), yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2835 "parser.tab.cc"
    break;

  case 24: // stmt: SWITCH logic '\n' BOOL stmtsGroup '\n' BOOL stmt '\n'
#line 90 "parser.y"
                                                                               {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::SWITCH, 5, yystack_[7].value.as < lab3::AbstractNode * > (), yystack_[5].value.as < lab3::BoolConstNode * > (), yystack_[4].value.as < lab3::AbstractNode * > (), yystack_[2].value.as < lab3::BoolConstNode * > (), yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2841 "parser.tab.cc"
    break;

  case 25: // stmt: SWITCH logic '\n' BOOL stmtsGroup '\n' BOOL stmtsGroup '\n'
#line 91 "parser.y"
                                                                                    {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::SWITCH, 5, yystack_[7].value.as < lab3::AbstractNode * > (), yystack_[5].value.as < lab3::BoolConstNode * > (), yystack_[4].value.as < lab3::AbstractNode * > (), yystack_[2].value.as < lab3::BoolConstNode * > (), yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2847 "parser.tab.cc"
    break;

  case 26: // stmt: ROTATE LEFT '\n'
#line 92 "parser.y"
                        {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::LEFT, 0);}
#line 2853 "parser.tab.cc"
    break;

  case 27: // stmt: ROTATE RIGHT '\n'
#line 93 "parser.y"
                         {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::RIGHT, 0);}
#line 2859 "parser.tab.cc"
    break;

  case 28: // stmt: MOVE '\n'
#line 94 "parser.y"
                 {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::MOVE, 0);}
#line 2865 "parser.tab.cc"
    break;

  case 29: // stmt: DO FUNC_NAME parameters '\n'
#line 95 "parser.y"
                                    {functionStack.push((lab3::FunctionNode *)functionsTable.at(yystack_[2].value.as < std::string > ())->clone());
                                yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('f', 2, functionStack.top(), yystack_[1].value.as < lab3::AbstractNode * > ());
                                functionStack.pop();}
#line 2873 "parser.tab.cc"
    break;

  case 31: // stmt: stmt THANKS '\n'
#line 99 "parser.y"
       { yylhs.value.as < lab3::AbstractNode * > () = yystack_[2].value.as < lab3::AbstractNode * > (); }
#line 2879 "parser.tab.cc"
    break;

  case 33: // stmt: RESULT id '\n'
#line 101 "parser.y"
                      {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::RESULT, 1, (*functionStack.top())[yystack_[1].value.as < std::string > ()]);}
#line 2885 "parser.tab.cc"
    break;

  case 34: // parameters: parameters id
#line 103 "parser.y"
                          {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(' ', 2, yystack_[1].value.as < lab3::AbstractNode * > (), (*functionStack.top())[yystack_[0].value.as < std::string > ()]);}
#line 2891 "parser.tab.cc"
    break;

  case 35: // parameters: parameters id '[' indexes ']'
#line 104 "parser.y"
                                         {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(' ', 3, yystack_[4].value.as < lab3::AbstractNode * > (), (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2897 "parser.tab.cc"
    break;

  case 36: // parameters: id
#line 105 "parser.y"
              { yylhs.value.as < lab3::AbstractNode * > () = (*functionStack.top())[yystack_[0].value.as < std::string > ()]; }
#line 2903 "parser.tab.cc"
    break;

  case 37: // parameters: id '[' indexes ']'
#line 106 "parser.y"
                              {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('[', 2, (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2909 "parser.tab.cc"
    break;

  case 38: // value: INTEGER
#line 108 "parser.y"
               {yylhs.value.as < lab3::AbstractNode * > () = yystack_[0].value.as < lab3::IntConstNode * > ();}
#line 2915 "parser.tab.cc"
    break;

  case 39: // value: BOOL
#line 109 "parser.y"
            {yylhs.value.as < lab3::AbstractNode * > () = yystack_[0].value.as < lab3::BoolConstNode * > ();}
#line 2921 "parser.tab.cc"
    break;

  case 40: // expr: arith
#line 111 "parser.y"
            {yylhs.value.as < lab3::AbstractNode * > () = yystack_[0].value.as < lab3::AbstractNode * > ();}
#line 2927 "parser.tab.cc"
    break;

  case 41: // expr: logic
#line 112 "parser.y"
            {yylhs.value.as < lab3::AbstractNode * > () = yystack_[0].value.as < lab3::AbstractNode * > ();}
#line 2933 "parser.tab.cc"
    break;

  case 43: // arith: '(' arith ')'
#line 115 "parser.y"
                     {yylhs.value.as < lab3::AbstractNode * > () = yystack_[1].value.as < lab3::AbstractNode * > ();}
#line 2939 "parser.tab.cc"
    break;

  case 44: // arith: id '[' indexes ']'
#line 116 "parser.y"
                          {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('[', 1, (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 2945 "parser.tab.cc"
    break;

  case 45: // arith: REDUCE id '[' INTEGER ']'
#line 117 "parser.y"
                                 {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::REDUCE, 2, (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::IntConstNode * > ());}
#line 2951 "parser.tab.cc"
    break;

  case 46: // arith: EXTEND id '[' INTEGER ']'
#line 118 "parser.y"
                                 {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::EXTEND, 2, (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::IntConstNode * > ());}
#line 2957 "parser.tab.cc"
    break;

  case 47: // arith: DIGITIZE id
#line 119 "parser.y"
                   {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::DIGITIZE, 1, (*functionStack.top())[yystack_[0].value.as < std::string > ()]);}
#line 2963 "parser.tab.cc"
    break;

  case 48: // arith: SIZE id
#line 120 "parser.y"
               {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::SIZE, 1, (*functionStack.top())[yystack_[0].value.as < std::string > ()]);}
#line 2969 "parser.tab.cc"
    break;

  case 49: // arith: arith '+' arith
#line 121 "parser.y"
                       {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('+', 2, yystack_[2].value.as < lab3::AbstractNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 2975 "parser.tab.cc"
    break;

  case 50: // arith: arith '-' arith
#line 122 "parser.y"
                       {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('-', 2, yystack_[2].value.as < lab3::AbstractNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 2981 "parser.tab.cc"
    break;

  case 51: // arith: arith '*' arith
#line 123 "parser.y"
                       {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('*', 2, yystack_[2].value.as < lab3::AbstractNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 2987 "parser.tab.cc"
    break;

  case 52: // arith: arith '/' arith
#line 124 "parser.y"
                       {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('/', 2, yystack_[2].value.as < lab3::AbstractNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 2993 "parser.tab.cc"
    break;

  case 53: // arith: GET ENVIRONMENT
#line 125 "parser.y"
                       {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::ENVIRONMENT, 0);}
#line 2999 "parser.tab.cc"
    break;

  case 54: // arith: GET FUNC_NAME
#line 126 "parser.y"
                     {yylhs.value.as < lab3::AbstractNode * > () = lastCall.at(yystack_[0].value.as < std::string > ());}
#line 3005 "parser.tab.cc"
    break;

  case 55: // logic: '(' logic ')'
#line 128 "parser.y"
                     {yylhs.value.as < lab3::AbstractNode * > () = yystack_[1].value.as < lab3::AbstractNode * > ();}
#line 3011 "parser.tab.cc"
    break;

  case 56: // logic: logic AND logic
#line 129 "parser.y"
                       {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::AND, 2, yystack_[2].value.as < lab3::AbstractNode * > (), yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3017 "parser.tab.cc"
    break;

  case 57: // logic: BOOL
#line 130 "parser.y"
            {yylhs.value.as < lab3::AbstractNode * > () = yystack_[0].value.as < lab3::BoolConstNode * > ();}
#line 3023 "parser.tab.cc"
    break;

  case 58: // logic: id
#line 131 "parser.y"
          {yylhs.value.as < lab3::AbstractNode * > () = (*functionStack.top())[yystack_[0].value.as < std::string > ()];}
#line 3029 "parser.tab.cc"
    break;

  case 59: // logic: id '[' indexes ']'
#line 132 "parser.y"
                          {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode('[', 1, (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::AbstractNode * > ());}
#line 3035 "parser.tab.cc"
    break;

  case 60: // logic: NOT logic
#line 133 "parser.y"
                 {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::NOT, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3041 "parser.tab.cc"
    break;

  case 61: // logic: LOGITIZE id
#line 134 "parser.y"
                   {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::LOGITIZE, 1, (*functionStack.top())[yystack_[0].value.as < std::string > ()]);}
#line 3047 "parser.tab.cc"
    break;

  case 62: // logic: MXEQ arith
#line 135 "parser.y"
                  {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::MXEQ, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3053 "parser.tab.cc"
    break;

  case 63: // logic: MXLT arith
#line 136 "parser.y"
                  {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::MXLT, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3059 "parser.tab.cc"
    break;

  case 64: // logic: MXGT arith
#line 137 "parser.y"
                  {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::MXGT, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3065 "parser.tab.cc"
    break;

  case 65: // logic: MXLTE arith
#line 138 "parser.y"
                   {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::MXLTE, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3071 "parser.tab.cc"
    break;

  case 66: // logic: MXGTE arith
#line 139 "parser.y"
                   {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::MXGTE, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3077 "parser.tab.cc"
    break;

  case 67: // logic: ELEQ arith
#line 140 "parser.y"
                  {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::ELEQ, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3083 "parser.tab.cc"
    break;

  case 68: // logic: ELLT arith
#line 141 "parser.y"
                  {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::ELLT, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3089 "parser.tab.cc"
    break;

  case 69: // logic: ELGT arith
#line 142 "parser.y"
                  {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::ELGT, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3095 "parser.tab.cc"
    break;

  case 70: // logic: ELLTE arith
#line 143 "parser.y"
                   {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::ELLTE, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3101 "parser.tab.cc"
    break;

  case 71: // logic: ELGTE arith
#line 144 "parser.y"
                   {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::ELGTE, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3107 "parser.tab.cc"
    break;

  case 72: // logic: MXFALSE logic
#line 145 "parser.y"
                     {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::MXFALSE, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3113 "parser.tab.cc"
    break;

  case 73: // logic: MXTRUE logic
#line 146 "parser.y"
                    {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::MXTRUE, 1, yystack_[0].value.as < lab3::AbstractNode * > ());}
#line 3119 "parser.tab.cc"
    break;

  case 74: // logic: REDUCE id '[' INTEGER ']'
#line 147 "parser.y"
                                 {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::REDUCE, 2, (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::IntConstNode * > ());}
#line 3125 "parser.tab.cc"
    break;

  case 75: // logic: EXTEND id '[' INTEGER ']'
#line 148 "parser.y"
                                 {yylhs.value.as < lab3::AbstractNode * > () = new lab3::OperationNode(token::EXTEND, 2, (*functionStack.top())[yystack_[3].value.as < std::string > ()], yystack_[1].value.as < lab3::IntConstNode * > ());}
#line 3131 "parser.tab.cc"
    break;


#line 3135 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -109;

  const signed char parser::yytable_ninf_ = -76;

  const short
  parser::yypact_[] =
  {
    -109,     6,     0,  -109,    14,  -109,     4,  -109,     2,  -109,
     -26,   202,  -109,    47,    75,    23,   132,   -20,    79,    49,
      31,   202,    62,  -109,   137,    20,   132,   132,  -109,    36,
      64,    82,    75,   102,    16,    16,    16,    16,    16,    16,
      16,    16,    16,    16,    75,    75,    75,   -17,   118,  -109,
      78,     8,   135,   136,   138,   142,   132,   101,    69,   125,
    -109,   104,   105,   110,   156,   -19,    50,  -109,    20,   133,
     144,   -27,  -109,   132,   127,   130,  -109,  -109,   131,   183,
     190,    16,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,  -109,  -109,   -14,    75,   194,   195,   132,  -109,
    -109,  -109,   146,   147,  -109,    43,  -109,    16,    16,    16,
      16,  -109,  -109,  -109,   153,     3,  -109,   122,   132,  -109,
    -109,   132,   145,   -11,   209,   210,   132,   161,   162,  -109,
    -109,   184,   207,    26,   216,   217,  -109,   108,   108,  -109,
    -109,   132,   170,  -109,  -109,  -109,   176,    30,  -109,   132,
    -109,   171,   172,    32,   226,   227,   181,   -12,   228,   205,
     179,   182,    33,   132,  -109,   185,   187,  -109,  -109,  -109,
     186,   188,   236,   237,   184,   218,   219,  -109,    39,   122,
    -109,  -109,  -109,   184,   184,   193,    -9,  -109,   197,   198,
      -8,  -109,    -7,  -109,  -109,  -109,  -109,  -109,  -109
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     2,     1,     0,     3,     0,     7,     0,     6,
       0,     0,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,    12,     0,     0,    57,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      58,     0,     0,     0,     0,     0,     0,     0,    40,    41,
      28,     0,     0,     0,     0,     0,     0,    10,    11,     0,
       0,     0,     9,     0,     0,     0,    60,    61,     0,     0,
       0,     0,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,    54,
      53,    47,     0,     0,    48,     0,    32,     0,     0,     0,
       0,    26,    27,    33,    36,     0,    30,     0,     0,    31,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,     0,     0,     0,     0,     0,    43,    49,    50,    51,
      52,     0,    34,    29,    38,    39,     0,     0,     8,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,     0,     0,     0,    16,     0,     0,    74,    75,    44,
       0,     0,    23,    20,     0,    45,    46,    37,     0,     0,
      15,    45,    46,     0,     0,     0,     0,    35,     0,     0,
       0,    22,     0,    18,    19,    17,    25,    24,    21
  };

  const signed char
  parser::yypgoto_[] =
  {
    -109,  -109,  -109,  -109,  -109,   -71,  -108,  -109,   -21,  -109,
      70,   -15,    22,   -10
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     1,     2,     5,     8,    71,    12,    24,    25,   115,
     146,    72,    58,    59
  };

  const short
  parser::yytable_[] =
  {
      65,    57,   123,    68,    47,    69,     3,     9,   142,     7,
      95,    70,    69,    95,    99,    69,    69,    69,     4,    49,
       6,    78,    76,   156,   121,   100,    11,   133,    48,   122,
      60,   116,    51,    96,    92,    93,    94,    64,   173,   129,
     121,   194,   197,   198,    69,   150,    94,   147,    52,    79,
      80,    55,    10,   143,    63,   153,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   185,    66,    81,    74,
     162,   107,   108,   109,   110,   189,   191,   121,   105,    28,
      29,   121,   159,   121,   121,   130,   165,    75,   169,   177,
     121,    73,   178,    61,    62,   187,   136,   107,   108,   109,
     110,    26,    27,   105,   117,   118,   148,    77,    30,    31,
     157,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,   144,   145,    46,    97,   137,
     138,   139,   140,    98,   166,    49,    28,    50,   109,   110,
     101,   102,    13,   103,    14,    15,    16,   104,    51,    17,
      18,   106,    95,   186,   111,   112,    19,    20,    21,    22,
     113,   114,   190,   192,    52,    53,    54,    55,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   124,   119,    56,   125,   126,    23,   127,    13,
      67,    14,    15,    16,   120,   128,    17,    18,   131,   149,
     132,   134,   135,    19,    20,    21,    22,    13,   141,    14,
      15,    16,   151,   152,    17,    18,   154,   155,   158,   160,
     161,    19,    20,    21,    22,   163,   164,   167,   168,   170,
     171,   172,   -59,   174,    23,   175,    11,   180,   176,   179,
     183,   184,   181,   193,   182,   -74,   -75,   195,   196,   188,
       0,     0,    23
  };

  const short
  parser::yycheck_[] =
  {
      21,    16,    73,    24,    14,    24,     0,     5,     5,     5,
      27,    26,    24,    27,     6,    24,    24,    24,    18,     3,
       6,     5,    32,   131,    51,    17,    52,    98,     5,    56,
      50,    50,    16,    50,    44,    45,    46,     6,    50,    53,
      51,    50,    50,    50,    24,    56,    56,   118,    32,    33,
      34,    35,    50,    50,     5,   126,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   174,     5,    52,     5,
     141,    28,    29,    30,    31,   183,   184,    51,    56,     4,
       5,    51,    56,    51,    51,    95,    56,     5,    56,    56,
      51,    55,   163,    14,    15,    56,    53,    28,    29,    30,
      31,    54,    55,    81,    54,    55,   121,     5,    33,    34,
     131,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,     3,     4,    52,    10,   107,
     108,   109,   110,    55,   149,     3,     4,     5,    30,    31,
       5,     5,     5,     5,     7,     8,     9,     5,    16,    12,
      13,    50,    27,   174,    50,    50,    19,    20,    21,    22,
      50,     5,   183,   184,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    55,    50,    52,    55,    55,    50,     5,     5,
      53,     7,     8,     9,    50,     5,    12,    13,     4,    54,
       5,    55,    55,    19,    20,    21,    22,     5,    55,     7,
       8,     9,     3,     3,    12,    13,    55,    55,    11,     3,
       3,    19,    20,    21,    22,    55,    50,    56,    56,     3,
       3,    50,    27,     5,    50,    56,    52,    50,    56,    54,
       4,     4,    56,    50,    56,    27,    27,    50,    50,   179,
      -1,    -1,    50
  };

  const signed char
  parser::yystos_[] =
  {
       0,    58,    59,     0,    18,    60,     6,     5,    61,     5,
      50,    52,    63,     5,     7,     8,     9,    12,    13,    19,
      20,    21,    22,    50,    64,    65,    54,    55,     4,     5,
      33,    34,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    52,    70,     5,     3,
       5,    16,    32,    33,    34,    35,    52,    68,    69,    70,
      50,    14,    15,     5,     6,    65,     5,    53,    65,    24,
      68,    62,    68,    55,     5,     5,    70,     5,     5,    33,
      34,    52,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    70,    27,    50,    10,    55,     6,
      17,     5,     5,     5,     5,    69,    50,    28,    29,    30,
      31,    50,    50,    50,     5,    66,    50,    54,    55,    50,
      50,    51,    56,    62,    55,    55,    55,     5,     5,    53,
      70,     4,     5,    62,    55,    55,    53,    69,    69,    69,
      69,    55,     5,    50,     3,     4,    67,    62,    68,    54,
      56,     3,     3,    62,    55,    55,    63,    65,    11,    56,
       3,     3,    62,    55,    50,    56,    68,    56,    56,    56,
       3,     3,    50,    50,     5,    56,    56,    56,    62,    54,
      50,    56,    56,     4,     4,    63,    65,    56,    67,    63,
      65,    63,    65,    50,    50,    50,    50,    50,    50
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    57,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     5,     2,     1,     3,     1,
       3,     2,     1,     1,     4,     7,     5,     8,     8,     8,
       6,     9,     8,     6,     9,     9,     3,     3,     2,     4,
       3,     3,     3,     3,     2,     5,     1,     4,     1,     1,
       1,     1,     1,     3,     4,     5,     5,     2,     2,     3,
       3,     3,     3,     2,     2,     3,     3,     1,     1,     4,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     5,     5
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "BOOL",
  "id", "FUNC_NAME", "SWITCH", "FOR", "PRINT", "BOUNDARY", "STEP", "MOVE",
  "ROTATE", "LEFT", "RIGHT", "GET", "ENVIRONMENT", "TASK", "RESULT", "DO",
  "PLEASE", "VAR", "PLSX", "THANKS", "SWITCHX", "HIGHSWITCHX", "AND",
  "'+'", "'-'", "'*'", "'/'", "DIGITIZE", "REDUCE", "EXTEND", "SIZE",
  "NOT", "LOGITIZE", "MXEQ", "MXLT", "MXGT", "MXLTE", "MXGTE", "ELEQ",
  "ELLT", "ELGT", "ELLTE", "ELGTE", "MXFALSE", "MXTRUE", "'\\n'", "','",
  "'('", "')'", "'='", "'['", "']'", "$accept", "program", "functions",
  "function", "ids", "indexes", "stmtsGroup", "stmts", "stmt",
  "parameters", "value", "expr", "arith", "logic", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    52,    52,    62,    63,    66,    68,    69,    71,    72,
      74,    76,    77,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      98,    99,   100,   101,   103,   104,   105,   106,   108,   109,
     111,   112,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
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
    // Last valid token kind.
    const int code_max = 300;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 3620 "parser.tab.cc"

