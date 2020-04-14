#include "AsioSerialPortClient.hpp"
#include "FooSerialFormatter.hpp"
#include "MyCommunicationManager.hpp"

using namespace after;

int main()
{

    AsioSerialPortClient serialPortClient;
    FooSerialFormatter serialFormatter; // Could also be BarSerialFormatter
    MyCommunicationManager communicationManager{serialPortClient,
                                                serialFormatter};
    communicationManager.sendViaSerial("First message");
    communicationManager.sendViaSerial("Second message");

    return 0;
}
