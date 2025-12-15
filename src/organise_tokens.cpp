#include <cstdint>
#include <string>
#include <vector>

#include <iostream>

#include "Token.hpp"
#include "Compiler.hpp"
#include "stringUtils.hpp"

// This file implements Compiler::organise_tokens and Compiler::clean_tokens

std::vector<Token> Compiler::clean_tokens(std::vector<Token> tokens) {
    std::vector<Token> ret = {};
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == TokenType::TT_invalid) continue;

        if (tokens[i].content[0] == ';') {
            while ((tokens[i].type != TokenType::TT_NL) && (tokens[i].type != TokenType::TT_EOF) && (i < tokens.size())) {
                i++;
            }
        }

        if (i > 0) {
            if ((ret[ret.size()-1].type == TokenType::TT_NL) && (tokens[i].type == TokenType::TT_NL)) {
                ret.pop_back();
            }
        }

        ret.push_back(tokens[i]);
    }
    return ret;
}

std::vector<Subroutine> Compiler::organise_tokens(std::vector<Token> tokens) {
    return {};
}