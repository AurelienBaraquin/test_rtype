project(GameEngine)

option(BUILD_GRAPHICS "Build graphics module" ON)
option(BUILD_AUDIO "Build audio module" ON)
option(BUILD_NETWORK "Build network module" ON)

add_subdirectory(core)

if(BUILD_GRAPHICS)
    add_subdirectory(graphics)
endif()

if(BUILD_AUDIO)
    add_subdirectory(audio)
endif()

if(BUILD_NETWORK)
    add_subdirectory(network)
endif()
