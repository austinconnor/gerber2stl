#pragma once
#include "GerberInstruction.hh"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Parser{
    public:
    static std::vector<GerberInstruction> Parse(const std::string& file);

    private:
    static bool Contains(const std::string& src, const std::string& substr);
};

