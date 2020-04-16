#ifndef CPP_REFACTORING_FOR_TESTABILITY_FILEWRITER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_FILEWRITER_HPP

#include <string>

struct FileWriter
{
    virtual ~FileWriter() = default;

    virtual bool write(const std::string& filePath,
                       const std ::string& content) const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_FILEWRITER_HPP
