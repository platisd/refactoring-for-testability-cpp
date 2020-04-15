#ifndef CPP_REFACTORING_WEBINAR_MOCKSENSORFACTORY_HPP
#define CPP_REFACTORING_WEBINAR_MOCKSENSORFACTORY_HPP

#include "SensorFactory.hpp"
#include "gmock/gmock.h"

class MockSensorFactory : public SensorFactory
{
public:
    MOCK_METHOD(std::unique_ptr<Sensor>,
                getSensor,
                (SensorType sensorType),
                (const, override));
};

#endif // CPP_REFACTORING_WEBINAR_MOCKSENSORFACTORY_HPP
