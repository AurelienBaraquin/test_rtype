project(GameServer)

add_executable(GameServer src/main.cpp)

target_include_directories(GameServer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(GameServer PRIVATE Common GameEngine)
