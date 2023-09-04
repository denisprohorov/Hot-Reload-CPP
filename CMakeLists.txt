cmake_minimum_required(VERSION 3.22)
project(hot_reloading)

set(CMAKE_CXX_STANDARD 23)

add_library(hot_reloading SHARED src/printer.cpp)
target_include_directories(hot_reloading PUBLIC include/)

add_library(hot_reloading2 SHARED src/printer2.cpp)
target_include_directories(hot_reloading2 PUBLIC include/)


add_executable(executable src/main.cpp)
target_include_directories(executable PRIVATE include/)
add_dependencies(executable hot_reloading hot_reloading2)

SET(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,${CMAKE_SOURCE_DIR}/build/")
