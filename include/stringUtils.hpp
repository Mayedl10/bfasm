#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP

#include <string>
#include <vector>

// this file provides a bunch of functions to help with manipulating strings

namespace su {

// removes whitespace at beginning and end
std::string strip(std::string str);

// recursively remove multiple occurences of c
// eg remove_duplicate("ooo.oo.o.o.aa", 'o') -> "o.o.o.o.aa"
std::string remove_duplicate(std::string str, char c);

// replace every occurence of old with replacement 
std::string replace_all(std::string str, char old, char replacement);
std::string replace_all(std::string str, std::string old, std::string replacement);

}

#endif