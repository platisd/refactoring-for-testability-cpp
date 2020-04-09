include_directories(include)

add_library(mypinreader src/MyPinReader.cpp)
add_library(myinterruptservicemanager src/MyInterruptServiceManager.cpp)
add_library(directionlessodometer src/DirectionlessOdometer.cpp)
add_library(directionalodometer src/DirectionalOdometer.cpp)

add_executable(HardcodedDependenciesBefore src/HardcodedDependenciesBefore.cpp)
target_link_libraries(HardcodedDependenciesBefore PRIVATE
        mypinreader
        myinterruptservicemanager
        directionlessodometer
        directionalodometer)

add_library(pulsestometerencoder src/PulsesToMetersEncoder.cpp)

add_executable(HardcodedDependenciesAfter src/HardcodedDependenciesAfter.cpp)
target_link_libraries(HardcodedDependenciesAfter PRIVATE
        mypinreader
        myinterruptservicemanager
        pulsestometerencoder
        directionlessodometer
        directionalodometer)
