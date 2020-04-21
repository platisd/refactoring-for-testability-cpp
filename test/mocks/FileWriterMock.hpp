#ifndef CPP_REFACTORING_FOR_TESTABILITY_FILEWRITERMOCK_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_FILEWRITERMOCK_HPP

#include "FileWriter.hpp"
#include "gmock/gmock.h"

class MockFileWriter : public FileWriter
{
public:
    MOCK_METHOD(bool,
                write,
                (const std::string& filePath, const std::string& content),
                (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_FILEWRITERMOCK_HPP
