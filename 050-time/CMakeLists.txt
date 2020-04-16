include_directories(include)
set(time_dir ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

add_library(myinterruptmanager src/MyInterruptManager.cpp)
add_library(mypinmanager src/MyPinManager.cpp)
add_library(powercontroller src/PowerController.cpp)

add_executable(TimeBefore src/TimeBefore.cpp)
target_link_libraries(TimeBefore PRIVATE
        myinterruptmanager
        mypinmanager
        powercontroller)

add_library(singletaskasynchronoustimer src/SingleTaskAsynchronousTimer.cpp)
target_link_libraries(singletaskasynchronoustimer PRIVATE pthread)
add_library(mytimekeeper src/MyTimeKeeper.cpp)

add_executable(TimeAfter src/TimeAfter.cpp)
target_link_libraries(TimeAfter PRIVATE
        myinterruptmanager
        mypinmanager
        singletaskasynchronoustimer
        mytimekeeper
        powercontroller)
