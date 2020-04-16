#ifndef CPP_REFACTORING_FOR_TESTABILITY_MYCOMMUNICATIONMANAGER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MYCOMMUNICATIONMANAGER_HPP

#include "CommunicationManager.hpp"
#include "SerialPortClient.hpp"

namespace before
{
struct MyCommunicationManager : public CommunicationManager
{
    MyCommunicationManager(SerialPortClient& serialPortClient);

    void sendViaSerial(std::string message) override;
    SerialPortClient& getSerialPortClient() const override;

private:
    SerialPortClient& mSerialPortClient;
    int mSequenceNumber{0};
};
} // namespace before

namespace after
{
struct MyCommunicationManager : public CommunicationManager
{
    MyCommunicationManager(SerialPortClient& serialPortClient);

    void sendViaSerial(std::string message) override;
    void sendViaRawSerial(std::string message) const override;

private:
    SerialPortClient& mSerialPortClient;
    int mSequenceNumber{0};
};
} // namespace after

#endif // CPP_REFACTORING_FOR_TESTABILITY_MYCOMMUNICATIONMANAGER_HPP
