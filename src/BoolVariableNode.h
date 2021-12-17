//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_BOOLVARIABLENODE_H
#define LAB3_BOOLVARIABLENODE_H


#include "AbstractVariableNode.h"

#include <string>
#include <vector>

namespace lab3 {
    class BoolVariableNode : public AbstractVariableNode {
    protected:
        bool val;

    public:
        BoolVariableNode(const std::string &name, int val);

        bool getVal() const;

        void setVal(bool val);

        inline bool isArray() override {return false;}

        virtual ~BoolVariableNode() = default;

        AbstractNode *clone() override {return new BoolVariableNode(*this);}

        AbstractNode *exec(AbstractNode *node) override;
    };
}

#endif //LAB3_BOOLVARIABLENODE_H
