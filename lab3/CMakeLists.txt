cmake_minimum_required(VERSION 3.21)
project(lab3 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-lreadline")
include_directories(model/table)
include_directories(model/keyspace/container)
include_directories(model/keyspace/node)
include_directories(model/keyspace/keyspace1)
include_directories(model/keyspace/keyspace2)
include_directories(model/table/item)
include_directories(model/keyspace/key)
include_directories(view)
include_directories(./)
include_directories(controller/iterator)
include_directories(controller/dialog)
add_executable(lab3
        main.c
        model/keyspace/keyspace1/KeySpace1.c
        model/table/CompositeKey.c
        model/table/item/Item.c
        model/keyspace/key/Key.c
        model/keyspace/node/Node.c
        model/keyspace/container/Container.c
        #        model/table/Table.c
        #        model/keyspace/keyspace2/KeySpace2.c
        #        view/Logger.c
        #        controller/iterator/IteratorKS.c
        #        model/keyspace/container/Waymark.c
        #        controller/dialog/Dialog.c
        )
