#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <cstdint>
#include <string>
#include <vector>

// cannot actually occur in code because the space would split the token
#define START_SECTION ": START"

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
    Token() {}
};

struct Section {
    std::vector<Token> tokens;
    std::string name;
    Section(std::vector<Token> sectionTokens, std::string sectionName) {
        tokens = sectionTokens;
        name = sectionName;
    }
    Section() {}
};

struct Subroutine {
    std::vector<Section> sections;
    std::string name;
    Subroutine(std::vector<Section> subsections, std::string subName) {
        sections = subsections;
        name = subName;
    }
    Subroutine() {}
};

#endif