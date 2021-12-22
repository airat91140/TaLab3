//
// Created by airat on 08.12.2021.
//

#include <map>
#include <stack>
#include <iostream>
#include "OperationNode.h"
#include "FunctionNode.h"
#include "BoolConstNode.h"
#include "IntVariableNode.h"

extern std::map<std::string, lab3::AbstractNode *> functionsTable;
extern std::map<std::string, lab3::AbstractNode *> lastCall;
extern std::stack<lab3::FunctionNode *> functionStack;
extern bool hasResult;

lab3::OperationNode::OperationNode(int operTag, int operNum, ...) {
    this->nodeType = OPERATION;
    this->operTag = operTag;
    this->operNum = operNum;
    va_list ap;
    va_start(ap, operNum);
    for (int i = 0; i < operNum; ++i)
        children.push_back(va_arg(ap, AbstractNode *));
    va_end(ap);
}

int lab3::OperationNode::getOperTag() const {
    return operTag;
}

int lab3::OperationNode::getOperNum() const {
    return operNum;
}

lab3::AbstractNode *lab3::OperationNode::operator[](int i) {
    return children.at(i);
}

lab3::AbstractNode *lab3::OperationNode::exec(lab3::AbstractNode *node) {
    switch (operTag) {
        case FOR:
            if ((children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_VAR)
                && (children.at(1)->nodeType == INT_ARR || children.at(1)->nodeType == INT_VAR)
                && (children.at(2)->nodeType == INT_ARR || children.at(2)->nodeType == INT_VAR)) {
                while (!dynamic_cast<IntVariableNode *>(children.at(0))->addInCycle(
                        dynamic_cast<IntVariableNode *>(children.at(1)),
                        dynamic_cast<IntVariableNode *>(children.at(2)))) {
                    children.at(3)->exec(nullptr);
                }
            } else throw std::runtime_error("Type mismatch");
            return nullptr;
        case SWITCH:
            if (operNum == 3) { //without else
                AbstractNode *tmpLogic = children.at(0)->exec(nullptr);
                if (tmpLogic->nodeType == BOOL_VAR) {
                    if (((BoolConstNode *) tmpLogic)->getVal() == ((BoolConstNode *) children.at(1))->getVal()) {
                        children.at(2)->exec(nullptr);
                    }
                } else throw std::runtime_error("Type mismatch");
                delete tmpLogic;
                return nullptr;
            } else if (operNum == 5) { //with else
                AbstractNode *tmpLogic = children.at(0)->exec(nullptr);
                auto *tmpConstFirst = (BoolConstNode *) children.at(1);
                auto *tmpConstSecond = (BoolConstNode *) children.at(3);
                if (tmpLogic->nodeType == BOOL_VAR && tmpConstFirst->getVal() != tmpConstSecond->getVal()) {
                    if (((BoolConstNode *) tmpLogic)->getVal() == tmpConstFirst->getVal()) {
                        children.at(2)->exec(nullptr);
                    } else {
                        children.at(4)->exec(nullptr);
                    }
                }
                delete tmpLogic;
                delete tmpConstFirst;
                delete tmpConstSecond;
            } else throw std::runtime_error("Invalid number of arguments");
            return nullptr;
        case PRINT:
            std::cout << children.at(0);
            return nullptr;
        case MOVE:
            break;
        case LEFT:
            break;
        case RIGHT:
            break;
        case ENVIRONMENT:
            break;
        case RESULT:
            hasResult = true;
            return nullptr;
        case DO:
            children.at(0)->exec(children.at(1));
            if (!hasResult)
                throw std::runtime_error("No RESULT");
            hasResult = false;
        case PLEASE:
            break;
        case THANKS:

        case DIGITIZE:
            if (children.at(0)->nodeType == BOOL_VAR || children.at(0)->nodeType == BOOL_ARR)
                return ((BoolVariableNode *) children.at(0))->digitize();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case REDUCE:

        case EXTEND:

        case SIZE:
            if ((children.at(0)->nodeType == BOOL_VAR) || (children.at(0)->nodeType == INT_VAR))
                return new IntVariableNode("tmp", 1);
            else if (children.at(0)->nodeType == BOOL_ARR)
                return new IntVariableNode("tmp", ((BoolArrayVariableNode *) children.at(0))->getSize());
            else if (children.at(0)->nodeType == INT_ARR)
                return new IntVariableNode("tmp", ((IntArrayVariableNode *) children.at(0))->getSize());
            else
                throw std::runtime_error("Type mismatch");
            break;
        case NOT:
            if (children.at(0)->nodeType == BOOL_VAR
            || children.at(0)->nodeType == BOOL_ARR
            || children.at(0)->nodeType == BOOL_CONST)
                return  ((BoolConstNode *) children.at(0))->not_();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case AND:
            if ((children.at(0)->nodeType == BOOL_VAR
            || children.at(0)->nodeType == BOOL_ARR
            || children.at(0)->nodeType == BOOL_CONST)
            && (children.at(1)->nodeType == BOOL_VAR
            || children.at(1)->nodeType == BOOL_ARR
            || children.at(0)->nodeType == BOOL_CONST))
                return ((BoolVariableNode *) children.at(0))->and_((BoolConstNode *) children.at(1));
            else
                throw std::runtime_error("Type mismatch");
            break;
        case LOGITIZE:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR)
                return ((IntVariableNode *) children.at(0))->logitize();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case MXEQ:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR)
                return new BoolVariableNode("tmp", ((IntConstNode *) children.at(0))->compareM() == 0);
            else
                throw std::runtime_error("Type mismatch");
            break;
        case MXLT:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST)
                return new BoolVariableNode("tmp", ((IntConstNode *) children.at(0))->compareM() == -1);
            else
                throw std::runtime_error("Type mismatch");
            break;
        case MXGT:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST)
                return new BoolVariableNode("tmp", ((IntConstNode *) children.at(0))->compareM() == 1);
            else
                throw std::runtime_error("Type mismatch");
            break;
        case MXLTE:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST) {
                int tmp = ((IntConstNode *) children.at(0))->compareM();
                return new BoolVariableNode("tmp", tmp == 0 || tmp == -1);
            } else
                throw std::runtime_error("Type mismatch");
            break;
        case MXGTE:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST) {
                int tmp = ((IntConstNode *) children.at(0))->compareM();
                return new BoolVariableNode("tmp", tmp == 0 || tmp == 1);
            } else
                throw std::runtime_error("Type mismatch");
            break;
        case ELEQ:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST)
                return ((IntConstNode *) children.at(0))->eleq();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case ELLT:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST)
                return ((IntConstNode *) children.at(0))->ellt();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case ELGT:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST)
                return ((IntConstNode *) children.at(0))->elgt();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case ELLTE:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST)
                return ((IntConstNode *) children.at(0))->ellte();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case ELGTE:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_CONST)
                return ((IntConstNode *) children.at(0))->elgte();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case MXFALSE:
            if (children.at(0)->nodeType == BOOL_VAR || children.at(0)->nodeType == BOOL_ARR ||
                children.at(0)->nodeType == BOOL_CONST)
                return ((BoolConstNode *) children.at(0))->mxfalse();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case MXTRUE:
            if (children.at(0)->nodeType == BOOL_VAR || children.at(0)->nodeType == BOOL_ARR ||
                children.at(0)->nodeType == BOOL_CONST)
                return ((BoolConstNode *) children.at(0))->mxtrue();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case ' ':
            return nullptr;
        case '\n':
            children.at(0)->exec(nullptr);
            if (hasResult)
                return nullptr;
            return children.at(1)->exec(nullptr);
        case ',':
            return nullptr;
        case '+':
            if ((children.at(0)->nodeType == INT_ARR
            || children.at(0)->nodeType == INT_VAR
            || children.at(0)->nodeType == INT_CONST)
            && (children.at(1)->nodeType == INT_ARR
            || children.at(1)->nodeType == INT_VAR
            || children.at(1)->nodeType == INT_CONST))
                return ((IntConstNode *)children.at(0))->add(dynamic_cast<IntConstNode *>(children.at(1)));
            else
                throw std::runtime_error("Type mismatch");
            break;
        case '-':
            if ((children.at(0)->nodeType == INT_ARR
            || children.at(0)->nodeType == INT_VAR
            || children.at(0)->nodeType == INT_CONST)
            && (children.at(1)->nodeType == INT_ARR
            || children.at(1)->nodeType == INT_VAR
            || children.at(1)->nodeType == INT_CONST))
                return ((IntConstNode *)children.at(0))->sub(dynamic_cast<IntConstNode *>(children.at(1)));
            else
                throw std::runtime_error("Type mismatch");
            break;
        case '*':
            if ((children.at(0)->nodeType == INT_ARR
            || children.at(0)->nodeType == INT_VAR
            || children.at(0)->nodeType == INT_CONST)
            && (children.at(1)->nodeType == INT_ARR
            || children.at(1)->nodeType == INT_VAR
            || children.at(1)->nodeType == INT_CONST))
                return ((IntConstNode *)children.at(0))->mul(dynamic_cast<IntConstNode *>(children.at(1)));
            else
                throw std::runtime_error("Type mismatch");
            break;
        case '/':
            if ((children.at(0)->nodeType == INT_ARR
            || children.at(0)->nodeType == INT_VAR
            || children.at(0)->nodeType == INT_CONST)
            && (children.at(1)->nodeType == INT_ARR
            || children.at(1)->nodeType == INT_VAR
            || children.at(1)->nodeType == INT_CONST))
                return ((IntConstNode *)children.at(0))->div(dynamic_cast<IntConstNode *>(children.at(1)));
            else
                throw std::runtime_error("Type mismatch");
            break;
        case '=':
            break;
        case '[':
            break;
    }
    return nullptr;
}

std::ostream &lab3::OperationNode::print(std::ostream &ostream) const {
    return ostream;
}

lab3::OperationNode::~OperationNode() {

}
