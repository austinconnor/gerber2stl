#include "os.hh"
#include <sys/types.h>
#include <sys/stat.h>
#include <filesystem>

namespace fs = std::filesystem;

//SUMMARY
//args: path (filepath to check)
//returns: -1 if can't access directory
//          1 if directory exists
//          0 if directory doesn't exist
bool os::dirExists(std::string path){
    return fs::is_directory(path);
}

//SUMMARY
//args path (filepath to check)
//returns: const char* vector containing all full filenames
std::vector<std::string> os::getFilesInDirectory(std::string path){

    std::vector<std::string> filenames;
    for(const auto& entry : fs::directory_iterator(path)){
        filenames.push_back(entry.path());
    }

    return filenames;
}