cmake_minimum_required(VERSION 2.8)

project(montyhallsimulator)

include_directories(include)

set(CMAKE_CXX_FLAGS "-O3 -Wall -Werror")

add_executable(montyhallsimulator src/mhstats.cpp src/mhresult.cpp src/mhplayer.cpp src/mhmodel.cpp src/proxyrandom.cpp src/mhdoor.cpp main.cpp)