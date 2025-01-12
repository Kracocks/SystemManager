cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

find_package(Catch2 3 REQUIRED)

file(GLOB TEST_FILES "unitests/**/*.cpp")

add_executable(test_runner ${TEST_FILES}
        unitests/model/Identifiant.test.cpp)

target_link_libraries(test_runner Catch2::Catch2)

target_include_directories(test_runner PRIVATE ${CMAKE_SOURCE_DIR}/src)

include(CTest)
include(Catch)