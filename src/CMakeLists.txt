PROJECT(src)

ADD_LIBRARY(src STATIC
        AbstractNode.cpp
        IntConstNode.cpp
        BoolConstNode.cpp
        IntVariableNode.cpp
        IntArrayVariableNode.cpp
        BoolVariableNode.cpp
        BoolArrayVariableNode.cpp
        OperationNode.cpp OperationNode.h)