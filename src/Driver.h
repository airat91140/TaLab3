//
// Created by airat on 18.12.2021.
//

#ifndef LAB3_DRIVER_H
#define LAB3_DRIVER_H


#include <map>
#include <stack>
#include <vector>
#include "FunctionNode.h"

namespace lab3 {
    class Driver {
    public:
        Driver(FILE *in);
        enum dir {U, L, R, D};
        FILE *file;
        std::map<std::string, lab3::AbstractNode *> functionsTable;
        std::map<std::string, lab3::AbstractNode *> lastCall;
        std::vector<std::vector<bool> > labyrinth;
        std::pair<int, int> position;
        dir curDir;
        std::stack<lab3::FunctionNode *> functionStack;
        bool hasResult = false;
    };
}

#endif //LAB3_DRIVER_H
