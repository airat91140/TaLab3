%{
#include "IntConstNode.h"
#include "BoolConstNode.h"
#include "parser.tab.h"

char buf[1024];
%}

%option yylineno

%%
[ \t]+ ;

TRUE|FALSE {yylval.boolVal = new lab3::BoolConstNode(yytext); return BOOL;}

-?0[0-7]+ {yylval.intVal = new lab3::IntConstNode(yytext, 8); return INTEGER;}

(-?[0-9]*[8-9][0-9]*)|-?([1-9][0-9]*) {yylval.intVal = new lab3::IntConstNode(yytext, 10); return INTEGER;}

(-?0x[A-F]([0-9]|[A-F])*)|-?0x[0-9]*|-?([0-9]|[A-F])+ {yylval.intVal = new lab3::IntConstNode(yytext, 16); return INTEGER;}

"SWITCH" return SWITCH;
"FOR" return FOR;
"PRINT" return PRINT; 
"BOUNDARY" return BOUNDARY;
"STEP" return STEP;
"MOVE" return MOVE;
"ROTATE" return ROTATE;
"LEFT" return LEFT;
"RIGHT" return RIGHT;
"GET" return GET;
"ENVIRONMENT" return ENVIRONMENT;
"TASK" return TASK;
"RESULT" return RESULT;
"DO" return DO;
"PLEASE" return PLEASE;
"VAR" return VAR;
"THANKS" return THANKS;

"DIGITIZE" return DIGITIZE;
"REDUCE" return REDUCE;
"EXTEND" return EXTEND;
"SIZE" return SIZE;
"NOT" return NOT;
"LOGITIZE" return LOGITIZE;
"MXEQ" return MXEQ;
"MXLT" return MXLT;
"MXGT" return MXGT;
"MXLTE" return MXLTE;
"MXGTE" return MXGTE;
"ELEQ" return ELEQ;
"ELLT" return ELLT;
"ELGT" return ELGT;
"ELLTE" return ELLTE;
"ELGTE" return ELGTE;
"MXFALSE" return MXFALSE;
"MXTRUE" return MXTRUE;

[a-zA-Z][a-zA-Z0-9]* {yylval.name = new std::string(yytext); return id;}

[-\(\)+*/\n\[\]=] return *yytext;

. yyerror(yytext);
%%

int yywrap(void) {
return 1;
}