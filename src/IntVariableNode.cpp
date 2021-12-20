//
// Created by airat on 07.12.2021.
//

#include <stdexcept>
#include "IntVariableNode.h"
#include "BoolVariableNode.h"

void lab3::IntVariableNode::setVal(int val) {
    IntVariableNode::val = val;
}

lab3::IntVariableNode::IntVariableNode(const std::string &name, int val) : IntConstNode(val){
    this->name = name;
    this->nodeType = INT_VAR;
}

lab3::AbstractNode *lab3::IntVariableNode::exec(lab3::AbstractNode *node) {
    return this;
}

bool lab3::IntVariableNode::addInCycle(lab3::IntVariableNode *bound, lab3::IntVariableNode *step) {
    if (bound->isArray() || step->isArray())
        throw std::runtime_error("Type mismatch");
    if (bound->val >= this->val)
        return false;
    this->val += step->val;
    return true;
}

std::ostream &lab3::IntVariableNode::print(std::ostream &ostream) const {
    ostream << val << std::endl;
    return ostream;
}

lab3::AbstractVariableNode *lab3::IntVariableNode::logitize() {
    return dynamic_cast<AbstractVariableNode *>(new IntVariableNode("tmp", val));
}

