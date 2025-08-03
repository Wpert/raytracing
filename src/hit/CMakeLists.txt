cmake_minimum_required(VERSION 3.10)

project (hittablelib)

set(CUSTOM_LIBRARY_PATH /home/vpert/gitproj/labs_3/sorting/)
find_library(CUSTOM_LIBRARY_PATH
    vec3_lib
)

include_directories(
    "${CMAKE_SOURCE_DIR}"
)

set(SOURCES
    hittable.cpp
)
set(HEADERS
    hittable.hpp
    material.hpp
    hittable_list.hpp
)

add_library(hittable_lib ${SOURCES} ${HEADERS})
target_link_libraries(hittable_lib vec3_lib)
target_include_directories(hittable_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message("___HITTABLE COMPILED")
