#include <iostream>
#include <string>
#include <vector>

#include "fileIO.hpp"
#include "Compiler.hpp"
#include "Token.hpp"

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        std::cerr << "Please provide a valid argument" << std::endl;
        return 1;
    }

    std::string source = fio::read_file("_examples/" + std::string(argv[1]) + ".ba");
    
    Compiler comp;

    auto tokens = comp.tokenise(source);
    
    for (int i = 0; i < tokens.size(); i++) {
        std::cout << i << "\t" << static_cast<int>(tokens[i].type) << "\t" << ((tokens[i].content == "\n") ? "\\n" : tokens[i].content) << std::endl;
    }

    // fio::write_file("_output/" + std::string(argv[1]) + ".bf", source);

    return 0;
}