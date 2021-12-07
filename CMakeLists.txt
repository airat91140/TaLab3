cmake_minimum_required(VERSION 3.16)
project(lab3)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)
include_directories(src)

add_executable(lab3 main.cpp)

target_link_libraries(lab3 src)
