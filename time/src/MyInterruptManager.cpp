#include "MyInterruptManager.hpp"
#include <iostream>

void MyInterruptManager::triggerOnChange(int, std::function<void(bool)>)
{
    std::cout << "triggerOnChange" << std::endl;
}
