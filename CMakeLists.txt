cmake_minimum_required(VERSION 3.2)
project(PingPong)

set(EXTERNAL_PATH "external/")

# for compiling SFML
include_directories (/usr/include/freetype2)
add_subdirectory (${EXTERNAL_PATH}SFML)

set(SRC_PATH "src/")
add_executable(PingPong ${SRC_PATH}main.cpp ${SRC_PATH}game.hpp ${SRC_PATH}game.cpp
                ${SRC_PATH}ball.hpp ${SRC_PATH}ball.cpp
                ${SRC_PATH}physics.hpp ${SRC_PATH}physics.cpp
                ${SRC_PATH}player.hpp ${SRC_PATH}player.cpp)

target_link_libraries (PingPong sfml-graphics sfml-audio sfml-window sfml-system)
target_include_directories (PingPong PRIVATE external/SFML/include)
