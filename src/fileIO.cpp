#include "fileIO.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string read_file(std::string path) {
    auto str = std::ifstream(path);
    if (!str.is_open()) {
        std::cerr << "[ERROR] Failed to open (r) file: " << path << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << str.rdbuf();
    return buffer.str();
}

void write_file(std::string path, std::string content) {
    auto str = std::ofstream(path);
    if (!str.is_open()) {
        std::cerr << "[ERROR] Failed to open (w) file: " << path << std::endl;
        return;
    }

    str << content;
    if (str.fail()) {
        std::cerr << "[ERROR] Failed to write to file: " << path << std::endl;
    }
}