cmake_minimum_required(VERSION 3.21)
project(lab4 C)

set(CMAKE_C_STANDARD 99)
include_directories(model/tree/binary)
include_directories(controller/graph)
add_executable(lab4 main.c
        model/tree/binary/BinaryTree.c
        model/tree/binary/BNode.c
        controller/graph/GraphGenerator.c
        )
