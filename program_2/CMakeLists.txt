cmake_minimum_required(VERSION 3.14)
project(ecen_5813_project_1_program_2 C)

set(CMAKE_C_STANDARD 99)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

include_directories(include)

add_executable(ecen_5813_project_1_program_2 source/main.c include/print_ascii_info.h source/print_ascii_info.c)