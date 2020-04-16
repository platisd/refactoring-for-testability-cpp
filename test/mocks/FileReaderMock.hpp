#ifndef CPP_REFACTORING_FOR_TESTABILITY_FILEREADERMOCK_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_FILEREADERMOCK_HPP

#include "FileReader.hpp"
#include "gmock/gmock.h"

class MockFileReader : public FileReader
{
public:
    MOCK_METHOD(std::optional<std::string>,
                read,
                (const std::string& filePath),
                (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_FILEREADERMOCK_HPP
