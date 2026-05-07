cmake_minimum_required(VERSION 3.15)
project(TwoSum LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# Enable testing
enable_testing()

# Main executable
add_executable(two_sum_app
    src/main.cpp
    src/twosum.cpp
)

# Test executable
add_executable(two_sum_tests
    src/test_twosum.cpp
    src/twosum.cpp
)

# Register tests with CTest
add_test(
    NAME TwoSumAllTests
    COMMAND two_sum_tests
)
