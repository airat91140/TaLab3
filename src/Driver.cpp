//
// Created by airat on 18.12.2021.
//

#include "Driver.h"
#include "ParameterNode.h"
#include "parser.tab.h"
#include <iostream>
#include <fstream>

void yyerror(char *s){
    std::cout << s <<std::endl;
}

void lab3::Driver::parseMap(const std::string &file) {
    std::ifstream f(file);
    if (!f)
        throw std::runtime_error("Something wrong with a file");
    bool exitSetFlag = false;
    bool positionSetFlag = false;
    int index = 0;
    int len = -1;
    for (std::string line; std::getline(f, line, '\n'); ) {
        if (len == -1)
            len = line.length();
        if (len != line.length())
            throw std::runtime_error("Incorrect length of " + std::to_string(index + 1) + " line");
        labyrinth.emplace_back();
        labyrinth.back().reserve(line.size());
        for (char c : line) {
            switch(c) {
                case '*':
                case ' ':
                    labyrinth.back().push_back(c);
                    break;
                case 'u':
                    if (positionSetFlag)
                        throw (std::runtime_error("multiple definition of position"));
                    currentDir = U;
                    positionSetFlag = true;
                    currentPos = {labyrinth.back().size(), index};
                    labyrinth.back().push_back(' ');
                    break;
                case 'd':
                    if (positionSetFlag)
                        throw (std::runtime_error("multiple definition of position"));
                    currentDir = D;
                    positionSetFlag = true;
                    currentPos = {labyrinth.back().size(), index};
                    labyrinth.back().push_back(' ');
                    break;
                case 'l':
                    if (positionSetFlag)
                        throw (std::runtime_error("multiple definition of position"));
                    currentDir = L;
                    positionSetFlag = true;
                    currentPos = {labyrinth.back().size(), index};
                    labyrinth.back().push_back(' ');
                    break;
                case 'r':
                    if (positionSetFlag)
                        throw (std::runtime_error("multiple definition of position"));
                    currentDir = R;
                    positionSetFlag = true;
                    currentPos = {labyrinth.back().size(), index};
                    labyrinth.back().push_back(' ');
                    break;
                case 'o':
                    if (exitSetFlag)
                        throw (std::runtime_error("multiple definition of exits"));
                    exitPos = {labyrinth.back().size(), index};
                    labyrinth.back().push_back(' ');
                    exitSetFlag = true;
                    break;
                default:
                    throw std::runtime_error("Unknown Charackter");
            }
        }
        ++index;
    }
    if (!positionSetFlag || !exitSetFlag)
        throw std::runtime_error("Unknown position of exit or robot");
}

lab3::BoolArrayVariableNode *lab3::Driver::getEnv() {
    auto *FALSE = new BoolConstNode(false);
    auto res = new BoolArrayVariableNode("tmp", true, {11, 11, 2});
    switch (currentDir) {
        case U: {
            for (int i = 1; i <= getMoodRate(); ++i) {
                if (!getWall({currentPos.first + i, currentPos.second}))
                    res->assignAt(FALSE, {6 + i, 6, 1});
                if (!getWall({currentPos.first, currentPos.second + i}))
                    res->assignAt(FALSE, {6, 6 + i, 1});
                if (!getWall({currentPos.first - i, currentPos.second}))
                    res->assignAt(FALSE, {6 - i, 6, 1});
                if (!getWall({currentPos.first, currentPos.second - i}))
                    res->assignAt(FALSE, {6, 6 - i, 1});
            }
            if (exitPos.first <= currentPos.first + getMoodRate() && exitPos.first >= currentPos.first - getMoodRate()
                && exitPos.second <= currentPos.second + getMoodRate() && exitPos.second >= currentPos.second - getMoodRate())
                res->assignAt(FALSE, {6 + currentPos.first - exitPos.first, 6 + currentPos.second - exitPos.second, 2});
            break;
        }
        case R: {
            for (int i = 1; i <= getMoodRate(); ++i) {
                if (!getWall({currentPos.first + i, currentPos.second}))
                    res->assignAt(FALSE, {6, 6 - i, 1});
                if (!getWall({currentPos.first, currentPos.second + i}))
                    res->assignAt(FALSE, {6 + i, 6, 1});
                if (!getWall({currentPos.first - i, currentPos.second}))
                    res->assignAt(FALSE, {6, 6 + i, 1});
                if (!getWall({currentPos.first, currentPos.second - i}))
                    res->assignAt(FALSE, {6 - i, 6, 1});
            }
            if (exitPos.first <= currentPos.first + getMoodRate() && exitPos.first >= currentPos.first - getMoodRate()
                && exitPos.second <= currentPos.second + getMoodRate() && exitPos.second >= currentPos.second - getMoodRate())
                res->assignAt(FALSE, {6 + currentPos.second - exitPos.second, 6 - currentPos.first + exitPos.first , 2});
            break;
        }
        case D: {
            for (int i = 1; i <= getMoodRate(); ++i) {
                if (!getWall({currentPos.first + i, currentPos.second}))
                    res->assignAt(FALSE, {6 - i, 6, 1});
                if (!getWall({currentPos.first, currentPos.second + i}))
                    res->assignAt(FALSE, {6, 6 - i, 1});
                if (!getWall({currentPos.first - i, currentPos.second}))
                    res->assignAt(FALSE, {6 + i, 6, 1});
                if (!getWall({currentPos.first, currentPos.second - i}))
                    res->assignAt(FALSE, {6, 6 + i, 1});
            }
            if (exitPos.first <= currentPos.first + getMoodRate() && exitPos.first >= currentPos.first - getMoodRate()
                && exitPos.second <= currentPos.second + getMoodRate() && exitPos.second >= currentPos.second - getMoodRate())
                res->assignAt(FALSE, { 6 - currentPos.first + exitPos.first, 6 - currentPos.second + exitPos.second, 2});
            break;
        }
        case L: {
            for (int i = 1; i <= getMoodRate(); ++i) {
                if (!getWall({currentPos.first + i, currentPos.second}))
                    res->assignAt(FALSE, {6, 6 + i, 1});
                if (!getWall({currentPos.first, currentPos.second + i}))
                    res->assignAt(FALSE, {6 - i, 6, 1});
                if (!getWall({currentPos.first - i, currentPos.second}))
                    res->assignAt(FALSE, {6, 6 - i, 1});
                if (!getWall({currentPos.first, currentPos.second - i}))
                    res->assignAt(FALSE, {6 + i, 6, 1});
            }
            if (exitPos.first <= currentPos.first + getMoodRate() && exitPos.first >= currentPos.first - getMoodRate()
                && exitPos.second <= currentPos.second + getMoodRate() && exitPos.second >= currentPos.second - getMoodRate())
                res->assignAt(FALSE, { 6 - currentPos.second + exitPos.second, 6 + currentPos.first - exitPos.first, 2});
            break;
        }
    }
    delete FALSE;
    return res;
}

int lab3::Driver::getMoodRate() {
    int average = (suspectnessBorder + sadnessBorder) / 2;
    if (mood < average)
        return (average - sadnessBorder) / (average - mood) >= 5 ? 5 : (average - sadnessBorder) / (average - mood);
    else
        return (suspectnessBorder - average) / (mood - average) >= 5 ? 5 : (suspectnessBorder - average) / (mood - average);
}

bool lab3::Driver::getWall(std::pair<int, int> pos) {
    try {
        return labyrinth.at(pos.second).at(pos.first) == '*';
    } catch (std::exception &ex) {
        return true;
    }
}

std::ostream &lab3::Driver::print(std::ostream &out) {
    std::string str;
    out << "===============================================================" << std::endl;
    for (int i = 0; i < labyrinth.size(); ++i) {
        str = formLine(labyrinth.at(i));
        if (currentPos.second == i) {
            switch (currentDir) {
                case U: str.at(currentPos.first) = '^'; break;
                case R: str.at(currentPos.first) = '>'; break;
                case L: str.at(currentPos.first) = '<'; break;
                case D: str.at(currentPos.first) = 'v'; break;
            }
        }
        if (exitPos.second == i) {
            str.at(exitPos.first) = 'o';
        }
        out << str << std::endl;
    }
    out << "===============================================================" << std::endl;
    return out;
}

bool lab3::Driver::move(int i) {
    switch (i) {
        case -1:
            currentDir = static_cast<dir>((currentDir + 1) % 4);
            print(std::cout);
            return true;
        case 1:
            currentDir = static_cast<dir>((currentDir + 3) % 4);
            print(std::cout);
            return true;
        case 0: {
            switch (currentDir) {
                case U:
                    if (!getWall({currentPos.first, currentPos.second - 1})) {
                        currentPos.second--;
                        print(std::cout);
                        return true;
                    }
                    break;
                case R:
                    if (!getWall({currentPos.first + 1, currentPos.second})) {
                        currentPos.first++;
                        print(std::cout);
                        return true;
                    }
                    break;
                case L:
                    if (!getWall({currentPos.first - 1, currentPos.second})) {
                        currentPos.first--;
                        print(std::cout);
                        return true;
                    }
                    break;
                case D:
                    if (!getWall({currentPos.first, currentPos.second + 1})) {
                        currentPos.second++;
                        print(std::cout);
                        return true;
                    }
                    break;
            }
            break;
        }
        default: return false;
    }
    return false;
}

std::string lab3::Driver::formLine(const std::vector<char> &array) {
    std::string res;
    for (char c : array) {
        res.push_back(c);
    }
    return res;
}
