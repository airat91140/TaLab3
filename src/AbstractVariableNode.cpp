//
// Created by airat on 17.12.2021.
//

#include "AbstractVariableNode.h"
#include "IntVariableNode.h"
#include "OperationNode.h"

const std::string &lab3::AbstractVariableNode::getName() const {
    return name;
}

std::list<int> lab3::AbstractVariableNode::makeDims(lab3::AbstractNode *root) {
    std::list<int> res;
    auto iter = root;
    while (iter->nodeType == OPERATION) {
        auto tmp = (*(OperationNode *)iter)[1]->exec(nullptr);
        if (tmp->nodeType != INT_VAR && tmp->nodeType != INT_CONST)
            throw std::runtime_error("Index type error");
        res.push_front(((IntConstNode *)tmp)->getVal());
        iter = (*(OperationNode *)iter)[0];
    }
    auto tmp = iter->exec(nullptr);
    if (tmp->nodeType != INT_VAR && tmp->nodeType != INT_CONST)
        throw std::runtime_error("Index type error");
    res.push_front(((IntConstNode *)tmp)->getVal());
    return res;
}
