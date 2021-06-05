message("-- PROJECT_BINARY_DIR : " ${PROJECT_BINARY_DIR})
message("-- CMAKE_BINARY_DIR : " ${CMAKE_BINARY_DIR} )
message("-- CMAKE_SOURCE_DIR : " ${CMAKE_SOURCE_DIR} )
message("-- CMAKE_LIBRARY_OUTPUT_DIRECTORY : " ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
message("-- CMAKE_RUNTIME_OUTPUT_DIRECTORY : "  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# The directories specified with the link_directories are applied only to targets created after the command. 
# Therefore, it is important to use this command before add_library or add_executable.
##link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

add_library(
    helloLib STATIC
    HelloLib/HelloWorld.h
    HelloLib/HelloWorld.cpp
)

add_library(
    subLib SHARED
    SubDirectoryFunction/makeDirectory.h
    SubDirectoryFunction/makeDirectory.cpp
)
# export modules for windows
if(WIN32)
add_definitions(-DGENERAL_FUNCTIONS_EXPORT)
endif()

# dependency library - link second order library to first library
target_link_libraries(helloLib PUBLIC subLib)

#Can't place this in front of add_libarary, need to include directory after specifying add_library,
target_include_directories(helloLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/HelloLib")
target_include_directories(subLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/SubDirectoryFunction")

