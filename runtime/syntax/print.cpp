#include "syntaxhandler.hpp"
#include "../errorhandler.hpp"
#include <iostream>

class PrintSyntax : public SyntaxHandler {
public:
    bool canHandle(const std::string &line) override {
        return line.rfind("print(", 0) == 0;
    }

    void handle(const std::string &line, int lineNum) override {
        size_t start = line.find("(");
        size_t end   = line.rfind(")");
        if (start == std::string::npos || end == std::string::npos || end <= start) {
            JSCPP::throwError("Invalid print syntax", lineNum, JSCPP::SYNTAX_ERROR);
            return;
        }
        std::string content = line.substr(start + 1, end - start - 1);
        std::cout << content << std::endl;
    }
};
