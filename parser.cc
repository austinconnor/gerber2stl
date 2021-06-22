#include "parser.hh"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<GerberInstruction*> parser::parse(std::string filepath){
    std::ifstream file(filepath);
    std::vector<std::string> filelines;
    std::vector<GerberInstruction*> instructions;
    std::cout << filepath << std::endl;
        
    std::string temp;
    while(std::getline(file, temp)){
        filelines.push_back(temp);
    }

    for(std::string line : filelines){
        std::vector<std::string> tokens = splitString(line);
        
        std::cout << tokens[0] << std::endl;

    }
    
    return instructions;
}

GerberInstruction* processTokens(std::vector<std::string> tokens){
    return NULL;
}

//SUMMARY
//args: std::string line (line of text from gerber file)
//returns vector<std::string> of tokens from original string

std::vector<std::string> parser::splitString(std::string line){

    std::vector<std::string> tokens;
    std::stringstream stringStream(line);
    std::string temp;

    while(std::getline(stringStream, temp)) 
    {
        std::size_t prev = 0, pos;
        while ((pos = temp.find_first_of(" %,*", prev)) != std::string::npos)
        {
            if (pos > prev)
                tokens.push_back(temp.substr(prev, pos-prev));
            prev = pos+1;
        }
        if (prev < temp.length())
            tokens.push_back(temp.substr(prev, std::string::npos));
    }

    return tokens;
}