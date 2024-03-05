cmake_minimum_required(VERSION 3.25)
project(CPlusPlusAlgorithm)

set(CMAKE_CXX_STANDARD 14)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_executable(CPlusPlusAlgorithm
        category/practice.cpp)
