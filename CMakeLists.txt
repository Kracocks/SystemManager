cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src/model)
add_subdirectory(tests)
add_subdirectory(libs/Catch2)

add_executable(SystemManager main.cpp)

target_link_libraries(SystemManager model)