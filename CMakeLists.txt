cmake_minimum_required(VERSION 3.27)
project(wielomaszynowy)

set(CMAKE_CXX_STANDARD 17)

add_executable(wielomaszynowy main.cpp
        Machine.cpp
        Problem.cpp
        Result.cpp
)
