#include <string>
#include <filesystem>
#include <vector>
#include <iostream>

class OS{
    public:
    static bool dirExists(const std::string& path);
    static std::vector<std::string> listFiles(const std::string& path);
};