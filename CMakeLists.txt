cmake_minimum_required(VERSION 2.6)
project(humming_distance)

add_executable(humming_distance main.cpp)

set (CMAKE_CXX_STANDARD 11)

install(TARGETS humming_distance RUNTIME DESTINATION bin)
