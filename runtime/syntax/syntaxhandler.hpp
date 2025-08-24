#pragma once
#include <string>

class SyntaxHandler {
public:
    virtual ~SyntaxHandler() = default;

    // Check if this handler can process the given line
    virtual bool canHandle(const std::string &line) = 0;

    // Actually process the line
    virtual void handle(const std::string &line, int lineNum) = 0;
};
