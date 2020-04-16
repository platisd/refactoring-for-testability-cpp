#ifndef CPP_REFACTORING_FOR_TESTABILITY_ULTRASONICSENSOR_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_ULTRASONICSENSOR_HPP

#include "Sensor.hpp"

struct UltrasonicSensor : public Sensor
{
    int getDistance() const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_ULTRASONICSENSOR_HPP
