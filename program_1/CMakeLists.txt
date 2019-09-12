cmake_minimum_required(VERSION 3.14)
project(ecen_5813_project_1_program_1 C)

set(CMAKE_C_STANDARD 99)
set(COMMON_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../common)
include_directories(include ${COMMON_DIR}/include)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

add_executable(ecen_5813_project_1_program_1 ${COMMON_DIR}/source/print_binary.c source/main.c include/constants.h include/custom_types.h include/print_helpers.h source/print_helpers.c)