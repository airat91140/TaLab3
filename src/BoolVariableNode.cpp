//
// Created by airat on 07.12.2021.
//
#include "AbstractVariableNode.h"
#include "IntVariableNode.h"
#include "BoolVariableNode.h"


void lab3::BoolVariableNode::setVal(bool val) {
    BoolVariableNode::val = val;
}

lab3::BoolVariableNode::BoolVariableNode(const std::string &name, bool val) : BoolConstNode(val) {
    this->name = name;
    this->val = val;
    this->nodeType = BOOL_VAR;
}

lab3::AbstractNode *lab3::BoolVariableNode::exec(lab3::AbstractNode *node) {
    return this;
}

std::ostream &lab3::BoolVariableNode::print(std::ostream &ostream) const {
    ostream << (val ? "TRUE" : "FALSE");
    return ostream;
}

lab3::AbstractVariableNode *lab3::BoolVariableNode::digitize(){
    return dynamic_cast<AbstractVariableNode *>(new IntVariableNode("tmp", val ? 1 : 0));

}

lab3::AbstractVariableNode *lab3::BoolVariableNode::and_(BoolConstNode *other) {
    if (other->nodeType == BOOL_ARR)
        throw std::runtime_error("type mismatch");
    return new BoolVariableNode("tmp", this->val && other->getVal());
}

void lab3::BoolVariableNode::countBools(std::pair<int, int> &cnt) {
    if (val) cnt.first++;
    else cnt.second++;
}

std::ostream &lab3::operator<<(std::ostream &os, const lab3::BoolVariableNode &node) {
    return node.print(os);
}

void lab3::BoolVariableNode::assign(lab3::AbstractVariableNode *value) {
    if (value->nodeType == BOOL_CONST || value->nodeType == BOOL_VAR) {
        this->val = ((BoolConstNode *)value)->getVal();
    }
    else throw std::runtime_error("Type mismatch");
}

void lab3::BoolVariableNode::assignAt(lab3::AbstractVariableNode *value, std::list<int> indexes) {
    throw std::runtime_error("Array size mismatch");
}
