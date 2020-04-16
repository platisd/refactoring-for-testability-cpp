#ifndef CPP_REFACTORING_FOR_TESTABILITY_SENSOR_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_SENSOR_HPP

struct Sensor
{
    virtual ~Sensor() = default;

    virtual int getDistance() const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_SENSOR_HPP
