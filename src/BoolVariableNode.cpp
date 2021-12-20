//
// Created by airat on 07.12.2021.
//
#include "AbstractVariableNode.h"
#include "IntVariableNode.h"
#include "BoolVariableNode.h"


void lab3::BoolVariableNode::setVal(bool val) {
    BoolVariableNode::val = val;
}

lab3::BoolVariableNode::BoolVariableNode(const std::string &name, int val) : BoolConstNode(val) {
    this->name = name;
    this->val = val;
    this->nodeType = BOOL_VAR;
}

lab3::AbstractNode *lab3::BoolVariableNode::exec(lab3::AbstractNode *node) {
    return this;
}

std::ostream &lab3::BoolVariableNode::print(std::ostream &ostream) const {
    ostream << val << std::endl;
    return ostream;
}

lab3::AbstractVariableNode *lab3::BoolVariableNode::digitize(){
    return dynamic_cast<AbstractVariableNode *>(new IntVariableNode("tmp", val ? 1 : 0));

}

lab3::BoolVariableNode *lab3::BoolVariableNode::not_() {
    return new BoolVariableNode("tmp", !val);
}

lab3::AbstractVariableNode *lab3::BoolVariableNode::and_(BoolConstNode *other) {
    if (other->nodeType == BOOL_ARR)
        throw std::runtime_error("type mismatch");
    return new BoolVariableNode("tmp", this->val && other->getVal());
}

lab3::BoolVariableNode *lab3::BoolVariableNode::mxfalse() {
    return new BoolVariableNode("tmp", !val);
}

lab3::BoolVariableNode *lab3::BoolVariableNode::mxtrue() {
    return new BoolVariableNode("tmp", val);
}

void lab3::BoolVariableNode::countBools(std::pair<int, int> &cnt) {
    if (val) cnt.first++;
    else cnt.second++;
}
