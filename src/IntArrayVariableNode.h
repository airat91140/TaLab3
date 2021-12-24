//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_INTARRAYVARIABLENODE_H
#define LAB3_INTARRAYVARIABLENODE_H

#include "AbstractNode.h"
#include "IntVariableNode.h"
#include "AbstractVariableNode.h"

#include <cstdarg>
#include <algorithm>
#include <list>
#include <ostream>

namespace lab3 {
    class IntArrayVariableNode : public IntVariableNode {
    private:
        std::vector<IntVariableNode *> array;

        struct AverageCounter {
            int x = 0, y = 0, z = 0;
        };

        AverageCounter recursiveCompareM(AverageCounter &cnt);
    public:
        inline int getSize() const { return array.size(); }

        IntArrayVariableNode(const std::string &name, int val, std::list<int> dims);

        bool inline isArray() override { return true; }

        IntVariableNode *operator[](int index);

        const IntVariableNode *operator[](int index) const;

        ~IntArrayVariableNode() override;

        IntArrayVariableNode(const IntArrayVariableNode &other);

        IntArrayVariableNode &operator=(const IntArrayVariableNode &other);

        IntArrayVariableNode(IntArrayVariableNode &&other);

        IntArrayVariableNode &operator=(IntArrayVariableNode &&other);

        AbstractNode *clone() override {return new IntArrayVariableNode(*this);}

        AbstractNode *exec(AbstractNode *node) override;

        bool addInCycle(IntVariableNode *bound, IntVariableNode *step) override;

        friend std::ostream &operator<<(std::ostream &os, const IntArrayVariableNode &node);

        std::ostream &print(std::ostream &ostream) const override;

        IntArrayVariableNode (lab3::AbstractVariableNode *other);

        void assign(AbstractVariableNode *value) override;

        void assignAt(AbstractVariableNode *value, std::list<int> indexes) override;

        int compareM() override;

        AbstractVariableNode *logitize() override;

        AbstractVariableNode *add(IntConstNode *other) override;

        AbstractVariableNode *sub(IntConstNode *other) override;

        AbstractVariableNode *mul(IntConstNode *other) override;

        AbstractVariableNode *div(IntConstNode *other) override;

        AbstractVariableNode *eleq() override;

        AbstractVariableNode *ellt() override;

        AbstractVariableNode *elgt() override;

        AbstractVariableNode *ellte() override;

        AbstractVariableNode *changeSize(std::list<int> dims) override;

        AbstractVariableNode *elgte() override;

        IntArrayVariableNode();

        IntVariableNode *get(std::list<int> indexes);

        IntArrayVariableNode(int size);
    };
}

#endif //LAB3_INTARRAYVARIABLENODE_H
