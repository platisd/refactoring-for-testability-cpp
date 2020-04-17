#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKINTERRUPTSERVICEMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKINTERRUPTSERVICEMANAGER_HPP

#include "InterruptServiceManager.hpp"
#include "gmock/gmock.h"

class MockInterruptServiceManager : public InterruptServiceManager
{
public:
    MOCK_METHOD(void,
                triggerOnNewPulse,
                (int pin, std::function<void()> callback),
                (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKINTERRUPTSERVICEMANAGER_HPP
