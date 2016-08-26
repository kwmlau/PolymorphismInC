cmake_minimum_required(VERSION 3.6)
project(PolymorphismInC)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Person.h Person.c Employee.h Employee.c main.c)
add_executable(PolymorphismInC ${SOURCE_FILES})