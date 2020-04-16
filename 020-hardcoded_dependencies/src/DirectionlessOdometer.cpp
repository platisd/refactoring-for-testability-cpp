#include "DirectionlessOdometer.hpp"

namespace before
{
DirectionlessOdometer::DirectionlessOdometer(int pulsePin, int pulsesPerMeter)
    : mPulsesPerMeter{pulsesPerMeter}
{
    mInterruptManager.triggerOnNewPulse(pulsePin, [this]() { mPulses++; });
}

double DirectionlessOdometer::getDistance() const
{
    return mPulses == 0 ? 0.0 : static_cast<double>(mPulsesPerMeter) / mPulses;
}
} // namespace before

namespace after
{
DirectionlessOdometer::DirectionlessOdometer(
    Encoder& encoder,
    InterruptServiceManager& interruptServiceManager,
    int pulsePin)
    : mEncoder{encoder}
{
    interruptServiceManager.triggerOnNewPulse(
        pulsePin, [this]() { mEncoder.incrementPulses(); });
}

double DirectionlessOdometer::getDistance() const
{
    return mEncoder.getDistance();
}
} // namespace after
