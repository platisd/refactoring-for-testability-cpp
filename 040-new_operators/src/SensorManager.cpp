#include "SensorManager.hpp"

namespace before
{
SensorManager::SensorManager(SensorScanner& sensorScanner)
{
    const auto detectedSensorIds = sensorScanner.scan();

    for (const auto& id : detectedSensorIds)
    {
        switch (id)
        {
        case SensorIdentifier::InfraredSensor:
            mSensors.emplace_back(std::make_unique<InfraredSensor>());
            break;
        case SensorIdentifier::UltrasonicSensor:
            mSensors.emplace_back(std::make_unique<UltrasonicSensor>());
            break;
        case SensorIdentifier::LaserSensor:
            mSensors.emplace_back(std::make_unique<LaserSensor>());
            break;
        default:
            throw std::logic_error("Unknown sensor");
        }
    }
}

std::vector<int> SensorManager::getSurroundingDistances() const
{
    std::vector<int> distances;
    for (const auto& sensor : mSensors)
    {
        distances.emplace_back(sensor->getDistance());
    }

    return distances;
}
} // namespace before

namespace after
{
SensorManager::SensorManager(SensorScanner& sensorScanner,
                             SensorFactory& sensorFactory)
{
    const auto detectedSensorIds = sensorScanner.scan();

    for (const auto& id : detectedSensorIds)
    {
        switch (id)
        {
        case SensorIdentifier::InfraredSensor:
            mSensors.emplace_back(
                sensorFactory.getSensor(SensorType::Infrared));
            break;
        case SensorIdentifier::UltrasonicSensor:
            mSensors.emplace_back(
                sensorFactory.getSensor(SensorType::Ultrasonic));
            break;
        case SensorIdentifier::LaserSensor:
            mSensors.emplace_back(sensorFactory.getSensor(SensorType::Laser));
            break;
        default:
            throw std::logic_error("Unknown sensor");
        }
    }
}

std::vector<int> SensorManager::getSurroundingDistances() const
{
    std::vector<int> distances;
    for (const auto& sensor : mSensors)
    {
        distances.emplace_back(sensor->getDistance());
    }

    return distances;
}
} // namespace after
