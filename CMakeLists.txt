cmake_minimum_required(VERSION 3.22)
project(Sodium VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

# ---------- OPTIONS ----------

option(SODIUM_BUILD_EXAMPLES "Build examples" ON)

# ---------- SOURCES ----------

add_subdirectory(src)
add_subdirectory(include)

if (SODIUM_BUILD_EXAMPLES)
    message(STATUS "Building examples...")
    add_subdirectory(examples)
endif ()

# ---------- LIBRARIES ----------

# Add submodules' libraries
add_subdirectory(libs/spdlog)

# Link submodules' libraries to the target
target_link_libraries(
    sodium PUBLIC spdlog::spdlog
)
