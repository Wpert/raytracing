cmake_minimum_required(VERSION 3.10)

project (camlib)

set(CUSTOM_LIBRARY_PATH /home/vpert/gitproj/labs_3/sorting/)
find_library(CUSTOM_LIBRARY_PATH
    vec3_lib
    hittable_lib
)

include_directories(
    "${CMAKE_SOURCE_DIR}"
)

set(SOURCES
    camera.cpp
)
set(HEADERS
    camera.hpp
)

add_library(camera_lib ${SOURCES} ${HEADERS})
target_include_directories(camera_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message("___HITTABLE COMPILED")
