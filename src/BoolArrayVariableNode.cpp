//
// Created by airat on 07.12.2021.
//

#include "BoolArrayVariableNode.h"
#include "IntArrayVariableNode.h"


lab3::BoolArrayVariableNode::BoolArrayVariableNode(const::std::string &name, bool val, std::list<int> dims) : BoolVariableNode(name, val) {
    nodeType = BOOL_ARR;
    if (dims.empty() || dims.front() <= 0)
        throw std::runtime_error("Invalid array size");
    if (dims.size() == 1)
        for (int i = 0; i < dims.front(); ++i) {
            array.push_back(new BoolVariableNode(name, val));
        }
    else {
        int len = dims.front();
        dims.pop_front();
        for (int i = 0; i < len; ++i)
            array.push_back(new BoolArrayVariableNode(name, val, dims));
    }
}

lab3::BoolVariableNode *&lab3::BoolArrayVariableNode::operator[](int index) {
    try {
        return array.at(index - 1);
    } catch (std::exception &e) {
        throw std::runtime_error("Wrong index");
    }
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

std::ostream &lab3::BoolArrayVariableNode::print(std::ostream &ostream) const {
    ostream << "[";
    for (const auto &it : array) {
        it->print(ostream) << ",";
    }
    ostream << "]";
    return ostream;
}

lab3::AbstractVariableNode * lab3::BoolArrayVariableNode::digitize(){
    return dynamic_cast<AbstractVariableNode *>(new IntArrayVariableNode(this));
}

const lab3::BoolVariableNode *lab3::BoolArrayVariableNode::operator[](int index) const {
    try {
        return array.at(index - 1);
    } catch (std::exception &e) {
        throw std::runtime_error("wrong index");
    }
}

lab3::BoolArrayVariableNode::BoolArrayVariableNode(AbstractVariableNode *other) : BoolVariableNode("tmp", 0) {
    nodeType = BOOL_ARR;
    auto t = (IntArrayVariableNode *)other;
    array.reserve(t->getSize());
    for (int i = 1; i <= t->getSize(); ++i) {
        array.push_back(dynamic_cast<BoolVariableNode *>((*t)[i]->logitize()));
    }
}

lab3::BoolArrayVariableNode::BoolArrayVariableNode(int size) : BoolVariableNode("tmp", 0) {
    nodeType = BOOL_ARR;
    for (int i = 0; i < size; ++i)
        array.push_back(new BoolVariableNode("tmp", 0));
}

lab3::AbstractVariableNode *lab3::BoolArrayVariableNode::not_() {
    auto res = new BoolArrayVariableNode(this->getSize());
    for (int i = 1; i <= array.size(); ++i) {
        delete (*res)[i];
        (*res)[i] = dynamic_cast<BoolVariableNode *>((*this)[i]->not_());
    }
    return res;
}

lab3::AbstractVariableNode * lab3::BoolArrayVariableNode::and_(BoolConstNode *other) {
    if (other->nodeType != BOOL_ARR || this->getSize() != ((BoolArrayVariableNode *)other)->getSize())
        throw std::runtime_error("Array sizes mismatch");
    auto res = new BoolArrayVariableNode(this->getSize());
    for (int i = 1; i <= array.size(); ++i) {
        delete (*res)[i];
        (*res)[i] = dynamic_cast<BoolVariableNode *>((*this)[i]->and_((*(BoolArrayVariableNode *) other)[i]));
    }
    return res;
}

lab3::BoolVariableNode *lab3::BoolArrayVariableNode::mxfalse() {
    std::pair<int, int> cnt = {0, 0};
    countBools(cnt);
    return new BoolVariableNode("tmp",cnt.first < cnt.second);
}

lab3::BoolVariableNode *lab3::BoolArrayVariableNode::mxtrue() {
    std::pair<int, int> cnt = {0, 0};
    countBools(cnt);
    return new BoolVariableNode("tmp",cnt.first > cnt.second);}

void lab3::BoolArrayVariableNode::countBools(std::pair<int, int> &cnt) {
    for (const auto &i : array)
        i->countBools(cnt);
}

std::ostream &lab3::operator<<(std::ostream &os, const lab3::BoolArrayVariableNode &node) {
    return node.print(os);
}

void lab3::BoolArrayVariableNode::assign(lab3::AbstractVariableNode *value) {
    if (value->nodeType != BOOL_ARR)
        throw std::runtime_error("Type mismatch");
    auto other = (BoolArrayVariableNode *)value;
    if (this->getSize() != other->getSize())
        throw std::runtime_error("Type mismatch");
    for (int i = 0; i < getSize(); ++i) {
        this->array[i]->assign(other->array[i]);
    }
}

void lab3::BoolArrayVariableNode::assignAt(lab3::AbstractVariableNode *value, std::list<int> indexes) {
    if (value->nodeType != BOOL_CONST && value->nodeType != BOOL_VAR)
        throw std::runtime_error("Type mismatch");
    BoolArrayVariableNode *iter = this;
    while (indexes.size() > 1) {
        if (!(*iter)[indexes.front()]->isArray())
            throw std::runtime_error("Too much indexes");
        iter = (BoolArrayVariableNode *)(*iter)[indexes.front()];
        indexes.pop_front();
    }
    if (indexes.size() == 1 && !(*iter)[indexes.front()]->isArray()) {
        (*iter)[indexes.front()]->assign(value);
        return;
    }
    BoolVariableNode *it = iter;
    while (it->isArray()) {
        it = (*(BoolArrayVariableNode *)it)[1];
    }
    it->assign(value);
}

lab3::BoolVariableNode *lab3::BoolArrayVariableNode::get(std::list<int> indexes) {
    BoolArrayVariableNode *iter = this;
    while (indexes.size() > 1) {
        if (!(*iter)[indexes.front()]->isArray())
            throw std::runtime_error("Too much indexes");
        iter = (BoolArrayVariableNode *)(*iter)[indexes.front()];
        indexes.pop_front();
    }
    BoolVariableNode *it = iter;
    while (it->isArray()) {
        it = (*(BoolArrayVariableNode *)it)[1];
    }
    return it;
}



