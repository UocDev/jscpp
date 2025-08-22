#include "print.hpp"
#include "errorhandler.hpp"
#include <iostream>
#include <string>

void parsePrint(const std::string &line, int lineNum) {
    size_t start = line.find("(");
    size_t end   = line.find_last_of(")");

    if (start == std::string::npos || end == std::string::npos || end <= start + 1) {
        JSCPP::throwError("Invalid print syntax", lineNum, JSCPP::SYNTAX_ERROR, false);
        return;
    }

    std::string content = line.substr(start + 1, end - start - 1);

    // Trim spaces
    size_t s = content.find_first_not_of(" \t");
    size_t e = content.find_last_not_of(" \t");
    if (s != std::string::npos && e != std::string::npos) {
        content = content.substr(s, e - s + 1);
    }

    // Remove quotes if present
    if (content.size() >= 2 &&
        ((content.front() == '"' && content.back() == '"') ||
         (content.front() == '\'' && content.back() == '\''))) {
        content = content.substr(1, content.size() - 2);
    }

    std::cout << content << std::endl;
}
