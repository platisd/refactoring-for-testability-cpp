#ifndef CPP_REFACTORING_FOR_TESTABILITY_COMMUNICATIONMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_COMMUNICATIONMANAGER_HPP

#include "SerialFormatter.hpp"
#include "SerialPortClient.hpp"

namespace before
{
struct CommunicationManager
{
    CommunicationManager(SerialPortClient& serialPortClient);

    void sendViaSerial(std::string message);

private:
    SerialPortClient& mSerialPortClient;
    int mSequenceNumber{0};
};
} // namespace before

namespace after
{
struct CommunicationManager
{
    CommunicationManager(SerialPortClient& serialPortClient,
                         SerialFormatter& serialFormatter);

    void sendViaSerial(std::string message);

private:
    SerialPortClient& mSerialPortClient;
    SerialFormatter& mSerialFormatter;
    int mSequenceNumber{0};
};
} // namespace after
#endif // CPP_REFACTORING_FOR_TESTABILITY_COMMUNICATIONMANAGER_HPP
