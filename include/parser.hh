#pragma once
#include <string>
#include <vector>
#include "gerber.hh"

class parser{
public:
    std::vector<GerberInstruction*> parse(std::string filepath, GerberFile* gf);
    std::vector<GerberInstruction*> instructions;
    GerberFile* gerberFile;

private:

    std::vector<std::string> splitString(std::string line);
    GerberInstruction* processLine(std::string tokens);
    bool contains(std::string line, std::string sub);
    void parseCoords(std::string line, GerberInstruction* instruction, bool onlyX, bool onlyY);
    void parseCoordFormat(std::string line);
    void parseOperationType(std::string line, GerberInstruction* instruction);
    void parseMeasurementUnit(std::string line);

};