#ifndef CPP_REFACTORING_WEBINAR_STATEBROADCASTER_HPP
#define CPP_REFACTORING_WEBINAR_STATEBROADCASTER_HPP

#include "CommunicationManager.hpp"

namespace before
{
struct StateBroadcaster
{
    StateBroadcaster(CommunicationManager& communicationManager);

    void broadcast();
    void emergencyBroadcast();

private:
    CommunicationManager& mCommunicationManager;
};

} // namespace before

namespace after
{
struct StateBroadcaster
{
    StateBroadcaster(
        CommunicationManager&
            communicationManager /*, SerialPortClient& serialPortClient */);
    // If we need a SerialPortClient then we should consider to inject it

    void broadcast();
    void emergencyBroadcast();

private:
    CommunicationManager& mCommunicationManager;
};
} // namespace after
#endif // CPP_REFACTORING_WEBINAR_STATEBROADCASTER_HPP
