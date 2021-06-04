
add_library(
    helloLib
    HelloLib/HelloWorld.h
    HelloLib/HelloWorld.cpp
)

add_library(
    subLib SHARED
    SubDirectoryFunction/makeDirectory.h
    SubDirectoryFunction/makeDirectory.cpp
)

# dependency library - link second order library to first library
target_link_libraries(helloLib PUBLIC subLib)

#Can't place this in front of add_libarary, need to include directory after specifying add_library,
target_include_directories(helloLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/HelloLib")
target_include_directories(subLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/SubDirectoryFunction")

