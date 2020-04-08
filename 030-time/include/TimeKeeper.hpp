#ifndef CPP_REFACTORING_WEBINAR_TIMEKEEPER_HPP
#define CPP_REFACTORING_WEBINAR_TIMEKEEPER_HPP

#include <chrono>

struct TimeKeeper
{
    virtual ~TimeKeeper() = default;

    virtual void sleep_for(std::chrono::milliseconds delay) const = 0;
};

#endif // CPP_REFACTORING_WEBINAR_TIMEKEEPER_HPP
