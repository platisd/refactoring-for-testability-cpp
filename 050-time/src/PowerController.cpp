#include "PowerController.hpp"
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

namespace
{
const auto kPin                = 42;
const auto kTimeBetweenPulses  = 1s;
const auto kTimeToWaitForPulse = 10s;
} // namespace

namespace before
{
PowerController::PowerController(PinManager& pinManager,
                                 InterruptManager& interruptManager)
    : mPinManager{pinManager}
{
    interruptManager.triggerOnChange(kPin, [this](bool pinSet) {
        if (pinSet)
        {
            mPulseReceived = true;
            mConditionVariable.notify_one();
        }
    });
}

bool PowerController::turnOn()
{
    mPinManager.setPin(kPin);
    std::this_thread::sleep_for(kTimeBetweenPulses);
    mPinManager.clearPin(kPin);

    std::unique_lock<std::mutex> lk(mRunnerMutex);
    std::cout << "Waiting for response" << std::endl;
    mConditionVariable.wait_for(
        lk, kTimeToWaitForPulse, [this]() { return mPulseReceived.load(); });

    return mPulseReceived.load();
}
} // namespace before

namespace after
{
PowerController::PowerController(PinManager& pinManager,
                                 InterruptManager& interruptManager,
                                 AsynchronousTimer& asynchronousTimer,
                                 TimeKeeper& timeKeeper)
    : mPinManager{pinManager}
    , mAsynchronousTimer{asynchronousTimer}
    , mTimeKeeper{timeKeeper}
{
    interruptManager.triggerOnChange(kPin, [this](bool pinSet) {
        if (pinSet)
        {
            mPulseReceived = true;
            mConditionVariable.notify_one();
        }
    });
}

bool PowerController::turnOn()
{
    mPinManager.setPin(kPin);
    mTimeKeeper.sleepFor(kTimeBetweenPulses);
    mPinManager.clearPin(kPin);

    mAsynchronousTimer.schedule(
        [this]() {
            mPulseTimedOut = true;
            mConditionVariable.notify_one();
        },
        kTimeToWaitForPulse);

    std::unique_lock<std::mutex> lk(mRunnerMutex);
    std::cout << "Waiting for response" << std::endl;
    mConditionVariable.wait(lk, [this]() {
        return mPulseReceived.load() || mPulseTimedOut.load();
    });

    mAsynchronousTimer.abort();
    mPulseTimedOut = false;

    return mPulseReceived.load();
}
} // namespace after
