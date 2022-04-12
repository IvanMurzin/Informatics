cmake_minimum_required(VERSION 3.21)
project(lab2 C)

set(CMAKE_C_STANDARD 11)
include_directories(game)
include_directories(console)
include_directories(field)
include_directories(math)
include_directories(stack)

add_executable(lab2 main.c game/Game.c game/Game.h console/ConsoleUtil.c console/ConsoleUtil.h field/Field.c field/Field.h math/Math.c math/Math.h console/Color.h console/Color.c console/KeyboardInput.c console/KeyboardInput.h stack/Stack.h stack/StackVector.c stack/StackVector.h stack/StackList.c stack/StackList.h)