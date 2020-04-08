cmake_minimum_required(VERSION 3.12)
project(cpp-refactoring-webinar)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(
        -Wcast-align
        -Wpedantic
        -Wcast-qual
        -Wconversion
        -Wctor-dtor-privacy
        -Wnon-virtual-dtor
        -Wmissing-include-dirs
        -Wdisabled-optimization
        -Winit-self
        -Wnon-virtual-dtor
        -Wold-style-cast
        -Woverloaded-virtual
        -Wparentheses
        -Wredundant-decls
        -Wshadow
        -Wsign-promo
        -Wstrict-aliasing
        -Wall
        -Wextra
        -Werror
)

add_subdirectory(030-time)
add_subdirectory(050-hardcoded_dependencies)
add_subdirectory(020-third_party)
add_subdirectory(010-files)
add_subdirectory(040-new_operators)
add_subdirectory(060-law_of_demeter)
add_subdirectory(070-domain_dependent_on_application)
