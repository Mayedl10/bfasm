#ifndef ERROR_HPP
#define ERROR_HPP

#include <string>
#include <cstdint>

#include "Token.hpp"

enum ErrorCode : uint16_t {
    EC_None,
    EC_unexpected_token
};

enum DataType : uint8_t {
    DT_INVALID,
    DT_NONE,    // "this argument is optional"
    DT_byte,
    DT_index,   // specifically an index variable
    DT_string,
    DT_static,
    DT_dynamic,
    DT_reference,   // basically same as byte, but it refers to stuff outside of your scope
    DT_index,
    DT_const,
    DT_subroutine,  // identifier for subroutine - call keyword

    DT_var,     // any type of variable - byte, reference, or index
    DT_arr      // any type of array - dynamic or static
};


/*
A SyntaxRule explains the required arguments of an instruction.
"expected" is a 2D vector, because expected[n] is a list of all
allowed types at position n. 
*/
struct SyntaxRule {
    std::string keyword;
    std::vector<std::vector<DataType>> expected;
    SyntaxRule(std::string kw, std::vector<std::vector<DataType>> args) {
        keyword = kw;
        expected = args;
    }
    SyntaxRule() {}
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