cmake_minimum_required(VERSION 3.24)
project(ReTooled)

set(CMAKE_CXX_STANDARD 23)

# To prevent the need to manually export symbols on Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(ReTooled SHARED re-tooled/re-tooled.hpp re-tooled/game.cpp re-tooled/entrypoint.hpp)
add_executable(ExampleGame example-game/main.cpp)

target_include_directories(ExampleGame PUBLIC re-tooled)

target_link_libraries(ExampleGame ReTooled)