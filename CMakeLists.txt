# set vsvars.bat
# "c:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars32.bat"

# type "start ." in terminal to open explorer
# type "start" in terminal to open command prompt

# build using msbuild
# cmake ..
# cmake --build . --target logicsComponent

# build using ninja
# cmake -G Ninja -DCMAKE_C_COMPILER=cl -DCMAKE_CXX_COMPILER=cl ..
# ninja logicsComponent -v

# build using nmake and make
# cmake -G "NMake Makefiles" .. 
# nmake

cmake_minimum_required(VERSION 3.10)
project(HELLOWORLDPROJ VERSION 1.0)

# this cmake variable sets library output and runtime to the same as binary
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

#Test for win32
if(WIN32)
message("-- compile for windows")    
else()
message("-- compile for linux")
endif()

message("-- PROJECT_BINARY_DIR : " ${PROJECT_BINARY_DIR})
message("-- CMAKE_BINARY_DIR : " ${CMAKE_BINARY_DIR} )
message("-- CMAKE_SOURCE_DIR : " ${CMAKE_SOURCE_DIR} )
message("-- CMAKE_ARCHIVE_OUTPUT_DIRECTORY : " ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
message("-- CMAKE_LIBRARY_OUTPUT_DIRECTORY : " ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
message("-- CMAKE_RUNTIME_OUTPUT_DIRECTORY : "  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

#sub directories to be added before add_executable
add_subdirectory(src)

add_executable(logicsComponent main.cpp)

#specify target_link libraries after add_executable only.
target_link_libraries(logicsComponent PRIVATE helloLib)

