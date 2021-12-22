/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

#include <string>
#include <map>
#include <exception>
#include "AbstractNode.h"
#include "BoolArrayVariableNode.h"
#include "OperationNode.h"
#include "IntArrayVariableNode.h"
#include "FunctionNode.h"
#include "ParameterNode.h"

static std::map<std::string, lab3::AbstractNode *> functionsTable;
static std::map<std::string, lab3::AbstractNode *> lastCall;
static std::map<std::string, lab3::AbstractNode *> varTable;
static bool hasResult;
static lab3::AbstractVariableNode *lastResult;
/* prototypes */
int yylex(void);

void yyerror(char *s);

#line 71 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    END = 258,                     /* END  */
    INTEGER = 259,                 /* INTEGER  */
    BOOL = 260,                    /* BOOL  */
    id = 261,                      /* id  */
    SWITCH = 262,                  /* SWITCH  */
    FOR = 263,                     /* FOR  */
    PRINT = 264,                   /* PRINT  */
    BOUNDARY = 265,                /* BOUNDARY  */
    STEP = 266,                    /* STEP  */
    MOVE = 267,                    /* MOVE  */
    ROTATE = 268,                  /* ROTATE  */
    LEFT = 269,                    /* LEFT  */
    RIGHT = 270,                   /* RIGHT  */
    GET = 271,                     /* GET  */
    ENVIRONMENT = 272,             /* ENVIRONMENT  */
    TASK = 273,                    /* TASK  */
    RESULT = 274,                  /* RESULT  */
    DO = 275,                      /* DO  */
    PLEASE = 276,                  /* PLEASE  */
    VAR = 277,                     /* VAR  */
    PLSX = 278,                    /* PLSX  */
    THANKS = 279,                  /* THANKS  */
    SWITCHX = 280,                 /* SWITCHX  */
    HIGHSWITCHX = 281,             /* HIGHSWITCHX  */
    AND = 282,                     /* AND  */
    DIGITIZE = 283,                /* DIGITIZE  */
    REDUCE = 284,                  /* REDUCE  */
    EXTEND = 285,                  /* EXTEND  */
    SIZE = 286,                    /* SIZE  */
    NOT = 287,                     /* NOT  */
    LOGITIZE = 288,                /* LOGITIZE  */
    MXEQ = 289,                    /* MXEQ  */
    MXLT = 290,                    /* MXLT  */
    MXGT = 291,                    /* MXGT  */
    MXLTE = 292,                   /* MXLTE  */
    MXGTE = 293,                   /* MXGTE  */
    ELEQ = 294,                    /* ELEQ  */
    ELLT = 295,                    /* ELLT  */
    ELGT = 296,                    /* ELGT  */
    ELLTE = 297,                   /* ELLTE  */
    ELGTE = 298,                   /* ELGTE  */
    MXFALSE = 299,                 /* MXFALSE  */
    MXTRUE = 300                   /* MXTRUE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    lab3::AbstractNode *nPtr;
    lab3::BoolConstNode *boolVal;
    lab3::IntConstNode *intVal;
    std::string *name;

#line 140 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
