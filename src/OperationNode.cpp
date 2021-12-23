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
    srand(time(nullptr));
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
    if (rand() % 100 > probability)
        mood--;
    if (mood < sadnessBorder)
        throw std::runtime_error("You are impolite!");
    switch (operTag) {
        case FOR: {
            bool adding;
            if ((children.at(0)->nodeType == INT_ARR || children.at(0)->nodeType == INT_VAR)
                && (children.at(1)->nodeType == INT_ARR || children.at(1)->nodeType == INT_VAR)
                && (children.at(2)->nodeType == INT_ARR || children.at(2)->nodeType == INT_VAR)) {
                while (dynamic_cast<IntVariableNode *>(children.at(0))->addInCycle(
                        dynamic_cast<IntVariableNode *>(children.at(1)),
                        dynamic_cast<IntVariableNode *>(children.at(2)))) {
                    children.at(3)->exec(nullptr);
                }
            } else throw std::runtime_error("Type mismatch");
            return nullptr;
        }
        case SWITCH:
            if (operNum == 3) { //without else
                AbstractNode *tmpLogic = children.at(0)->exec(nullptr);
                if (tmpLogic->nodeType == BOOL_VAR || tmpLogic->nodeType == BOOL_CONST) {
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
                if ((tmpLogic->nodeType == BOOL_VAR || tmpLogic->nodeType == BOOL_CONST) && tmpConstFirst->getVal() != tmpConstSecond->getVal()) {
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
            std::cout << *children.at(0)->exec(nullptr) << std::endl;
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
        case THANKS:
            mood += 3;
            if (mood > suspectnessBorder)
                throw std::runtime_error("You are suspected");
            children.at(0)->exec(nullptr);
            break;
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
        case NOT: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == BOOL_VAR
            || first->nodeType == BOOL_ARR
            || first->nodeType == BOOL_CONST)
                return ((BoolConstNode *) first)->not_();
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case AND: {
            auto first = children.at(0)->exec(nullptr);
            auto second = children.at(1)->exec(nullptr);
            if ((first->nodeType == BOOL_VAR
                || first->nodeType == BOOL_ARR
                || first->nodeType == BOOL_CONST)
                && (second->nodeType == BOOL_VAR
                || second->nodeType == BOOL_ARR
                || second->nodeType == BOOL_CONST))
                return ((BoolConstNode *) first)->and_((BoolConstNode *) second);
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case LOGITIZE:
            if (children.at(0)->nodeType == INT_VAR || children.at(0)->nodeType == INT_ARR)
                return ((IntVariableNode *) children.at(0))->logitize();
            else
                throw std::runtime_error("Type mismatch");
            break;
        case MXEQ: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST)
                return new BoolVariableNode("tmp", ((IntConstNode *) first)->compareM() == 0);
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case MXLT: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST)
                return new BoolVariableNode("tmp", ((IntConstNode *) first)->compareM() == -1);
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case MXGT: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST)
                return new BoolVariableNode("tmp", ((IntConstNode *) first)->compareM() == 1);
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case MXLTE: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST) {
                int tmp = ((IntConstNode *) first)->compareM();
                return new BoolVariableNode("tmp", tmp == 0 || tmp == -1);
            } else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case MXGTE: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST) {
                int tmp = ((IntConstNode *) first)->compareM();
                return new BoolVariableNode("tmp", tmp == 0 || tmp == 1);
            } else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case ELEQ: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST)
                return ((IntConstNode *) first)->eleq();
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case ELLT: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST)
                return ((IntConstNode *) first)->ellt();
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case ELGT: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST)
                return ((IntConstNode *) first)->elgt();
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case ELLTE: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST)
                return ((IntConstNode *) first)->ellte();
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case ELGTE: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == INT_VAR
            || first->nodeType == INT_ARR
            || first->nodeType == INT_CONST)
                return ((IntConstNode *) first)->elgte();
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case MXFALSE: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == BOOL_VAR
            || first->nodeType == BOOL_ARR
            || first->nodeType == BOOL_CONST)
                return ((BoolConstNode *) first)->mxfalse();
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case MXTRUE: {
            auto first = children.at(0)->exec(nullptr);
            if (first->nodeType == BOOL_VAR
            || first->nodeType == BOOL_ARR
            || first->nodeType == BOOL_CONST)
                return ((BoolConstNode *) first)->mxtrue();
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case ' ':
            return nullptr;
        case '\n':
            if (children.size() == 1)
                return children.at(0)->exec(nullptr);
            children.at(0)->exec(nullptr);
            if (hasResult)
                return nullptr;
            return children.at(1)->exec(nullptr);
        case ',':
            return nullptr;
        case '+': {
            auto first = children.at(0)->exec(nullptr);
            auto second = children.at(1)->exec(nullptr);
            if ((first->nodeType == INT_ARR
            || first->nodeType == INT_VAR
            || first->nodeType == INT_CONST)
            && (second->nodeType == INT_ARR
            || second->nodeType == INT_VAR
            || second->nodeType == INT_CONST))
                return ((IntConstNode *) first)->add(dynamic_cast<IntConstNode *>(second));
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case '-': {
            auto first = children.at(0)->exec(nullptr);
            auto second = children.at(1)->exec(nullptr);
            if ((first->nodeType == INT_ARR
            || first->nodeType == INT_VAR
            || first->nodeType == INT_CONST)
            && (second->nodeType == INT_ARR
            || second->nodeType == INT_VAR
            || second->nodeType == INT_CONST))
                return ((IntConstNode *) first)->sub(dynamic_cast<IntConstNode *>(second));
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case '*': {
            auto first = children.at(0)->exec(nullptr);
            auto second = children.at(1)->exec(nullptr);
            if ((first->nodeType == INT_ARR
            || first->nodeType == INT_VAR
            || first->nodeType == INT_CONST)
            && (second->nodeType == INT_ARR
            || second->nodeType == INT_VAR
            || second->nodeType == INT_CONST))
                return ((IntConstNode *) first)->mul(dynamic_cast<IntConstNode *>(second));
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case '/': {
            auto first = children.at(0)->exec(nullptr);
            auto second = children.at(1)->exec(nullptr);
            if ((first->nodeType == INT_ARR
            || first->nodeType == INT_VAR
            || first->nodeType == INT_CONST)
            && (second->nodeType == INT_ARR
            || second->nodeType == INT_VAR
            || second->nodeType == INT_CONST))
                return ((IntConstNode *) first)->div(dynamic_cast<IntConstNode *>(second));
            else
                throw std::runtime_error("Type mismatch");
            break;
        }
        case '=': {
            if (operNum == 2)
                ((AbstractVariableNode *)children.at(0))->assign(dynamic_cast<AbstractVariableNode *>(children.at(1)->exec(nullptr)));
            else if (operNum == 3)
                ((AbstractVariableNode *)children.at(0))->assignAt(dynamic_cast<AbstractVariableNode *>(children.at(2)->exec(nullptr)), AbstractVariableNode::makeDims(children.at(1)));
            return nullptr;
        }
        case '[': {
            if (children.at(0)->nodeType == INT_ARR)
                return ((IntArrayVariableNode *)children.at(0))->get(AbstractVariableNode::makeDims(children.at(1)));
            else if (children.at(0)->nodeType == BOOL_ARR)
                return ((BoolArrayVariableNode *)children.at(0))->get(AbstractVariableNode::makeDims(children.at(1)));
            else throw std::runtime_error("Type mismatch");
        }
    }
    return nullptr;
}

std::ostream &lab3::OperationNode::print(std::ostream &ostream) const {
    return ostream;
}

lab3::OperationNode::~OperationNode() {

}

std::ostream &lab3::operator<<(std::ostream &os, const lab3::OperationNode &node) {
    return node.print(os);
}
