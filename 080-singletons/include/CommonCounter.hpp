#ifndef CPP_REFACTORING_FOR_TESTABILITY_COMMONCOUNTER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_COMMONCOUNTER_HPP

#include "Counter.hpp"
#include "CounterSingleton.hpp"

struct CommonCounter : public Counter
{
    CommonCounter(before::CounterSingleton& counterSingleton);

    void increment() override;
    void decrement() override;
    int get() const override;

private:
    before::CounterSingleton& mCounterSingleton;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_COMMONCOUNTER_HPP
