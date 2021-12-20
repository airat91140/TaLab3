//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_INTCONSTNODE_H
#define LAB3_INTCONSTNODE_H

#include <string>

#include "AbstractVariableNode.h"

namespace lab3 {
    class IntConstNode : public AbstractVariableNode {
    protected:
        int val;
    public:
        explicit IntConstNode(int num);

        IntConstNode(std::string str, int base);

        int getVal() const;

        AbstractNode *clone() override { return new IntConstNode(*this); }

        AbstractNode *exec(AbstractNode *node) override;

        ~IntConstNode() override = default;

        bool isArray() override;

        std::ostream &print(std::ostream &ostream) const override;

        virtual int compareM();

        virtual AbstractVariableNode *eleq();

        virtual AbstractVariableNode *ellt();

        virtual AbstractVariableNode *elgt();

        virtual AbstractVariableNode *ellte();

        virtual AbstractVariableNode *elgte();

        virtual AbstractVariableNode *add(IntConstNode *other);

        virtual AbstractVariableNode *sub(IntConstNode *other);

        virtual AbstractVariableNode *mul(IntConstNode *other);

        virtual AbstractVariableNode *div(IntConstNode *other);

    };
}

#endif //LAB3_INTCONSTNODE_H
