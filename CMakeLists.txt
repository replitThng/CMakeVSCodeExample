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

cmake_minimum_required(VERSION 3.12)
project(HELLOWORLDPROJ VERSION 1.0)

#sub directories to be added before add_executable
add_subdirectory(src)

add_executable(logicsComponent main.cpp)

#specify target_link libraries after add_executable only.
target_link_libraries(logicsComponent PRIVATE helloLib)
