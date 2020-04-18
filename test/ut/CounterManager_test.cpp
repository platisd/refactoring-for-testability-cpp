#include "CounterManager.hpp"
#include "MockCounter.hpp"
#include "gtest/gtest.h"

using namespace testing;

namespace
{
const auto kNumberToReach = 5213;
}

struct CounterManagerTest : public Test
{
    MockCounter mCounter;
    CounterManager mCounterManager{mCounter};
};

TEST_F(CounterManagerTest,
       countTo_WhenNumberSmallerThanCounter_WillIncrementUntilNumberIsReached)
{
    EXPECT_CALL(mCounter, get())
        .WillOnce(Return(kNumberToReach - 1))
        .WillOnce(Return(kNumberToReach - 1))
        .WillOnce(Return(kNumberToReach));
    EXPECT_CALL(mCounter, increment());

    mCounterManager.countTo(kNumberToReach);
}

TEST_F(CounterManagerTest,
       countTo_WhenNumberLargerThanCounter_WillDecrementUntilNumberIsReached)
{
    EXPECT_CALL(mCounter, get())
        .WillOnce(Return(kNumberToReach + 1))
        .WillOnce(Return(kNumberToReach + 1))
        .WillOnce(Return(kNumberToReach));
    EXPECT_CALL(mCounter, decrement());

    mCounterManager.countTo(kNumberToReach);
}

TEST_F(CounterManagerTest,
       countTo_WhenNumberSameWithCounter_WillNotDecrementOrIncrement)
{
    EXPECT_CALL(mCounter, get())
        .WillOnce(Return(kNumberToReach))
        .WillOnce(Return(kNumberToReach));
    EXPECT_CALL(mCounter, increment()).Times(0);
    EXPECT_CALL(mCounter, decrement()).Times(0);

    mCounterManager.countTo(kNumberToReach);
}