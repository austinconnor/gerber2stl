#include <string>
#include <vector>
#include "gerber.hh"

class parser{
public:
    static std::vector<GerberInstruction*> parse(std::string filepath);

private:
    static std::vector<std::string> splitString(std::string line);
    static GerberInstruction* processTokens(std::vector<std::string> tokens);
};