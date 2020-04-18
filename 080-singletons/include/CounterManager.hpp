#ifndef CPP_REFACTORING_FOR_TESTABILITY_COUNTERMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_COUNTERMANAGER_HPP

#include "Counter.hpp"

struct CounterManager
{
    CounterManager(Counter& counter);

    void countTo(int number);

private:
    Counter& mCounter;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_COUNTERMANAGER_HPP
