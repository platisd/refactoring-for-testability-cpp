#include "CommunicationManager.hpp"
#include "MockSerialFormatter.hpp"
#include "MockSerialPortClient.hpp"
#include "gtest/gtest.h"

using namespace testing;
using namespace after;

struct CommunicationManagerTest : public Test
{
    MockSerialPortClient mSerialPortClient;
    MockSerialFormatter mSerialFormatter;
    CommunicationManager mCommunicationManager{mSerialPortClient,
                                               mSerialFormatter};
};

TEST_F(CommunicationManagerTest,
       sendViaSerial_WhenCalled_WillSendFormattedMessage)
{
    const auto message = "( ͡°( ͡° ͜ʖ( ͡° ͜ʖ ͡°)ʖ ͡°) ͡°)";
    const auto formattedMessage = "(ง ͠° ͟ل͜ ͡°)ง";
    EXPECT_CALL(mSerialFormatter, format(message))
        .WillOnce(Return(formattedMessage));
    EXPECT_CALL(mSerialPortClient, send(formattedMessage));

    mCommunicationManager.sendViaSerial(message);
}
