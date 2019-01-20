# cmake_minimum_required(VERSION <specify CMake version here>)
project(beauty_in_code)

set(CMAKE_CXX_STANDARD 14)

add_library(beauty_in_code.o library.cpp library.h main.cpp)

add_executable(beauty_in_code main.cpp library.cpp library.h)