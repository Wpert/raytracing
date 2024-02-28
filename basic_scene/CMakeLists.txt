cmake_minimum_required(VERSION 3.25)
project(bscene VERSION 0.0.1 LANGUAGES C CXX)

include(CTest)

add_library(vec3 vec3/vec3.hpp vec3/vec3.cpp)

add_executable(bscene main.cpp vec3 color.hpp ray.hpp)
set(CMAKE_CXX_STANDARD 20)
target_compile_features(bscene PUBLIC cxx_std_20)

# testing binary
add_executable(test_vec3 test/test_vec3.cpp)
target_link_libraries(test_vec3 vec3)

# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME vec3_t
  COMMAND $<TARGET_FILE:test_vec3>
  )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
