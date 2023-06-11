cmake_minimum_required(VERSION 3.26.4)

set(CMAKE_MAKE_PROGRAM "mingw32-make" CACHE STRING "NMake or MinGW make")

set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")

project(SpaceWarsProject)

add_executable(SpaceWars SpaceWars.cpp)