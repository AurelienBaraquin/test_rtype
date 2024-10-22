project(LibCode)

add_library(lib STATIC src/lib.cpp)

target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(lib boost::boost)
