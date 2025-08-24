#include "syntaxhandler.hpp"
#include "../errorhandler.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

class IncludeSyntax : public SyntaxHandler {
public:
    bool canHandle(const std::string &line) override {
        return line.rfind("#include", 0) == 0;
    }

    void handle(const std::string &line, int lineNum) override {
        size_t start = line.find("<");
        size_t end   = line.find(">");
        if (start == std::string::npos || end == std::string::npos || end <= start) {
            JSCPP::throwError("Invalid include syntax", lineNum, JSCPP::SYNTAX_ERROR);
            return;
        }

        std::string filename = line.substr(start + 1, end - start - 1);
        std::string fullpath = "../library/" + filename + ".hpp";

        std::ifstream file(fullpath);
        if (!file) {
            JSCPP::throwError("Cannot open include file: " + filename, lineNum, JSCPP::FILE_ERROR);
            return;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::cout << "[DEBUG] Included file: " << filename << std::endl;

        // Now re-parse the included file
        std::string lineContent;
        int subLineNum = 1;
        while (std::getline(buffer, lineContent)) {
            // Recurse into parser
            Parser subParser;
            subParser.parseLine(lineContent, subLineNum++);
        }
    }
};
