cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_executable(SystemManager src/main.cpp
        src/bd/Connector.cpp
        src/bd/Connector.h)

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME}
        SQLite::SQLite3
)