#include "MyInterruptManager.hpp"
#include "MyPinManager.hpp"
#include "PowerController.hpp"
#include <iostream>

using namespace before;

int main()
{
    MyPinManager pinManager;
    MyInterruptManager interruptManager;

    PowerController p{pinManager, interruptManager};
    const auto turnedOn = p.turnOn();

    std::cout << "Power turned on "
              << (turnedOn ? "successfully" : "unsuccessfully") << std::endl;

    return 0;
}
