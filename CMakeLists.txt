cmake_minimum_required(VERSION 3.1)
project(humming_distance)

add_executable(humming_distance main.cpp)

ADD_DEFINITIONS(-std=c++11)

install(TARGETS humming_distance RUNTIME DESTINATION bin)
