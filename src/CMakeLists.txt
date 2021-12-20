PROJECT(src)

SET_SOURCE_FILES_PROPERTIES( parser.tab.c lex.yy.c PROPERTIES LANGUAGE CXX )

ADD_LIBRARY(src STATIC
        AbstractNode.cpp
        IntConstNode.cpp
        BoolConstNode.cpp
        IntVariableNode.cpp
        IntArrayVariableNode.cpp
        BoolVariableNode.cpp
        BoolArrayVariableNode.cpp
        OperationNode.cpp
        FunctionNode.cpp
        ParameterNode.cpp
        AbstractVariableNode.cpp
        parser.tab.c
        Driver.cpp
        lex.yy.c)