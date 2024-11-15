cmake_minimum_required(VERSION 3.15)
project(TestRType VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

find_package(Boost REQUIRED)
find_package(chipmunk2d REQUIRED)
find_package(raylib REQUIRED)
find_package(lua REQUIRED)
find_package(EnTT REQUIRED)

add_subdirectory(engine)
add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(common)

add_custom_target(server
    COMMAND build/build/Release/server/GameServer
    DEPENDS server
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_target(client
    COMMAND build/build/Release/client/GameClient
    DEPENDS client
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
