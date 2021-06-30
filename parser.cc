#include "parser.hh"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <ctype.h>
#include <math.h>

std::vector<GerberInstruction*> parser::parse(std::string filepath, GerberFile* gf){

    this->gerberFile = gf;

    std::ifstream file(filepath);
    std::vector<std::string> filelines;
    
    //get all lines in the file
    std::string temp;
    while(std::getline(file, temp)){
        filelines.push_back(temp);
    }
    file.close();

    for(std::string line : filelines){
        GerberInstruction* instruction = processLine(line);

        if(instruction != NULL){
            this->instructions.push_back(instruction);
        }
    }
    
    return this->instructions;
}

GerberInstruction* parser::processLine(std::string line){

    GerberInstruction* instruction = new GerberInstruction();
    
    if(contains(line, "FSLA")){
        size_t start = line.find("FSLA") + 4;
        size_t end = line.find("*");

        parseCoordFormat(line.substr(start, end-start));
    }

    if(contains(line, "MO")){
        parseMeasurementUnit(line);
    }

    //interpolation conditionals
    if(contains(line, "G") && contains(line, "X")){

        if(line.substr(0,3) == "G01"){
            instruction->interpolation_type = GerberUtils::LINEAR;
        }
        else if(line.substr(0,3) == "G02"){
            instruction->interpolation_type = GerberUtils::CIRC_CW;
        }
        else if(line.substr(0,3) == "G03"){
            instruction->interpolation_type = GerberUtils::CIRC_CCW;
        }
        else if(line.substr(0,3) == "G04"){ return NULL; }
        
        if(contains(line, "X") || contains(line, "Y")){
            line = line.substr(3,line.length()-3);
        }
    }

    //coordinate conditionals
    if(line[0] == 'X' && contains(line, "Y")){

        parseCoords(line, instruction, false, false);
        
    }
    else if(line[0] == 'X' && !contains(line, "Y")){

        parseCoords(line, instruction, true, false);
    }
    else if(line[0] == 'Y'){
        parseCoords(line, instruction, false, true);
    }

    //TODO: ADD APERTURES
    if(contains(line, "ADD")){  }

    if(contains(line, "M02")){ std::cout << "END OF FILE" << std::endl; }

    
    return instruction;
}

//checks if string line contains string sub
bool parser::contains(std::string line, std::string sub){
    return(line.find(sub) != std::string::npos);
}

void parser::parseCoords(std::string line, GerberInstruction* instruction, bool onlyX, bool onlyY){

    float x_coord = 0.0;
    float y_coord = 0.0;

    int x_ind = line.find("X");
    int y_ind = line.find("Y");
    int end = line.find("D");

    parseOperationType(line.substr(end, 3), instruction);
    

    std::string x_coord_str = line.substr(x_ind+1, y_ind-x_ind-1);
    std::string y_coord_str = line.substr(y_ind+1, end-y_ind-1);
    size_t x_len = x_coord_str.length();
    size_t y_len = y_coord_str.length();

    if(onlyX){
        std::string x_int_str = x_coord_str.substr(0, this->gerberFile->xInt);
        std::string x_dec_str = x_coord_str.substr(this->gerberFile->xInt, x_len);

        x_coord += (float)std::stoi(x_int_str, nullptr);
        if(x_dec_str.length() != 0){ x_coord += (float)std::stoi(x_dec_str, nullptr) / pow(10, x_dec_str.length());}

        y_coord = this->instructions[instructions.size()-1]->y_coords;
    }
    else if(onlyY){
        std::string y_int_str = y_coord_str.substr(0, this->gerberFile->yInt);
        std::string y_dec_str = y_coord_str.substr(this->gerberFile->yInt, y_len);

        y_coord += (float)std::stoi(y_int_str, nullptr);
        if(y_dec_str.length() != 0){ y_coord += (float)std::stoi(y_dec_str, nullptr) / pow(10, y_dec_str.length());}

        x_coord = this->instructions[instructions.size()-1]->x_coords;
    }
    else{
        
        std::string x_int_str = x_coord_str.substr(0, this->gerberFile->xInt);
        std::string x_dec_str = x_coord_str.substr(this->gerberFile->xInt, x_len);

        std::string y_int_str = y_coord_str.substr(0, this->gerberFile->yInt);
        std::string y_dec_str = y_coord_str.substr(this->gerberFile->yInt, y_len);

        x_coord += (float)std::stoi(x_int_str, nullptr);
        if(x_dec_str.length() != 0){ x_coord += (float)std::stoi(x_dec_str, nullptr) / pow(10, x_dec_str.length());}
        
        y_coord += (float)std::stoi(y_int_str, nullptr);
        if(y_dec_str.length() != 0){ y_coord += (float)std::stoi(y_dec_str, nullptr) / pow(10, y_dec_str.length());}
        
    }

    instruction->x_coords = x_coord;
    instruction->y_coords = y_coord;
    instruction->hasCoords = true;

    if(instruction->x_coords == 0 && instruction->y_coords == 0){
        std::cout << "THIS LINE IS ALL 0" << std::endl;
        std::cout << line << std::endl;
    }
    

    // std::cout << line << " : " << instruction->x_coords << ", " << instruction->y_coords << std::endl;

    //if no interpolation type is set, use same as previous instruction
    if(instruction->interpolation_type == GerberUtils::NONE){
        size_t iLen = this->instructions.size()-1;
        instruction->interpolation_type = this->instructions[iLen]->interpolation_type;
    }

}

void parser::parseCoordFormat(std::string line){

    this->gerberFile->xInt = (int)(line[1] - '0');
    this->gerberFile->xDec = (int)(line[2] - '0');
    this->gerberFile->yInt = (int)(line[4] - '0');
    this->gerberFile->yDec = (int)(line[5] - '0');
}

void parser::parseOperationType(std::string line, GerberInstruction* instruction){

    
    switch(line[2]- '0'){
        case 1:
            instruction->operation_type = GerberUtils::DRAW;
            break;
        case 2:
            instruction->operation_type = GerberUtils::FLY;
            break;
        case 3:
            instruction->operation_type = GerberUtils::FLASH;
            break;
        default:
            instruction->operation_type = GerberUtils::OP_NONE;
    }
    
    return;
}

void parser::parseMeasurementUnit(std::string line){
    int ind = line.find("MO");

    switch(line.substr(ind+3,1)[0]){
        case 'M':
            this->gerberFile->measurement_unit = GerberUtils::MM;
            break;
        case 'N':
            this->gerberFile->measurement_unit = GerberUtils::IN;
            break;
    }

    return;
}
