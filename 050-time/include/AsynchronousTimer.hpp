#ifndef CPP_REFACTORING_FOR_TESTABILITY_ASYNCHRONOUSTIMER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_ASYNCHRONOUSTIMER_HPP

#include <chrono>
#include <functional>

struct AsynchronousTimer
{
    virtual ~AsynchronousTimer() = default;

    virtual void schedule(std::function<void()> task,
                          std::chrono::seconds delay)
        = 0;
    virtual bool hasPendingTask() const = 0;
    virtual void abort()                = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_ASYNCHRONOUSTIMER_HPP
