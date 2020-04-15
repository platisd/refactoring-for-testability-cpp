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

function(configure_test testExecutable)
    # Include mock directory
    target_include_directories(${testExecutable} PRIVATE ${mocks})
    # Link against gtest library
    target_link_libraries(${testExecutable} gtest gtest_main gmock_main)
    # Add gcov style coverage
    target_compile_options(${testExecutable} PUBLIC -O0 --coverage)
    target_link_options(${testExecutable} PUBLIC --coverage)
    # Create test name as the capitalized form of the test executable
    string(TOUPPER ${testExecutable} testName)
    # Add executable to test suite
    add_test(${testName} ${testExecutable} ${GTEST_RUN_FLAGS})
endfunction(configure_test)

# FileEncoder test
add_executable(fileencoder_test
        ${files_dir}/src/FileEncoder
        ${unit_tests}/FileEncoder_test.cpp)
target_include_directories(fileencoder_test PUBLIC
        ${files_dir}/include)
configure_test(fileencoder_test)
