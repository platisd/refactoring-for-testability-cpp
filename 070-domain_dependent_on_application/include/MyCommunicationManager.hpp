#ifndef CPP_REFACTORING_WEBINAR_MYCOMMUNICATIONMANAGER_HPP
#define CPP_REFACTORING_WEBINAR_MYCOMMUNICATIONMANAGER_HPP

#include "CommunicationManager.hpp"
#include "SerialFormatter.hpp"
#include "SerialPortClient.hpp"

namespace before
{
struct MyCommunicationManager : public CommunicationManager
{
    MyCommunicationManager(SerialPortClient& serialPortClient);

    void sendViaSerial(std::string message) override;

private:
    SerialPortClient& mSerialPortClient;
    int mSequenceNumber{0};
};
} // namespace before

namespace after
{
struct MyCommunicationManager : public CommunicationManager
{
    MyCommunicationManager(SerialPortClient& serialPortClient,
                           SerialFormatter& serialFormatter);

    void sendViaSerial(std::string message) override;

private:
    SerialPortClient& mSerialPortClient;
    SerialFormatter& mSerialFormatter;
    int mSequenceNumber{0};
};
} // namespace after
#endif // CPP_REFACTORING_WEBINAR_MYCOMMUNICATIONMANAGER_HPP
