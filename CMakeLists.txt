cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp)

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME}
        SQLite::SQLite3
        model
        bd
)

add_subdirectory(src/model)
add_subdirectory(src/bd)
add_subdirectory(tests)
add_subdirectory(libs/Catch2)