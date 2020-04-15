include_directories(include)
set(third_party_dir ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

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
