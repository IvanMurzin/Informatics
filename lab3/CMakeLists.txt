cmake_minimum_required(VERSION 3.22)
project(lab3)


include_directories(lib/model)
include_directories(lib/controller)

include_directories(model)
include_directories(controller)

add_subdirectory(test)

set(CMAKE_CXX_STANDARD 17)


add_executable(lab3 lib/model/Action.cpp lib/controller/Dialog.cpp main.cpp model/Table.cpp model/Table.h model/Item.cpp model/Item.h controller/TableController.cpp controller/TableController.h)
