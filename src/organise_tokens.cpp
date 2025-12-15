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
    std::vector<Subroutine> ret = {};
    
    std::vector<Section> subsections = {};
    std::vector<Token> tempToks = {};
    std::string curSec = "";
    std::vector<Token> sections = {};
    Subroutine tempSec({}, "");

    /*
    first create subsections
    at end of subsection, add an empty one called :stop
    then, create subroutines
    */

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].type == TokenType::TT_subsection) {

            if (curSec != "") {
                subsections.push_back(Section(tempToks, curSec));
                tempToks.clear();
            }
            curSec = tokens[i].content;

        } else if (tokens[i].type == TokenType::TT_section) {
            if (curSec != "") {
                subsections.push_back(Section(tempToks, curSec));
                tempToks.clear();
            }
            curSec = "";
            subsections.push_back(Section({}, START_SECTION));

            sections.push_back(tokens[i]);

        } else {
            tempToks.push_back(tokens[i]);
        }
    }
    subsections.push_back(Section(tempToks, curSec));

    int j = 0;
    for (size_t i = 0; i < subsections.size(); ++i) {
        if (subsections[i].name == START_SECTION) {
            if (!tempSec.sections.empty()) {
                ret.push_back(tempSec);
            }

            tempSec.name = sections[j++].content;
            tempSec.sections.clear();
        }

        tempSec.sections.push_back(subsections[i]);
    }

    if (!tempSec.sections.empty()) {
        ret.push_back(tempSec);
    }

    return ret;
}