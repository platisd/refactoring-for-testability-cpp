#ifndef CPP_REFACTORING_FOR_TESTABILITY_ODOMETER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_ODOMETER_HPP

struct Odometer
{
    virtual ~Odometer() = default;

    virtual double getDistance() const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_ODOMETER_HPP
