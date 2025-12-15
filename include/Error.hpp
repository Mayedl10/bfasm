#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>
#include <cstdint>

enum ErrorCode : uint16_t {
    EC_None
};

struct CompilerError {
    ErrorCode errco;
    std::string message;
    std::string subroutine; // in what subroutine?
    std::string section; // in what subsection of the subroutine?
    std::string context; // surrounding code
    int line; // on what line INSIDE THE SUBROUTINE!!! the error occurred
    CompilerError (ErrorCode code, std::string msg)
        : errco(code), message(msg) {}
    CompilerError (ErrorCode code, std::string msg, std::string sub)
        : CompilerError(code, msg) {
            this->subroutine = sub;
        }
    CompilerError (ErrorCode code, std::string msg, std::string sub, std::string sec)
        : CompilerError(code, msg, sub) {
            this->section = sec;
        }
    CompilerError (ErrorCode code, std::string msg, std::string sub, std::string sec, std::string ctx)
        : CompilerError(code, msg, sub, sec) {
            this->context = ctx;
        }
    CompilerError (ErrorCode code, std::string msg, std::string sub, std::string sec, std::string ctx, int ln)
        : CompilerError(code, msg, sub, sec, ctx) {
            this->line = ln;
        }
};

#endif