#ifndef CPP_REFACTORING_FOR_TESTABILITY_COUNTER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_COUNTER_HPP

struct Counter
{
    virtual ~Counter()       = default;
    virtual void increment() = 0;
    virtual void decrement() = 0;
    virtual int get() const  = 0;
};
#endif // CPP_REFACTORING_FOR_TESTABILITY_COUNTER_HPP
