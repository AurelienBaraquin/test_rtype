project(GameClient)

add_executable(GameClient src/main.cpp)

target_include_directories(GameClient PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(GameClient PRIVATE lib GameEngine)
