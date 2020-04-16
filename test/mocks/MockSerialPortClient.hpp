#ifndef CPP_REFACTORING_FOR_TESTABILITY_MOCKSERIALPORTCLIENT_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MOCKSERIALPORTCLIENT_HPP

#include "SerialPortClient.hpp"
#include "gmock/gmock.h"

class MockSerialPortClient : public SerialPortClient
{
public:
    MOCK_METHOD(void, send, (std::string message), (const, override));
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MOCKSERIALPORTCLIENT_HPP
