#ifndef CPP_REFACTORING_FOR_TESTABILITY_SINGLETASKASYNCHRONOUSTIMER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_SINGLETASKASYNCHRONOUSTIMER_HPP

#include "AsynchronousTimer.hpp"
#include <atomic>
#include <condition_variable>
#include <future>
#include <mutex>

class SingleTaskAsynchronousTimer : public AsynchronousTimer
{
public:
    ~SingleTaskAsynchronousTimer();

    void schedule(std::function<void()> task,
                  std::chrono::seconds delay) override;
    bool hasPendingTask() const override;
    void abort() override;

private:
    std::atomic<bool> mPendingTask{false};
    std::atomic<bool> mShouldAbort{false};
    std::condition_variable mConditionVariable;
    std::mutex mTimerMutex;
    std::mutex mSchedulerMutex;
    std::future<void> mRunner;

    void abortTaskAndWaitForThreadToExit();
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_SINGLETASKASYNCHRONOUSTIMER_HPP
