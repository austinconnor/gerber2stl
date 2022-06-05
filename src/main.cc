#include <iostream>
#include <vector>
#include "OS.hh"
#include "Parser.hh"
#include "GerberInstruction.hh"

int main(int argc, char** argv){
    std::string inpath = argv[1];
    std::string outdir = argv[2];

    if(!OS::dirExists(inpath) || !OS::dirExists(outdir)){ return -1; }    
    std::vector<std::string> files = OS::listFiles(inpath);

    for(auto file : files){
        std::vector<GerberInstruction> instructions = Parser::Parse(file);
    }

    return 0;
}