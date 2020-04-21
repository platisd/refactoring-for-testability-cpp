#include "MyFileWriter.hpp"
#include <fstream>

bool MyFileWriter::write(const std::string& filePath,
                         const std::string& content) const
{
    std::ofstream outfile(filePath.c_str(), std::ios::trunc);
    if (outfile.good())
    {
        outfile << content << std::endl;
    }

    return outfile.good();
}
