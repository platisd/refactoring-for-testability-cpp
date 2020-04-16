#ifndef CPP_REFACTORING_FOR_TESTABILITY_PINMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_PINMANAGER_HPP

struct PinManager
{
    virtual ~PinManager() = default;

    virtual void setPin(int pin)   = 0;
    virtual void clearPin(int pin) = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_PINMANAGER_HPP
