#include "parser.hpp"
#include "errorhandler.hpp"

// include syntax modules
#include "syntax/include.cpp"
#include "syntax/print.cpp"
#include "syntax/variable.cpp"

Parser::Parser() {
    // Register all syntax handlers here
    handlers.push_back(std::make_unique<PrintSyntax>());
    handlers.push_back(std::make_unique<VariableSyntax>());
    handlers.push_back(std::make_unique<IncludeSyntax>());
}

void Parser::parseLine(const std::string &line, int lineNum) {
    std::string trimmed = line;
    // simple trim
    trimmed.erase(0, trimmed.find_first_not_of(" \t"));
    trimmed.erase(trimmed.find_last_not_of(" \t") + 1);

    // skip empty or comments
    if (trimmed.empty() || trimmed.rfind("//", 0) == 0 || trimmed[0] == '#')
        return;

    for (auto &h : handlers) {
        if (h->canHandle(trimmed)) {
            h->handle(trimmed, lineNum);
            return;
        }
    }

    JSCPP::throwError("Unknown syntax: " + trimmed, lineNum, JSCPP::SYNTAX_ERROR);
}
