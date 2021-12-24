//
// Created by airat on 07.12.2021.
//

#include "IntArrayVariableNode.h"
#include "BoolArrayVariableNode.h"


lab3::IntArrayVariableNode::IntArrayVariableNode(const ::std::string &name, int val,  std::list<int> dims)
        : IntVariableNode(name, val) {
    nodeType = INT_ARR;
    if (dims.empty() || dims.front() <= 0)
        throw std::runtime_error("Invalid array size");
    if (dims.size() == 1)
        for (int i = 0; i < dims.front(); ++i)
            array.push_back(new IntVariableNode(name, val));
    else {
        int len = dims.front();
        dims.pop_front();
        for (int i = 0; i < len; ++i)
            array.push_back(new IntArrayVariableNode(name, val, dims));
    }
}

lab3::IntVariableNode *lab3::IntArrayVariableNode::operator[](int index) {
    try {
        return array.at(index - 1);
    } catch (std::exception &e) {
        throw std::runtime_error("Wrong index");
    }
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
    ostream << "]";
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
    try {
        return array.at(index - 1);
    } catch (std::exception &e) {
        throw std::runtime_error("Wrong index");
    }
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
    if (cnt.y > average)
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
        }
        return cnt;
    } else {
        for (const auto &it : array) {
            ((IntArrayVariableNode *)it)->recursiveCompareM(cnt);
        }
        return cnt;
    }
    return cnt;
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

std::ostream &lab3::operator<<(std::ostream &os, const lab3::IntArrayVariableNode &node) {
    return node.print(os);
}

void lab3::IntArrayVariableNode::assign(lab3::AbstractVariableNode *value) {
    if (value->nodeType != INT_ARR)
        throw std::runtime_error("Type mismatch");
    auto other = (IntArrayVariableNode *)value;
    if (this->getSize() != other->getSize())
        throw std::runtime_error("Type mismatch");
    for (int i = 0; i < getSize(); ++i) {
        this->array[i]->assign(other->array[i]);
    }
}

void lab3::IntArrayVariableNode::assignAt(lab3::AbstractVariableNode *value, std::list<int> indexes) {
    if (value->nodeType != INT_CONST && value->nodeType != INT_VAR)
        throw std::runtime_error("Type mismatch");
    IntArrayVariableNode *iter = this;
    while (indexes.size() > 1) {
        if (!(*iter)[indexes.front()]->isArray())
            throw std::runtime_error("Too much indexes");
        iter = (IntArrayVariableNode *)(*iter)[indexes.front()];
        indexes.pop_front();
    }
    if (indexes.size() == 1 && !(*iter)[indexes.front()]->isArray()) {
        (*iter)[indexes.front()]->assign(value);
        return;
    }
    IntVariableNode *it = iter;
    while (it->isArray()) {
        it = (*(IntArrayVariableNode *)it)[1];
    }
    it->assign(value);
}

lab3::IntVariableNode *lab3::IntArrayVariableNode::get(std::list<int> indexes) {
    IntArrayVariableNode *iter = this;
    while (indexes.size() > 1) {
        if (!(*iter)[indexes.front()]->isArray())
            throw std::runtime_error("Too much indexes");
        iter = (IntArrayVariableNode *)(*iter)[indexes.front()];
        indexes.pop_front();
    }
    IntVariableNode *it = (*iter)[indexes.front()];
    while (it->isArray()) {
        it = (*(IntArrayVariableNode *)it)[1];
    }
    return it;
}

lab3::AbstractVariableNode *lab3::IntArrayVariableNode::changeSize(std::list<int> dims) {
    if (dims.empty())
        throw std::runtime_error("Wrong array size");
    auto result = new IntArrayVariableNode(dims.front());
    dims.pop_front();
    for (int i = 0; i < std::min(result->getSize(), this->getSize()); ++i) {
        delete result->array[i];
        if (this->array[i]->isArray())
            result->array[i] = dynamic_cast<IntVariableNode *>(this->array[i]->changeSize(dims));
        else if (dims.size() == 0)
            result->array[i] = dynamic_cast<IntVariableNode *>(this->array[i]->clone());
        else throw std::runtime_error("Wrong array size");
    }
    if (result->getSize() <= this->getSize())
        return result;
    for (int i = this->getSize(); i < result->getSize(); ++i) {
        delete result->array[i];
        if (this->array[0]->isArray())
            result->array[i] = new IntArrayVariableNode("tmp", 0, dims);
        else if (dims.size() == 0)
            result->array[i] = new IntVariableNode("tmp", true);
        else throw std::runtime_error("Wrong array size");
    }
    return result;
}

lab3::IntArrayVariableNode::IntArrayVariableNode(int size) : IntVariableNode("tmp", 0) {
    nodeType = INT_ARR;
    for (int i = 0; i < size; ++i)
        array.push_back(new IntVariableNode("tmp", 0));
}
