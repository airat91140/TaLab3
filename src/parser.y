%{
#include <string>
#include <map>
#include "AbstractNode.h"
#include "BoolArrayVariableNode.h"
#include "BoolConstNode.h"
#include "BoolVariableNode.h"
#include "IntArrayVariableNode.h"
#include "IntConstNode.h"
#include "IntVariableNode.h"
#include "OperationNode.h"

enum dir {UP, LEFT, RIGHT, DOWN};
extern FILE *yyin;
std::map<std::string, AbstractNode *> functionsTable;
std::map<std::string, AbstractNode *> lastCall;
std::vector<std::vector<bool> > labyrinth;
std::pair<int, int> position;
dir direction;
std::stack<FunctionNode *> functionStack;
/* prototypes */
int yylex(void);
void init (void);
void yyerror(char *s);

%}

%union {
    AbstractNode *nPtr;
    BoolConstNode boolVal;
    IntConstNode intVal;
    std::string name;
    BoolArrayVariableNode boolArrVar;
    BoolVariableNode boolVar;
    IntArrayVariableNode intArrVar;
    IntVariableNode intVar;
}

%token <intVal> INTEGER
%token <boolVal> BOOL
%token <name> id
%token <name> FUNC_NAME
%token SWITCH FOR PRINT BOUNDARY STEP MOVE ROTATE LEFT RIGHT GET ENVIRONMENT TASK RESULT DO PLEASE THANKS VAR
%nonassoc IFX
%nonassoc ELSE
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'

program:
    functions { if (!functionsTable.contains("FINDEXIT"))
                    throw std::RuntimeException("Could not find FINDEXIT function");

                functionsTable.at("FINDEXIT").exec(new BoolConstNode(true));
                for (const auto &[key, value] : functionsTable)
                    delete value;
                exit(0);
               }

functions:
    functions function {functionsTable.insert({$2.getName(), $2}); lastCall.insert({$2.getName(), nullptr})}
    | %empty

function:
    TASK FUNC_NAME ids stmtsGroup {$$ = new FunctionNode($2, $3, $4);}

ids: ids id {$$ = new OperationNode(' ', $1, new parameterNode($2);}
    | id {$$ = new parameterNode($1);}

indexes: indexes ',' num {$$ = new OperationNode(',', 2, $1, $3); }
        | num { $$ = new OperationNode(',', 1, $1) }

stmtsGroup: '(' stmts ')' {$$ = $2}

stmts: stmts stmt {$$ = new OperationNode(';', 2, $1, $2);}
     | stmt {$$ = $1;}
     | %empty {$$ = nullptr;}

stmt: %empty {$$ = nullptr;}
     | id '=' expr {$$ = new OperationNode('=', 2, *(functionStack.top())[$1], $3);}
     | id '[' indexes ']' '=' expr {$$ = new OperationNode('=', 3, *(functionStack.top())[$1], $3, $6);}
     | VAR id '=' value {$$ = new OperationNode(VAR, 2, new parameterNode($2), $4);}
     | VAR id '[' indexes ']' '=' value {$$ = new OperationNode(VAR, 3, new parameterNode($2), $4, $7);}
     | FOR id BOUNDARY id STEP id stmtsGroup {$$ = new OperationNode(FOR, 4, *(functionStack.top())[$2], *(functionStack.top())[$4], *(functionStack.top())[$6], $7);}
     | FOR id BOUNDARY id STEP id stmt {$$ = new OperationNode(FOR, 4, *(functionStack.top())[$2], *(functionStack.top())[$4], *(functionStack.top())[$6], $7);}
     | SWITCH logic BOOL stmt {$$ = new OperationNode(SWITCH, 3, $2, $3, $4);}
     | SWITCH logic BOOL stmt BOOL stmt {$$ = new OperationNode(SWITCH, 5, $2, $3, $4, $5, $6);}
     | SWITCH logic BOOL stmt BOOL stmtGroup {$$ = new OperationNode(SWITCH, 5, $2, $3, $4, $5, $6);}
     | SWITCH logic BOOL stmtGroup {$$ = new OperationNode(SWITCH, 3, $2, $3, $4);}
     | SWITCH logic BOOL stmtGroup BOOL stmt {$$ = new OperationNode(SWITCH, 5, $2, $3, $4, $5, $6);}
     | SWITCH logic BOOL stmtGroup BOOL stmtGroup {$$ = new OperationNode(SWITCH, 5, $2, $3, $4, $5, $6);}
     | ROTATE LEFT
     | ROTATE RIGHT
     | MOVE
     | DO FUNC_NAME parameters {functionStack.push(functionsTable.at($2)->clone());
                                $$ = new OperationNode('f', 2, functionStack.top(), $3);
                                functionStack.pop();}
     | PLEASE stmt
     | stmt THANKS
     | PRINT expr
     | RESULT id {$$ = new OperationNode(RESULT, (*functionStack.top())[$2];}

parameters: parameters id {$$ = new OperationNode(' ', 2, $1, *(functionStack.top())[$2]);}
         | parameters id '[' indexes ']' {$$ = new OperationNode(' ', 3, $1, *(functionStack.top())[$2], $4);}
         | id { ($$ = *(functionStack.top())[$1]; }
         | id '[' indexes ']' {$$ = new OperationNode('[', *(functionStack.top())[$1], $3);}

value: INTEGER {$$ = $1;}
     | BOOL {$$ = $1;}

expr: arith {$$ = $1;}
    | logic {$$ = $1;}

arith: INTEGER
     | '(' arith ')' {$$ = $2;}
     | id '[' indexes ']' {$$ = new OperationNode('[', 1, *(functionStack.top())[$1], $3);}
     | REDUCE id '[' num ']' {$$ = new OperationNode(REDUCE, 2, *(functionStack.top())[$2], $4);}
     | EXTEND id '[' num ']' {$$ = new OperationNode(EXTEND, 2, *(functionStack.top())[$2], $4);}
     | DIGITIZE id {$$ = new OperationNode(DIGITIZE, 1, *(functionStack.top())[$2]);}
     | SIZE id {$$ = new OperationNode(SIZE, 1, *(functionStack.top())[$2]);}
     | arith + arith {$$ = new OperationNode('+', 2, $1, $3);}
     | arith - arith {$$ = new OperationNode('-', 2, $1, $3);}
     | arith * arith {$$ = new OperationNode('*', 2, $1, $3);}
     | arith / arith {$$ = new OperationNode('/', 2, $1, $3);}
     | GET ENVIRONMENT {$$ = new OperationNode(ENVIRONMENT, 0);}
     | GET FUNC_NAME parameters {$$ = lastCall.at($2);}

logic: '(' logic ')' {$$ = $2;}
     | logic AND logic {$$ = new OperationNode(AND, 2, $1, $3);}
     | BOOL {$$ = $1;}
     | id {$$ = *(functionStack.top())[$1];}
     | id '[' indexes ']' {$$ = new OperationNode('[', 1, *(functionStack.top())[$1], $3);}
     | NOT logic {$$ = new OperationNode(NOT, 1, $2);}
     | LOGITIZE id {$$ = new OperationNode(LOGITIZE, 1, *(functionStack.top())[$2]);}
     | MXEQ arith {$$ = new OperationNode(MXEQ, 1, $2);}
     | MXLT arith {$$ = new OperationNode(MXLT, 1, $2);}
     | MXGT arith {$$ = new OperationNode(MXGT, 1, $2);}
     | MXLTE arith {$$ = new OperationNode(MXLTE, 1, $2);}
     | MXGTE arith {$$ = new OperationNode(MXGTE, 1, $2);}
     | ELEQ arith {$$ = new OperationNode(ELEQ, 1, $2);}
     | ELLT arith {$$ = new OperationNode(ELLT, 1, $2);}
     | ELGT arith {$$ = new OperationNode(ELGT, 1, $2);}
     | ELLTE arith {$$ = new OperationNode(ELLTE, 1, $2);}
     | ELGTE arith {$$ = new OperationNode(ELGTE, 1, $2);}
     | MXFALSE logic {$$ = new OperationNode(MXFALSE, 1, $2);}
     | MXTRUE logic {$$ = new OperationNode(MXTRUE, 1, $2);}
     | REDUCE id '[' num ']' {$$ = new OperationNode(REDUCE, 2, *(functionStack.top())[$2], $4);}
     | EXTEND id '[' num ']' {$$ = new OperationNode(EXTEND, 2, *(functionStack.top())[$2], $4);}