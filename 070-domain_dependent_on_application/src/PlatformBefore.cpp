#include "AsioSerialPortClient.hpp"
#include "CommunicationManager.hpp"

using namespace before;

int main()
{
    AsioSerialPortClient serialPortClient;
    CommunicationManager communicationManager{serialPortClient};
    communicationManager.sendViaSerial("First message");
    communicationManager.sendViaSerial("Second message");

    return 0;
}
