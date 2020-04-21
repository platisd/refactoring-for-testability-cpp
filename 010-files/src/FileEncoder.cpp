#include "FileEncoder.hpp"
#include <cctype>
#include <fstream>
#include <sstream>

namespace before
{
bool write(const std::string& filePath, const std::string& content)
{
    std::ofstream outfile(filePath.c_str(), std::ios::trunc);
    if (outfile.good())
    {
        outfile << content << std::endl;
    }

    return outfile.good();
}

std::optional<std::string> read(const std::string& filePath)
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

bool FileEncoder::encode(const std::string& filePath) const
{
    const auto validFileContents = read(filePath);
    if (!validFileContents)
    {
        return false;
    }
    auto encodedFileContents = validFileContents.value();
    for (auto& c : encodedFileContents)
    {
        if (std::isalnum(c))
        {
            c++;
        }
    }
    const auto wroteFileSuccessfully
        = write(filePath + ".encoded", encodedFileContents);

    return wroteFileSuccessfully;
}
} // namespace before

namespace after
{
FileEncoder::FileEncoder(FileReader& fileReader, FileWriter& fileWriter)
    : mFileReader{fileReader}
    , mFileWriter{fileWriter}
{
}

bool FileEncoder::encode(const std::string& filePath) const
{
    const auto validFileContents = mFileReader.read(filePath);
    if (!validFileContents)
    {
        return false;
    }
    auto encodedFileContents = validFileContents.value();
    for (auto& c : encodedFileContents)
    {
        if (std::isalnum(c))
        {
            c++;
        }
    }
    const auto wroteFileSuccessfully
        = mFileWriter.write(filePath + ".encoded", encodedFileContents);

    return wroteFileSuccessfully;
}
} // namespace after
