cmake_minimum_required(VERSION 3.26)
project(os_3rdterm)

set(CMAKE_CXX_STANDARD 17)

add_executable(OperatSysNotebook seminar_1/1_task_one.cpp
        seminar_1/2_task_two.cpp
        headers/commons.hpp
        seminar_1/3_task_three.cpp
        seminar_2/4_task_four.cpp
        seminar_3/5_task_five.cpp
        seminar_3/myCopy.cpp
        seminar_3/myCopy.hpp
        seminar_3/6_task_six.cpp)
