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

add_subdirectory(time)
add_subdirectory(hardcoded_dependencies)
add_subdirectory(third_party)
add_subdirectory(files)
add_subdirectory(new_operators)
add_subdirectory(law_of_demeter)
add_subdirectory(domain_dependent_on_application)
