#include "StateBroadcaster.hpp"

namespace before
{
StateBroadcaster::StateBroadcaster(CommunicationManager& communicationManager)
    : mCommunicationManager{communicationManager}
{
}

void StateBroadcaster::broadcast()
{
    mCommunicationManager.sendViaSerial("get_power");
}

void StateBroadcaster::emergencyBroadcast()
{
    mCommunicationManager.getSerialPortClient().send("emergency");
}
} // namespace before

namespace after
{
StateBroadcaster::StateBroadcaster(CommunicationManager& communicationManager)
    : mCommunicationManager{communicationManager}
{
}

void StateBroadcaster::broadcast()
{
    mCommunicationManager.sendViaSerial("get_power");
}

void StateBroadcaster::emergencyBroadcast()
{
    mCommunicationManager.sendViaRawSerial("emergency");
}
} // namespace after
