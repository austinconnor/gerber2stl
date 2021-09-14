#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "gerber.hh"

class converter{
    
public:
    GerberFile* gerberFile;

    bool gerber2stl(std::string inpath, std::string outdir, GerberFile* gf);
};