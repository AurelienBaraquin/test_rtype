cmake_minimum_required(VERSION 3.15)
project(TestRType VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)
find_package(chipmunk2d REQUIRED)
find_package(raylib REQUIRED)

add_subdirectory(engine)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(lib)
