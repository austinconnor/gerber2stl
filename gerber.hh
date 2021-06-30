#pragma once
#include <vector>
#include <string>


class GerberUtils{
public:
    enum INTERPOLATION_TYPE{NONE, LINEAR, CIRC_CW, CIRC_CCW};
    enum MEASUREMENT_UNIT{MM,IN};
    enum OPERATION_TYPE{OP_NONE, DRAW, FLY, FLASH};
    enum APERTURE_TYPE{CIRCLE, RECT, OBROUND, POLY};
    float mmToInchRatio = 25.4;

};

class GerberInstruction{
public:
    float x_coords;
    float y_coords;
    bool hasCoords = false;
    int aperture_id;

    GerberUtils::INTERPOLATION_TYPE interpolation_type = GerberUtils::NONE;
    GerberUtils::OPERATION_TYPE operation_type = GerberUtils::OP_NONE;

    void print(bool debug);

};

class GerberFile{
public:
    GerberFile(std::string filepath, std::string outdir);
    std::string filename;
    std::string outdir;
    std::vector<GerberInstruction*> instructions;
    GerberUtils::MEASUREMENT_UNIT measurement_unit;

    int xInt;
    int xDec;
    
    int yInt;
    int yDec;


};