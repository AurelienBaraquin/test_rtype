project(Audio)

add_library(Audio STATIC src/audio.cpp)

target_include_directories(Audio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/core/include)

target_link_libraries(Audio PRIVATE Core)

add_library(GameEngine::Audio ALIAS Audio)
