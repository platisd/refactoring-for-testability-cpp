#include "I2cSensorScanner.hpp"

std::vector<SensorIdentifier> I2cSensorScanner::scan() const
{
    return {SensorIdentifier::LaserSensor,
            SensorIdentifier::LaserSensor,
            SensorIdentifier::UltrasonicSensor,
            SensorIdentifier::InfraredSensor};
}
