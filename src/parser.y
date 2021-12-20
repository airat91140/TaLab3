%{
#include <string>
#include <map>
#include <stack>
#include <exception>
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
#include "Driver.h"

lab3::Driver dr;
/* prototypes */
int yylex(void);
void init (void);
void yyerror(char *s);

%}

%union {
    lab3::AbstractNode *nPtr;
    lab3::BoolConstNode *boolVal;
    lab3::IntConstNode *intVal;
    char *name;
    lab3::BoolArrayVariableNode *boolArrVar;
    lab3::BoolVariableNode *boolVar;
    lab3::IntArrayVariableNode *intArrVar;
    lab3::IntVariableNode *intVar;
}

%token <intVal> INTEGER
%token <boolVal> BOOL
%token <name> id
%token SWITCH FOR PRINT BOUNDARY STEP MOVE ROTATE LEFT RIGHT GET ENVIRONMENT TASK RESULT DO PLEASE VAR
%left PLSX
%left THANKS
%nonassoc  SWITCHX
%nonassoc  HIGHSWITCHX
%left AND
%left '+' '-'
%left '*' '/'
%nonassoc DIGITIZE REDUCE EXTEND SIZE NOT LOGITIZE MXEQ MXLT MXGT MXLTE MXGTE ELEQ ELLT ELGT ELLTE ELGTE MXFALSE MXTRUE

%type<nPtr> functions function stmts ids logic arith expr indexes value parameters stmtsGroup stmt

%%

program:
    functions { if (!dr.functionsTable.contains("FINDEXIT"))
                    throw std::runtime_error("Could not find FINDEXIT function");

                dr.functionsTable.at("FINDEXIT")->exec(new lab3::BoolConstNode(true));
                for (const auto &[key, value] : dr.functionsTable)
                    delete value;
                exit(0);
               }

functions:
    functions function {dr.functionsTable.insert({((lab3::FunctionNode *)$2)->getName(), $2}); dr.lastCall.insert({((lab3::FunctionNode *)$2)->getName(), nullptr});}
    | %empty

function:
    TASK id ids '\n' stmtsGroup {$$ = new lab3::FunctionNode($2, $3, $5);}

ids: ids id {$$ = new lab3::OperationNode(' ', 2, $1, new lab3::ParameterNode($2));}
    | id {$$ = new lab3::ParameterNode($1);}

indexes: indexes ',' expr {$$ = new lab3::OperationNode(',', 2, $1, $3); }
        | expr { $$ = new lab3::OperationNode(',', 1, $1); }

stmtsGroup: '(' stmts ')' {$$ = $2;}

stmts: stmts stmt {$$ = new lab3::OperationNode('\n', 2, $1, $2);}
     | stmt {$$ = $1;}

stmt:  '\n' { $$ = nullptr;}
     | id '=' expr '\n' {$$ = new lab3::OperationNode('=', 2, (*dr.functionStack.top())[$1], $3);}
     | id '[' indexes ']' '=' expr '\n' {$$ = new lab3::OperationNode('=', 3, (*dr.functionStack.top())[$1], $3, $6);}
     | VAR id '=' value '\n' {$$ = new lab3::OperationNode(VAR, 2, new lab3::ParameterNode($2), $4);}
     | VAR id '[' indexes ']' '=' value '\n' {$$ = new lab3::OperationNode(VAR, 3, new lab3::ParameterNode($2), $4, $7);}
     | FOR id BOUNDARY id STEP id stmtsGroup '\n' {$$ = new lab3::OperationNode(FOR, 4, (*dr.functionStack.top())[$2], (*dr.functionStack.top())[$4], (*dr.functionStack.top())[$6], $7);}
     | FOR id BOUNDARY id STEP id stmt '\n' {$$ = new lab3::OperationNode(FOR, 4, (*dr.functionStack.top())[$2], (*dr.functionStack.top())[$4], (*dr.functionStack.top())[$6], $7);}
     | SWITCH logic '\n' BOOL stmt '\n' %prec SWITCHX {$$ = new lab3::OperationNode(SWITCH, 3, $2, $4, $5);}
     | SWITCH logic '\n' BOOL stmt '\n' BOOL stmt '\n' %prec HIGHSWITCHX {$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $7, $8);}
     | SWITCH logic '\n' BOOL stmt '\n' BOOL stmtsGroup %prec HIGHSWITCHX{$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $7, $8);}
     | SWITCH logic '\n' BOOL stmtsGroup '\n' %prec SWITCHX {$$ = new lab3::OperationNode(SWITCH, 3, $2, $4, $5);}
     | SWITCH logic '\n' BOOL stmtsGroup '\n' BOOL stmt '\n' %prec HIGHSWITCHX {$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $7, $8);}
     | SWITCH logic '\n' BOOL stmtsGroup '\n' BOOL stmtsGroup '\n' %prec HIGHSWITCHX{$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $7, $8);}
     | ROTATE LEFT '\n' {$$ = new lab3::OperationNode(LEFT, 0);}
     | ROTATE RIGHT '\n' {$$ = new lab3::OperationNode(RIGHT, 0);}
     | MOVE '\n' {$$ = new lab3::OperationNode(MOVE, 0);}
     | DO id parameters '\n' {dr.functionStack.push((lab3::FunctionNode *)dr.functionsTable.at($2)->clone());
                                $$ = new lab3::OperationNode('DO', 2, dr.functionStack.top(), $3);}
     | PLEASE stmt %prec PLSX '\n'
     | stmt THANKS '\n'
     | PRINT expr '\n' {$$ = new lab3::OperationNode(PRINT, 1, $2);}
     | RESULT id '\n' {$$ = new lab3::OperationNode(RESULT, 1, (*dr.functionStack.top())[$2]);
                        dr.lastCall.at($2) = (*dr.functionStack.top())[$2];
                        dr.functionStack.pop();}

parameters: parameters id {$$ = new lab3::OperationNode(' ', 2, $1, (*dr.functionStack.top())[$2]);}
         | parameters id '[' indexes ']' {$$ = new lab3::OperationNode(' ', 3, $1, (*dr.functionStack.top())[$2], $4);}
         | id { $$ = (*dr.functionStack.top())[$1]; }
         | id '[' indexes ']' {$$ = new lab3::OperationNode('[', 2, (*dr.functionStack.top())[$1], $3);}

value: INTEGER {$$ = $1;}
     | BOOL {$$ = $1;}

expr: arith {$$ = $1;}
    | logic {$$ = $1;}

arith: INTEGER
     | '(' arith ')' {$$ = $2;}
     | id '[' indexes ']' {$$ = new lab3::OperationNode('[', 1, (*dr.functionStack.top())[$1], $3);}
     | REDUCE id '[' INTEGER ']' {$$ = new lab3::OperationNode(REDUCE, 2, (*dr.functionStack.top())[$2], $4);}
     | EXTEND id '[' INTEGER ']' {$$ = new lab3::OperationNode(EXTEND, 2, (*dr.functionStack.top())[$2], $4);}
     | DIGITIZE id {$$ = new lab3::OperationNode(DIGITIZE, 1, (*dr.functionStack.top())[$2]);}
     | SIZE id {$$ = new lab3::OperationNode(SIZE, 1, (*dr.functionStack.top())[$2]);}
     | arith '+' arith {$$ = new lab3::OperationNode('+', 2, $1, $3);}
     | arith '-' arith {$$ = new lab3::OperationNode('-', 2, $1, $3);}
     | arith '*' arith {$$ = new lab3::OperationNode('*', 2, $1, $3);}
     | arith '/' arith {$$ = new lab3::OperationNode('/', 2, $1, $3);}
     | GET ENVIRONMENT {$$ = new lab3::OperationNode(ENVIRONMENT, 0);}
     | GET id {$$ = dr.lastCall.at($2);}

logic: '(' logic ')' {$$ = $2;}
     | logic AND logic {$$ = new lab3::OperationNode(AND, 2, $1, $3);}
     | BOOL {$$ = $1;}
     | id {$$ = (*dr.functionStack.top())[$1];}
     | id '[' indexes ']' {$$ = new lab3::OperationNode('[', 1, (*dr.functionStack.top())[$1], $3);}
     | NOT logic {$$ = new lab3::OperationNode(NOT, 1, $2);}
     | LOGITIZE id {$$ = new lab3::OperationNode(LOGITIZE, 1, (*dr.functionStack.top())[$2]);}
     | MXEQ arith {$$ = new lab3::OperationNode(MXEQ, 1, $2);}
     | MXLT arith {$$ = new lab3::OperationNode(MXLT, 1, $2);}
     | MXGT arith {$$ = new lab3::OperationNode(MXGT, 1, $2);}
     | MXLTE arith {$$ = new lab3::OperationNode(MXLTE, 1, $2);}
     | MXGTE arith {$$ = new lab3::OperationNode(MXGTE, 1, $2);}
     | ELEQ arith {$$ = new lab3::OperationNode(ELEQ, 1, $2);}
     | ELLT arith {$$ = new lab3::OperationNode(ELLT, 1, $2);}
     | ELGT arith {$$ = new lab3::OperationNode(ELGT, 1, $2);}
     | ELLTE arith {$$ = new lab3::OperationNode(ELLTE, 1, $2);}
     | ELGTE arith {$$ = new lab3::OperationNode(ELGTE, 1, $2);}
     | MXFALSE logic {$$ = new lab3::OperationNode(MXFALSE, 1, $2);}
     | MXTRUE logic {$$ = new lab3::OperationNode(MXTRUE, 1, $2);}
     | REDUCE id '[' INTEGER ']' {$$ = new lab3::OperationNode(REDUCE, 2, (*dr.functionStack.top())[$2], $4);}
     | EXTEND id '[' INTEGER ']' {$$ = new lab3::OperationNode(EXTEND, 2, (*dr.functionStack.top())[$2], $4);}