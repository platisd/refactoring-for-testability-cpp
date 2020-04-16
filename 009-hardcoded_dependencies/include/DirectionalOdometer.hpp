#ifndef CPP_REFACTORING_FOR_TESTABILITY_DIRECTIONALODOMETER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_DIRECTIONALODOMETER_HPP

#include "DirectionlessOdometer.hpp" // Remove this after refactoring
#include "Encoder.hpp"
#include "InterruptServiceManager.hpp"
#include "MyPinReader.hpp" // Remove this after refactoring
#include "Odometer.hpp"
#include "PinReader.hpp"

namespace before
{
struct DirectionalOdometer : public DirectionlessOdometer
{
    DirectionalOdometer(int directionPin, int pulsePin, int pulsesPerMeter);

private:
    MyPinReader mPinReader;
    const int mDirectionPin;
};
} // namespace before

namespace after
{
struct DirectionalOdometer : public Odometer
{
    DirectionalOdometer(Encoder& encoder,
                        InterruptServiceManager& interruptServiceManager,
                        PinReader& pinReader,
                        int directionPin,
                        int pulsePin);

    double getDistance() const override;

private:
    Encoder& mEncoder;
    PinReader& mPinReader;
    const int mDirectionPin;
};
} // namespace after
#endif // CPP_REFACTORING_FOR_TESTABILITY_DIRECTIONALODOMETER_HPP
