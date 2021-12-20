//
// Created by airat on 07.12.2021.
//

#include "AbstractNode.h"

std::ostream &operator<<(std::ostream &os, const lab3::AbstractNode &node) {
    return node.print(os);
}
