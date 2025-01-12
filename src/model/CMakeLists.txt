cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_library(model STATIC Service.cpp
        Service.h
        Identifiant.cpp
        Identifiant.h
        TokenGroup.cpp
        TokenGroup.h
        Token.cpp
        Token.h)

target_include_directories(model PUBLIC ${CMAKE_SOURCE_DIR}/src/model)