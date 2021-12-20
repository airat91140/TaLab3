//
// Created by airat on 08.12.2021.
//

#ifndef LAB3_FUNCTIONNODE_H
#define LAB3_FUNCTIONNODE_H

#include <list>
#include <string>
#include <map>

#include "AbstractNode.h"
#include "AbstractVariableNode.h"
#include "OperationNode.h"

namespace lab3 {
    class FunctionNode : public AbstractNode{
    private:
        std::string name;
        int parCount;
        std::map<std::string, AbstractVariableNode *> varTable;
        AbstractNode *kid;
    public:
        int getParCount() const;

        FunctionNode(const std::string &name, AbstractNode *parameters, AbstractNode *kid);

        AbstractNode *getKid() const;

        const std::string &getName() const;

        const AbstractNode *operator[](const std::string &name) const;

        AbstractNode *clone() override;

        AbstractNode *operator[](const std::string &name);

        AbstractNode *exec(AbstractNode *node) override;

        std::list<AbstractVariableNode *> getParametersList(AbstractNode *root);

        int parametersCount(AbstractNode *);

        ~FunctionNode() override;

        std::ostream &print(std::ostream &ostream) const override;
    };
}

#endif //LAB3_FUNCTIONNODE_H
