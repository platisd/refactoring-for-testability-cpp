#ifndef CPP_REFACTORING_WEBINAR_COMMUNICATIONMANAGER_HPP
#define CPP_REFACTORING_WEBINAR_COMMUNICATIONMANAGER_HPP

#include "SerialPortClient.hpp" // Remove after refactoring
#include <string>

struct CommunicationManager
{
    virtual ~CommunicationManager() = default;

    virtual void sendViaSerial(std::string message) = 0;
};

#endif // CPP_REFACTORING_WEBINAR_COMMUNICATIONMANAGER_HPP
