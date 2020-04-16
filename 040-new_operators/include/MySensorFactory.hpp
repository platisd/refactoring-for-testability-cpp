#ifndef CPP_REFACTORING_FOR_TESTABILITY_MYSENSORFACTORY_HPP
#define CPP_REFACTORING_FOR_TESTABILITY_MYSENSORFACTORY_HPP

#include "SensorFactory.hpp"

struct MySensorFactory : public SensorFactory
{
    std::unique_ptr<Sensor> getSensor(SensorType sensorType) const override;
};

#endif // CPP_REFACTORING_FOR_TESTABILITY_MYSENSORFACTORY_HPP
