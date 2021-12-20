//
// Created by airat on 07.12.2021.
//

#include "IntConstNode.h"
#include "BoolVariableNode.h"
#include "IntVariableNode.h"

lab3::IntConstNode::IntConstNode(int num) {
    nodeType = INT_CONST;
    val = num;
}

lab3::IntConstNode::IntConstNode(std::string str, int base) {
    if (base == 16 && !str.starts_with("0x"))
        str.insert(0, "0x");
    nodeType = INT_CONST;
    val = std::stoi(str, nullptr, base);
}

int lab3::IntConstNode::getVal() const {
    return val;
}

lab3::AbstractNode *lab3::IntConstNode::exec(lab3::AbstractNode *node) {
    return this;
}

std::ostream &lab3::IntConstNode::print(std::ostream &ostream) const {
    ostream << val << std::endl;
    return ostream;
}

bool lab3::IntConstNode::isArray() {
    return false;
}

int lab3::IntConstNode::compareM() {
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

lab3::AbstractVariableNode *lab3::IntConstNode::eleq() {
    return new BoolVariableNode("tmp", val == 0);
}

lab3::AbstractVariableNode *lab3::IntConstNode::ellt() {
    return new BoolVariableNode("tmp", val < 0);
}

lab3::AbstractVariableNode *lab3::IntConstNode::elgt() {
    return new BoolVariableNode("tmp", val > 0);
}

lab3::AbstractVariableNode *lab3::IntConstNode::ellte() {
    return new BoolVariableNode("tmp", val <= 0);
}

lab3::AbstractVariableNode *lab3::IntConstNode::elgte() {
    return new BoolVariableNode("tmp", val >= 0);
}

lab3::AbstractVariableNode *lab3::IntConstNode::add(lab3::IntConstNode *other) {
    if (other->isArray())
        throw std::runtime_error("Array sizes mismatch");
    return new IntVariableNode("tmp", this->val + other->val);
}

lab3::AbstractVariableNode *lab3::IntConstNode::sub(lab3::IntConstNode *other) {
    if (other->isArray())
        throw std::runtime_error("Array sizes mismatch");
    return new IntVariableNode("tmp", this->val - other->val);
}

lab3::AbstractVariableNode *lab3::IntConstNode::mul(lab3::IntConstNode *other) {
    if (other->isArray())
        throw std::runtime_error("Array sizes mismatch");
    return new IntVariableNode("tmp", this->val * other->val);
}

lab3::AbstractVariableNode *lab3::IntConstNode::div(lab3::IntConstNode *other) {
    if (other->isArray())
        throw std::runtime_error("Array sizes mismatch");
    return new IntVariableNode("tmp", this->val / other->val);
}
