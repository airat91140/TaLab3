//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_INTARRAYVARIABLENODE_H
#define LAB3_INTARRAYVARIABLENODE_H

#include "AbstractNode.h"
#include "IntVariableNode.h"

#include <cstdarg>

namespace lab3 {
    class IntArrayVariableNode : public IntVariableNode {
    private:
        std::vector<IntVariableNode *> array;
    public:
        IntArrayVariableNode(const std::string &name, int val, int arrSize, int *dims);
        bool inline isArray() override {return true;}
        IntVariableNode *operator[](int index);

        virtual ~IntArrayVariableNode();

        IntArrayVariableNode(const IntArrayVariableNode &other);
        IntArrayVariableNode &operator=(const IntArrayVariableNode &other);
        IntArrayVariableNode (IntArrayVariableNode &&other);
        IntArrayVariableNode operator= (IntArrayVariableNode &&other);
    };
}

#endif //LAB3_INTARRAYVARIABLENODE_H
