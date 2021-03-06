//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_BOOLARRAYVARIABLENODE_H
#define LAB3_BOOLARRAYVARIABLENODE_H

#include "AbstractVariableNode.h"
#include "AbstractNode.h"
#include "BoolVariableNode.h"

#include <algorithm>
#include <list>
#include <ostream>

namespace lab3 {
    class BoolArrayVariableNode : public BoolVariableNode {
    private:
        std::vector<BoolVariableNode *> array;
    public:
        inline int getSize() const{return array.size();}

        BoolArrayVariableNode(const std::string &name, bool val, std::list<int> dims);

        bool inline isArray() override { return true; }

        BoolVariableNode *&operator[](int index);

        const BoolVariableNode *operator[](int index) const;

        friend std::ostream &operator<<(std::ostream &os, const BoolArrayVariableNode &node);

        ~BoolArrayVariableNode() override;

        BoolArrayVariableNode(const BoolArrayVariableNode &other);

        BoolArrayVariableNode &operator=(const BoolArrayVariableNode &other);

        BoolArrayVariableNode(BoolArrayVariableNode &&other);

        BoolArrayVariableNode &operator=(BoolArrayVariableNode &&other);

        AbstractNode *clone() override;

        void assign(AbstractVariableNode *value) override;

        void assignAt(AbstractVariableNode *value, std::list<int> indexes) override;

        std::ostream &print(std::ostream &ostream) const override;

        AbstractNode *exec(AbstractNode *) override;

        AbstractVariableNode * digitize() override;

        explicit BoolArrayVariableNode(AbstractVariableNode *other);

        explicit BoolArrayVariableNode(int size);

        BoolVariableNode *mxfalse() override;

        BoolVariableNode *mxtrue() override;

        AbstractVariableNode * changeSize(std::list<int> dims) override;

    protected:
        void countBools(std::pair<int, int> &cnt) override;

    public:
        AbstractVariableNode *not_() override;

        AbstractVariableNode * and_(BoolConstNode *other) override;

        BoolVariableNode *get(std::list<int> indexes);
    };
}

#endif //LAB3_BOOLARRAYVARIABLENODE_H
