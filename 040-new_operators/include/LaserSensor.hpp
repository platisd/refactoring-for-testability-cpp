#ifndef CPP_REFACTORING_FOR_TESTABILITY_LASERSENSOR_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_LASERSENSOR_HPP

#include "Sensor.hpp"

struct LaserSensor : public Sensor
{
    int getDistance() const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_LASERSENSOR_HPP
