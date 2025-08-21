#include "variable.hpp"
#include <iostream>
#include <unordered_map>

struct Variable {
    std::string name;
    std::string value;
    bool constant;
};

static std::unordered_map<std::string, Variable> variables;

void parseVariable(const std::string &line, int  lineNum) {
    bool isConst = line.find("const ") == 0;
    size_t nameStart = isConst ? 6 : 4;
    size_t colonPos = line.find(":");
    size_t semicolon = line.find(";");
    std::string name = line.substr(nameStart, colonPos - nameStart);
    std::string value = line.substr(colonPos + 1, semicolon - colonPos - 1);

    variables[name] = {name, value, isConst};
    std::cout << "[DEBUG] " << (isConst ? "const " : "var ")
              << name << " = " << value << std::endl;
}
