#include "PlatisSolutionsBenchmarker.hpp"
#include <iostream>

using namespace before;

int main()
{
    PlatisSolutionsBenchmarker benchmarker;

    const auto validResponseTime = benchmarker.getResponseTime();
    if (validResponseTime)
    {
        std::cout << "platis.solutions responded in "
                  << validResponseTime.value().count() << " milliseconds"
                  << std::endl;
    }
    else
    {
        std::cout << "platis.solutions failed to respond" << std::endl;
    }

    return 0;
}
