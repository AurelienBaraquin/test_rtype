project(GameEngine)

add_library(GameEngine STATIC src/engine.cpp)

target_include_directories(GameEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(GameEngine box2d::box2d)
