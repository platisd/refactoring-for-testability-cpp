#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKCOMMUNICATIONMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKCOMMUNICATIONMANAGER_HPP

#include "CommunicationManager.hpp"
#include "gmock/gmock.h"

namespace after
{
class MockCommunicationManager : public CommunicationManager
{
public:
    MOCK_METHOD(void, sendViaSerial, (std::string message), (override));
    MOCK_METHOD(void,
                sendViaRawSerial,
                (std::string message),
                (const, override));
};
} // namespace after

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKCOMMUNICATIONMANAGER_HPP
