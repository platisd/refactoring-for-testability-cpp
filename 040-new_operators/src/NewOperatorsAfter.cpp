#include "I2cSensorScanner.hpp"
#include "MySensorFactory.hpp"
#include "SensorManager.hpp"
#include <iostream>

using namespace after;

int main()
{
    I2cSensorScanner sensorScanner;
    MySensorFactory sensorFactory;
    after::SensorManager sensorManager{sensorScanner, sensorFactory};
    const auto measurements = sensorManager.getSurroundingDistances();
    for (const auto& m : measurements)
    {
        std::cout << m << std::endl;
    }

    return 0;
}
