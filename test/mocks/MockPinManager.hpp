#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKPINMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKPINMANAGER_HPP

#include "PinManager.hpp"
#include "gmock/gmock.h"

class MockPinManager : public PinManager
{
public:
    MOCK_METHOD(void, setPin, (int pin), (override));
    MOCK_METHOD(void, clearPin, (int pin), (override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKPINMANAGER_HPP
