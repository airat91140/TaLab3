//
// Created by airat on 07.12.2021.
//

#include "BoolConstNode.h"

lab3::BoolConstNode::BoolConstNode(bool val) {
    nodeType = BOOL_CONST;
    this->val = val;
}

int lab3::BoolConstNode::getVal() const {
    return val;
}
