#ifndef CPP_REFACTORING_FOR_TESTABILITY_MYINTERRUPTSERVICEMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MYINTERRUPTSERVICEMANAGER_HPP

#include "InterruptServiceManager.hpp"

struct MyInterruptServiceManager : public InterruptServiceManager
{
    void triggerOnNewPulse(int pin,
                           std::function<void()> callback) const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MYINTERRUPTSERVICEMANAGER_HPP
