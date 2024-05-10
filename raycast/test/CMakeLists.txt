project (testVec3)

set(CUSTOM_LIBRARY_PATH /home/vpert/gitproj/labs_3/sorting/)
find_library(CUSTOM_LIBRARY_PATH
    vec3_lib
)

include_directories(
    "${CMAKE_SOURCE_DIR}"
)

add_executable(vec3exe test_vec3.cpp)
target_link_libraries(
    vec3_lib
)

add_test(vec3test vec3exe)
