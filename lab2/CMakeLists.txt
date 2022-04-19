cmake_minimum_required(VERSION 3.21)
project(lab2 C)

set(CMAKE_C_STANDARD 11)
include_directories(game)
include_directories(console)
include_directories(field)
include_directories(math)
include_directories(stack)
include_directories(point)

add_executable(
        lab2 main.c
        game/Game.c
        console/ConsoleUtil.c
        field/Field.c
        math/Math.c
        console/Color.c
        console/KeyboardInput.c
        stack/StackVector.c
        stack/StackList.c
        point/Point.c
)