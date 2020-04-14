#include "MyCommunicationManager.hpp"

namespace before
{
MyCommunicationManager::MyCommunicationManager(
    SerialPortClient& serialPortClient)
    : mSerialPortClient{serialPortClient}
{
}

void MyCommunicationManager::sendViaSerial(std::string message)
{
    mSerialPortClient.send(std::to_string(mSequenceNumber++) + ":" + message);
}

SerialPortClient& MyCommunicationManager::getSerialPortClient() const
{
    return mSerialPortClient;
}
} // namespace before

namespace after
{
MyCommunicationManager::MyCommunicationManager(
    SerialPortClient& serialPortClient)
    : mSerialPortClient{serialPortClient}
{
}

void MyCommunicationManager::sendViaSerial(std::string message)
{
    mSerialPortClient.send(std::to_string(mSequenceNumber++) + ":" + message);
}

void MyCommunicationManager::sendViaRawSerial(std::string message) const
{
    mSerialPortClient.send(message);
}
} // namespace after
