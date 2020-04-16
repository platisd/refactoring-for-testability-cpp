#ifndef CPP_REFACTORING_FOR_TESTABILITY_INTERRUPTSERVICEMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_INTERRUPTSERVICEMANAGER_HPP

#include <functional>

struct InterruptServiceManager
{
    virtual ~InterruptServiceManager() = default;

    virtual void triggerOnNewPulse(int pin,
                                   std::function<void()> callback) const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_INTERRUPTSERVICEMANAGER_HPP
