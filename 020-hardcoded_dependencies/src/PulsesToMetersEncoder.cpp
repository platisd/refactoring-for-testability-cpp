#include "PulsesToMetersEncoder.hpp"

PulsesToMetersEncoder::PulsesToMetersEncoder(int pulsesPerMeter)
    : mPulsesPerMeter{pulsesPerMeter}
{
}

void PulsesToMetersEncoder::incrementPulses()
{
    mPulses++;
}

void PulsesToMetersEncoder::decrementPulses()
{
    mPulses--;
}

double PulsesToMetersEncoder::getDistance() const
{
    return mPulses == 0 ? 0.0 : static_cast<double>(mPulsesPerMeter) / mPulses;
}
