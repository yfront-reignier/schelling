cmake_minimum_required(VERSION 3.15)

project(Schelling VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(schelling.exe src/main.cpp)
