#include "DirectionalOdometer.hpp"
#include "DirectionlessOdometer.hpp"
#include "MockEncoder.hpp"
#include "MockInterruptServiceManager.hpp"
#include "MockPinReader.hpp"
#include "gtest/gtest.h"
#include <memory>

using namespace testing;
using namespace after;

namespace
{
const auto kPulsePin     = 123;
const auto kDirectionPin = 643;
} // namespace

struct DirectionlessOdometerConstructorTest : public Test
{
    MockEncoder mEncoder;
    MockInterruptServiceManager mInterruptServiceManager;
};

struct DirectionlessOdometerTest : public Test
{
    void SetUp() override
    {
        EXPECT_CALL(mInterruptServiceManager, triggerOnNewPulse(_, _))
            .WillOnce(SaveArg<1>(&mInterruptRoutine));

        mOdometer = std::make_unique<DirectionlessOdometer>(
            mEncoder, mInterruptServiceManager, kPulsePin);
    }

    MockEncoder mEncoder;
    MockInterruptServiceManager mInterruptServiceManager;
    std::unique_ptr<DirectionlessOdometer> mOdometer;
    std::function<void()> mInterruptRoutine;
};

TEST_F(DirectionlessOdometerConstructorTest,
       constructor_WhenCalled_WillRegisterInterruptForPulsePin)
{
    EXPECT_CALL(mInterruptServiceManager, triggerOnNewPulse(kPulsePin, _));

    DirectionlessOdometer odometer{
        mEncoder, mInterruptServiceManager, kPulsePin};
}

TEST_F(DirectionlessOdometerTest,
       getDistance_WhenCalled_WillReturnEncoderDistance)
{
    const auto distance = 12315;
    EXPECT_CALL(mEncoder, getDistance()).WillOnce(Return(distance));

    EXPECT_EQ(mOdometer->getDistance(), distance);
}

TEST_F(DirectionlessOdometerTest,
       interruptRoutine_WhenCalled_WillIncrementPulses)
{
    EXPECT_CALL(mEncoder, incrementPulses());
    mInterruptRoutine();
}

struct DirectionalOdometerConstructorTest : public Test
{
    MockEncoder mEncoder;
    MockInterruptServiceManager mInterruptServiceManager;
    MockPinReader mPinReader;
};

struct DirectionalOdometerTest : public Test
{
    void SetUp() override
    {
        EXPECT_CALL(mInterruptServiceManager, triggerOnNewPulse(_, _))
            .WillOnce(SaveArg<1>(&mInterruptRoutine));

        mOdometer
            = std::make_unique<DirectionalOdometer>(mEncoder,
                                                    mInterruptServiceManager,
                                                    mPinReader,
                                                    kDirectionPin,
                                                    kPulsePin);
    }

    MockEncoder mEncoder;
    MockInterruptServiceManager mInterruptServiceManager;
    MockPinReader mPinReader;
    std::unique_ptr<DirectionalOdometer> mOdometer;
    std::function<void()> mInterruptRoutine;
};

TEST_F(DirectionalOdometerConstructorTest,
       constructor_WhenCalled_WillRegisterInterruptForPulsePin)
{
    EXPECT_CALL(mInterruptServiceManager, triggerOnNewPulse(kPulsePin, _));

    DirectionalOdometer odometer{mEncoder,
                                 mInterruptServiceManager,
                                 mPinReader,
                                 kDirectionPin,
                                 kPulsePin};
}

TEST_F(DirectionalOdometerTest,
       getDistance_WhenCalled_WillReturnEncoderDistance)
{
    const auto distance = 12315;
    EXPECT_CALL(mEncoder, getDistance()).WillOnce(Return(distance));

    EXPECT_EQ(mOdometer->getDistance(), distance);
}

TEST_F(DirectionalOdometerTest,
       interruptRoutine_WhenDirectionPinSet_WillIncrementPulses)
{
    EXPECT_CALL(mEncoder, incrementPulses());
    EXPECT_CALL(mPinReader, read(kDirectionPin)).WillOnce(Return(true));
    mInterruptRoutine();
}

TEST_F(DirectionalOdometerTest,
       interruptRoutine_WhenDirectionPinClear_WillDecrementPulses)
{
    EXPECT_CALL(mEncoder, decrementPulses());
    EXPECT_CALL(mPinReader, read(kDirectionPin)).WillOnce(Return(false));
    mInterruptRoutine();
}
