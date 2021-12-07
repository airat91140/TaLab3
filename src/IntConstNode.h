//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_INTCONSTNODE_H
#define LAB3_INTCONSTNODE_H

#include <string>

#include "AbstractNode.h"

namespace lab3 {
    class IntConstNode : public AbstractNode {
    private:
        int val;
    public:
        explicit IntConstNode(int num);
        explicit IntConstNode(std::string &str, int base);

        int getVal() const;
    };
}

#endif //LAB3_INTCONSTNODE_H
