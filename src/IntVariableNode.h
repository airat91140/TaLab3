//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_INTVARIABLENODE_H
#define LAB3_INTVARIABLENODE_H


#include "AbstractNode.h"

#include <string>
#include <vector>

namespace lab3 {
    class IntVariableNode : public AbstractNode {
    protected:
        std::string name;
        int val;

    public:
        IntVariableNode(const std::string &name, int val);

        int getVal() const;

        const std::string &getName() const;

        void setVal(int val);

        virtual inline bool isArray() {return false;}

        virtual ~IntVariableNode() = default;
    };
}

#endif //LAB3_INTVARIABLENODE_H
