include_directories(include)

add_library(asioserialportclient2 src/AsioSerialPortClient.cpp)
add_library(mycommunicationmanager2 src/MyCommunicationManager.cpp)
target_compile_definitions(mycommunicationmanager2 PRIVATE BAR_PRODUCT)

add_executable(PlatformBefore src/PlatformBefore.cpp)
target_link_libraries(PlatformBefore PRIVATE
        asioserialportclient2
        mycommunicationmanager2)

add_library(fooserialformatter src/FooSerialFormatter.cpp)
add_library(barserialformatter src/BarSerialFormatter.cpp)

add_executable(PlatformAfter src/PlatformAfter.cpp)
target_link_libraries(PlatformAfter PRIVATE
        asioserialportclient2
        mycommunicationmanager2
        fooserialformatter
        barserialformatter)
