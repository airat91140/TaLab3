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

enum dir {U, L, D, R};
inline std::map<std::string, lab3::AbstractNode *> functionsTable;
inline std::map<std::string, lab3::AbstractNode *> lastCall;
inline std::map<std::string, lab3::AbstractNode *> varTable;
inline bool hasResult;
inline lab3::AbstractVariableNode *lastResult = new lab3::ParameterNode("");
inline int sadnessBorder = -(rand() % 30 + 120);
inline int suspectnessBorder = (rand() % 30 + 120);
inline int mood = 0;
inline int probability = rand() % 41 + 10;
inline bool errorFlag = false;
inline std::vector<std::vector<char> > labyrinth;
inline dir currentDir;
inline std::pair<int, int> currentPos;
inline std::pair<int, int> exitPos;
inline bool hasError = false;
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
    functions { try {
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

functions:
    functions '\n' function
    | functions '\n' error {hasError = true; std::cout << "Some error on line " << @3.first_line << std::endl; yyerrok;}
    | function
    | '\n' {$$ = nullptr;}
    | error  {hasError = true; std::cout << "Some error on line " << @1.first_line << std::endl; yyerrok;}

function:
    TASK id ids '\n' stmtsGroup {auto tmp = new lab3::FunctionNode(*$2, $3, $5);
                                 for (const auto &it : varTable)
                                     tmp->addVar(it.first, (lab3::AbstractVariableNode *)it.second);
                                 varTable.clear();
                                 lastCall.insert({*$2, lastResult});
                                 functionsTable.insert({*$2, tmp});
                                 lastResult = new lab3::ParameterNode("");
                                 $$ = tmp;
                                 }

ids: ids id {auto res = new lab3::ParameterNode(*$2); varTable.insert({*$2, res}); $$ = new lab3::OperationNode(' ', @1.first_line, 2, $1, res);}
    | id {auto res = new lab3::ParameterNode(*$1); varTable.insert({*$1, res}); $$ = res;}

indexes: inds {$$ = $1;}
        | %empty {$$ = new lab3::OperationNode(',', 0, 0);}

inds: inds ',' expr {$$ = new lab3::OperationNode(',', @1.first_line, 2, $1, $3); }
    | expr { $$ = new lab3::OperationNode(',', @1.first_line, 1, $1); }

stmtsGroup: '(' '\n' stmts ')' {$$ = $3;}

stmts: stmts stmt '\n' {$$ = new lab3::OperationNode('\n', @1.first_line, 2, $1, $2);}
     | stmt '\n' {$$ = $1;}
     | stmts error '\n' {hasError = true; std::cout << "Some error on line " << @2.first_line << std::endl; yyerrok;}
     | error '\n' {hasError = true; std::cout << "Some error on line " << @1.first_line << std::endl; yyerrok;}
stmt:  id '=' expr {$$ = new lab3::OperationNode('=', @1.first_line, 2, varTable.at(*$1), $3);}
     | id '[' indexes ']' '=' expr {$$ = new lab3::OperationNode('=', @1.first_line, 3, varTable.at(*$1), $3, $6);}
     | VAR id '=' BOOL {if (!varTable.insert({*$2, new lab3::BoolVariableNode(*$2, $4->getVal())}).second)
                                throw std::runtime_error("Variable already defined");
                             delete $4;
                             $$ = new lab3::OperationNode(VAR, @1.first_line, 0);}
     | VAR id '[' indexes ']' '=' BOOL {if (!varTable.insert({*$2, new lab3::BoolArrayVariableNode(*$2, $7->getVal(), lab3::AbstractVariableNode::makeDims($4))}).second)
                                                throw std::runtime_error("Variable already defined");
                                             delete $7;
                                             $$ = new lab3::OperationNode(VAR, @1.first_line, 0);}
     | VAR id '=' INTEGER  {if (!varTable.insert({*$2, new lab3::IntVariableNode(*$2, $4->getVal())}).second)
                                    throw std::runtime_error("Variable already defined");
                                delete $4;
                                $$ = new lab3::OperationNode(VAR, @1.first_line, 0);}
     | VAR id '[' indexes ']' '=' INTEGER {if (!varTable.insert({*$2, new lab3::IntArrayVariableNode(*$2, $7->getVal(), lab3::AbstractVariableNode::makeDims($4))}).second)
                                                    throw std::runtime_error("Variable already defined");
                                                delete $7;
                                                $$ = new lab3::OperationNode(VAR, @1.first_line, 0);}
     | FOR id BOUNDARY id STEP id stmtsGroup {$$ = new lab3::OperationNode(FOR, @1.first_line, 4, varTable.at(*$2), varTable.at(*$4), varTable.at(*$6), $7);}
     | FOR id BOUNDARY id STEP id stmt {$$ = new lab3::OperationNode(FOR, @1.first_line, 4, varTable.at(*$2), varTable.at(*$4), varTable.at(*$6), $7);}
     | SWITCH expr '\n' BOOL stmt %prec SWITCHX {$$ = new lab3::OperationNode(SWITCH, @1.first_line, 3, $2, $4, $5);}
     | SWITCH expr '\n' BOOL stmt BOOL stmt {$$ = new lab3::OperationNode(SWITCH, @1.first_line, 5, $2, $4, $5, $6, $7);}
     | SWITCH expr '\n' BOOL stmt BOOL stmtsGroup {$$ = new lab3::OperationNode(SWITCH, @1.first_line, 5, $2, $4, $5, $6, $7);}
     | SWITCH expr '\n' BOOL stmtsGroup %prec SWITCHX {$$ = new lab3::OperationNode(SWITCH, @1.first_line, 3, $2, $4, $5);}
     | SWITCH expr '\n' BOOL stmtsGroup BOOL stmt {$$ = new lab3::OperationNode(SWITCH, @1.first_line, 5, $2, $4, $5, $6, $7);}
     | SWITCH expr '\n' BOOL stmtsGroup BOOL stmtsGroup {$$ = new lab3::OperationNode(SWITCH, @1.first_line, 5, $2, $4, $5, $6, $7);}
     | ROTATE LEFT {$$ = new lab3::OperationNode(LEFT, @1.first_line, 0);}
     | ROTATE RIGHT {$$ = new lab3::OperationNode(RIGHT, @1.first_line, 0);}
     | MOVE  {$$ = new lab3::OperationNode(MOVE, @1.first_line, 0);}
     | DO id parameters {$$ = new lab3::OperationNode(DO, @1.first_line, 2, new lab3::ParameterNode(*$2), $3);}
     | PLEASE stmt {$$ = new lab3::OperationNode(PLEASE, @1.first_line, 1, $2);}
     | stmt THANKS {$$ = new lab3::OperationNode(THANKS, @1.first_line, 1, $1);}
     | PRINT expr {$$ = new lab3::OperationNode(PRINT, @1.first_line, 1, $2);}
     | RESULT id {$$ = new lab3::OperationNode(RESULT, @1.first_line, 2, varTable.at(*$2), lastResult);}

parameters: parameters id {$$ = new lab3::OperationNode(' ', @1.first_line, 2, $1, varTable.at(*$2));}
         | parameters id '[' indexes ']' {$$ = new lab3::OperationNode(' ', @1.first_line, 3, $1, varTable.at(*$2), $4);}
         | id { $$ = varTable.at(*$1); }
         | id '[' indexes ']' {$$ = new lab3::OperationNode('[', @1.first_line, 2, varTable.at(*$1), $3);}

value: INTEGER {$$ = $1;}
     | BOOL {$$ = $1;}

expr: INTEGER
     | '(' expr ')' {$$ = $2;}
     | id {$$ = varTable.at(*$1);}
     | id '[' indexes ']' {$$ = new lab3::OperationNode('[', @1.first_line, 2, varTable.at(*$1), $3);}
     | REDUCE id '[' indexes ']' {$$ = new lab3::OperationNode(REDUCE, @1.first_line, 2, varTable.at(*$2), $4);}
     | EXTEND id '[' indexes ']' {$$ = new lab3::OperationNode(EXTEND, @1.first_line, 2, varTable.at(*$2), $4);}
     | DIGITIZE id {$$ = new lab3::OperationNode(DIGITIZE, @1.first_line, 1, varTable.at(*$2));}
     | SIZE id {$$ = new lab3::OperationNode(SIZE, @1.first_line, 1, varTable.at(*$2));}
     | expr '+' expr {$$ = new lab3::OperationNode('+', @1.first_line, 2, $1, $3);}
     | expr '-' expr {$$ = new lab3::OperationNode('-', @1.first_line, 2, $1, $3);}
     | expr '*' expr {$$ = new lab3::OperationNode('*', @1.first_line, 2, $1, $3);}
     | expr '/' expr {$$ = new lab3::OperationNode('/', @1.first_line, 2, $1, $3);}
     | GET ENVIRONMENT {$$ = new lab3::OperationNode(ENVIRONMENT, @1.first_line, 0);}
     | GET id {$$ = new lab3::OperationNode(GET, @1.first_line, 1, new lab3::ParameterNode(*$2));}
     | expr AND expr {$$ = new lab3::OperationNode(AND, @1.first_line, 2, $1, $3);}
     | BOOL {$$ = $1;}
     | NOT expr {$$ = new lab3::OperationNode(NOT, @1.first_line, 1, $2);}
     | LOGITIZE id {$$ = new lab3::OperationNode(LOGITIZE, @1.first_line, 1, varTable.at(*$2));}
     | MXEQ expr {$$ = new lab3::OperationNode(MXEQ, @1.first_line, 1, $2);}
     | MXLT expr {$$ = new lab3::OperationNode(MXLT, @1.first_line, 1, $2);}
     | MXGT expr {$$ = new lab3::OperationNode(MXGT, @1.first_line, 1, $2);}
     | MXLTE expr {$$ = new lab3::OperationNode(MXLTE, @1.first_line, 1, $2);}
     | MXGTE expr {$$ = new lab3::OperationNode(MXGTE, @1.first_line, 1, $2);}
     | ELEQ expr {$$ = new lab3::OperationNode(ELEQ, @1.first_line, 1, $2);}
     | ELLT expr {$$ = new lab3::OperationNode(ELLT, @1.first_line, 1, $2);}
     | ELGT expr {$$ = new lab3::OperationNode(ELGT, @1.first_line, 1, $2);}
     | ELLTE expr {$$ = new lab3::OperationNode(ELLTE, @1.first_line, 1, $2);}
     | ELGTE expr {$$ = new lab3::OperationNode(ELGTE, @1.first_line, 1, $2);}
     | MXFALSE expr {$$ = new lab3::OperationNode(MXFALSE, @1.first_line, 1, $2);}
     | MXTRUE expr {$$ = new lab3::OperationNode(MXTRUE, @1.first_line, 1, $2);}