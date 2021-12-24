//
// Created by airat on 07.12.2021.
//

#include "BoolConstNode.h"
#include "BoolVariableNode.h"
#include <cstring>

lab3::BoolConstNode::BoolConstNode(const char *val) {
    nodeType = BOOL_CONST;
    this->val = std::strcmp(val, "TRUE") == 0;
}

bool lab3::BoolConstNode::getVal() const {
    return val;
}

lab3::AbstractNode *lab3::BoolConstNode::exec(lab3::AbstractNode *node) {
    return this;
}

std::ostream &lab3::BoolConstNode::print(std::ostream &ostream) const {
    ostream << (val ? "TRUE" : "FALSE");
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

std::ostream &lab3::operator<<(std::ostream &os, const lab3::BoolConstNode &node) {
    return node.print(os);
}

void lab3::BoolConstNode::assign(lab3::AbstractVariableNode *value) {
    throw std::runtime_error("Can\'t assign value to constant");
}

void lab3::BoolConstNode::assignAt(lab3::AbstractVariableNode *value, std::list<int> indexes) {
    throw std::runtime_error("Can\'t assign value to constant");
}

lab3::AbstractVariableNode * lab3::BoolConstNode::changeSize(std::list<int> dims) {
    throw std::runtime_error("Can't change size of constant");
}
