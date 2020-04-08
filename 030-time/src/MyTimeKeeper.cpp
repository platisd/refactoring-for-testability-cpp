#include "MyTimeKeeper.hpp"
#include <thread>

void MyTimeKeeper::sleep_for(std::chrono::milliseconds delay) const
{
    std::this_thread::sleep_for(delay);
}
