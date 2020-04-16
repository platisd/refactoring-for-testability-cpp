#ifndef CPP_REFACTORING_FOR_TESTABILITY_MYFILEREADER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MYFILEREADER_HPP

#include "FileReader.hpp"

struct MyFileReader : public FileReader
{
    std::optional<std::string> read(const std::string& filePath) const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MYFILEREADER_HPP
