#ifndef CPP_REFACTORING_FOR_TESTABILITY_DIRECTIONLESSODOMETER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_DIRECTIONLESSODOMETER_HPP

#include "Encoder.hpp"
#include "InterruptServiceManager.hpp"
#include "MyInterruptServiceManager.hpp" // Remove this after refactoring
#include "Odometer.hpp"

namespace before
{
struct DirectionlessOdometer : public Odometer
{
    DirectionlessOdometer(int pulsePin, int pulsesPerMeter);

    double getDistance() const override;

protected:
    const int mPulsesPerMeter;
    int mPulses{0};
    MyInterruptServiceManager mInterruptManager;
};
} // namespace before

namespace after
{
struct DirectionlessOdometer : public Odometer
{
    DirectionlessOdometer(Encoder& encoder,
                          InterruptServiceManager& interruptServiceManager,
                          int pulsePin);

    double getDistance() const override;

private:
    Encoder& mEncoder;
};
} // namespace after

#endif // CPP_REFACTORING_FOR_TESTABILITY_DIRECTIONLESSODOMETER_HPP
