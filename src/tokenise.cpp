#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

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
    Token temp;
    std::vector<std::string> words; // everything separated by a space ' '

    for (std::string line : lines) {
        words = su::split(line, ' ');

        for (std::string word : words) {
            if (word.length() < 1) {
                temp.type = TokenType::TT_invalid;
                temp.content = "\\INVALID[EMPTY]";

            } else if (std::find(this->keywords.begin(), this->keywords.end(), word) != this->keywords.end()) {
                temp.type = TokenType::TT_instruction;
                temp.content = word;
            
            } else if (word[0] == '.') {
                temp.type = TokenType::TT_section;
                temp.content = word;
            
            } else if (word[0] == ':') {
                temp.type = TokenType::TT_subsection;
                temp.content = word;
            } else {

                bool isValidHex = true;
                for (char c: word) {
                    if (!isxdigit(c)) {
                        isValidHex = false;
                        break;
                    }
                }

                temp.type = isValidHex ? TokenType::TT_number : TokenType::TT_identifier;
                temp.content = word;
            }

            ret.push_back(temp);
        }
        temp.content = "\n";
        temp.type = TokenType::TT_NL;
        ret.push_back(temp);
    }

    temp.content = "\\EOF";
    temp.type = TokenType::TT_EOF;
    ret.push_back(temp);

    return ret;

}