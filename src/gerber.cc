#include "gerber.hh"
#include "converter.hh"

GerberFile::GerberFile(std::string filepath, std::string outdir){
    this->filename = filepath;
    this->outdir = outdir;

    converter c;
    c.gerber2stl(this->filename, this->outdir, this);
}

void GerberInstruction::print(bool debug){

    if(debug){
        //std::cout << this->operation_type << std::endl;
        if(this->hasCoords){
            std::cout << "--------" << std::endl;
            std::cout << "X: " << this->x_coords << std::endl;
            std::cout << "Y: " << this->y_coords << std::endl;
            std::cout << this->operation_type << std::endl;
        }
    }

    return;
}