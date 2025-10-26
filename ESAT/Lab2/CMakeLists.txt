cmake_minimum_required(VERSION 3.20)

if(Ex1_1)
    message(STATUS "Prerequisite set for Ex1_1")
    set(Lab2_Ex1_1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex1_1/main.cpp
    )

    add_executable(Lab2_Ex1_1 ${Lab2_Ex1_1_src})
elseif(Ex1_2)
    message(STATUS "Prerequisite set for Ex1_2")
    set(Lab2_Ex1_2_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex1_2/main.cpp
    )

    add_executable(Lab2_Ex1_2 ${Lab2_Ex1_2_src})
elseif(Ex2_1)
    message(STATUS "Prerequisite set for Ex2_1")
    set(Lab2_Ex2_1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex2_1/main.cpp
    )

    add_executable(Lab2_Ex2_1 ${Lab2_Ex2_1_src})
elseif(Ex2_2)
    message(STATUS "Prerequisite set for Ex2_2")
    set(Lab2_Ex2_2_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex2_2/main.cpp
    )

    add_executable(Lab2_Ex2_2 ${Lab2_Ex2_2_src})
elseif(Ex3_1)
    message(STATUS "Prerequisite set for Ex3_1")
    set(Lab2_Ex3_1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex3_1/main.cpp
    )

    add_executable(Lab2_Ex3_1 ${Lab2_Ex3_1_src})
elseif(Ex4_1)
    message(STATUS "Prerequisite set for Ex4_1")
    set(Lab2_Ex4_1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex4_1/main.cpp
    )

    add_executable(Lab2_Ex4_1 ${Lab2_Ex4_1_src})
elseif(Ex5_1)
    message(STATUS "Prerequisite set for Ex5_1")
    set(Lab2_Ex5_1_src
        ${CMAKE_CURRENT_SOURCE_DIR}/Ex5_1/main.cpp
    )

    add_executable(Lab2_Ex5_1 ${Lab2_Ex5_1_src})
endif()