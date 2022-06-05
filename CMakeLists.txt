cmake_minimum_required(VERSION 3.23.2)

project(gerber2stl LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-std=c++17")

file(GLOB src
     "src/*.hh"
     "src/*.cc"
)

add_executable(gerber2stl ${src})

