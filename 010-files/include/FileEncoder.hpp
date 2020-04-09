#ifndef CPP_REFACTORING_WEBINAR_FILEENCODER_HPP
#define CPP_REFACTORING_WEBINAR_FILEENCODER_HPP

#include "FileReader.hpp"
#include "FileWriter.hpp"

namespace before
{
struct FileEncoder
{
    bool encode(const std::string& filePath) const;
};
} // namespace before

namespace after
{
struct FileEncoder
{
    FileEncoder(FileReader& fileReader, FileWriter& fileWriter);

    bool encode(const std::string& filePath) const;

private:
    FileReader& mFileReader;
    FileWriter& mFileWriter;
};
} // namespace after
#endif // CPP_REFACTORING_WEBINAR_FILEENCODER_HPP
