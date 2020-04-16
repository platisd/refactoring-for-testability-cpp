#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKSENSORSCANNER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKSENSORSCANNER_HPP

#include "SensorScanner.hpp"
#include "gmock/gmock.h"

class MockSensorScanner : public SensorScanner
{
public:
    MOCK_METHOD(std::vector<SensorIdentifier>, scan, (), (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKSENSORSCANNER_HPP
