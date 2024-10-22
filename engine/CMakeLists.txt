project(GameEngine)

add_library(GameEngine STATIC src/engine.cpp)

target_include_directories(GameEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
