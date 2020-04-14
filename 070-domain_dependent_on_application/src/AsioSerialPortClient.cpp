#include "AsioSerialPortClient.hpp"
#include <iostream>

AsioSerialPortClient::AsioSerialPortClient(/* asio::serial_port& serialPort */)
{
    /* ... */
}

void AsioSerialPortClient::send(std::string message) const
{
    std::cout << message << std::endl;
}
