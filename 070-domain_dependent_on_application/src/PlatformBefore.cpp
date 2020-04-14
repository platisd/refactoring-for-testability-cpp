#include "AsioSerialPortClient.hpp"
#include "MyCommunicationManager.hpp"

using namespace before;

int main()
{

    AsioSerialPortClient serialPortClient;
    MyCommunicationManager communicationManager{serialPortClient};
    communicationManager.sendViaSerial("First message");
    communicationManager.sendViaSerial("Second message");

    return 0;
}
