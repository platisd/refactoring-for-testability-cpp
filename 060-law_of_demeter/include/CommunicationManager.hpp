#ifndef CPP_REFACTORING_WEBINAR_COMMUNICATIONMANAGER_HPP
#define CPP_REFACTORING_WEBINAR_COMMUNICATIONMANAGER_HPP

#include "SerialPortClient.hpp" // Remove after refactoring
#include <string>

namespace before
{
struct CommunicationManager
{
    virtual ~CommunicationManager() = default;

    virtual void sendViaSerial(std::string message)       = 0;
    virtual SerialPortClient& getSerialPortClient() const = 0;
};
} // namespace before

namespace after
{
struct CommunicationManager
{
    virtual ~CommunicationManager() = default;

    virtual void sendViaSerial(std::string message)          = 0;
    virtual void sendViaRawSerial(std::string message) const = 0;
    // or let whoever wants to use the "raw" serial port inject it themselves
};
} // namespace after

#endif // CPP_REFACTORING_WEBINAR_COMMUNICATIONMANAGER_HPP
