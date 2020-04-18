#include "CounterSingleton.hpp"
#include <iostream>

using namespace before;

void countTo(int number)
{
    // Hard to test context
    auto& counter        = CounterSingleton::getInstance();
    bool shouldIncrement = counter.get() < number;

    while (counter.get() != number)
    {
        if (shouldIncrement)
        {
            counter.increment();
        }
        else
        {
            counter.decrement();
        }
    }
}

int main()
{
    auto& counter = CounterSingleton::getInstance();
    std::cout << counter.get() << std::endl;
    countTo(10);
    std::cout << counter.get() << std::endl;
    return 0;
}