//
// Created by airat on 17.12.2021.
//

#ifndef LAB3_ABSTRACTVARIABLENODE_H
#define LAB3_ABSTRACTVARIABLENODE_H

#include "AbstractNode.h"

#include <string>
#include <list>

namespace lab3 {
    class AbstractVariableNode : public AbstractNode {
    protected:
        std::string name;
    public:
        const std::string &getName() const;

        virtual bool inline isArray() = 0;

        AbstractNode *clone() override = 0;

        AbstractNode *exec(AbstractNode *node) override = 0;

        ~AbstractVariableNode() override = default;

        static std::list<int> makeDims(AbstractNode *root);

        virtual void assign(AbstractVariableNode *value) = 0;

        virtual void assignAt(AbstractVariableNode *value, std::list<int> indexes) = 0;

    };
}

#endif //LAB3_ABSTRACTVARIABLENODE_H
