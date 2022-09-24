cmake_minimum_required(VERSION 3.22)
project(lab2)

include_directories(lib/model)
include_directories(lib/controller)
add_subdirectory(test)
set(CMAKE_CXX_STANDARD 17)

add_executable(lab2 main.cpp lib/controller/Dialog.cpp lib/controller/Dialog.h lib/model/Action.cpp lib/model/Action.h model/Cardioid.cpp model/Cardioid.h)
