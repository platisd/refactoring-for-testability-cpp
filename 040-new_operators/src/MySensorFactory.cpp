#include "MySensorFactory.hpp"
#include <InfraredSensor.hpp>
#include <LaserSensor.hpp>
#include <UltrasonicSensor.hpp>

std::unique_ptr<Sensor> MySensorFactory::getSensor(SensorType sensorType) const
{
    switch (sensorType)
    {
    case SensorType::Ultrasonic:
        return std::make_unique<UltrasonicSensor>();
    case SensorType::Infrared:
        return std::make_unique<InfraredSensor>();
    case SensorType::Laser:
        return std::make_unique<LaserSensor>();
    default:
        throw std::logic_error("Unknown sensor type for this factory");
    }
}
