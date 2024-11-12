project(Render)

add_library(Render STATIC src/render.cpp)

target_include_directories(Render PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/components 
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_SOURCE_DIR}/core/include/components)

target_link_libraries(Render PRIVATE Core raylib)

add_library(GameEngine::Render ALIAS Render)
