#include <cstdint>
#include <string>
#include <vector>

#include "Token.hpp"
#include "Compiler.hpp"
#include "stringUtils.hpp"

// This file implements Compiler::tokenise

std::vector<Token> Compiler::tokenise(std::string code) {
    std::vector<std::string> lines = su::split(code, '\n');
    for (int i = 0; i < lines.size(); i++) {
        lines[i] = su::strip(lines[i]);
    }

    std::vector<Token> ret;
}