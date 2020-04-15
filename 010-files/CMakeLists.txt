include_directories(include)
set(files_dir ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

add_library(myfilereader src/MyFileReader.cpp)
add_library(myfilewriter src/MyFileWriter.cpp)

add_library(fileencoder src/FileEncoder.cpp)

add_executable(FilesBefore src/FilesBefore.cpp)
target_link_libraries(FilesBefore PRIVATE
        myfilereader
        myfilewriter
        fileencoder)

add_executable(FilesAfter src/FilesAfter.cpp)
target_link_libraries(FilesAfter PRIVATE
        myfilereader
        myfilewriter
        fileencoder)
