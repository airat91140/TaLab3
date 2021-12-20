//
// Created by airat on 07.12.2021.
//

#include "BoolConstNode.h"
#include "BoolVariableNode.h"

lab3::BoolConstNode::BoolConstNode(const std::string &val) {
    nodeType = BOOL_CONST;
    this->val = val == "TRUE";
}

bool lab3::BoolConstNode::getVal() const {
    return val;
}

lab3::AbstractNode *lab3::BoolConstNode::exec(lab3::AbstractNode *node) {
    return this;
}

std::ostream &lab3::BoolConstNode::print(std::ostream &ostream) const {
    ostream << val << std::endl;
    return ostream;
}

lab3::BoolConstNode::BoolConstNode(bool val) : val(val) {
    nodeType = BOOL_CONST;
}

bool lab3::BoolConstNode::isArray() {
    return false;
}

lab3::AbstractVariableNode *lab3::BoolConstNode::and_(lab3::BoolConstNode *other) {
    if (other->nodeType == BOOL_ARR)
        throw std::runtime_error("type mismatch");
    return new BoolVariableNode("tmp", this->val && other->getVal());
}

lab3::AbstractVariableNode *lab3::BoolConstNode::not_() {
    return new BoolVariableNode("tmp", !val);
}

lab3::AbstractVariableNode *lab3::BoolConstNode::mxfalse() {
    return new BoolVariableNode("tmp", !val);
}

lab3::AbstractVariableNode *lab3::BoolConstNode::mxtrue() {
    return new BoolVariableNode("tmp", val);
}