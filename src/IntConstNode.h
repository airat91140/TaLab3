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

        IntConstNode(std::string &str, int base);

        int getVal() const;

        AbstractNode *clone() override {return new IntConstNode(*this);}

        AbstractNode *exec(AbstractNode *node) override;
    };
}

#endif //LAB3_INTCONSTNODE_H
