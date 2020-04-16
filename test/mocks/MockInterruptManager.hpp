#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKINTERRUPTMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKINTERRUPTMANAGER_HPP

#include "InterruptManager.hpp"
#include "gmock/gmock.h"

class MockInterruptManager : public InterruptManager
{
public:
    MOCK_METHOD(void,
                triggerOnChange,
                (int pin, std::function<void(bool)> callback),
                (override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKINTERRUPTMANAGER_HPP
