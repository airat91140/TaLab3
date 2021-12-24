#include <iostream>
#include <Driver.h>
#include "parser.tab.h"

extern FILE *yyin;

int main() {
    yydebug = 0;
    lab3::Driver::parseMap("./map.txt");
    yyin = fopen ("./test.txt", "r");
    yyparse();
    fclose (yyin);
    return 0;
}
