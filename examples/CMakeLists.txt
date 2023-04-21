project(${PROJECT_NAME})

add_executable(example Sandbox.cpp)

target_link_libraries(
    example PRIVATE sodium
)
