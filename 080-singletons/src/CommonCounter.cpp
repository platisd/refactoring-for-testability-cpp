#include "CommonCounter.hpp"

CommonCounter::CommonCounter(before::CounterSingleton& counterSingleton)
    : mCounterSingleton{counterSingleton}
{
}

void CommonCounter::increment()
{
    mCounterSingleton.increment();
}

void CommonCounter::decrement()
{
    mCounterSingleton.decrement();
}

int CommonCounter::get() const
{
    return mCounterSingleton.get();
}