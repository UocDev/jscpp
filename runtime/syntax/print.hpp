#include <iostream>
#include <string>

inline void parsePrint(const std::string &expr, int /*line*/) {
    size_t start = expr.find("(");
    size_t end   = expr.rfind(")");
    if (start == std::string::npos || end == std::string::npos || end <= start) {
        std::cerr << "[JSCPP Runtime Error] Invalid print syntax" << std::endl;
        return;
    }

    std::string content = expr.substr(start + 1, end - start - 1);

    // Trim whitespace
    if (!content.empty() && content.front() == '"' && content.back() == '"') {
        content = content.substr(1, content.size() - 2); // remove quotes
    }

    std::cout << content << std::endl;
}
