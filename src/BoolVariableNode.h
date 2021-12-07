//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_BOOLVARIABLENODE_H
#define LAB3_BOOLVARIABLENODE_H


#include "AbstractNode.h"

#include <string>
#include <vector>

namespace lab3 {
    class BoolVariableNode : public AbstractNode {
    protected:
        std::string name;
        bool val;

    public:
        BoolVariableNode(const std::string &name, int val);

        bool getVal() const;

        const std::string &getName() const;

        void setVal(bool val);

        virtual inline bool isArray() {return false;}

        virtual ~BoolVariableNode() = default;
    };
}

#endif //LAB3_BOOLVARIABLENODE_H
