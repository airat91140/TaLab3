//
// Created by airat on 08.12.2021.
//

#include "FunctionNode.h"

const std::string &lab3::FunctionNode::getName() const {
    return name;
}

const lab3::AbstractNode *lab3::FunctionNode::operator[](const std::string &name) const {
    if (varTable.find(name) == varTable.end())
        return nullptr;
    return (AbstractNode *)varTable.at(name);
}

lab3::AbstractNode *lab3::FunctionNode::clone() {
    return new FunctionNode(this->name, this->parCount, this->kid->clone());
}

lab3::AbstractNode *lab3::FunctionNode::operator[](const std::string &name) {
    if (varTable.find(name) == varTable.end()){
        varTable.insert({name, nullptr});
    }
    return varTable.at(name);
}

int lab3::FunctionNode::getParCount() const {
    return parCount;
}

lab3::AbstractNode *lab3::FunctionNode::getKid() const {
    return kid;
}

lab3::FunctionNode::FunctionNode(const std::string &name, AbstractNode *parameters, lab3::AbstractNode *kid) : name(name), kid(kid) {
    nodeType = FUNCTION;
    parCount = parametersCount(parameters);
}

lab3::AbstractNode *lab3::FunctionNode::exec(lab3::AbstractNode *node) {
    auto lst = getParametersList(node);
    for (auto &i : lst)
        varTable.insert({i->getName(), i});
    kid->exec(nullptr);
    return nullptr;
}

std::list<lab3::AbstractVariableNode *> lab3::FunctionNode::getParametersList(lab3::AbstractNode *root) {
    AbstractNode *iter = root;
    std::list<AbstractVariableNode *> result;
    while (iter->nodeType == OPERATION) {
        result.push_front((AbstractVariableNode *)((*(OperationNode *)iter)[1]));
        iter = (*(OperationNode *)iter)[0];
    }
    result.push_front((AbstractVariableNode *)((*(OperationNode *)iter)[0]));
    if (result.size() != parCount)
        throw std::runtime_error("Invalid number of arguments");
    return result;
}

lab3::FunctionNode::~FunctionNode() {

}

int lab3::FunctionNode::parametersCount(lab3::AbstractNode *node) {
    int count = 0;
    AbstractNode *iter = node;
    while (iter->nodeType == OPERATION) {
        ++count;
    }
    return ++count;
}

std::ostream &lab3::FunctionNode::print(std::ostream &ostream) const {
    return ostream;
}
