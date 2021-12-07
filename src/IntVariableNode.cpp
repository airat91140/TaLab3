//
// Created by airat on 07.12.2021.
//

#include "IntVariableNode.h"

int lab3::IntVariableNode::getVal() const {
    return val;
}

void lab3::IntVariableNode::setVal(int val) {
    IntVariableNode::val = val;
}

const std::string &lab3::IntVariableNode::getName() const {
    return name;
}

lab3::IntVariableNode::IntVariableNode(const std::string &name, int val) {
    this->name = name;
    this->val = val;
    this->nodeType = INT_VAR;
}
