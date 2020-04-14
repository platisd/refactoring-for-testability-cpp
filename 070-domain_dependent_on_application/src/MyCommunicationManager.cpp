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
#if defined(FOO_PRODUCT)
    mSerialPortClient.send(std::to_string(mSequenceNumber++) + ":" + message);
#elif defined(BAR_PRODUCT)
    mSerialPortClient.send("M:" + message + ",");
#else
#error Did you forget to define a product?
#endif
}
} // namespace before

namespace after
{
MyCommunicationManager::MyCommunicationManager(
    SerialPortClient& serialPortClient, SerialFormatter& serialFormatter)
    : mSerialPortClient{serialPortClient}
    , mSerialFormatter{serialFormatter}
{
}

void MyCommunicationManager::sendViaSerial(std::string message)
{
    mSerialPortClient.send(mSerialFormatter.format(message));
}
} // namespace after
