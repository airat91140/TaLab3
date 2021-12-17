//
// Created by airat on 08.12.2021.
//

#include "OperationNode.h"

lab3::OperationNode::OperationNode(int operTag, int operNum, ...) {
    this->nodeType = OPERATION;
    this->operTag = operTag;
    this->operNum = operNum;
    va_list ap;
    va_start(ap, operNum);
    for (int i = 0; i < operNum; ++i)
        children.push_back(va_arg(ap, AbstractNode *));
    va_end(ap);
}

int lab3::OperationNode::getOperTag() const {
    return operTag;
}

int lab3::OperationNode::getOperNum() const {
    return operNum;
}

lab3::AbstractNode *lab3::OperationNode::operator[](int i) {
    return children.at(i);
}

lab3::AbstractNode *lab3::OperationNode::exec(lab3::AbstractNode *node) {
    switch (operTag) {
        case FOR:
    }
}
