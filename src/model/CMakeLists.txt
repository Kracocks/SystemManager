cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_library(model STATIC
        Service.cpp
        Service.h
        Identifiant.h
        TokenGroup.cpp
        TokenGroup.h
        Token.cpp
        Token.h)

find_package(OpenSSL REQUIRED)

target_include_directories(model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})