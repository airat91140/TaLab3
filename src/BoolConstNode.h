//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_BOOLCONSTNODE_H
#define LAB3_BOOLCONSTNODE_H

#include "AbstractVariableNode.h"
#include <string>
#include <ostream>

namespace lab3 {
    class BoolConstNode : public AbstractVariableNode {
    protected:
        bool val;
    public:
        explicit BoolConstNode(const char *val);

        explicit BoolConstNode(bool val);

        bool getVal() const;

        AbstractNode *exec(AbstractNode *node) override;

        AbstractNode *clone() override {return new BoolConstNode(*this);}

        ~BoolConstNode() override = default;

        bool isArray() override;

        void assign(AbstractVariableNode *value) override;

        void assignAt(AbstractVariableNode *value, std::list<int> indexes) override;

        std::ostream &print(std::ostream &ostream) const override;

        virtual AbstractVariableNode * and_(BoolConstNode *other);

        virtual AbstractVariableNode *not_();

        virtual AbstractVariableNode *mxfalse();

        virtual AbstractVariableNode *mxtrue();

        friend std::ostream &operator<<(std::ostream &os, const BoolConstNode &node);

    };
}

#endif //LAB3_BOOLCONSTNODE_H
