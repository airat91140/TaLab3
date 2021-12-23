//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_BOOLVARIABLENODE_H
#define LAB3_BOOLVARIABLENODE_H

#include "BoolConstNode.h"
#include "AbstractVariableNode.h"


#include <iostream>
#include <string>
#include <vector>

namespace lab3 {
    class BoolVariableNode : public BoolConstNode {
    public:
        virtual void countBools(std::pair<int, int> &cnt);

        BoolVariableNode(const std::string &name, bool val);

        void setVal(bool val);

        inline bool isArray() override {return false;}

        ~BoolVariableNode() override = default;

        AbstractNode *clone() override {return new BoolVariableNode(*this);}

        AbstractNode *exec(AbstractNode *node) override;

        std::ostream &print(std::ostream &ostream) const override;

        virtual AbstractVariableNode *digitize();

        AbstractVariableNode * and_(BoolConstNode *other) override;

        void assign(AbstractVariableNode *value) override;

        void assignAt(AbstractVariableNode *value, std::list<int> indexes) override;

        friend std::ostream &operator<<(std::ostream &os, const BoolVariableNode &node);
    };
}

#endif //LAB3_BOOLVARIABLENODE_H
