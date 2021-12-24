//
// Created by airat on 16.12.2021.
//

#include "ParameterNode.h"

lab3::ParameterNode::ParameterNode(const std::string &name, AbstractVariableNode *kid) {
    nodeType = PARAMETER;
    this->name = name;
    this->var = kid;
}

lab3::AbstractNode *lab3::ParameterNode::clone() {
    return new ParameterNode(this->name, var);
}

lab3::AbstractNode *lab3::ParameterNode::exec(lab3::AbstractNode *node) {
    return var;
}

std::ostream &lab3::ParameterNode::print(std::ostream &ostream) const {
    var->print(ostream);
    return ostream;
}

lab3::AbstractVariableNode *lab3::ParameterNode::getVar() const {
    return var;
}

bool lab3::ParameterNode::isArray() {
    return false;
}

void lab3::ParameterNode::setVar(lab3::AbstractVariableNode *var) {
    ParameterNode::var = var;
}

std::ostream &lab3::operator<<(std::ostream &os, const lab3::ParameterNode &node) {
    return node.print(os);
}

void lab3::ParameterNode::assign(lab3::AbstractVariableNode *value) {
}

void lab3::ParameterNode::assignAt(lab3::AbstractVariableNode *value, std::list<int> indexes) {
}

lab3::AbstractVariableNode *lab3::ParameterNode::changeSize(std::list<int> dims) {
    if (var != nullptr)
        return var->changeSize(dims);
    throw std::runtime_error("Strange access");
}

