//
// Created by airat on 08.12.2021.
//

#include "FunctionNode.h"
#include "ParameterNode.h"
#include "OperationNode.h"


const std::string &lab3::FunctionNode::getName() const {
    return name;
}

const lab3::AbstractNode *lab3::FunctionNode::operator[](const std::string &name) const {
    if (varTable.find(name) == varTable.end())
        return nullptr;
    return (AbstractNode *) varTable.at(name);
}

lab3::AbstractNode *lab3::FunctionNode::clone() {
    return new FunctionNode(*this);
}

lab3::AbstractNode *lab3::FunctionNode::operator[](const std::string &name) {
    if (varTable.find(name) == varTable.end()) {
        varTable.insert({name, nullptr});
    }
    return varTable.at(name);
}

int lab3::FunctionNode::getParCount() const {
    return parameters.size();
}

lab3::AbstractNode *lab3::FunctionNode::getKid() const {
    return kid;
}

lab3::FunctionNode::FunctionNode(const std::string &name, AbstractNode *pars, lab3::AbstractNode *kid) : name(name),
                                                                                                         kid(kid) {
    nodeType = FUNCTION;
    auto iter = pars;
    while (iter->nodeType == OPERATION) {
        parameters.push_front(((AbstractVariableNode *) (*(OperationNode *) iter)[1])->getName());
        iter = (*(OperationNode *) iter)[0];
    }
    parameters.push_front(((AbstractVariableNode *) iter)->getName());
}

lab3::AbstractNode *lab3::FunctionNode::exec(lab3::AbstractNode *node) {
    auto iter = node;
    auto i = parameters.rbegin();
    while (iter->nodeType == OPERATION) {
        auto tmp = (ParameterNode *) this->varTable.at(*i);
        tmp->setVar((AbstractVariableNode *) ((*(OperationNode *) iter)[1]->exec(nullptr)));
        ++i;
        iter = (*(OperationNode *) iter)[0];
        if (i == parameters.rend())
            throw std::runtime_error("Invalid number of arguments");
    }
    auto tmp = (ParameterNode *) this->varTable.at(*i);
    tmp->setVar((AbstractVariableNode *) (iter->exec(nullptr)));
    ++i;
    if (i != parameters.rend())
        throw std::runtime_error("Invalid number of arguments");
    return kid->exec(nullptr);
}

std::ostream &lab3::FunctionNode::print(std::ostream &ostream) const {
    return ostream;
}

lab3::FunctionNode::FunctionNode(const std::string &name, std::list<std::string> pars, lab3::AbstractNode *kid) : name(
        name), parameters(pars), kid(kid) {
    nodeType = FUNCTION;
}

lab3::FunctionNode::~FunctionNode() {
    for (auto &it: varTable) {
        if (std::find(parameters.begin(), parameters.end(), it.second->getName()) == parameters.end())
            delete it.second;
    }
    delete kid;
}

bool lab3::FunctionNode::addVar(const std::string &name, AbstractVariableNode *var) {
    return varTable.insert({name, var}).second;
}

std::ostream &lab3::operator<<(std::ostream &os, const lab3::FunctionNode &node) {
    return node.print(os);
}

lab3::FunctionNode::FunctionNode(const lab3::FunctionNode &other) : name(other.name), parameters(other.parameters) {
    this->nodeType = FUNCTION;
    for (auto &it: other.varTable)
        addVar(it.first, dynamic_cast<AbstractVariableNode *>(it.second->clone()));
    this->kid = other.kid->clone();
    changeVars(kid);
}

void lab3::FunctionNode::changeVars(lab3::AbstractNode *root) {
    if (root->nodeType != OPERATION) return;
    for (int i = 0; i < ((OperationNode *) root)->getOperNum(); ++i) {
        auto tmp = (OperationNode *) root;
        if ((*tmp)[i]->nodeType <= BOOL_ARR && (*tmp)[i]->nodeType >= INT_VAR || (*tmp)[i]->nodeType == PARAMETER) {
            if (this->varTable.contains(((AbstractVariableNode *) (*tmp)[i])->getName())) {
                auto toDelete = (*tmp)[i];
                (*tmp)[i] = this->varTable.at(((AbstractVariableNode *) (*tmp)[i])->getName());
                delete toDelete;
            } else if ((*tmp)[i]->nodeType == PARAMETER && ((AbstractVariableNode *) (*tmp)[i])->getName().empty()) {
                delete (*tmp)[i];
                (*tmp)[i] = lastCall.at(name);
            }
        } else changeVars((*tmp)[i]);
    }

}
