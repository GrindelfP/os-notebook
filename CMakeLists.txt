#
#   ___  ____    _   _  ___ _____ _____ ____
#  / _ \/ ___|  | \ | |/ _ \_   _| ____/ ___|
# | | | \___ \  |  \| | | | || | |  _| \___ \
# | |_| |___) | | |\  | |_| || | | |___ ___) |
#  \___/|____/  |_| \_|\___/ |_| |_____|____/
#
# Created on 2023-09-06 by Grindelf P.
#
# CMakeLists.txt file for the project.
# The os-notebook project is a storage place for my seminar tasks on the subject of operating systems in UNI.
# Each task has its own main() function so every task would have its own executable file.
# The naming of files is inconsistent because the tasks in the course was not always of the same kind.
# One great part of the task is a development of a shell, which in my case is called
# GShellLight and is placed in a separate repository (see https://github.com/GrindelfP/gshell-light).
#

cmake_minimum_required(VERSION 3.26)
project(os-notebook)

set(CMAKE_CXX_STANDARD 17)

# Seminar 1
add_executable(seminar-1-1 seminar_1/task-1.cpp)
add_executable(seminar-1-2 seminar_1/task-2.cpp)
add_executable(seminar-1-3 seminar_1/task-3.cpp)

# Seminar 2
add_executable(seminar-2-4 seminar_2/task-4.cpp)

# Seminar 3
add_executable(seminar-3-5 seminar_3/task-5.cpp)
add_executable(seminar-3-6 seminar_3/task-6.cpp)
add_executable(seminar-3-my-copy seminar_3/my-copy.cpp)

# Seminar 8
add_executable(seminar-8-8 seminar_8/task-8.c)

# Seminar 9
add_executable(seminar-9-philosophers seminar_9/eating-philosophers.c)

# Seminar 11
add_executable(seminar_11-9 seminar_11/task-9.cpp)

# Seminar 12
add_executable(seminar_12-10 seminar_12/10-task.cpp)
