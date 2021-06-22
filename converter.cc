#include "converter.hh"
#include "parser.hh"

bool converter::gerber2stl(std::string inpath, std::string outdir){

    std::vector<GerberInstruction*> instructions = parser::parse(inpath);
    
    return true;
}