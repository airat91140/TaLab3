//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_INTVARIABLENODE_H
#define LAB3_INTVARIABLENODE_H


#include "AbstractNode.h"
#include "AbstractVariableNode.h"
#include "IntConstNode.h"

#include <string>
#include <vector>

namespace lab3 {
    class IntVariableNode : public IntConstNode {
    protected:
        std::string name;
    public:
        IntVariableNode(const std::string &name, int val);

        void setVal(int val);

        inline bool isArray() override {return false;}

        ~IntVariableNode() override = default;

        AbstractNode *clone() override {return new IntVariableNode(*this);}

        AbstractNode *exec(AbstractNode *node) override;

        std::ostream &print(std::ostream &ostream) const override;

        virtual bool addInCycle(IntVariableNode *bound, IntVariableNode *step); //returns if it was added or not

        virtual AbstractVariableNode *logitize();

    };
}

#endif //LAB3_INTVARIABLENODE_H
