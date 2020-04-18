#include "CounterManager.hpp"

CounterManager::CounterManager(Counter& counter)
    : mCounter{counter}
{
}

void CounterManager::countTo(int number)
{
    bool shouldIncrement = mCounter.get() < number;

    while (mCounter.get() != number)
    {
        if (shouldIncrement)
        {
            mCounter.increment();
        }
        else
        {
            mCounter.decrement();
        }
    }
}