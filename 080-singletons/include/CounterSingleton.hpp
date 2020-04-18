#ifndef CPP_REFACTORING_FOR_TESTABILITY_COUNTERSINGLETON_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_COUNTERSINGLETON_HPP

#include <Counter.hpp>
#include <atomic>

namespace before
{
struct CounterSingleton
{
    CounterSingleton(const CounterSingleton&) = delete;
    CounterSingleton(CounterSingleton&&)      = delete;
    CounterSingleton& operator=(const CounterSingleton&) = delete;
    CounterSingleton& operator=(CounterSingleton&&) = delete;

    void increment();
    void decrement();
    int get() const;

    static CounterSingleton& getInstance();

private:
    CounterSingleton() = default;

    std::atomic<int> mCounter{0};
};
} // namespace before

namespace after
{
struct CounterSingleton : public Counter
{
    CounterSingleton(const CounterSingleton&) = delete;
    CounterSingleton(CounterSingleton&&)      = delete;
    CounterSingleton& operator=(const CounterSingleton&) = delete;
    CounterSingleton& operator=(CounterSingleton&&) = delete;

    void increment() override;
    void decrement() override;
    int get() const override;

    static CounterSingleton& getInstance();

private:
    CounterSingleton() = default;

    std::atomic<int> mCounter{0};
};
} // namespace after
#endif // CPP_REFACTORING_FOR_TESTABILITY_COUNTERSINGLETON_HPP
