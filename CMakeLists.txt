cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_executable(SystemManager src/main.cpp
        src/bd/Connector.cpp
        src/bd/Connector.h
        src/model/Service.cpp
        src/model/Service.h
        src/model/Identifiant.cpp
        src/model/Identifiant.h
        src/model/TokenGroup.cpp
        src/model/TokenGroup.h
        src/model/Token.cpp
        src/model/Token.h)

find_package(SQLite3 REQUIRED)

target_link_libraries(${PROJECT_NAME}
        SQLite::SQLite3
)