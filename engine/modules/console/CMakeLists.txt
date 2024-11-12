project(Console)

add_library(Console STATIC src/console.cpp)

target_include_directories(Console PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/include/components 
    ${CMAKE_SOURCE_DIR}/core/include
    ${CMAKE_SOURCE_DIR}/core/include/components)

target_link_libraries(Console PRIVATE Core)

add_library(GameEngine::Console ALIAS Console)
