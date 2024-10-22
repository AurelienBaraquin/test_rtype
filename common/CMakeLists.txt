project(Common)

add_library(Common STATIC src/common.cpp)

target_include_directories(Common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Common boost::boost)
