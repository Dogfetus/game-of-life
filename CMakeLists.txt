cmake_minimum_required(VERSION 3.21)
project(game-of-life)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib REQUIRED)

add_executable(game-of-life 
    game-of-life.cpp
    grid/grid.cpp
    grid/cell.cpp
    utils/random.cpp
)

target_link_libraries(game-of-life raylib)
