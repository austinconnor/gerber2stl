#include "Parser.hh"

bool Parser::Contains(const std::string& src, const std::string& substr){
    return (src.find(substr) != std::string::npos);
}

std::vector<GerberInstruction> Parser::Parse(const std::string& file){
    std::vector<GerberInstruction> instructions;
    std::cout << "I AM PARSING FILE: " << file << std::endl;

    std::ifstream in(file);
    if(!in){ std::cout << "Error, cannot open file: " << file << std::endl;}

    std::string line;
    auto count = 1;
    while(getline(in,line)){
        // std::cout << line << std::endl;
        if(Contains(line,"LPD")){
            std::cout << count << std::endl;
        }
        ++count;
    }

    return instructions;
}   