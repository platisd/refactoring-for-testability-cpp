#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKCOUNTER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKCOUNTER_HPP

#include "Counter.hpp"
#include "gmock/gmock.h"

class MockCounter : public Counter
{
public:
    MOCK_METHOD(void, increment, (), (override));
    MOCK_METHOD(void, decrement, (), (override));
    MOCK_METHOD(int, get, (), (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKCOUNTER_HPP
