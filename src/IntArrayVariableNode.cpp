//
// Created by airat on 07.12.2021.
//

#include "IntArrayVariableNode.h"

lab3::IntArrayVariableNode::IntArrayVariableNode(const::std::string &name, int val, int arrSize, int *dims) : IntVariableNode(name, val) {
    nodeType = INT_ARR;
    if (arrSize == 1)
        for (int i = 0; i < *dims; ++i)
            array.push_back(new IntVariableNode(name, val));
    else
        for (int i = 0; i < *dims; ++i)
            array.push_back(new IntArrayVariableNode(name, val, arrSize - 1, dims + 1));
}

lab3::IntVariableNode *lab3::IntArrayVariableNode::operator[](int index) {
    return array.at(index);
}

lab3::IntArrayVariableNode::~IntArrayVariableNode() {
    for (const auto &i : array)
        delete i;
}

lab3::IntArrayVariableNode::IntArrayVariableNode(const lab3::IntArrayVariableNode &other) : IntVariableNode(other.getName(), other.getVal()) {
    this->nodeType = INT_ARR;
    this->array.reserve(other.array.size());
    for (const auto &i : other.array)
        this->array.push_back((IntVariableNode *) i->clone());
    }
}

lab3::IntArrayVariableNode &lab3::IntArrayVariableNode::operator=(const lab3::IntArrayVariableNode &other) {
    if (this != &other) {
        std::for_each(this->array.begin(), this->array.end(), [&](IntVariableNode *i) -> void { delete i; });
        this->array.reserve(other.array.size());
        this->name = other.name;
        this->val = other.val;
        for (const auto &i : other.array)
            this->array.push_back((IntVariableNode *)i->clone());
    }
    return *this;
}

lab3::IntArrayVariableNode::IntArrayVariableNode(lab3::IntArrayVariableNode &&other) : IntVariableNode(other.getName(), other.getVal()) {
    std::swap(this->array, other.array);
}

lab3::IntArrayVariableNode &lab3::IntArrayVariableNode::operator=(lab3::IntArrayVariableNode &&other) {
    if (this != &other) {
        std::for_each(this->array.begin(), this->array.end(), [&](IntVariableNode *i) -> void { delete i; });
        std::swap(this->array, other.array);
        std::swap(this->name, other.name);
        std::swap(this->val, other.val);
    }
    return *this;
}

lab3::AbstractNode *lab3::IntArrayVariableNode::exec(lab3::AbstractNode *node) {
    return this;
}
