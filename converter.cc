#include "converter.hh"
#include "parser.hh"

bool converter::gerber2stl(std::string inpath, std::string outdir, GerberFile* gf){
    
    this->gerberFile = gf;

    parser p;
    std::vector<GerberInstruction*> instructions = p.parse(inpath, gf);

    for(auto instruction : instructions){
        instruction->print(true);
    }
    
    return true;
}