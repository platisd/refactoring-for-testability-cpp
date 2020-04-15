#ifndef CPP_REFACTORING_WEBINAR_MOCKSENSOR_HPP
#define CPP_REFACTORING_WEBINAR_MOCKSENSOR_HPP

#include "Sensor.hpp"
#include "gmock/gmock.h"

class MockSensor : public Sensor
{
public:
    MOCK_METHOD(int, getDistance, (), (const, override));
};

#endif // CPP_REFACTORING_WEBINAR_MOCKSENSOR_HPP
