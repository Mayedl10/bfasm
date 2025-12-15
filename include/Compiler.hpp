#ifndef COMPILE_HPP
#define COMPILE_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "Token.hpp"

class Compiler {
public:
    // code -> tokens
    std::vector<Token> tokenise(std::string code);

    // removes comments and invalid (empty) tokens
    std::vector<Token> clean_tokens(std::vector<Token> tokens);

    // organises tokens into subroutines and sections
    std::vector<Subroutine> organise_tokens(std::vector<Token> tokens);

    // optimise code before turning into bf
    Subroutine optimise_subroutine(Subroutine subroutine);

    // tokens -> bf
    // expects entry point "main"
    std::string compile_program(std::vector<Subroutine> subroutines);

    // optimise bf code (remove redundant patterns)
    std::string optimise_bf(std::string bf);

// make earlier section private for release

//public:

    // all the reserved words
    const std::vector<const char*> keywords = {
        "++", "--", "+", "-", "*", "/", "%",
        ">", ">=", "<", "<=", "==", "!=",
        "&", "|", "!", "^",

        "printV_c", "printV_n",
        "printS",
        "printSA_c", "printSA_n",
        "printDA_c", "printDA_n",

        "readV_c", "readV_n",
        "readSA_c", "readSA_n",
        "readDA_n", "readDA_c",

        "if", "else",
        "while",
        "clear", "set",
        "memset",
        "collapse"
    };
    std::string compile(std::string code);  // exposed part of the api
};

#endif