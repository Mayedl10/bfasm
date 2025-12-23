#ifndef COMPILE_HPP
#define COMPILE_HPP

#include <cstdint>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>

#include "Token.hpp"
#include "Error.hpp"
#include "Routine.hpp"


struct BfInstructions {
    static constexpr const char* inc    = "+";
    static constexpr const char* dec    = "-";
    static constexpr const char* print  = ".";
    static constexpr const char* read   = ",";
    static constexpr const char* left   = "<";
    static constexpr const char* right  = ">";
    static constexpr const char* open   = "[";
    static constexpr const char* close  = "]";
};

class Compiler {
public:

    ////////////////
    // Variables

    std::unordered_map<std::string, std::function<void()>> instructionMap;

    std::vector<SyntaxRule> syntaxRules;

    ////////////////
    // Methods

    void set_syntax_rules();
    void create_instruction_mappings();

    // code -> tokens
    std::vector<Token> tokenise(std::string code);

    // removes comments and invalid (empty) tokens
    std::vector<Token> clean_tokens(std::vector<Token> tokens);

    // organises tokens into subroutines and sections
    std::vector<Subroutine> organise_tokens(std::vector<Token> tokens);

    // check for (syntax) errors
    std::vector<CompilerError> validate(ParsedSubroutine routine);

    // optimise code before turning into bf
    Subroutine optimise_subroutine(Subroutine subroutine);

    // tokens -> bf
    // expects entry point "main"
    std::string compile_program(std::vector<Subroutine> subroutines);

    // optimise bf code (remove redundant patterns)
    std::string optimise_bf(std::string bf);

// make earlier section private for release

//public:

    ////////////////
    // Variables

    // all the reserved words
    const std::vector<const char*> keywords = {
        "++", "--", "+", "-", "*", "/", "%",
        ">", ">=", "<", "<=", "==", "!=",
        "&", "|", "!", "^",

        "printV_c", "printV_n",
        "printS",
        "printA_c", "printA_n",

        "readV_c", "readV_n",
        "readA_c", "readA_n",

        "if", "else", "endIf",
        "while", "endWhile",
        "clear", "set",
        "collapse",
        "call",
        "index", "setD", "getD"
    };

    ////////////////
    // Methods

    std::string compile(std::string code);  // exposed part of the api

    Compiler(); // allocate instructionMap
    ~Compiler(); // deallocate instructionMap

};

#endif