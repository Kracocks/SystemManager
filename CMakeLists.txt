cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_executable(SystemManager src/main.cpp
        src/model/Service.cpp
        src/model/Service.h
        src/model/Identifiant.cpp
        src/model/Identifiant.h
)
