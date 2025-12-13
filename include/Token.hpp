#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstdint>
#include <string>

enum TokenType : uint8_t {
    TT_invalid,
    TT_EOF,
    TT_identifier,      // x, ?var (pointer prefix is part of name)
    TT_instruction,     // if, set, ++, !=, etc.
    TT_section,         // denoted by .
    TT_subsection,      // denoted by :
    TT_number,          // hexadecimal numbers

};

struct Token {
    std::string content;    // exact eg. identifier this token contains
    TokenType type;         // what kind of token is this?
    
    std::string file;       // used for error tracking
    int lineInFile;         // line# in file for error tracking
};

#endif