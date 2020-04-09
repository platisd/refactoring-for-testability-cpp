#include "MyFileReader.hpp"
#include <fstream>
#include <sstream>

std::optional<std::string> MyFileReader::read(const std::string& filePath) const
{
    std::ifstream fileToRead(filePath);
    std::stringstream buffer;
    buffer << fileToRead.rdbuf();

    if (buffer.good())
    {
        return std::make_optional(buffer.str());
    }

    return std::nullopt;
}
