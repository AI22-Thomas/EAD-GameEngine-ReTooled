cmake_minimum_required(VERSION 3.24)
project(ReTooled)

set(CMAKE_CXX_STANDARD 23)

# To prevent the need to manually export symbols on Windows
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(re-tooled/vendor/glfw)

add_library(ReTooled SHARED
        re-tooled/re-tooled/rtpch.hpp
        re-tooled/re-tooled/entrypoint.hpp
        re-tooled/re-tooled/event.hpp
        re-tooled/re-tooled/game.cpp
        re-tooled/re-tooled/log.cpp
        re-tooled/re-tooled/window.cpp)

add_executable(ExampleGame example-game/main.cpp)

target_precompile_headers(ReTooled PUBLIC re-tooled/re-tooled/rtpch.hpp)

target_include_directories(ExampleGame PUBLIC re-tooled)
target_include_directories(ReTooled PUBLIC re-tooled/vendor/spdlog/include)
target_include_directories(ReTooled PUBLIC re-tooled/vendor/eventpp/include)

target_link_libraries(ReTooled glfw)
target_link_libraries(ExampleGame ReTooled)