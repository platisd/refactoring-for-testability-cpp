include_directories(include)
set(singletons_dir ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

add_library(countersingleton src/CounterSingleton.cpp)
add_library(commoncounter src/CommonCounter.cpp)
target_link_libraries(commoncounter PRIVATE countersingleton)

add_executable(SingletonBefore src/SingletonBefore.cpp)
target_link_libraries(SingletonBefore PRIVATE countersingleton)

add_library(countermanager src/CounterManager.cpp)

add_executable(SingletonAfter src/SingletonAfter.cpp)
target_link_libraries(SingletonAfter PRIVATE
        countersingleton
        commoncounter
        countermanager)

add_executable(SingletonAfterAlternative src/SingletonAfterAlternative.cpp)
target_link_libraries(SingletonAfterAlternative PRIVATE
        countersingleton
        countermanager)