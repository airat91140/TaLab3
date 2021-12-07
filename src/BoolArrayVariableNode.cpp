//
// Created by airat on 07.12.2021.
//

#include "BoolArrayVariableNode.h"

lab3::BoolArrayVariableNode::BoolArrayVariableNode(const::std::string &name, bool val, int arrSize, int *dims) : BoolVariableNode(name, val) {
    nodeType = BOOL_ARR;
    if (arrSize == 1)
        for (int i = 0; i < *dims; ++i)
            array.push_back(new BoolVariableNode(name, val));
    else
        for (int i = 0; i < *dims; ++i)
            array.push_back(new BoolArrayVariableNode(name, val, arrSize - 1, dims + 1));
}

lab3::BoolVariableNode *lab3::BoolArrayVariableNode::operator[](int index) {
    return array.at(index);
}

lab3::BoolArrayVariableNode::~BoolArrayVariableNode() {
    for (const auto &i : array)
        delete i;
}

lab3::BoolArrayVariableNode::BoolArrayVariableNode(const lab3::BoolArrayVariableNode &other) : BoolVariableNode(other.getName(), other.getVal()) {
    this->nodeType = BOOL_ARR;
    this->array.reserve(other.array.size());
    if (other.array.front()->nodeType == BOOL_ARR)
        for (const auto &i : other.array) {
            auto *tmp = dynamic_cast<BoolArrayVariableNode *>(i);
            this->array.push_back(new BoolArrayVariableNode(*tmp));
        }
    else {
        for (const auto &i : other.array)
            this->array.push_back(new BoolVariableNode(*i));
    }
}

lab3::BoolArrayVariableNode &lab3::BoolArrayVariableNode::operator=(const lab3::BoolArrayVariableNode &other) {
    if (this != &other) {
        std::for_each(this->array.begin(), this->array.end(), [&](BoolVariableNode *i) -> void { delete i; });
        this->array.reserve(other.array.size());
        this->name = other.name;
        this->val = other.val;
        if (other.array.front()->nodeType == BOOL_ARR)
            for (const auto &i : other.array) {
                auto *tmp = dynamic_cast<BoolArrayVariableNode *>(i);
                this->array.push_back(new BoolArrayVariableNode(*tmp));
            }
        else {
            for (const auto &i : other.array)
                this->array.push_back(new BoolVariableNode(*i));
        }
    }
    return *this;
}

lab3::BoolArrayVariableNode::BoolArrayVariableNode(lab3::BoolArrayVariableNode &&other) : BoolVariableNode(other.getName(), other.getVal()) {
    std::swap(this->array, other.array);
}

lab3::BoolArrayVariableNode &lab3::BoolArrayVariableNode::operator=(lab3::BoolArrayVariableNode &&other) {
    if (this != &other) {
        std::for_each(this->array.begin(), this->array.end(), [&](BoolVariableNode *i) -> void { delete i; });
        std::swap(this->array, other.array);
        std::swap(this->name, other.name);
        std::swap(this->val, other.val);
    }
    return *this;
}
