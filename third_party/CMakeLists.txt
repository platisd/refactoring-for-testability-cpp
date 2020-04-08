include_directories(include)

find_package(CURL REQUIRED)
add_library(curldownloader src/CurlDownloader.cpp)
target_link_libraries(curldownloader PRIVATE ${CURL_LIBRARIES})

add_library(platissolutionsbenchmarker src/PlatisSolutionsBenchmarker.cpp)
target_link_libraries(platissolutionsbenchmarker PRIVATE ${CURL_LIBRARIES})

add_executable(ThirdPartyBefore src/ThirdPartyBefore.cpp)
target_link_libraries(ThirdPartyBefore PRIVATE
        curldownloader
        platissolutionsbenchmarker)

add_executable(ThirdPartyAfter src/ThirdPartyAfter.cpp)
target_link_libraries(ThirdPartyAfter PRIVATE
        curldownloader
        platissolutionsbenchmarker)
