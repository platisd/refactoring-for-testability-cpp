#include "AsioSerialPortClient.hpp"
#include "CommunicationManager.hpp"
#include "FooSerialFormatter.hpp"

using namespace after;

int main()
{
    AsioSerialPortClient serialPortClient;
    FooSerialFormatter serialFormatter; // Could also be BarSerialFormatter
    CommunicationManager communicationManager{serialPortClient,
                                              serialFormatter};
    communicationManager.sendViaSerial("First message");
    communicationManager.sendViaSerial("Second message");

    return 0;
}
