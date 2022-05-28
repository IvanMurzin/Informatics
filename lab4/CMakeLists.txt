cmake_minimum_required(VERSION 3.21)
project(lab4 C)

set(CMAKE_C_STANDARD 99)

add_executable(lab4 main.c model/tree/binary/BinaryTree.c model/tree/binary/BinaryTree.h model/tree/binary/BNode.c model/tree/binary/BNode.h)
