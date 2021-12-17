//
// Created by airat on 07.12.2021.
//

#include "BoolArrayVariableNode.h"

lab3::BoolArrayVariableNode::BoolArrayVariableNode(const::std::string &name, bool val, std::list<int> &dims) : BoolVariableNode(name, val) {
    nodeType = BOOL_ARR;
    if (dims.size() == 1)
        for (int i = 0; i < dims.front(); ++i)
            array.push_back(new BoolVariableNode(name, val));
    else {
        dims.pop_front();
        for (int i = 0; i < dims.front(); ++i)
            array.push_back(new BoolArrayVariableNode(name, val, dims));
    }
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
    for (const auto &i : other.array)
        this->array.push_back((BoolVariableNode *) i->clone());
}

lab3::BoolArrayVariableNode &lab3::BoolArrayVariableNode::operator=(const lab3::BoolArrayVariableNode &other) {
    if (this != &other) {
        std::for_each(this->array.begin(), this->array.end(), [&](BoolVariableNode *i) -> void { delete i; });
        this->array.reserve(other.array.size());
        this->name = other.name;
        this->val = other.val;
        for (const auto &i : other.array)
            this->array.push_back((BoolVariableNode *) i->clone());
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

lab3::AbstractNode *lab3::BoolArrayVariableNode::clone() {
    return new BoolArrayVariableNode(*this);
}

lab3::AbstractNode *lab3::BoolArrayVariableNode::exec(lab3::AbstractNode *) {
    return this;
}
