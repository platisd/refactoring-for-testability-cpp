#include "MockCommunicationManager.hpp"
#include "StateBroadcaster.hpp"
#include "gtest/gtest.h"

using namespace testing;
using namespace after;

struct StateBroadcasterTest : public Test
{
    MockCommunicationManager mCommunicationManager;
    StateBroadcaster mStateBroadcaster{mCommunicationManager};
};

TEST_F(StateBroadcasterTest, broadcast_WhenCalled_WillSendViaSerial)
{
    EXPECT_CALL(mCommunicationManager, sendViaSerial(_));
    mStateBroadcaster.broadcast();
}

TEST_F(StateBroadcasterTest, emergencyBroadcast_WhenCalled_WillSendViaRawSerial)
{
    EXPECT_CALL(mCommunicationManager, sendViaRawSerial(_));
    mStateBroadcaster.emergencyBroadcast();
}
