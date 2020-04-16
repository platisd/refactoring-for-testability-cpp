#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKASYNCHRONOUSTIMER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKASYNCHRONOUSTIMER_HPP

#include "AsynchronousTimer.hpp"
#include "gmock/gmock.h"

class MockAsynchronousTimer : public AsynchronousTimer
{
public:
    MOCK_METHOD(void,
                schedule,
                (std::function<void()> task, std::chrono::seconds delay),
                (override));
    MOCK_METHOD(bool, hasPendingTask, (), (const, override));
    MOCK_METHOD(void, abort, (), (override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKASYNCHRONOUSTIMER_HPP
