//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_ABSTRACTNODE_H
#define LAB3_ABSTRACTNODE_H

namespace lab3 {
    enum type {
        ABSTRACT,
        INT_CONST,
        BOOL_CONST,
        INT_VAR,
        BOOL_VAR,
        INT_ARR,
        BOOL_ARR,
        OPERATION,
        FUNCTION,
        PARAMETER
    };

    class AbstractVariableNode;

    class AbstractNode {
    public:
        type nodeType = ABSTRACT;
        virtual AbstractNode *clone() = 0;
        virtual AbstractNode *exec(AbstractNode *node) = 0;
    };
}

#endif //LAB3_ABSTRACTNODE_H
