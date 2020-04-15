#include "MyTimeKeeper.hpp"
#include <thread>

void MyTimeKeeper::sleepFor(std::chrono::milliseconds delay) const
{
    std::this_thread::sleep_for(delay);
}
