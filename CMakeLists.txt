cmake_minimum_required(VERSION 3.20)
project(UJSCC)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/runtime/syntax)

set(SOURCES
    runtime/main.cpp
    runtime/parser.cpp
    runtime/errorhandler.cpp
    runtime/syntax/print.cpp
    runtime/syntax/variable.cpp
)

add_executable(ujscc ${SOURCES})

