#include <iostream>
#include <Driver.h>
#include "parser.tab.h"

extern FILE *yyin;



int main() {
    yydebug = 0;
    yyin = fopen ("./test.txt", "r");
    yyparse();
    fclose (yyin);
    return 0;
}
