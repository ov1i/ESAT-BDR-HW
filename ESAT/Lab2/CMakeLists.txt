cmake_minimum_required(VERSION 3.20)

if(Ex1_1)
    message(STATUS "Prerequisite set for Ex1")
    
    set(Lab2_Ex1_1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex1_1/main.cpp
    )

    add_executable(Lab2_Ex1_1 ${Lab2_Ex1_1_src})
endif()

if(Ex2_1)
    set(Lab2_Ex2_1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex1_1/main.cpp
    )

    add_executable(Lab2_Ex2_1 ${Lab1_Ex2_src})
endif()

if(Ex3_1)
    set(Lab2_Ex3_1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex1_1/main.cpp
    )

    add_executable(Lab2_Ex2_1 ${Lab1_Ex3_src})
endif()