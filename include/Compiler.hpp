#ifndef COMPILE_HPP
#define COMPILE_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "Token.hpp"

class Compiler {

    // code -> tokens
    std::vector<Token> tokenise(std::string code);

    // optimise code before turning into bf
    std::vector<Token> optimise_tokens(std::vector<Token> tokens);

    // tokens -> bf
    std::string compile_tokens(std::vector<Token> tokens);

    // optimise bf code (remove redundant patterns)
    std::string optimise_bf(std::string bf);

public:
    std::string compile(std::string code);  // exposed part of the api
};

#endif