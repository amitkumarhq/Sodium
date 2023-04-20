cmake_minimum_required(VERSION 3.22)

project(Sodium VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

# ---------- OPTIONS ---------- #

option(SODIUM_BUILD_EXAMPLES "Build examples" ON)

# ---------- ADD SUBDIRECTORIES ---------- #

add_subdirectory(src)
add_subdirectory(include)

if(SODIUM_BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif()
