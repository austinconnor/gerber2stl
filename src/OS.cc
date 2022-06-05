#include "OS.hh"

bool OS::dirExists(const std::string& path){
    return std::filesystem::exists(path);
}
std::vector<std::string> OS::listFiles(const std::string& path){
    std::vector<std::string> ret;
    for (const auto& entry : std::filesystem::directory_iterator(path)){
        ret.push_back(entry.path().string());
    }
        
    return ret;
}