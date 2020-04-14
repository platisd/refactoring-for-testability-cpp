include_directories(include)

add_library(asioserialportclient src/AsioSerialPortClient.cpp)
add_library(mycommunicationmanager src/MyCommunicationManager.cpp)
add_library(statebroadcaster src/StateBroadcaster.cpp)

add_executable(DemeterBefore src/DemeterBefore.cpp)
target_link_libraries(DemeterBefore PRIVATE
        asioserialportclient
        mycommunicationmanager
        statebroadcaster)

add_executable(DemeterAfter src/DemeterAfter.cpp)
target_link_libraries(DemeterAfter PRIVATE
        asioserialportclient
        mycommunicationmanager
        statebroadcaster)
