#ifndef CPP_REFACTORING_FOR_TESTABILITY_TIMEKEEPER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_TIMEKEEPER_HPP

#include <chrono>

struct TimeKeeper
{
    virtual ~TimeKeeper() = default;

    virtual void sleepFor(std::chrono::milliseconds delay) const = 0;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_TIMEKEEPER_HPP
