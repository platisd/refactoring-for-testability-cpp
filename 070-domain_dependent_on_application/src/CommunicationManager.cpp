#include "CommunicationManager.hpp"

namespace before
{
CommunicationManager::CommunicationManager(SerialPortClient& serialPortClient)
    : mSerialPortClient{serialPortClient}
{
}

void CommunicationManager::sendViaSerial(std::string message)
{
#if defined(FOO_PRODUCT)
    static int sequenceNumber = 0;
    mSerialPortClient.send(std::to_string(sequenceNumber++) + ":" + message);
#elif defined(BAR_PRODUCT)
    mSerialPortClient.send("M:" + message + ",");
#else
#error Did you forget to define a product?
#endif
}
} // namespace before

namespace after
{
CommunicationManager::CommunicationManager(SerialPortClient& serialPortClient,
                                           SerialFormatter& serialFormatter)
    : mSerialPortClient{serialPortClient}
    , mSerialFormatter{serialFormatter}
{
}

void CommunicationManager::sendViaSerial(std::string message)
{
    mSerialPortClient.send(mSerialFormatter.format(message));
}
} // namespace after
