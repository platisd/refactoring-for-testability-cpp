#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKPINREADER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKPINREADER_HPP

#include "PinReader.hpp"
#include "gmock/gmock.h"

class MockPinReader : public PinReader
{
public:
    MOCK_METHOD(bool, read, (int pin), (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKPINREADER_HPP
