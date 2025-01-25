cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(libs/Catch2)

target_link_libraries(${PROJECT_NAME}
    model
    bd
    impl)