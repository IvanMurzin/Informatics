cmake_minimum_required(VERSION 3.0.2)
project(lab1)

include_directories(model)
include_directories(controller)
include_directories(lib/model)

set(CMAKE_CXX_STANDARD 11)

add_executable(lab1 main.cpp model/Matrix.cpp model/Matrix.h model/List.h model/Item.cpp controller/ConsoleController.cpp controller/ConsoleController.h model/Item.h lib/model/Scanner.cpp lib/model/Scanner.h controller/ConsoleController.cpp controller/ConsoleController.h controller/MatrixController.cpp model/Line.cpp model/Line.h)
