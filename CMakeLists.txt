cmake_minimum_required(VERSION 3.15)

project(stack_test)

add_definitions(-Wall -g)
add_definitions(-DDEBUG -DSECURE)

include_directories(
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

add_subdirectory(stack_test)