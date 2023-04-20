project(${PROJECT_NAME})

file(GLOB_RECURSE SRC_FILES "./**/*.c" "./**/*.cpp")
file(GLOB_RECURSE HEADER_FILES "./**/*.h" "./**/*.hpp")

add_library(sodium SHARED ${SRC_FILES} ${HEADER_FILES})

target_include_directories(
    sodium PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
