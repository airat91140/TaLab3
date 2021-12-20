//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_BOOLCONSTNODE_H
#define LAB3_BOOLCONSTNODE_H

#include "AbstractVariableNode.h"
#include <string>

namespace lab3 {
    class BoolConstNode : public AbstractVariableNode {
    protected:
        bool val;
    public:
        explicit BoolConstNode(const std::string &val);

        explicit BoolConstNode(bool val);

        bool getVal() const;

        AbstractNode *exec(AbstractNode *node) override;

        AbstractNode *clone() override {return new BoolConstNode(*this);}

        ~BoolConstNode() override = default;

        bool isArray() override;

        std::ostream &print(std::ostream &ostream) const override;

        virtual AbstractVariableNode * and_(BoolConstNode *other);

    };
}

#endif //LAB3_BOOLCONSTNODE_H
