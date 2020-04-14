#ifndef CPP_REFACTORING_WEBINAR_SERIALPORTCLIENT_HPP
#define CPP_REFACTORING_WEBINAR_SERIALPORTCLIENT_HPP

#include <string>

struct SerialPortClient
{
    virtual ~SerialPortClient() = default;

    virtual void send(std::string message) const = 0;
};

#endif // CPP_REFACTORING_WEBINAR_SERIALPORTCLIENT_HPP
