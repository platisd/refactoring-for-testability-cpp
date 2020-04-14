#include "AsioSerialPortClient.hpp"
#include "MyCommunicationManager.hpp"
#include "StateBroadcaster.hpp"

using namespace before;

int main()
{
    AsioSerialPortClient serialPortClient;
    MyCommunicationManager communicationManager{serialPortClient};
    StateBroadcaster stateBroadcaster{communicationManager};
    stateBroadcaster.broadcast();
    stateBroadcaster.emergencyBroadcast();
    stateBroadcaster.broadcast();
    stateBroadcaster.broadcast();

    return 0;
}
