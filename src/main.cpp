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
    tokens = comp.clean_tokens(tokens);
    std::vector<Subroutine> subs = comp.organise_tokens(tokens);
    
    for (Subroutine r: subs) {
        std::cout << r.name << std::endl;
        for (Section s: r.sections) {
            std::cout << "\t" << s.name << "\t" << s.tokens.size() << std::endl;
        }
    }

    // fio::write_file("_output/" + std::string(argv[1]) + ".bf", source);

    return 0;
}