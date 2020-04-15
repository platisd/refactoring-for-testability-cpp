#include "MockSensor.hpp"
#include "MockSensorFactory.hpp"
#include "MockSensorScanner.hpp"
#include "SensorManager.hpp"
#include "gtest/gtest.h"
#include <memory>

using namespace testing;
using namespace after;

using identifierToType = std::pair<SensorIdentifier, SensorType>;
const std::vector identifierToTypePairs{
    identifierToType{SensorIdentifier::InfraredSensor, SensorType::Infrared},
    identifierToType{SensorIdentifier::LaserSensor, SensorType::Laser},
    identifierToType{SensorIdentifier::UltrasonicSensor,
                     SensorType::Ultrasonic}};

struct SensorManagerConstructorTest : public TestWithParam<identifierToType>
{
    void SetUp() override
    {
        std::tie(mSensorIdentifier, mSensorType) = GetParam();
    }

    MockSensorScanner mSensorScanner;
    MockSensorFactory mSensorFactory;
    SensorIdentifier mSensorIdentifier;
    SensorType mSensorType;
};

struct SensorManagerTest : public Test
{
    void SetUp() override
    {
        const std::vector scanResults{SensorIdentifier::UltrasonicSensor,
                                      SensorIdentifier::InfraredSensor};
        EXPECT_CALL(mSensorScanner, scan()).WillOnce(Return(scanResults));

        auto sensor1OwningPointer = std::make_unique<MockSensor>();
        auto sensor2OwningPointer = std::make_unique<MockSensor>();
        // Get a local non-owning pointer of the mocks
        mSensor1 = sensor1OwningPointer.get();
        mSensor2 = sensor2OwningPointer.get();

        EXPECT_CALL(mSensorFactory, getSensor(_))
            .WillOnce(Return(ByMove(std::move(sensor1OwningPointer))))
            .WillOnce(Return(ByMove(std::move(sensor2OwningPointer))));

        mSensorManager
            = std::make_unique<SensorManager>(mSensorScanner, mSensorFactory);
    }

    MockSensorScanner mSensorScanner;
    MockSensorFactory mSensorFactory;
    std::unique_ptr<SensorManager> mSensorManager;
    MockSensor* mSensor1;
    MockSensor* mSensor2;
    MockSensor* mSensor3;
};

TEST_P(SensorManagerConstructorTest, constructor_WhenCalled_WillScanForSensors)
{
    EXPECT_CALL(mSensorScanner, scan());

    SensorManager sensorManager{mSensorScanner, mSensorFactory};
}

INSTANTIATE_TEST_SUITE_P(ValidIdentifiers,
                         SensorManagerConstructorTest,
                         ValuesIn(identifierToTypePairs));

TEST_P(SensorManagerConstructorTest,
       constructor_WhenSensorScanned_WillGetCorrectSensor)
{
    EXPECT_CALL(mSensorScanner, scan())
        .WillOnce(Return(std::vector{mSensorIdentifier}));
    EXPECT_CALL(mSensorFactory, getSensor(mSensorType));

    SensorManager sensorManager{mSensorScanner, mSensorFactory};
}

TEST_P(SensorManagerConstructorTest,
       constructor_WhenInvalidSensorScanned_WillCrash)
{
    const auto invalidSensor = static_cast<SensorIdentifier>(2131);
    EXPECT_CALL(mSensorScanner, scan())
        .WillOnce(Return(std::vector{invalidSensor}));

    EXPECT_ANY_THROW(SensorManager(mSensorScanner, mSensorFactory));
}

TEST_F(SensorManagerTest,
       getSurroundingDistances_WhenCalled_WillReturnDistances)
{
    const auto sensor1Distance = 54;
    const auto sensor2Distance = 123;
    EXPECT_CALL(*mSensor1, getDistance()).WillOnce(Return(sensor1Distance));
    EXPECT_CALL(*mSensor2, getDistance()).WillOnce(Return(sensor2Distance));

    const auto distances = mSensorManager->getSurroundingDistances();
    const std::vector expectedDistances{sensor1Distance, sensor2Distance};
    EXPECT_EQ(distances, expectedDistances);
}
