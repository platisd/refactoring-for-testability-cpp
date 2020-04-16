#include "DirectionalOdometer.hpp"

namespace before
{
DirectionalOdometer::DirectionalOdometer(int directionPin,
                                         int pulsePin,
                                         int pulsesPerMeter)
    : DirectionlessOdometer(pulsePin, pulsesPerMeter)
    , mDirectionPin{directionPin}
{
    mInterruptManager.triggerOnNewPulse(pulsePin, [this]() {
        if (mPinReader.read(mDirectionPin))
        {
            mPulses++;
        }
        else
        {
            mPulses--;
        }
    });
}
} // namespace before

namespace after
{

DirectionalOdometer::DirectionalOdometer(
    Encoder& encoder,
    InterruptServiceManager& interruptServiceManager,
    PinReader& pinReader,
    int directionPin,
    int pulsePin)
    : mEncoder{encoder}
    , mPinReader{pinReader}
    , mDirectionPin{directionPin}
{
    interruptServiceManager.triggerOnNewPulse(pulsePin, [this]() {
        if (mPinReader.read(mDirectionPin))
        {
            mEncoder.incrementPulses();
        }
        else
        {
            mEncoder.decrementPulses();
        }
    });
}

double DirectionalOdometer::getDistance() const
{
    return mEncoder.getDistance();
}
} // namespace after
