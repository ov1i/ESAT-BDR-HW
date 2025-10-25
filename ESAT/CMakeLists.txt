cmake_minimum_required(VERSION 3.20)

if(Lab1)
    message(STATUS "Building Lab1")
    add_subdirectory(Lab1)
elseif(Lab2)
    message(STATUS "Building Lab2")
    add_subdirectory(Lab2)
endif()


