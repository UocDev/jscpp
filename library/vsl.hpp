#pragma once
#include <string>
#include <unordered_map>

struct variable {
    std::unordered_map<std::string, std::string> vars;
    void set(const std::string& name, const std::string& value) { vars[name] = value; }
    std::string get(const std::string& name) { return vars[name]; }
};
