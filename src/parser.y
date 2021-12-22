%code requires {
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
}

%union {
    lab3::AbstractNode *nPtr;
    lab3::BoolConstNode *boolVal;
    lab3::IntConstNode *intVal;
    std::string *name;
}
%nonassoc END
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
    functions { if (!functionsTable.contains("FINDEXIT"))
                    throw std::runtime_error("Could not find FINDEXIT function");

                functionsTable.at("FINDEXIT")->exec(new lab3::BoolConstNode(true));
                for (const auto &[key, value] : functionsTable)
                    delete value;
                exit(0);
               }

functions:
    functions function {functionsTable.insert({((lab3::FunctionNode *)$2)->getName(), $2}); lastCall.insert({((lab3::FunctionNode *)$2)->getName(), nullptr});}
    | %empty {$$ = nullptr;}

function:
    TASK id ids '\n' stmtsGroup {auto tmp = new lab3::FunctionNode(*$2, $3, $5);
                                 for (const auto &it : varTable)
                                     tmp->addVar(it.first, (lab3::AbstractVariableNode *)it.second);
                                 auto iter = $3;
                                     while (iter->nodeType == lab3::OPERATION) {
                                         tmp->addVar(((lab3::AbstractVariableNode *)(*(lab3::OperationNode *)iter)[1])->getName(), ((lab3::AbstractVariableNode *)(*(lab3::OperationNode *)iter)[1]));
                                         iter = (*(lab3::OperationNode *)iter)[0];
                                     }
                                 tmp->addVar(((lab3::AbstractVariableNode *)iter)->getName(), ((lab3::AbstractVariableNode *)iter));
                                 varTable.clear();
                                 lastCall.insert({*$2, lastResult});
                                 $$ = tmp;
                                 }

ids: ids id {$$ = new lab3::OperationNode(' ', 2, $1, new lab3::ParameterNode(*$2));}
    | id {$$ = new lab3::ParameterNode(*$1);}

indexes: indexes ',' expr {$$ = new lab3::OperationNode(',', 2, $1, $3); }
        | expr { $$ = new lab3::OperationNode(',', 1, $1); }
        | %empty {$$ = new lab3::OperationNode(',', 0);}

stmtsGroup: '(' stmts ')' {$$ = $2;}

stmts: stmts stmt {$$ = new lab3::OperationNode('\n', 2, $1, $2);}
     | stmt {$1->print(std::cout); $$ = $1;}

stmt:  '\n' {new lab3::OperationNode('e', 0);}
     | id '=' expr '\n' {$$ = new lab3::OperationNode('=', 2, varTable.at(*$1), $3);}
     | id '[' indexes ']' '=' expr '\n' {$$ = new lab3::OperationNode('=', 3, varTable.at(*$1), $3, $6);}
     | VAR id '=' BOOL '\n' {if (!varTable.insert({*$2, new lab3::BoolVariableNode(*$2, $4->getVal())}).second)
                                throw std::runtime_error("Variable already defined");
                             delete $4;
                             $$ = new lab3::OperationNode(VAR, 0);}
     | VAR id '[' indexes ']' '=' BOOL '\n' {if (!varTable.insert({*$2, new lab3::BoolArrayVariableNode(*$2, $7->getVal(), lab3::AbstractVariableNode::makeDims($4))}).second)
                                                throw std::runtime_error("Variable already defined");
                                             delete $7;
                                             $$ = new lab3::OperationNode(VAR, 0);}
     | VAR id '=' INTEGER '\n' {if (!varTable.insert({*$2, new lab3::IntVariableNode(*$2, $4->getVal())}).second)
                                    throw std::runtime_error("Variable already defined");
                                delete $4;
                                $$ = new lab3::OperationNode(VAR, 0);}
     | VAR id '[' indexes ']' '=' INTEGER '\n' {if (!varTable.insert({*$2, new lab3::IntArrayVariableNode(*$2, $7->getVal(), lab3::AbstractVariableNode::makeDims($4))}).second)
                                                    throw std::runtime_error("Variable already defined");
                                                delete $7;
                                                $$ = new lab3::OperationNode(VAR, 0);}
     | FOR id BOUNDARY id STEP id stmtsGroup '\n' {$$ = new lab3::OperationNode(FOR, 4, varTable.at(*$2), varTable.at(*$4), varTable.at(*$6), $7);}
     | FOR id BOUNDARY id STEP id stmt '\n' {$$ = new lab3::OperationNode(FOR, 4, varTable.at(*$2), varTable.at(*$4), varTable.at(*$6), $7);}
     | SWITCH logic '\n' BOOL stmt '\n' %prec SWITCHX {$$ = new lab3::OperationNode(SWITCH, 3, $2, $4, $5);}
     | SWITCH logic '\n' BOOL stmt '\n' BOOL stmt '\n' %prec HIGHSWITCHX {$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $7, $8);}
     | SWITCH logic '\n' BOOL stmt '\n' BOOL stmtsGroup %prec HIGHSWITCHX{$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $7, $8);}
     | SWITCH logic '\n' BOOL stmtsGroup '\n' %prec SWITCHX {$$ = new lab3::OperationNode(SWITCH, 3, $2, $4, $5);}
     | SWITCH logic '\n' BOOL stmtsGroup '\n' BOOL stmt '\n' %prec HIGHSWITCHX {$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $7, $8);}
     | SWITCH logic '\n' BOOL stmtsGroup '\n' BOOL stmtsGroup '\n' %prec HIGHSWITCHX{$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $7, $8);}
     | ROTATE LEFT '\n' {$$ = new lab3::OperationNode(LEFT, 0);}
     | ROTATE RIGHT '\n' {$$ = new lab3::OperationNode(RIGHT, 0);}
     | MOVE '\n' {$$ = new lab3::OperationNode(MOVE, 0);}
     | DO id parameters '\n' {$$ = new lab3::OperationNode('DO', 2, new lab3::ParameterNode(*$2), $3);}
     | PLEASE stmt %prec PLSX '\n'
     | stmt THANKS '\n'
     | PRINT expr '\n' {$$ = new lab3::OperationNode(PRINT, 1, $2);}
     | RESULT id '\n' {$$ = new lab3::OperationNode(RESULT, 1, varTable.at(*$2));
                        lastResult = (lab3::AbstractVariableNode *)varTable.at(*$2);
                        }

parameters: parameters id {$$ = new lab3::OperationNode(' ', 2, $1, varTable.at(*$2));}
         | parameters id '[' indexes ']' {$$ = new lab3::OperationNode(' ', 3, $1, varTable.at(*$2), $4);}
         | id { $$ = varTable.at(*$1); }
         | id '[' indexes ']' {$$ = new lab3::OperationNode('[', 2, varTable.at(*$1), $3);}

value: INTEGER {$$ = $1;}
     | BOOL {$$ = $1;}

expr: arith {$$ = $1;}
    | logic {$$ = $1;}

arith: INTEGER
     | '(' arith ')' {$$ = $2;}
     | id '[' indexes ']' {$$ = new lab3::OperationNode('[', 1, varTable.at(*$1), $3);}
     | REDUCE id '[' INTEGER ']' {$$ = new lab3::OperationNode(REDUCE, 2, varTable.at(*$2), $4);}
     | EXTEND id '[' INTEGER ']' {$$ = new lab3::OperationNode(EXTEND, 2, varTable.at(*$2), $4);}
     | DIGITIZE id {$$ = new lab3::OperationNode(DIGITIZE, 1, varTable.at(*$2));}
     | SIZE id {$$ = new lab3::OperationNode(SIZE, 1, varTable.at(*$2));}
     | arith '+' arith {$$ = new lab3::OperationNode('+', 2, $1, $3);}
     | arith '-' arith {$$ = new lab3::OperationNode('-', 2, $1, $3);}
     | arith '*' arith {$$ = new lab3::OperationNode('*', 2, $1, $3);}
     | arith '/' arith {$$ = new lab3::OperationNode('/', 2, $1, $3);}
     | GET ENVIRONMENT {$$ = new lab3::OperationNode(ENVIRONMENT, 0);}
     | GET id {$$ = lastCall.at(*$2);}

logic: '(' logic ')' {$$ = $2;}
     | logic AND logic {$$ = new lab3::OperationNode(AND, 2, $1, $3);}
     | BOOL {$$ = $1;}
     | id {$$ = varTable.at(*$1);}
     | id '[' indexes ']' {$$ = new lab3::OperationNode('[', 1, varTable.at(*$1), $3);}
     | NOT logic {$$ = new lab3::OperationNode(NOT, 1, $2);}
     | LOGITIZE id {$$ = new lab3::OperationNode(LOGITIZE, 1, varTable.at(*$2));}
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
     | REDUCE id '[' INTEGER ']' {$$ = new lab3::OperationNode(REDUCE, 2, varTable.at(*$2), $4);}
     | EXTEND id '[' INTEGER ']' {$$ = new lab3::OperationNode(EXTEND, 2, varTable.at(*$2), $4);}