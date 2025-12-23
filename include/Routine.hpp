#ifndef ROUTINE_HPP
#define ROUTINE_HPP

#include <cstdint>
#include <string>
#include <vector>

#include "Error.hpp"
#include "Token.hpp"

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

struct Variable {
    std::string identifier;
    int dataPointer;
    int size; // only really important for arrays and strings
    DataType type;
};

class ParsedSubroutine {
public:
    std::vector<Variable> bytes;
    Section source;

    ParsedSubroutine(Subroutine raw);

};

#endif