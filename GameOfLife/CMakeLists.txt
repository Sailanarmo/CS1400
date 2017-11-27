cmake_minimum_required(VERSION 3.3)
project(Game_Of_Life)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Game_Of_Life ${SOURCE_FILES})