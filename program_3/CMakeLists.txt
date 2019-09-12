cmake_minimum_required(VERSION 3.14)
project(ecen_5813_project_1_program_3 C)

set(COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common)


include_directories(${COMMON_DIR}/include include)

set(CMAKE_C_STANDARD 99)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

add_executable(ecen_5813_project_1_program_3 ${COMMON_DIR}/source/print_binary.c  include/rotate_and_print.h source/rotate_and_print.c source/main.c)