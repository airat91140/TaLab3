//
// Created by airat on 07.12.2021.
//

#include "IntConstNode.h"

lab3::IntConstNode::IntConstNode(int num) {
    nodeType = INT_CONST;
    val = num;
}

lab3::IntConstNode::IntConstNode(std::string &str, int base) {
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
