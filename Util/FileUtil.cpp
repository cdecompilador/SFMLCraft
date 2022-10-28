#include "FileUtil.h"

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cstdio>

std::string
getFileContents(const std::string& filePath)
{
    std::ifstream inFile(filePath);
    if (!inFile.is_open())
    {
        printf("File doesn't exist\n");
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    std::stringstream stream;
    stream << inFile.rdbuf();
    return stream.str();
}
