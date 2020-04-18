# Adopted from https://github.com/google/googletest/blob/master/googletest/README.md
# Download and unpack googletest at configure time
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif ()

# GTest and GMock do not play nicely with these flags, so disable them
target_compile_options(gtest PRIVATE
        -Wno-ctor-dtor-privacy
        -Wno-missing-include-dirs)
target_compile_options(gmock PRIVATE -Wno-pedantic)

# ========= Unit test configurations =========
enable_testing()
set(unit_tests ${CMAKE_CURRENT_SOURCE_DIR}/ut)
set(mocks ${CMAKE_CURRENT_SOURCE_DIR}/mocks)
set(gtest_run_flags --gtest_color=yes --gtest_repeat=5 --gtest_shuffle)

function(configure_test testExecutable)
    # Include mock directory
    target_include_directories(${testExecutable} PRIVATE ${mocks})
    # Link against gtest library
    target_link_libraries(${testExecutable} PRIVATE gtest gtest_main gmock_main)
    # Disable variadic macro warnings (can be a problem when compiling with Clang)
    target_compile_options(${testExecutable} PRIVATE -Wno-gnu-zero-variadic-macro-arguments)
    # Add gcov style coverage
    target_compile_options(${testExecutable} PUBLIC -O0 --coverage)
    target_link_options(${testExecutable} PUBLIC --coverage)
    # Create test name as the capitalized form of the test executable
    string(TOUPPER ${testExecutable} testName)
    # Add executable to test suite
    add_test(${testName} ${testExecutable} ${gtest_run_flags})
endfunction(configure_test)

# FileEncoder test
add_executable(fileencoder_test
        ${files_dir}/src/FileEncoder.cpp
        ${unit_tests}/FileEncoder_test.cpp)
target_include_directories(fileencoder_test PUBLIC
        ${files_dir}/include)
configure_test(fileencoder_test)

# Odometers test
# Let's include tests for both in the same file so to have all
# examples from a specific thematic tested together
add_executable(odometers_test
        ${hardcoded_dependencies_dir}/src/DirectionlessOdometer.cpp
        ${hardcoded_dependencies_dir}/src/DirectionalOdometer.cpp
        ${unit_tests}/Odometers_test.cpp)
target_include_directories(odometers_test PUBLIC
        ${hardcoded_dependencies_dir}/include)
configure_test(odometers_test)
# You should not normally link to unrelated (and possibly untestable)
# classes. However, in this case, since we the code before the
# refactoring in the same file (for the sake of simplicity) we need
# to link to those extra libraries to get everything to compile.
# Typically, this would be an indication of bad design and code smells.
target_link_libraries(odometers_test PRIVATE
        myinterruptservicemanager
        mypinreader)

# PlatisSolutionsBenchmarker test
add_executable(platissolutionsbenchmarker_test
        ${third_party_dir}/src/PlatisSolutionsBenchmarker.cpp
        ${unit_tests}/PlatisSolutionsBenchmarker_test.cpp)
target_include_directories(platissolutionsbenchmarker_test PUBLIC
        ${third_party_dir}/include)
configure_test(platissolutionsbenchmarker_test)
# We should not pull third party libraries (e.g. curl) in our tests
# but since in this case, for the sake of the example, we have
# the `before` and `after` namespaces in the same file, we need
# to get both compiled. Both the "good" and the "bad" way.
# In fact, pulling third party libraries, which are supposed to
# be abstracted out in the tests, is a sign you do things wrong.
find_package(CURL REQUIRED)
target_link_libraries(platissolutionsbenchmarker_test PRIVATE ${CURL_LIBRARIES})

# PowerController test
add_executable(powercontroller_test
        ${time_dir}/src/PowerController.cpp
        ${unit_tests}/PowerController_test.cpp)
target_include_directories(powercontroller_test PUBLIC
        ${time_dir}/include)
configure_test(powercontroller_test)

# SensorManager test
add_executable(sensormanager_test
        ${new_operators_dir}/src/SensorManager.cpp
        ${unit_tests}/SensorManager_test.cpp)
target_include_directories(sensormanager_test PUBLIC
        ${new_operators_dir}/include)
configure_test(sensormanager_test)
# You should normally not be pulling in untestable resources such as
# the concrete sensor classes that are supposed to be abstracted out
# and are irrelevant to the unit under test. Here we have to link
# towards them since, for the sake of the example, they are used by
# the SensorManager version *before* the refactoring which lies in the
# same file as the new version. In fact, having to link with irrelevant
# resources is a strong indicator that there is a problem.
target_link_libraries(sensormanager_test PRIVATE
        infraredsensor
        ultrasonicsensor
        lasersensor)

# StateBroadcaster test
add_executable(statebroadcaster_test
        ${law_of_demeter_dir}/src/StateBroadcaster.cpp
        ${unit_tests}/StateBroadcaster_test.cpp)
target_include_directories(statebroadcaster_test PUBLIC
        ${law_of_demeter_dir}/include)
configure_test(statebroadcaster_test)

# CommunicationManager test
add_executable(communicationmanager_test
        ${domain_dependent_on_application_dir}/src/CommunicationManager.cpp
        ${unit_tests}/CommunicationManager_test.cpp)
target_include_directories(communicationmanager_test PUBLIC
        ${domain_dependent_on_application_dir}/include)
configure_test(communicationmanager_test)
# You normally should not include specific project details in your test
# fixtures or have general/domain logic dependent on specific/application
# logic. In our case, for the sake of the example, we have `before` and
# `after` namespaces in the same file and therefore need to make sure
# everything compiles. This should typically be considered a smell.
target_compile_definitions(communicationmanager_test PRIVATE BAR_PRODUCT)

# CounterManager test
add_executable(countermanager_test
        ${singletons_dir}/src/CounterManager.cpp
        ${unit_tests}/CounterManager_test.cpp)
target_include_directories(countermanager_test PUBLIC
        ${singletons_dir}/include)
configure_test(countermanager_test)