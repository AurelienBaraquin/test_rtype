project(core)

add_library(Core STATIC src/engine.cpp)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Core raylib chipmunk2d::chipmunk2d)

add_library(GameEngine ALIAS Core)
