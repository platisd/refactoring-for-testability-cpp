#include "DirectionalOdometer.hpp"
#include "DirectionlessOdometer.hpp"
#include "MyInterruptServiceManager.hpp"
#include "MyPinReader.hpp"
#include "PulsesToMetersEncoder.hpp"
#include <iostream>

using namespace after;

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
    MyInterruptServiceManager interruptServiceManager;

    PulsesToMetersEncoder directionlessEncoder{
        kDirectionlessOdometerPulsesPerMeter};
    DirectionlessOdometer directionlessOdometer{directionlessEncoder,
                                                interruptServiceManager,
                                                kDirectionlessOdometerPulsePin};

    PulsesToMetersEncoder directionalEncoder{
        kDirectionalOdometerPulsesPerMeter};
    MyPinReader pinReader;
    DirectionalOdometer directionalOdometer{directionalEncoder,
                                            interruptServiceManager,
                                            pinReader,
                                            kDirectionPin,
                                            kDirectionalOdometerPulsePin};

    std::cout << directionlessOdometer.getDistance() << std::endl;
    std::cout << directionalOdometer.getDistance() << std::endl;

    return 0;
}
