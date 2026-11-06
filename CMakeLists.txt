cmake_minimum_required(VERSION 3.15)

project(Schelling VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --- Google Test ---
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  DOWNLOAD_EXTRACT_TIMESTAMP True
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# --- Common library ---
add_library(schelling_lib src/schelling_naive.cpp)
target_include_directories(schelling_lib PUBLIC include/)

# --- Main executable ---
add_executable(schelling.exe src/main.cpp)
target_link_libraries(schelling.exe PRIVATE schelling_lib)

# --- Test executable ---
add_executable(test.exe test/test_schelling_naive.cpp)
target_link_libraries(test.exe
                PRIVATE GTest::gtest_main
                PRIVATE schelling_lib
)

include(GoogleTest)
gtest_discover_tests(test.exe)
