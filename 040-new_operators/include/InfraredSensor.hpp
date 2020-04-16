#ifndef CPP_REFACTORING_FOR_TESTABILITY_INFRAREDSENSOR_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_INFRAREDSENSOR_HPP

#include "Sensor.hpp"

struct InfraredSensor : public Sensor
{
    int getDistance() const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_INFRAREDSENSOR_HPP
