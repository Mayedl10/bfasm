#include <iostream>
#include <string>

#include "fileIO.hpp"

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Please provide a valid argument" << std::endl;
        return 1;
    }

    std::string source = fio::read_file("_examples/" + std::string(argv[1]) + ".ba");
    
    
    
    fio::write_file("_output/" + std::string(argv[1]) + ".bf", source);

    return 0;
}