project(core)

add_library(Core STATIC src/engine.cpp)

target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/components)

target_link_libraries(Core raylib chipmunk2d::chipmunk2d lua::lua EnTT::EnTT)

add_library(GameEngine ALIAS Core)
