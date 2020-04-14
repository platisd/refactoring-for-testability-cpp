#ifndef CPP_REFACTORING_WEBINAR_SENSORFACTORY_HPP
#define CPP_REFACTORING_WEBINAR_SENSORFACTORY_HPP

#include "Sensor.hpp"
#include <memory>

enum class SensorType
{
    Infrared,
    Ultrasonic,
    Laser,
    Lidar,
    Odometer,
    Radar
};

struct SensorFactory
{
    virtual ~SensorFactory() = default;

    virtual std::unique_ptr<Sensor> getSensor(SensorType sensorType) const = 0;
};

#endif // CPP_REFACTORING_WEBINAR_SENSORFACTORY_HPP
