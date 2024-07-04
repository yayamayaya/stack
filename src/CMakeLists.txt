cmake_minimum_required(VERSION 3.15)

set(SOURCES 
    stack_ext_func.hpp
    stack_itern_func.hpp
    stack_log.h
    stack_type_funcs.cpp
    stack.h
)

add_library(stack ${SOURCES})