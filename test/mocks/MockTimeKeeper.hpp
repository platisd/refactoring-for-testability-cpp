#ifndef CPP_REFACTORING_WEBINAR_MOCKTIMEKEEPER_HPP
#define CPP_REFACTORING_WEBINAR_MOCKTIMEKEEPER_HPP

#include "TimeKeeper.hpp"
#include "gmock/gmock.h"

class MockTimeKeeper : public TimeKeeper
{
public:
    MOCK_METHOD(void,
                sleepFor,
                (std::chrono::milliseconds delay),
                (const, override));
};

#endif // CPP_REFACTORING_WEBINAR_MOCKTIMEKEEPER_HPP
