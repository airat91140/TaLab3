//
// Created by airat on 18.12.2021.
//

#include "Driver.h"
#include "ParameterNode.h"
#include <iostream>

void yyerror(char *s){
    std::cout << s <<std::endl;
}

void lab3::Driver::parseMap(std::istream &file) {
    while (!file) {}
}