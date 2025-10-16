cmake_minimum_required(VERSION 3.20)

if(Ex1)
    message(STATUS "Prerequisite set for Ex1")
    
    set(Lab1_Ex1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex1/main.cpp
    )

    add_executable(Lab1_Ex1 ${Lab1_Ex1_src})
endif()

if(Ex2)
    set(Lab1_Ex2_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex1/main.cpp
    )

    add_executable(Lab1_Ex2 ${Lab1_Ex2_src})
endif()

if(Ex3)
    set(Lab1_Ex3_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex1/main.cpp
    )

    add_executable(Lab1_Ex3 ${Lab1_Ex3_src})
endif()