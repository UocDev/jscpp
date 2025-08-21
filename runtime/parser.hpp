#pragma once
#include <string>
#include <unordered_map>

struct Declaration {
    std::string keyword;
    std::string name;
    std::string type; // "function" or "variable"
};

class Parser {
public:
    static std::unordered_map<std::string, Declaration> userDeclarations;

    void parseFile(const std::string &filepath);
    void parseLine(const std::string &line, int lineNum);
};

inline bool DEBUG_LOGS = false;
