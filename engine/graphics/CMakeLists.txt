project(Graphics)

add_library(Graphics STATIC src/graphics.cpp)

target_include_directories(Graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/core/include)

target_link_libraries(Graphics PRIVATE Core raylib)

add_library(GameEngine::Graphics ALIAS Graphics)
