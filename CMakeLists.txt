cmake_minimum_required(VERSION 3.26)
project(CPlusPlusAlgorithm)

set(CMAKE_CXX_STANDARD 14)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

add_executable(CPlusPlusAlgorithm
        # answer/자료구조/11720_숫자의합.cpp
        # answer/자료구조/1546_평균.cpp
        # theory/정렬/버블정렬.cpp
        # theory/정렬/포인터_버블정렬.cpp
        # theory/정렬/선택정렬.cpp
        # theory/정렬/삽입정렬.cpp
        # theory/정렬/병합정렬.cpp
        # theory/정렬/힙정렬.cpp
        # theory/정렬/힙정렬ver2.cpp
        theory/sorting/퀵정렬.cpp)
