project(Network)

add_library(Network STATIC src/network.cpp)

target_include_directories(Network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/core/include)

target_link_libraries(Network PRIVATE Core)

add_library(GameEngine::Network ALIAS Network)
