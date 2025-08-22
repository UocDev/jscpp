#include "errorhandler.hpp"
#include <iostream>
#include <cstdlib>

namespace JSCPP {

    void throwError(const std::string &message, int line, ErrorType type, bool fatal) {
        std::string typeStr;
        switch (type) {
            case SYNTAX_ERROR: typeStr = "Syntax Error"; break;
            case RUNTIME_ERROR: typeStr = "Runtime Error"; break;
            case WARNING:      typeStr = "Warning"; break;
            case SYSTEM_ERROR: typeStr = "System Error"; break;
        }

        if (line > 0)
            std::cerr << "[JSCPP " << typeStr << "] Line " << line << ": " << message << std::endl;
        else
            std::cerr << "[JSCPP " << typeStr << "] " << message << std::endl;

        // Only exit if fatal error
        if (fatal && type != WARNING) {
            std::exit(1);
        }
    }

    void warn(const std::string &message, int line) {
        throwError(message, line, WARNING, false);
    }

}
