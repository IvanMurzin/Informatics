cmake_minimum_required(VERSION 3.21)
project(lab5 C)

set(CMAKE_C_STANDARD 99)
include_directories(controller/dialog)
include_directories(controller/graph)
include_directories(model/container)
include_directories(model/edge)
include_directories(model/matrix)
include_directories(model/node)
include_directories(model/vertex)
include_directories(view)
add_executable(lab5 main.c
        model/matrix/Matrix.c

        model/vertex/Vertex.c

        model/container/Container.c

        view/Logger.c
        model/edge/Edge.c
        controller/graph/GraphGenerator.c
        model/node/Node.c controller/dialog/Dialog.c)
