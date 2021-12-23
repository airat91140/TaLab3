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
static lab3::AbstractVariableNode *lastResult = new lab3::ParameterNode("tmp");
static int sadnessBorder = -(rand() % 30 + 60); //-30 to -59
static int suspectnessBorder = (rand() % 30 + 60); // 30 to 59
static int mood = 0;
static int probability = rand() % 41 + 30; //30 to 70;
static bool errorFlag = false;
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

%precedence  SWITCHX
%precedence  BOOL
%left PLSX
%right THANKS
%left AND
%left '+' '-'
%left '*' '/'
%nonassoc DIGITIZE REDUCE EXTEND SIZE NOT LOGITIZE MXEQ MXLT MXGT MXLTE MXGTE ELEQ ELLT ELGT ELLTE ELGTE MXFALSE MXTRUE


%type<nPtr>inds functions function stmts ids expr indexes value parameters stmtsGroup stmt

%%

program:
    functions { if (!functionsTable.contains("FINDEXIT"))
                    throw std::runtime_error("Could not find FINDEXIT function");

                functionsTable.at("FINDEXIT")->exec(new lab3::BoolVariableNode("tmp", true));
                for (const auto &[key, value] : functionsTable)
                    delete value;
                exit(0);
               }

functions:
    functions '\n' function
    | function
    | '\n' {$$ = nullptr;}

function:
    TASK id ids '\n' stmtsGroup {auto tmp = new lab3::FunctionNode(*$2, $3, $5);
                                 for (const auto &it : varTable)
                                     tmp->addVar(it.first, (lab3::AbstractVariableNode *)it.second);
                                 varTable.clear();
                                 lastCall.insert({*$2, lastResult});
                                 functionsTable.insert({*$2, tmp});
                                 lastResult = new lab3::ParameterNode("tmp");
                                 $$ = tmp;
                                 }

ids: ids id {auto res = new lab3::ParameterNode(*$2); varTable.insert({*$2, res}); $$ = new lab3::OperationNode(' ', 2, $1, res);}
    | id {auto res = new lab3::ParameterNode(*$1); varTable.insert({*$1, res}); $$ = res;}

indexes: inds {$$ = $1;}
        | %empty {$$ = new lab3::OperationNode(',', 0);}

inds: inds ',' expr {$$ = new lab3::OperationNode(',', 2, $1, $3); }
    | expr { $$ = new lab3::OperationNode(',', 1, $1); }

stmtsGroup: '(' '\n' stmts '\n' ')' {$$ = $3;}

stmts: stmts '\n' stmt {$$ = new lab3::OperationNode('\n', 2, $1, $3);}
     | stmt {$$ = $1;}
     | stmts '\n' {$$ = new lab3::OperationNode('\n', 1, $1);}
     | stmts error {std::cout << "Some error on line " << @2.first_line << std::endl; yyerrok;}

stmt:  id '=' expr {$$ = new lab3::OperationNode('=', 2, varTable.at(*$1), $3);}
     | id '[' indexes ']' '=' expr {$$ = new lab3::OperationNode('=', 3, varTable.at(*$1), $3, $6);}
     | VAR id '=' BOOL {if (!varTable.insert({*$2, new lab3::BoolVariableNode(*$2, $4->getVal())}).second)
                                throw std::runtime_error("Variable already defined");
                             delete $4;
                             $$ = new lab3::OperationNode(VAR, 0);}
     | VAR id '[' indexes ']' '=' BOOL {if (!varTable.insert({*$2, new lab3::BoolArrayVariableNode(*$2, $7->getVal(), lab3::AbstractVariableNode::makeDims($4))}).second)
                                                throw std::runtime_error("Variable already defined");
                                             delete $7;
                                             $$ = new lab3::OperationNode(VAR, 0);}
     | VAR id '=' INTEGER  {if (!varTable.insert({*$2, new lab3::IntVariableNode(*$2, $4->getVal())}).second)
                                    throw std::runtime_error("Variable already defined");
                                delete $4;
                                $$ = new lab3::OperationNode(VAR, 0);}
     | VAR id '[' indexes ']' '=' INTEGER {if (!varTable.insert({*$2, new lab3::IntArrayVariableNode(*$2, $7->getVal(), lab3::AbstractVariableNode::makeDims($4))}).second)
                                                    throw std::runtime_error("Variable already defined");
                                                delete $7;
                                                $$ = new lab3::OperationNode(VAR, 0);}
     | FOR id BOUNDARY id STEP id stmtsGroup {$$ = new lab3::OperationNode(FOR, 4, varTable.at(*$2), varTable.at(*$4), varTable.at(*$6), $7);}
     | FOR id BOUNDARY id STEP id stmt {$$ = new lab3::OperationNode(FOR, 4, varTable.at(*$2), varTable.at(*$4), varTable.at(*$6), $7);}
     | SWITCH expr '\n' BOOL stmt %prec SWITCHX {$$ = new lab3::OperationNode(SWITCH, 3, $2, $4, $5);}
     | SWITCH expr '\n' BOOL stmt BOOL stmt {$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $6, $7);}
     | SWITCH expr '\n' BOOL stmt BOOL stmtsGroup {$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $6, $7);}
     | SWITCH expr '\n' BOOL stmtsGroup %prec SWITCHX {$$ = new lab3::OperationNode(SWITCH, 3, $2, $4, $5);}
     | SWITCH expr '\n' BOOL stmtsGroup BOOL stmt {$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $6, $7);}
     | SWITCH expr '\n' BOOL stmtsGroup BOOL stmtsGroup {$$ = new lab3::OperationNode(SWITCH, 5, $2, $4, $5, $6, $7);}
     | ROTATE LEFT {$$ = new lab3::OperationNode(LEFT, 0);}
     | ROTATE RIGHT {$$ = new lab3::OperationNode(RIGHT, 0);}
     | MOVE  {$$ = new lab3::OperationNode(MOVE, 0);}
     | DO id parameters {$$ = new lab3::OperationNode('DO', 2, new lab3::ParameterNode(*$2), $3);}
     | PLEASE stmt {$$ = new lab3::OperationNode(PLEASE, 1, $2);}
     | stmt THANKS {$$ = new lab3::OperationNode(THANKS, 1, $1);}
     | PRINT expr {$$ = new lab3::OperationNode(PRINT, 1, $2);}
     | RESULT id {$$ = new lab3::OperationNode(RESULT, 2, varTable.at(*$2), lastResult);}

parameters: parameters id {$$ = new lab3::OperationNode(' ', 2, $1, varTable.at(*$2));}
         | parameters id '[' indexes ']' {$$ = new lab3::OperationNode(' ', 3, $1, varTable.at(*$2), $4);}
         | id { $$ = varTable.at(*$1); }
         | id '[' indexes ']' {$$ = new lab3::OperationNode('[', 2, varTable.at(*$1), $3);}

value: INTEGER {$$ = $1;}
     | BOOL {$$ = $1;}

expr: INTEGER
     | '(' expr ')' {$$ = $2;}
     | id {$$ = varTable.at(*$1);}
     | id '[' indexes ']' {$$ = new lab3::OperationNode('[', 2, varTable.at(*$1), $3);}
     | REDUCE id '[' INTEGER ']' {$$ = new lab3::OperationNode(REDUCE, 2, varTable.at(*$2), $4);}
     | EXTEND id '[' INTEGER ']' {$$ = new lab3::OperationNode(EXTEND, 2, varTable.at(*$2), $4);}
     | DIGITIZE id {$$ = new lab3::OperationNode(DIGITIZE, 1, varTable.at(*$2));}
     | SIZE id {$$ = new lab3::OperationNode(SIZE, 1, varTable.at(*$2));}
     | expr '+' expr {$$ = new lab3::OperationNode('+', 2, $1, $3);}
     | expr '-' expr {$$ = new lab3::OperationNode('-', 2, $1, $3);}
     | expr '*' expr {$$ = new lab3::OperationNode('*', 2, $1, $3);}
     | expr '/' expr {$$ = new lab3::OperationNode('/', 2, $1, $3);}
     | GET ENVIRONMENT {$$ = new lab3::OperationNode(ENVIRONMENT, 0);}
     | GET id {try {$$ = lastCall.at(*$2);}
                catch (std::exception &ex) {
                    $$ = lastResult;
                }
               }
     | expr AND expr {$$ = new lab3::OperationNode(AND, 2, $1, $3);}
     | BOOL {$$ = $1;}
     | NOT expr {$$ = new lab3::OperationNode(NOT, 1, $2);}
     | LOGITIZE id {$$ = new lab3::OperationNode(LOGITIZE, 1, varTable.at(*$2));}
     | MXEQ expr {$$ = new lab3::OperationNode(MXEQ, 1, $2);}
     | MXLT expr {$$ = new lab3::OperationNode(MXLT, 1, $2);}
     | MXGT expr {$$ = new lab3::OperationNode(MXGT, 1, $2);}
     | MXLTE expr {$$ = new lab3::OperationNode(MXLTE, 1, $2);}
     | MXGTE expr {$$ = new lab3::OperationNode(MXGTE, 1, $2);}
     | ELEQ expr {$$ = new lab3::OperationNode(ELEQ, 1, $2);}
     | ELLT expr {$$ = new lab3::OperationNode(ELLT, 1, $2);}
     | ELGT expr {$$ = new lab3::OperationNode(ELGT, 1, $2);}
     | ELLTE expr {$$ = new lab3::OperationNode(ELLTE, 1, $2);}
     | ELGTE expr {$$ = new lab3::OperationNode(ELGTE, 1, $2);}
     | MXFALSE expr {$$ = new lab3::OperationNode(MXFALSE, 1, $2);}
     | MXTRUE expr {$$ = new lab3::OperationNode(MXTRUE, 1, $2);}