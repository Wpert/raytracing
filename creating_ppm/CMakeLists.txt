cmake_minimum_required(VERSION 3.25)
project(gradient VERSION 0.0.1 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(gradient main.cpp)
set(CMAKE_CXX_STANDARD 20)
target_compile_features(gradient PUBLIC cxx_std_20)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
