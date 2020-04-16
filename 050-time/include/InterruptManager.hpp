#ifndef CPP_REFACTORING_FOR_TESTABILITY_INTERRUPTMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_INTERRUPTMANAGER_HPP

#include <functional>

struct InterruptManager
{
    virtual ~InterruptManager() = default;

    virtual void triggerOnChange(int pin, std::function<void(bool)> callback)
        = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_INTERRUPTMANAGER_HPP
