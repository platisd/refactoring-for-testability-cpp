#ifndef CPP_REFACTORING_WEBINAR_SENSORMANAGER_HPP
#define CPP_REFACTORING_WEBINAR_SENSORMANAGER_HPP

#include "InfraredSensor.hpp" // Remove this after refactoring
#include "LaserSensor.hpp"    // Remove this after refactoring
#include "SensorFactory.hpp"
#include "SensorScanner.hpp"
#include "UltrasonicSensor.hpp" // Remove this after refactoring

namespace before
{
struct SensorManager
{
    SensorManager(SensorScanner& sensorScanner);

    std::vector<int> getSurroundingDistances() const;

private:
    std::vector<std::unique_ptr<Sensor>> mSensors;
};
} // namespace before

namespace after
{
struct SensorManager
{
    SensorManager(SensorScanner& sensorScanner, SensorFactory& sensorFactory);

    std::vector<int> getSurroundingDistances() const;

private:
    std::vector<std::unique_ptr<Sensor>> mSensors;
};
} // namespace after

#endif // CPP_REFACTORING_WEBINAR_SENSORMANAGER_HPP
