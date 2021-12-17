//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_BOOLCONSTNODE_H
#define LAB3_BOOLCONSTNODE_H

#include "AbstractNode.h"

namespace lab3 {
    class BoolConstNode : public AbstractNode {
    private:
        bool val;
    public:
        explicit BoolConstNode(bool val);

        int getVal() const;

        AbstractNode *exec(AbstractNode *node) override;

        AbstractNode *clone() override {return new BoolConstNode(*this);}
    };
}

#endif //LAB3_BOOLCONSTNODE_H
