%{
#include "IntConstNode.h"
#include "BoolConstNode.h"
#include "parser.tab.h"

char buf[1024];
%}

%option yylineno

%%
[ \t]+ ;

TRUE|FALSE {yylloc.last_line = yylloc.first_line = yylineno;
            yylval.boolVal = new lab3::BoolConstNode(yytext); return BOOL;
            }

-?0[0-7]+ {yylloc.last_line = yylloc.first_line = yylineno;
           yylval.intVal = new lab3::IntConstNode(yytext, 8); return INTEGER;
           }

(-?[0-9]*[8-9][0-9]*)|-?([1-9][0-9]*) {yylloc.last_line = yylloc.first_line = yylineno;
                                       yylval.intVal = new lab3::IntConstNode(yytext, 10); return INTEGER;}

(-?0x[A-F]([0-9]|[A-F])*)|-?0x[0-9]*|-?([0-9]|[A-F])+ {yylloc.last_line = yylloc.first_line = yylineno;
                                                       yylval.intVal = new lab3::IntConstNode(yytext, 16); return INTEGER;}

"SWITCH" {yylloc.last_line = yylloc.first_line = yylineno; return SWITCH;}
"FOR" {yylloc.last_line = yylloc.first_line = yylineno; return FOR;}
"PRINT" {yylloc.last_line = yylloc.first_line = yylineno; return PRINT;}
"BOUNDARY" {yylloc.last_line = yylloc.first_line = yylineno; return BOUNDARY;}
"STEP" {yylloc.last_line = yylloc.first_line = yylineno; return STEP;}
"MOVE" {yylloc.last_line = yylloc.first_line = yylineno; return MOVE;}
"ROTATE" {yylloc.last_line = yylloc.first_line = yylineno; return ROTATE;}
"LEFT" {yylloc.last_line = yylloc.first_line = yylineno; return LEFT;}
"RIGHT" {yylloc.last_line = yylloc.first_line = yylineno; return RIGHT;}
"GET" {yylloc.last_line = yylloc.first_line = yylineno; return GET;}
"ENVIRONMENT" {yylloc.last_line = yylloc.first_line = yylineno; return ENVIRONMENT;}
"TASK" {yylloc.last_line = yylloc.first_line = yylineno; return TASK;}
"RESULT" {yylloc.last_line = yylloc.first_line = yylineno; return RESULT;}
"DO" {yylloc.last_line = yylloc.first_line = yylineno; return DO;}
"PLEASE" {yylloc.last_line = yylloc.first_line = yylineno; return PLEASE;}
"VAR" {yylloc.last_line = yylloc.first_line = yylineno; return VAR;}
"THANKS" {yylloc.last_line = yylloc.first_line = yylineno; return THANKS;}

"DIGITIZE" {yylloc.last_line = yylloc.first_line = yylineno; return DIGITIZE;}
"REDUCE" {yylloc.last_line = yylloc.first_line = yylineno; return REDUCE;}
"EXTEND" {yylloc.last_line = yylloc.first_line = yylineno; return EXTEND;}
"SIZE" {yylloc.last_line = yylloc.first_line = yylineno; return SIZE;}
"NOT" {yylloc.last_line = yylloc.first_line = yylineno; return NOT;}
"AND" {yylloc.last_line = yylloc.first_line = yylineno; return AND;}
"LOGITIZE" {yylloc.last_line = yylloc.first_line = yylineno; return LOGITIZE;}
"MXEQ" {yylloc.last_line = yylloc.first_line = yylineno; return MXEQ;}
"MXLT" {yylloc.last_line = yylloc.first_line = yylineno; return MXLT;}
"MXGT" {yylloc.last_line = yylloc.first_line = yylineno; return MXGT;}
"MXLTE" {yylloc.last_line = yylloc.first_line = yylineno; return MXLTE;}
"MXGTE" {yylloc.last_line = yylloc.first_line = yylineno; return MXGTE;}
"ELEQ" {yylloc.last_line = yylloc.first_line = yylineno; return ELEQ;}
"ELLT" {yylloc.last_line = yylloc.first_line = yylineno; return ELLT;}
"ELGT" {yylloc.last_line = yylloc.first_line = yylineno; return ELGT;}
"ELLTE" {yylloc.last_line = yylloc.first_line = yylineno; return ELLTE;}
"ELGTE" {yylloc.last_line = yylloc.first_line = yylineno; return ELGTE;}
"MXFALSE" {yylloc.last_line = yylloc.first_line = yylineno; return MXFALSE;}
"MXTRUE" {yylloc.last_line = yylloc.first_line = yylineno; return MXTRUE;}

[a-zA-Z][a-zA-Z0-9]* {yylval.name = new std::string(yytext); yylloc.last_line = yylloc.first_line = yylineno; return id;}

[-\(\)+*/\n\[\]=,] {yylloc.last_line = yylloc.first_line = yylineno; return *yytext;}

. yyerror(yytext);
%%

int yywrap(void) {
return 1;
}