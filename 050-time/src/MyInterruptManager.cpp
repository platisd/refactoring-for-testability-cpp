#include "MyInterruptManager.hpp"
#include <iostream>

void MyInterruptManager::triggerOnChange(
    int /* pin */, std::function<void(bool)> /* callback */)
{
    std::cout << "triggerOnChange" << std::endl;
}
