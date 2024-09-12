cmake_minimum_required(VERSION 3.10)

project (vec3lib)

set(SOURCES
    vec3.cpp
    interval.cpp
)
set(HEADERS
    common_func.hpp
    vec3.hpp
    ray.hpp
    interval.hpp
    color.hpp
)

add_library(vec3_lib ${SOURCES} ${HEADERS})

target_include_directories(vec3_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message("___VEC3 COMPILED")
