#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKENCODER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKENCODER_HPP

#include "Encoder.hpp"
#include "gmock/gmock.h"

class MockEncoder : public Encoder
{
public:
    MOCK_METHOD(void, incrementPulses, (), (override));
    MOCK_METHOD(void, decrementPulses, (), (override));
    MOCK_METHOD(double, getDistance, (), (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKENCODER_HPP
