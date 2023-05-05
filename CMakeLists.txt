cmake_minimum_required(VERSION 3.22)

project(Sodium VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Options
option(SODIUM_BUILD_BENCHMARKS "Build benchmarks" OFF)
option(SODIUM_BUILD_DOC "Build documentation" OFF)
option(SODIUM_BUILD_EXAMPLES "Build examples" ON)
option(SODIUM_BUILD_TESTS "Build tests" OFF)
option(SODIUM_ENABLE_PCH "Enable precompiled headers" OFF)
option(SODIUM_UPDATE_SUBMODULES "Update submodules during build" ON)
option(SODIUM_FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)

# Subdirectories
add_subdirectory(src)

if (SODIUM_BUILD_BENCHMARKS)
    message(STATUS "Building benchmarks...")
    add_subdirectory(benchmarks)
endif ()

if (SODIUM_BUILD_DOC)
    message(STATUS "Building documentation...")
    add_subdirectory(documentation)
endif ()

if (SODIUM_BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif ()

if (SODIUM_BUILD_TESTS)
    message(STATUS "Building tests...")
    add_subdirectory(tests)
endif ()

if (SODIUM_ENABLE_PCH)
    message(STATUS "Precompiling headers...")
    target_precompile_headers(
        sodium PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/sodpch.hpp
    )
else ()
    message(STATUS "Precompiled headers disabled.")
endif ()

# Git submodule update
find_package(Git QUIET)

if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    if (SODIUM_UPDATE_SUBMODULES)
        message(STATUS "Updating submodules...")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT
        )

        if (NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif ()
    endif ()
endif ()

# Libraries
file(
    GLOB LIB_DIRS
    LIST_DIRECTORIES true
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/*
)

foreach (DIR ${LIB_DIRS})
    if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${DIR}/CMakeLists.txt)
        message(STATUS "Adding ${DIR}...")
        add_subdirectory(${DIR})
    endif ()
endforeach ()

# Preprocessor definitions
if (WIN32)
    target_compile_definitions(
        sodium
        PUBLIC SOD_PLATFORM_WINDOWS
        PUBLIC SOD_BUILD_DLL
    )
endif ()
