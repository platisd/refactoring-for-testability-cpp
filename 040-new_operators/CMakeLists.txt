include_directories(include)

add_library(infraredsensor src/InfraredSensor.cpp)
add_library(ultrasonicsensor src/UltrasonicSensor.cpp)
add_library(lasersensor src/LaserSensor.cpp)
add_library(i2csensorscanner src/I2cSensorScanner.cpp)
add_library(oldsensormanager src/SensorManager.cpp)
target_link_libraries(oldsensormanager PRIVATE
        infraredsensor
        ultrasonicsensor
        lasersensor)

add_executable(NewOperatorsBefore src/NewOperatorsBefore.cpp)
target_link_libraries(NewOperatorsBefore PRIVATE
        i2csensorscanner
        oldsensormanager)

add_library(mysensorfactory src/MySensorFactory.cpp)
target_link_libraries(mysensorfactory PRIVATE
        infraredsensor
        ultrasonicsensor
        lasersensor)
add_library(newsensormanager src/SensorManager.cpp)
target_link_libraries(newsensormanager PRIVATE
        mysensorfactory)

add_executable(NewOperatorsAfter src/NewOperatorsAfter.cpp)
target_link_libraries(NewOperatorsAfter PRIVATE
        i2csensorscanner
        newsensormanager)
