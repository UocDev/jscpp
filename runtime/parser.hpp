#pragma once
#include <string>
#include <vector>
#include <memory>
#include "syntax/syntaxhandler.hpp"

class Parser {
private:
    std::vector<std::unique_ptr<SyntaxHandler>> handlers;

public:
    Parser();
    void parseLine(const std::string &line, int lineNum);
};
