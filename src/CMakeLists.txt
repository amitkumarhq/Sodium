project(${PROJECT_NAME})

# Files
file(GLOB_RECURSE SRC_FILES "./*.c" "./*.cpp")

# Target
add_library(sodium SHARED ${SRC_FILES})

# Include directories
target_include_directories(
    sodium PUBLIC ${PROJECT_ROOT_DIR}/include
)

# System libraries
find_package(OpenGL REQUIRED)

# Libraries
target_link_libraries(
    sodium
    PUBLIC OpenGL::GL
    PUBLIC spdlog::spdlog
    PUBLIC glfw
)

# Place the lib and the executable in the bin/
set_target_properties(
    sodium PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
