project(${PROJECT_NAME})

add_executable(example example.cpp)

target_link_libraries(
    example PRIVATE sodium
)
