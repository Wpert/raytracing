cmake_minimum_required(VERSION 3.25)
project(raycast VERSION 0.0.1 LANGUAGES C CXX)

include(CTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

enable_testing ()

add_subdirectory (vec3)
add_subdirectory (hit)
add_subdirectory (cam)
add_subdirectory (test)

add_executable (raycast main.cpp)
target_link_libraries (raycast vec3_lib hittable_lib camera_lib)
target_compile_features(raycast PUBLIC cxx_std_20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
