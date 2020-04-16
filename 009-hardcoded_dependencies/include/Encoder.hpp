#ifndef CPP_REFACTORING_FOR_TESTABILITY_ENCODER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_ENCODER_HPP

struct Encoder
{
    virtual ~Encoder() = default;

    virtual void incrementPulses()     = 0;
    virtual void decrementPulses()     = 0;
    virtual double getDistance() const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_ENCODER_HPP
