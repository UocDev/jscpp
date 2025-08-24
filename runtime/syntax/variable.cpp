#include "syntaxhandler.hpp"
#include "../errorhandler.hpp"
#include <iostream>
#include <unordered_map>

// Simple variable store
static std::unordered_map<std::string, std::string> variables;

class VariableSyntax : public SyntaxHandler {
public:
    bool canHandle(const std::string &line) override {
        return line.rfind("var ", 0) == 0 || line.rfind("const ", 0) == 0;
    }

    void handle(const std::string &line, int lineNum) override {
        // Example: var hi: "Hallo";
        size_t nameStart = line.find(" ");
        size_t colonPos  = line.find(":");
        if (nameStart == std::string::npos || colonPos == std::string::npos) {
            JSCPP::throwError("Invalid variable syntax", lineNum, JSCPP::SYNTAX_ERROR);
            return;
        }

        std::string name = line.substr(nameStart + 1, colonPos - (nameStart + 1));
        std::string value = line.substr(colonPos + 1);
        variables[name] = value;

        std::cout << "[DEBUG] var " << name << " = " << value << std::endl;
    }
};
