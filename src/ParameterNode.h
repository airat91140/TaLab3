//
// Created by airat on 16.12.2021.
//

#ifndef LAB3_PARAMETERNODE_H
#define LAB3_PARAMETERNODE_H

#include "AbstractNode.h"

#include <string>

namespace lab3 {
    class ParameterNode : public AbstractNode {
    private:
        std::string name;
    public:
        ParameterNode(const std::string &name);

        AbstractNode *clone() override;

        AbstractNode *exec(AbstractNode *node) override;
    };
}

#endif //LAB3_PARAMETERNODE_H
