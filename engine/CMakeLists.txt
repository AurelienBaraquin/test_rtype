project(GameEngine)

option(BUILD_RENDER "Build render module" ON)
option(BUILD_CONSOLE "Build console module" ON)

add_subdirectory(core)

if(BUILD_RENDER)
    add_subdirectory(modules/render)
endif()

if(BUILD_CONSOLE)
    add_subdirectory(modules/console)
endif()
