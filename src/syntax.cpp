#include <cstdint>
#include <string>
#include <vector>

#include "Token.hpp"
#include "Compiler.hpp"
#include "Error.hpp"

/*
This is a very ugly solution and not very efficient,
but I didn't want to clutter Compiler.hpp too much
*/
void Compiler::set_syntax_rules() {
    this->syntaxRules = {
        SyntaxRule("++", 
                {{DataType::DT_var}}),
        SyntaxRule("--", 
                {{DataType::DT_var}}),
        SyntaxRule("+", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("-", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("*", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("/", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("%", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule(">", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule(">=", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("<", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("<=", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("==", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("!=", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("&", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("|", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("!", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("^", 
                {
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const},
                        {DataType::DT_var, DataType::DT_const}
                }),

        SyntaxRule("printV_c", 
                {
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("printV_n", 
                {
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("printS", 
                {
                        {DataType::DT_string}
                }),
        SyntaxRule("printA_c", 
                {
                        {DataType::DT_arr},
                        {DataType::DT_var, DataType::DT_string, DataType::DT_const, DataType::DT_NONE}
                }),
        SyntaxRule("printA_n", 
                {
                        {DataType::DT_arr},
                        {DataType::DT_var, DataType::DT_string, DataType::DT_const, DataType::DT_NONE}
                }),
        SyntaxRule("readV_c", 
                {
                        {DataType::DT_var}
                }),
        SyntaxRule("readV_n", 
                {
                        {DataType::DT_var}
                }),
        SyntaxRule("readA_c", 
                {
                        {DataType::DT_arr},
                        {DataType::DT_const}
                }),
        SyntaxRule("readA_n", 
                {
                        {DataType::DT_arr},
                        {DataType::DT_const}
                }),
        SyntaxRule("if", 
                {
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("else", 
                {
                        // no parameters
                }),
        SyntaxRule("endIf", 
                {
                        // no parameters
                }),
        SyntaxRule("while", 
                {
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("endWhile", 
                {
                        // no parameters
                }),
        SyntaxRule("clear", 
                {
                        {DataType::DT_var, DataType::DT_arr}
                }),
        SyntaxRule("set", 
                {
                        {DataType::DT_var, DataType::DT_arr},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("collapse", 
                {
                        {DataType::DT_var}
                }),
        SyntaxRule("call", 
                {
                        {DataType::DT_subroutine}
                }),
        SyntaxRule("index", 
                {
                        {DataType::DT_index},
                        {DataType::DT_arr},
                        {DataType::DT_const}
                }),
        SyntaxRule("setD", 
                {
                        {DataType::DT_dynamic},
                        {DataType::DT_var},
                        {DataType::DT_var, DataType::DT_const}
                }),
        SyntaxRule("getD", 
                {
                        {DataType::DT_dynamic},
                        {DataType::DT_var},
                        {DataType::DT_var}
                }),
    };
}