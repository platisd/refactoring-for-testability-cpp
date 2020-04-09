#ifndef CPP_REFACTORING_WEBINAR_FILEREADER_HPP
#define CPP_REFACTORING_WEBINAR_FILEREADER_HPP

#include <optional>
#include <string>

struct FileReader
{
    virtual ~FileReader() = default;

    virtual std::optional<std::string>
    read(const std::string& filePath) const = 0;
};

#endif // CPP_REFACTORING_WEBINAR_FILEREADER_HPP
