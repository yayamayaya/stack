cmake_minimum_required(VERSION 3.15)

set(SOURCES 
    stack_ext_funcs.hpp
    stack_itern_funcs.hpp
    stack_log.h
    stack_type_funcs.cpp
    stack.h
)

add_library(stack ${SOURCES})

target_include_directories(
    stack
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)