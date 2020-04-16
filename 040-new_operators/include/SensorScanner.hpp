#ifndef CPP_REFACTORING_FOR_TESTABILITY_SENSORSCANNER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_SENSORSCANNER_HPP

#include <vector>

enum class SensorIdentifier
{
    LaserSensor      = 0x2A,
    InfraredSensor   = 0x1C,
    UltrasonicSensor = 0x1D
};

struct SensorScanner
{
    virtual ~SensorScanner() = default;

    virtual std::vector<SensorIdentifier> scan() const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_SENSORSCANNER_HPP
