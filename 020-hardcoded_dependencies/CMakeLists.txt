include_directories(include)
set(hardcoded_dependencies_dir ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

add_library(mypinreader src/MyPinReader.cpp)
add_library(myinterruptservicemanager src/MyInterruptServiceManager.cpp)
add_library(directionlessodometer src/DirectionlessOdometer.cpp)
# After refactoring this would be removed
target_link_libraries(directionlessodometer PRIVATE myinterruptservicemanager)
add_library(directionalodometer src/DirectionalOdometer.cpp)
# After refactoring these would be removed
target_link_libraries(directionalodometer PRIVATE directionlessodometer)
target_link_libraries(directionalodometer PRIVATE mypinreader)

add_executable(HardcodedDependenciesBefore src/HardcodedDependenciesBefore.cpp)
target_link_libraries(HardcodedDependenciesBefore PRIVATE
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
