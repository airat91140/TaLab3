//
// Created by airat on 07.12.2021.
//

#include "IntArrayVariableNode.h"
#include "BoolArrayVariableNode.h"


lab3::IntArrayVariableNode::IntArrayVariableNode(const ::std::string &name, int val,  std::list<int> &dims)
        : IntVariableNode(name, val) {
    nodeType = INT_ARR;
    if (dims.size() == 1)
        for (int i = 0; i < dims.front(); ++i)
            array.push_back(new IntVariableNode(name, val));
    else {
        dims.pop_front();
        for (int i = 0; i < dims.front(); ++i)
            array.push_back(new IntArrayVariableNode(name, val, dims));
    }
}

lab3::IntVariableNode *lab3::IntArrayVariableNode::operator[](int index) {
    return array.at(index - 1);
}

lab3::IntArrayVariableNode::~IntArrayVariableNode() {
    for (const auto &i: array)
        delete i;
}

lab3::IntArrayVariableNode::IntArrayVariableNode(const lab3::IntArrayVariableNode &other) : IntVariableNode(
        other.getName(), other.getVal()) {
    this->nodeType = INT_ARR;
    this->array.reserve(other.array.size());
    for (const auto &i: other.array)
        this->array.push_back((IntVariableNode *) i->clone());
}

lab3::IntArrayVariableNode &lab3::IntArrayVariableNode::operator=(const lab3::IntArrayVariableNode &other) {
    if (this != &other) {
        std::for_each(this->array.begin(), this->array.end(), [&](IntVariableNode *i) -> void { delete i; });
        this->array.reserve(other.array.size());
        this->name = other.name;
        this->val = other.val;
        for (const auto &i: other.array)
            this->array.push_back((IntVariableNode *) i->clone());
    }
    return *this;
}

lab3::IntArrayVariableNode::IntArrayVariableNode(lab3::IntArrayVariableNode &&other) : IntVariableNode(other.getName(),
                                                                                                       other.getVal()) {
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

bool lab3::IntArrayVariableNode::addInCycle(lab3::IntVariableNode *bound, lab3::IntVariableNode *step) {
    for (int i = 1; i <= this->array.size(); ++i) {
        if (addInCycle((*dynamic_cast<IntArrayVariableNode *>(bound))[i],
                       (*dynamic_cast<IntArrayVariableNode *>(step))[i]))
            return true;
    }
    return false;
}

std::ostream &lab3::IntArrayVariableNode::print(std::ostream &ostream) const {
    ostream << "[";
    for (const auto &it : array) {
        it->print(ostream) << ",";
    }
    ostream << "]" << std::endl;
    return ostream;
}

lab3::IntArrayVariableNode::IntArrayVariableNode(lab3::AbstractVariableNode *other) : IntVariableNode("tmp", 0) {
    nodeType = INT_ARR;
    auto *t = (BoolArrayVariableNode *)other;
    array.reserve(t->getSize());
    for (int i = 1; i <= t->getSize(); ++i) {
        array.push_back(dynamic_cast<IntVariableNode *>((*t)[i]->digitize()));
    }
}

const lab3::IntVariableNode *lab3::IntArrayVariableNode::operator[](int index) const {
    return array.at(index - 1);
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::logitize() {
    return IntVariableNode::logitize();
}

int lab3::IntArrayVariableNode::compareM() { // 2 не выполняется для большинства, -1 < 0, 0 =0, 1 >0
    auto cnt = AverageCounter();
    recursiveCompareM(cnt);
    float average = (cnt.x + cnt.y + cnt.z) / 3.0;
    if (cnt.x > average)
        return -1;
    if (cnt.z > average)
        return 0;
    if (cnt.z > average)
        return 1;
    return 2;
}

lab3::IntArrayVariableNode::AverageCounter
lab3::IntArrayVariableNode::recursiveCompareM(lab3::IntArrayVariableNode::AverageCounter &cnt) {
    if (array[0]->nodeType == INT_VAR) {
        for (const auto &it : array) {
            switch(it->compareM()) {
                case 1: cnt.z++; break;
                case 0: cnt.y++; break;
                case -1: cnt.x++; break;
            }
            return cnt;
        }
    } else {
        for (const auto &it : array) {
            ((IntArrayVariableNode *)it)->recursiveCompareM(cnt);
        }
        return cnt;
    }
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::eleq() {
    auto res = new BoolArrayVariableNode(array.size());
    for (int i = 1; i <= array.size(); ++i) {
        delete (*res)[i];
        (*res)[i] = dynamic_cast<BoolVariableNode *>((*this)[i]->eleq());
    }
    return res;
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::ellt() {
    auto res = new BoolArrayVariableNode(array.size());
    for (int i = 1; i <= array.size(); ++i) {
        delete (*res)[i];
        (*res)[i] = dynamic_cast<BoolVariableNode *>((*this)[i]->eleq());
    }
    return res;
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::elgt() {
    auto res = new BoolArrayVariableNode(array.size());
    for (int i = 1; i <= array.size(); ++i) {
        delete (*res)[i];
        (*res)[i] = dynamic_cast<BoolVariableNode *>((*this)[i]->elgt());
    }
    return res;
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::ellte() {
    auto res = new BoolArrayVariableNode(array.size());
    for (int i = 1; i <= array.size(); ++i) {
        delete (*res)[i];
        (*res)[i] = dynamic_cast<BoolVariableNode *>((*this)[i]->ellte());
    }
    return res;
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::elgte() {
    auto res = new BoolArrayVariableNode(array.size());
    for (int i = 1; i <= array.size(); ++i) {
        delete (*res)[i];
        (*res)[i] = dynamic_cast<BoolVariableNode *>((*this)[i]->elgte());
    }
    return res;
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::add(lab3::IntConstNode *other) {
    if (other->nodeType != INT_ARR || this->getSize() != ((IntArrayVariableNode *)other)->getSize())
        throw std::runtime_error("Array sizes mismatch");
    auto res = new IntArrayVariableNode();
    for (int i = 1; i <= array.size(); ++i)
        res->array.push_back(dynamic_cast<IntVariableNode *>((*this)[i]->add((*(IntArrayVariableNode *) other)[i])));
    return res;
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::sub(lab3::IntConstNode *other) {
    if (other->nodeType != INT_ARR || this->getSize() != ((IntArrayVariableNode *)other)->getSize())
        throw std::runtime_error("Array sizes mismatch");
    auto res = new IntArrayVariableNode();
    for (int i = 1; i <= array.size(); ++i)
        res->array.push_back(dynamic_cast<IntVariableNode *>((*this)[i]->sub((*(IntArrayVariableNode *) other)[i])));
    return res;}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::mul(lab3::IntConstNode *other) {
    if (other->nodeType != INT_ARR || this->getSize() != ((IntArrayVariableNode *)other)->getSize())
        throw std::runtime_error("Array sizes mismatch");
    auto res = new IntArrayVariableNode();
    for (int i = 1; i <= array.size(); ++i)
        res->array.push_back(dynamic_cast<IntVariableNode *>((*this)[i]->mul((*(IntArrayVariableNode *) other)[i])));
    return res;}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::div(lab3::IntConstNode *other) {
    if (other->nodeType != INT_ARR || this->getSize() != ((IntArrayVariableNode *)other)->getSize())
        throw std::runtime_error("Array sizes mismatch");
    auto res = new IntArrayVariableNode();
    for (int i = 1; i <= array.size(); ++i)
        res->array.push_back(dynamic_cast<IntVariableNode *>((*this)[i]->div((*(IntArrayVariableNode *) other)[i])));
    return res;}

lab3::IntArrayVariableNode::IntArrayVariableNode() : IntVariableNode("tmp", 0) {
    nodeType = INT_ARR;
}
