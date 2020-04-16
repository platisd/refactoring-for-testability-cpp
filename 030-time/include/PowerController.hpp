#ifndef CPP_REFACTORING_FOR_TESTABILITY_POWERCONTROLLER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_POWERCONTROLLER_HPP

#include "AsynchronousTimer.hpp"
#include "InterruptManager.hpp"
#include "PinManager.hpp"
#include "TimeKeeper.hpp"
#include <atomic>
#include <condition_variable>
#include <mutex>

namespace before
{

struct PowerController
{
    PowerController(PinManager& pinManager, InterruptManager& interruptManager);

    bool turnOn();

private:
    PinManager& mPinManager;

    std::condition_variable mConditionVariable;
    std::atomic<bool> mPulseReceived{false};
    std::mutex mRunnerMutex;
};
} // namespace before

namespace after
{
struct PowerController
{
    PowerController(PinManager& pinManager,
                    InterruptManager& interruptManager,
                    AsynchronousTimer& asynchronousTimer,
                    TimeKeeper& timeKeeper);

    bool turnOn();

private:
    PinManager& mPinManager;
    AsynchronousTimer& mAsynchronousTimer;
    TimeKeeper& mTimeKeeper;

    std::condition_variable mConditionVariable;
    std::atomic<bool> mPulseReceived{false};
    std::atomic<bool> mPulseTimedOut{false};
    std::mutex mRunnerMutex;
};
} // namespace after
#endif // CPP_REFACTORING_FOR_TESTABILITY_POWERCONTROLLER_HPP
