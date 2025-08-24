cmake_minimum_required(VERSION 3.20)
project(WCC)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/runtime/syntax)

set(SOURCES
    runtime/main.cpp
    runtime/parser.cpp
    runtime/errorhandler.cpp
    runtime/syntax/print.cpp
    runtime/syntax/variable.cpp
    runtime/syntax/include.cpp
)

add_executable(WCC ${SOURCES})

