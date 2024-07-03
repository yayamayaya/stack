cmake_minimum_required(VERSION 3.15)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(test ${SOURCES})

target_include_directories(
    test
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)