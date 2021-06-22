#include <iostream>
#include <vector>
#include "os.hh"
#include "converter.hh"


int main(int argc, char** argv){
    std::string inpath = argv[1];
    std::string outdir = argv[2];

    if(!os::dirExists(inpath) || !os::dirExists(outdir)){ return -1; }    
    std::vector<std::string> files = os::getFilesInDirectory(inpath);

    for(auto file : files){
        converter::gerber2stl(file, outdir);
    }

    return 0;
}