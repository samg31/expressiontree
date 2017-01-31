cmake_minimum_required(VERSION 2.8)
project(expressiontree)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")

add_executable(expr main.cpp expr.cpp type.cpp astcontext.cpp )