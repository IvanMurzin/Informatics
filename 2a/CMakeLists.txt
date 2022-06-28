cmake_minimum_required(VERSION 3.21)
project(lab2 C)

set(CMAKE_C_STANDARD 11)
include_directories(game)
include_directories(console)
include_directories(field)
include_directories(stack)
include_directories(point)

add_executable(
        lab2 main.c
        lib/StackVector.c
        point/Point.c
)