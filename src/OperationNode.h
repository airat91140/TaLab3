//
// Created by airat on 08.12.2021.
//

#ifndef LAB3_OPERATIONNODE_H
#define LAB3_OPERATIONNODE_H


#include <vector>
#include <cstdarg>
#include "AbstractNode.h"

namespace lab3 {
    class OperationNode : public AbstractNode {
    private:
        int operTag;
        int operNum;
        std::vector<AbstractNode *> children;
    public:
        OperationNode(int operTag, int operNum, ...);

        int getOperTag() const;

        int getOperNum() const;

        AbstractNode *operator[](int i);

        AbstractNode *clone() override {return new OperationNode(*this);}

        AbstractNode *exec(AbstractNode *node) override;
    };
}

#endif //LAB3_OPERATIONNODE_H
