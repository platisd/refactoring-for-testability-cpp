#include "CommonCounter.hpp"
#include "CounterSingleton.hpp"
#include <CounterManager.hpp>
#include <iostream>

using namespace after;

int main()
{
    auto& counter1 = CounterSingleton::getInstance();
    std::cout << counter1.get() << std::endl;
    CounterManager counterManager{counter1};
    counterManager.countTo(10);
    std::cout << counter1.get() << std::endl;

    return 0;
}
