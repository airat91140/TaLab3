//
// Created by airat on 16.12.2021.
//

#ifndef LAB3_PARAMETERNODE_H
#define LAB3_PARAMETERNODE_H

#include "AbstractVariableNode.h"

#include <string>
#include <ostream>

namespace lab3 {
    class ParameterNode : public AbstractVariableNode {
    private:
        AbstractVariableNode *var;
    public:
        explicit ParameterNode(const std::string &name, AbstractVariableNode *kid = nullptr);

        void setVar(AbstractVariableNode *var);

        AbstractNode *clone() override;

        void assign(AbstractVariableNode *value) override;

        void assignAt(AbstractVariableNode *value, std::list<int> indexes) override;

        AbstractNode *exec(AbstractNode *node) override;

        ~ParameterNode() override = default;

        std::ostream &print(std::ostream &ostream) const override;

        AbstractVariableNode *getVar() const;

        friend std::ostream &operator<<(std::ostream &os, const ParameterNode &node);

        bool isArray() override;
    };
}

#endif //LAB3_PARAMETERNODE_H
