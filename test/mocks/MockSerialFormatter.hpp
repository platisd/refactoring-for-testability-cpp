#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKSERIALFORMATTER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKSERIALFORMATTER_HPP

#include "SerialFormatter.hpp"
#include "gmock/gmock.h"

class MockSerialFormatter : public SerialFormatter
{
public:
    MOCK_METHOD(std::string, format, (const std::string& input), (override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKSERIALFORMATTER_HPP
