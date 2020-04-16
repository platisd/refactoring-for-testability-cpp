#ifndef CPP_REFACTORING_FOR_TESTABILITY_ASIOSERIALPORTCLIENT_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_ASIOSERIALPORTCLIENT_HPP

#include "SerialPortClient.hpp"

struct AsioSerialPortClient : public SerialPortClient
{
    AsioSerialPortClient(/* asio::serial_port& serialPort */);

    void send(std::string message) const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_ASIOSERIALPORTCLIENT_HPP
