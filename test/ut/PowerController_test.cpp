#include "MockAsynchronousTimer.hpp"
#include "MockInterruptManager.hpp"
#include "MockPinManager.hpp"
#include "MockTimeKeeper.hpp"
#include "PowerController.hpp"
#include "gtest/gtest.h"
#include <chrono>
#include <future>

using namespace testing;
using namespace after;
using namespace std::chrono_literals;

namespace
{
const auto kPulseArrived      = true;
const auto kPulseDidNotArrive = false;
} // namespace

struct PowerControllerConstructorTest : public Test
{
    MockPinManager mPinManager;
    MockInterruptManager mInterruptManager;
    MockAsynchronousTimer mAsynchronousTimer;
    MockTimeKeeper mTimeKeeper;
};

struct PowerControllerTest : public Test
{
    void SetUp() override
    {
        EXPECT_CALL(mInterruptManager, triggerOnChange(_, _))
            .WillOnce(SaveArg<1>(&mOnChangeInterrupt));

        mPowerController = std::make_unique<PowerController>(
            mPinManager, mInterruptManager, mAsynchronousTimer, mTimeKeeper);
    }

    MockPinManager mPinManager;
    MockInterruptManager mInterruptManager;
    MockAsynchronousTimer mAsynchronousTimer;
    MockTimeKeeper mTimeKeeper;
    std::unique_ptr<PowerController> mPowerController;
    std::function<void(bool)> mOnChangeInterrupt;
};

TEST_F(PowerControllerConstructorTest,
       constructor_WhenCalled_WillRegisterInterrupt /*OnCorrectPin*/)
{
    // You may choose to verify whether the *hardcoded* pin is correct if you
    // think it is really important for your test case (e.g. part of a
    // requirement). In that case, it's probably best if you expose this
    // variable via the PowerController header file instead of duplicating the
    // information as done here.
    const auto kPin = 42;
    EXPECT_CALL(mInterruptManager, triggerOnChange(kPin, _));

    PowerController powerController{
        mPinManager, mInterruptManager, mAsynchronousTimer, mTimeKeeper};
}

TEST_F(PowerControllerTest, turnOn_WhenCalled_WillSendPulse)
{
    {
        // Here depending on your requirements and business case, you may choose
        // to check if it is there correct pin and pulse duration that is used
        InSequence pulseSequence;
        EXPECT_CALL(mPinManager, setPin(_));
        EXPECT_CALL(mTimeKeeper, sleepFor(_));
        EXPECT_CALL(mPinManager, clearPin(_));
    }
    // To avoid getting blocked forever, let's induce a timeout by invoking the
    // pulse timeout function
    EXPECT_CALL(mAsynchronousTimer, schedule(_, _))
        .WillOnce(InvokeArgument<0>());

    mPowerController->turnOn();
}

TEST_F(PowerControllerTest,
       turnOn_WhenNoResponseReceivedBeforeTimeout_WillReturnFalse)
{
    EXPECT_CALL(mAsynchronousTimer, schedule(_, _))
        .WillOnce(InvokeArgument<0>());

    EXPECT_FALSE(mPowerController->turnOn());
}

TEST_F(PowerControllerTest, turnOn_WhenResponseReceived_WillReturnTrue)
{
    mOnChangeInterrupt(kPulseArrived);
    EXPECT_TRUE(mPowerController->turnOn());
}

TEST_F(PowerControllerTest, turnOn_WhenTimeoutScheduled_WillBeAbortedSoToReuse)
{
    EXPECT_CALL(mAsynchronousTimer, schedule(_, _))
        .WillOnce(InvokeArgument<0>());
    EXPECT_CALL(mAsynchronousTimer, abort());

    mPowerController->turnOn();
}

// Checking to if we *actually* block until we receive a pulse or we get a
// timeout is trickier, since it has to involve threads. Threads are
// non-deterministic therefore we should find a good trade-off between the
// repeatability of our test fixture and the time it takes to execute.
// Depending on your business logic you may choose to omit this test.
TEST_F(PowerControllerTest,
       turnOn_WhenWaitingForPulse_WillBlockUntilPulseIsReceived)
{
    // Launch the task asynchronously
    auto asynchronousTurnOn = std::async(
        std::launch::async, [this]() { return mPowerController->turnOn(); });
    // Give it some *reasonable* time to reach the point where it should block.
    // This is of course not guaranteed and therefore you need to choose between
    // how much non-deterministic behavior you would like and the execution
    // time of your tests. For example, if you would want to ensure that this
    // will *always* wait until the thread is blocked, then you can use a
    // large(r) duration as an argument to `wait_for`.
    const auto waitingForPulse = asynchronousTurnOn.wait_for(2ms);
    EXPECT_EQ(waitingForPulse, std::future_status::timeout);

    // By now, if the above expectation did not fail, we can be certain, to a
    // reasonable extent that the thread was blocked and is waiting for a pulse.
    // So let's give it one.
    mOnChangeInterrupt(kPulseArrived);
    EXPECT_TRUE(asynchronousTurnOn.get());
}

TEST_F(PowerControllerTest, turnOn_WhenWaitingForPulse_WillBlockUntilTimeout)
{
    std::function<void()> pulseTimedOut;
    EXPECT_CALL(mAsynchronousTimer, schedule(_, _))
        .WillOnce(SaveArg<0>(&pulseTimedOut));

    auto asynchronousTurnOn = std::async(
        std::launch::async, [this]() { return mPowerController->turnOn(); });
    const auto waitingForPulse = asynchronousTurnOn.wait_for(2ms);
    EXPECT_EQ(waitingForPulse, std::future_status::timeout);

    pulseTimedOut();
    EXPECT_FALSE(asynchronousTurnOn.get());
}

TEST_F(PowerControllerTest, turnOn_WhenWrongEndOfPulseReceived_WillNotUnblock)
{
    std::function<void()> pulseTimedOut;
    EXPECT_CALL(mAsynchronousTimer, schedule(_, _))
        .WillOnce(SaveArg<0>(&pulseTimedOut));

    auto asynchronousTurnOn = std::async(
        std::launch::async, [this]() { return mPowerController->turnOn(); });
    auto waitingForPulse = asynchronousTurnOn.wait_for(2ms);
    EXPECT_EQ(waitingForPulse, std::future_status::timeout);

    mOnChangeInterrupt(kPulseDidNotArrive);
    // Re-ensure we are still blocked and that the wrong pulse did not unblock
    // the thread
    waitingForPulse = asynchronousTurnOn.wait_for(2ms);
    EXPECT_EQ(waitingForPulse, std::future_status::timeout);

    pulseTimedOut();
    EXPECT_FALSE(asynchronousTurnOn.get());
}
