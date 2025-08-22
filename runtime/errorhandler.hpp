#pragma once
#include <string>

namespace JSCPP {
    enum ErrorType {
        SYNTAX_ERROR,
        RUNTIME_ERROR,
        SYSTEM_ERROR,
        WARNING
    };

    // Report an error, optionally with line number
    void throwError(const std::string &message, int line = -1,
                    ErrorType type = SYNTAX_ERROR, bool fatal = false);

    // Report a warning (non-fatal)
    void warn(const std::string &message, int line = -1);
}
