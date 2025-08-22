#include "parser.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "syntax/print.hpp"
#include "syntax/variable.hpp"
#include "errorhandler.hpp"

std::unordered_map<std::string, Declaration> Parser::userDeclarations;

namespace {
    // Trim helper
    std::string trim(const std::string &s) {
        size_t start = s.find_first_not_of(" \t\n\r");
        size_t end   = s.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) return "";
        return s.substr(start, end - start + 1);
    }
}

void Parser::parseFile(const std::string &filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        JSCPP::throwError("Cannot open file: " + filepath, 0, JSCPP::SYSTEM_ERROR, true);
        return;
    }

    std::string line;
    int lineNum = 1;
    while (std::getline(file, line)) {
        parseLine(line, lineNum++);
    }
}

void Parser::parseLine(const std::string &line, int lineNum) {
    std::string trimmed = trim(line);

    // Ignore blank, comment, braces
    if (trimmed.empty() || trimmed.substr(0, 2) == "//" ||
        trimmed[0] == '#' || trimmed == "{" || trimmed == "}") {
        return;
    }

    // Built-in syntax handlers
    if (trimmed.rfind("print(", 0) == 0) {
        parsePrint(trimmed, lineNum);
        return;
    } else if (trimmed.rfind("var ", 0) == 0 || trimmed.rfind("const ", 0) == 0) {
        parseVariable(trimmed, lineNum);
        return;
    }

    // Custom declaration
    std::istringstream iss(trimmed);
    std::string keyword, name;
    iss >> keyword >> name;

    if (!keyword.empty() && !name.empty()) {
        if (name.find("(") != std::string::npos) {
            // function
            Declaration d{keyword, name.substr(0, name.find("(")), "function"};
            userDeclarations[keyword + " " + d.name] = d;

            if (DEBUG_LOGS) {
                std::cout << "[Parser] Registered function: "
                          << keyword << " " << d.name << "()" << std::endl;
            }
        } else {
            // variable
            Declaration d{keyword, name, "variable"};
            userDeclarations[keyword + " " + name] = d;

            if (DEBUG_LOGS) {
                std::cout << "[Parser] Registered variable: "
                          << keyword << " " << name << std::endl;
            }
        }
        return;
    }

    // Unknown syntax → warning (non-fatal)
    JSCPP::warn("Unknown syntax: " + trimmed, lineNum);
}
