#ifndef CPP_REFACTORING_FOR_TESTABILITY_PULSESTOMETERSENCODER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_PULSESTOMETERSENCODER_HPP

#include "Encoder.hpp"

struct PulsesToMetersEncoder : public Encoder
{
    PulsesToMetersEncoder(int pulsesPerMeter);

    void incrementPulses() override;
    void decrementPulses() override;
    double getDistance() const override;

private:
    const int mPulsesPerMeter;
    int mPulses{0};
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_PULSESTOMETERSENCODER_HPP
