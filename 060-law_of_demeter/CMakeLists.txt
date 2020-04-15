include_directories(include)
set(law_of_demeter_dir ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

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
