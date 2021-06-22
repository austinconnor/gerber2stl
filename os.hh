#include <vector>
#include <string>

class os{

public:
    static bool dirExists(std::string path);
    static std::vector<std::string> getFilesInDirectory(std::string path);

};
