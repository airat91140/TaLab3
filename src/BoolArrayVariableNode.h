//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_BOOLARRAYVARIABLENODE_H
#define LAB3_BOOLARRAYVARIABLENODE_H

#include "AbstractVariableNode.h"
#include "AbstractNode.h"
#include "BoolVariableNode.h"

#include <algorithm>
#include <list>

namespace lab3 {
    class BoolArrayVariableNode : public BoolVariableNode {
    private:
        std::vector<BoolVariableNode *> array;
    public:
        BoolArrayVariableNode(const std::string &name, bool val, std::list<int> &dims);

        bool inline isArray() override { return true; }

        BoolVariableNode *operator[](int index);

        virtual ~BoolArrayVariableNode();

        BoolArrayVariableNode(const BoolArrayVariableNode &other);

        BoolArrayVariableNode &operator=(const BoolArrayVariableNode &other);

        BoolArrayVariableNode(BoolArrayVariableNode &&other);

        BoolArrayVariableNode &operator=(BoolArrayVariableNode &&other);

        AbstractNode *clone() override;

        AbstractNode *exec(AbstractNode *) override;
    };
}

#endif //LAB3_BOOLARRAYVARIABLENODE_H
