#ifndef CPP_REFACTORING_WEBINAR_MYINTERRUPTMANAGER_HPP
#define CPP_REFACTORING_WEBINAR_MYINTERRUPTMANAGER_HPP

#include "InterruptManager.hpp"

struct MyInterruptManager : public InterruptManager
{
    void triggerOnChange(int pin, std::function<void(bool)> callback) override;
};

#endif // CPP_REFACTORING_WEBINAR_MYINTERRUPTMANAGER_HPP
