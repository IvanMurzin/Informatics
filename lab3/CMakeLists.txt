cmake_minimum_required(VERSION 3.21)
project(lab3 C)

set(CMAKE_C_STANDARD 99)

include_directories(model/table)
include_directories(model/keyspace/keyspace1)
include_directories(model/keyspace/keyspace2)
include_directories(model/keyspace/item)
include_directories(view)
include_directories(./)
include_directories(controller/keyspace)
add_executable(lab3 main.c
        model/table/Table.c
        model/keyspace/keyspace1/KeySpace1.c
        model/keyspace/keyspace2/KeySpace2.c
        model/table/CompositeKey.c
        model/keyspace/item/Item.c
        view/Logger.c
        controller/keyspace/KeySpace1Controller.c
        model/keyspace/key/Key.c
        controller/keyspace/IteratorKS1.c
        )
