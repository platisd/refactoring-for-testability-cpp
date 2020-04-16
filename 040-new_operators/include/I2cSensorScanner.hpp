#ifndef CPP_REFACTORING_FOR_TESTABILITY_I2CSENSORSCANNER_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_I2CSENSORSCANNER_HPP

#include "SensorScanner.hpp"

struct I2cSensorScanner : public SensorScanner
{
    std::vector<SensorIdentifier> scan() const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_I2CSENSORSCANNER_HPP
