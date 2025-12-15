#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstdint>
#include <string>
#include <vector>

enum TokenType : uint8_t {
    TT_invalid,
    TT_EOF,
    TT_NL,              // new line - instruction separator
    TT_identifier,      // x, ?var (pointer prefix is part of name)
    TT_instruction,     // if, set, ++, !=, etc.
    TT_section,         // denoted by .
    TT_subsection,      // denoted by :
    TT_number,          // hexadecimal numbers

};

struct Token {
    std::string content;    // exact eg. identifier this token contains
    TokenType type;         // what kind of token is this?
    Token(std::string tokenContent, TokenType tokenType) {
        content = tokenContent;
        type = tokenType;
    }
};

struct Section {
    std::vector<Token> tokens;
    std::string name;
};

struct Subroutine {
    std::vector<Section> sections;
    std::string name;
};

#endif