cmake_minimum_required(VERSION 3.30)
project(SystemManager)

set(CMAKE_CXX_STANDARD 23)

add_library(bd STATIC
        Connector.h
        Connector.cpp
        IGenericDao.h
        IIdentifiantDao.h
        IServiceDAO.h
        ITokenDao.h
        ITokenGroupDAO.h)

find_package(SQLite3 REQUIRED)

target_link_libraries(bd PUBLIC SQLite::SQLite3)

target_include_directories(bd PUBLIC ${CMAKE_SOURCE_DIR}/src/bd)