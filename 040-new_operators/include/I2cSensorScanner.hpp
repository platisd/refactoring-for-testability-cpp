#ifndef CPP_REFACTORING_WEBINAR_I2CSENSORSCANNER_HPP
#define CPP_REFACTORING_WEBINAR_I2CSENSORSCANNER_HPP

#include "SensorScanner.hpp"

struct I2cSensorScanner : public SensorScanner
{
    std::vector<SensorIdentifier> scan() const override;
};

#endif // CPP_REFACTORING_WEBINAR_I2CSENSORSCANNER_HPP
