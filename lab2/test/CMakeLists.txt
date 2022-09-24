cmake_minimum_required(VERSION 3.22)
project(test)

set(CMAKE_CXX_STANDARD 17)

include_directories(../model/)

add_executable(test ../model/Cardioid.cpp test.cpp catch.h)
