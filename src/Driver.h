//
// Created by airat on 18.12.2021.
//

#ifndef LAB3_DRIVER_H
#define LAB3_DRIVER_H


#include <map>
#include <stack>
#include <vector>
#include "BoolArrayVariableNode.h"

namespace lab3 {
    class Driver {
    private:
        static int getMoodRate();

        static bool getWall(std::pair<int, int> pos);

        static std::ostream &print(std::ostream &out);

        static std::string formLine(const std::vector<char> &array);

    public:
        static void parseMap(const std::string &file);
        static BoolArrayVariableNode *getEnv();
        static bool move(int i); // i = 0 move forward, i = 1 rotate right, i = -1 rotate left
    };
}

#endif //LAB3_DRIVER_H
