#include <string>
#include <vector>
#include <algorithm>

#include "stringUtils.hpp"

std::string su::strip(std::string str) {
    auto start = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) {
        return std::isspace(ch);
    });

    auto end = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) {
        return std::isspace(ch);
    }).base();

    return (start < end) ? std::string(start, end) : std::string();
}

std::string su::remove_duplicate(std::string str, char c) {
    std::string result;
    bool lastWasChar = false; // Keep track of the last character
    
    for (char current : str) {
        if (current == c) {
            if (!lastWasChar) {
                result += current;
                lastWasChar = true;
            }
        } else {
            result += current;
            lastWasChar = false;
        }
    }
    
    return result;
}

std::string su::replace_all(std::string str, char old, char replacement) {
    std::string ret = str;
    for (int i = 0; i < ret.length(); i++) {
        ret[i] = (ret[i] == old) ? replacement : ret[i];
    }
    return ret;
}

std::string su::replace_all(std::string str, std::string old, std::string replacement) {
    return "su::replace_all has not been implemented yet. check src/stringUtils.cpp";
}