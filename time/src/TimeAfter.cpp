#include "MyInterruptManager.hpp"
#include "MyPinManager.hpp"
#include "MyTimeKeeper.hpp"
#include "PowerController.hpp"
#include "SingleTaskAsynchronousTimer.hpp"
#include <iostream>

using namespace after;

int main()
{
    MyPinManager pinManager;
    MyInterruptManager interruptManager;
    SingleTaskAsynchronousTimer timer;
    MyTimeKeeper timeKeeper;

    PowerController p{pinManager, interruptManager, timer, timeKeeper};
    const auto turnedOn = p.turnOn();

    std::cout << "Power turned on "
              << (turnedOn ? "successfully" : "unsuccessfully") << std::endl;

    return 0;
}
