cmake_minimum_required(VERSION 3.21)
project(lab4 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-lreadline")
include_directories(model/tree)
include_directories(model/key)
include_directories(model/item)
include_directories(model/node)
include_directories(controller/graph)
include_directories(controller/dialog)
add_executable(lab4 main.c
        model/tree/Tree.c
        model/item/Item.c
        controller/graph/GraphGenerator.c
        controller/dialog/Dialog.c
        model/tree/Tree.c
        model/key/Key.c
        model/node/Node.c
        test/test.c
        )
