//
// Created by airat on 07.12.2021.
//

#include "BoolVariableNode.h"

bool lab3::BoolVariableNode::getVal() const {
    return val;
}

void lab3::BoolVariableNode::setVal(bool val) {
    BoolVariableNode::val = val;
}

const std::string &lab3::BoolVariableNode::getName() const {
    return name;
}

lab3::BoolVariableNode::BoolVariableNode(const std::string &name, int val) {
    this->name = name;
    this->val = val;
    this->nodeType = BOOL_VAR;
}
