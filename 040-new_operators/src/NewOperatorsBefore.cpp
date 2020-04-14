#include "I2cSensorScanner.hpp"
#include "SensorManager.hpp"
#include <iostream>

using namespace before;

int main()
{
    I2cSensorScanner sensorScanner;
    SensorManager sensorManager{sensorScanner};
    const auto measurements = sensorManager.getSurroundingDistances();
    for (const auto& m : measurements)
    {
        std::cout << m << std::endl;
    }

    return 0;
}
