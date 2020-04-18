#include "CounterSingleton.hpp"

namespace before
{
CounterSingleton& CounterSingleton::getInstance()
{
    static CounterSingleton instance;

    return instance;
}

void CounterSingleton::increment()
{
    mCounter++;
}

void CounterSingleton::decrement()
{
    mCounter--;
}

int CounterSingleton::get() const
{
    return mCounter;
}
} // namespace before

namespace after
{
CounterSingleton& CounterSingleton::getInstance()
{
    static CounterSingleton instance;

    return instance;
}

void CounterSingleton::increment()
{
    mCounter++;
}

void CounterSingleton::decrement()
{
    mCounter--;
}

int CounterSingleton::get() const
{
    return mCounter;
}
} // namespace after