//
// Created by airat on 07.12.2021.
//

#ifndef LAB3_ABSTRACTNODE_H
#define LAB3_ABSTRACTNODE_H

namespace lab3 {
    enum type {
        ABSTRACT, INT_CONST, BOOL_CONST, INT_VAR, BOOL_VAR, INT_ARR, BOOL_ARR
    };

    class AbstractNode {
    public:
        type nodeType = ABSTRACT;
    };
}

#endif //LAB3_ABSTRACTNODE_H
