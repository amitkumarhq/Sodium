project(${PROJECT_NAME})

# Source files
add_executable(sandbox Sandbox.cpp)

# Libraries
target_link_libraries(
    sandbox PUBLIC sodium
)

# Copy engine shared library to the bin/
if (WIN32)
    add_custom_command(
        TARGET sandbox POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_BINARY_DIR}/bin/libsodium.dll
        ${CMAKE_CURRENT_BINARY_DIR}/bin/libsodium.dll
    )
endif ()

# Output directory
set_target_properties(
    sandbox PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin
)
