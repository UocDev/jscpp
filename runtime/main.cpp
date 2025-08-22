#include "parser.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ujscc <file.jscpp>" << std::endl;
        return 1;
    }

    Parser parser;
    parser.parseFile(argv[1]);

    return 0;
}
