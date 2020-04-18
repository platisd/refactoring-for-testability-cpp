#include "CommonCounter.hpp"
#include "CounterSingleton.hpp"
#include <CounterManager.hpp>
#include <iostream>

using namespace before; // We are still using the original Singleton

int main()
{
    auto& counter1 = CounterSingleton::getInstance();
    std::cout << counter1.get() << std::endl;
    CommonCounter commonCounter{counter1};
    CounterManager counterManager{commonCounter};
    counterManager.countTo(10);
    std::cout << counter1.get() << std::endl;

    return 0;
}
