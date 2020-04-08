#include "SingleTaskAsynchronousTimer.hpp"

SingleTaskAsynchronousTimer::~SingleTaskAsynchronousTimer()
{
    abortTaskAndWaitForThreadToExit();
}

void SingleTaskAsynchronousTimer::schedule(std::function<void()> task,
                                           std::chrono::seconds delay)
{
    std::lock_guard<std::mutex> lock(mSchedulerMutex);
    if (!task)
    {
        return;
    }
    if (hasPendingTask())
    {
        abort();
    }
    // If we reached this point, there should be no previous task running
    mPendingTask = true;
    mShouldAbort = false;

    mRunner = std::async(std::launch::async, [task, delay, this]() {
        std::unique_lock<std::mutex> lk(mTimerMutex);
        mConditionVariable.wait_for(
            lk, delay, [this]() { return mShouldAbort.load(); });
        if (!mShouldAbort.load())
        {
            task();
        }
        mPendingTask = false;
    });
}

bool SingleTaskAsynchronousTimer::hasPendingTask() const
{
    return mPendingTask.load();
}

void SingleTaskAsynchronousTimer::abort()
{
    abortTaskAndWaitForThreadToExit();
}

void SingleTaskAsynchronousTimer::abortTaskAndWaitForThreadToExit()
{
    if (!mPendingTask.load())
    {
        return;
    }
    mShouldAbort = true;
    mConditionVariable.notify_all();

    mRunner.wait();
    mRunner.get();
}
