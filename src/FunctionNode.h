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

namespace lab3 {
    class FunctionNode : public AbstractNode{
    private:
        std::string name;
        std::map<std::string, AbstractVariableNode *> varTable;
        AbstractNode *kid;
        std::list<std::string> parameters; // contains ordered parameters
        FunctionNode(const std::string &name, std::list<std::string> pars, AbstractNode *kid);

    public:
        int getParCount() const;

        FunctionNode(const std::string &name, AbstractNode *parameters, AbstractNode *kid);

        AbstractNode *getKid() const;

        const std::string &getName() const;

        const AbstractNode *operator[](const std::string &name) const;

        AbstractNode *clone() override;

        AbstractNode *operator[](const std::string &name);

        AbstractNode *exec(AbstractNode *node) override;

        ~FunctionNode() override;

        std::ostream &print(std::ostream &ostream) const override;

        bool addVar(const std::string &name, lab3::AbstractVariableNode *var);
    };
}

#endif //LAB3_FUNCTIONNODE_H
