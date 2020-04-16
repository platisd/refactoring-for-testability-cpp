#include "DirectionalOdometer.hpp"
#include "DirectionlessOdometer.hpp"
#include <iostream>

using namespace before;

namespace
{
const auto kDirectionlessOdometerPulsePin       = 12;
const auto kDirectionalOdometerPulsePin         = 13;
const auto kDirectionPin                        = 14;
const auto kDirectionlessOdometerPulsesPerMeter = 100;
const auto kDirectionalOdometerPulsesPerMeter   = 500;

} // namespace

int main()
{
    DirectionlessOdometer directionlessOdometer{
        kDirectionlessOdometerPulsePin, kDirectionlessOdometerPulsesPerMeter};
    DirectionalOdometer directionalOdometer{kDirectionalOdometerPulsePin,
                                            kDirectionPin,
                                            kDirectionalOdometerPulsesPerMeter};

    std::cout << directionlessOdometer.getDistance() << std::endl;
    std::cout << directionalOdometer.getDistance() << std::endl;

    return 0;
}
