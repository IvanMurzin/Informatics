cmake_minimum_required(VERSION 3.21)
project(lab1 C)

set(CMAKE_C_STANDARD 11)
include_directories(model)
include_directories(controller)

add_executable(lab1 main.c model/IntDynamicArray.c model/IntDynamicArray.h model/IntHashSet.c model/IntHashSet.h controller/ConsoleController.c controller/ConsoleController.h model/Matrix.h model/Matrix.c)
