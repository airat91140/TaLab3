//
// Created by airat on 16.12.2021.
//

#include "ParameterNode.h"

lab3::ParameterNode::ParameterNode(const std::string &name) : name(name) {
    nodeType = PARAMETER;
}

lab3::AbstractNode *lab3::ParameterNode::clone() {
    return new ParameterNode(*this);
}

lab3::AbstractNode *lab3::ParameterNode::exec(lab3::AbstractNode *node) {
    return this;
}
