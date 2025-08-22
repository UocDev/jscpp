#include "errorhandler.hpp"
#include <iostream>
#include <cstdlib>

namespace JSCPP {

    // Helper to convert ErrorType into string
    static std::string errorTypeToString(ErrorType type) {
        switch (type) {
            case SYNTAX_ERROR:  return "Syntax Error";
            case RUNTIME_ERROR: return "Runtime Error";
            case WARNING:       return "Warning";
            case SYSTEM_ERROR:  return "System Error";
            default:            return "Unknown Error";
        }
    }

    void throwError(const std::string &message, int line, ErrorType type, bool fatal) {
        std::string typeStr = errorTypeToString(type);

        if (line > 0)
            std::cerr << "[JSCPP " << typeStr << "] Line " << line << ": " << message << std::endl;
        else
            std::cerr << "[JSCPP " << typeStr << "] " << message << std::endl;

        // Exit on any fatal error except warnings
        if (fatal && type != WARNING) {
            std::exit(1);  // Compiler stops here
        }
    }

    void warn(const std::string &message, int line) {
        throwError(message, line, WARNING, false);
    }

    // Convenience wrappers so parser/runtime can call directly
    void syntaxError(const std::string &message, int line, bool fatal) {
        throwError(message, line, SYNTAX_ERROR, fatal);
    }

    void runtimeError(const std::string &message, int line, bool fatal) {
        throwError(message, line, RUNTIME_ERROR, fatal);
    }

    void systemError(const std::string &message, int line, bool fatal) {
        throwError(message, line, SYSTEM_ERROR, fatal);
    }

} // namespace JSCPP
