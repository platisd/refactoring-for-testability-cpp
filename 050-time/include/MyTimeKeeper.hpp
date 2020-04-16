#ifndef CPP_REFACTORING_FOR_TESTABILITY_MYTIMEKEEPER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MYTIMEKEEPER_HPP

#include "TimeKeeper.hpp"

struct MyTimeKeeper : public TimeKeeper
{
    void sleepFor(std::chrono::milliseconds delay) const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MYTIMEKEEPER_HPP
