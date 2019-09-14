/*
 * @file main.c
 * @brief Project 1 Program 3
 *
 * @details This program follows the series of steps outlined in the assignment, which boils down to
 *          performing in-place rotate operations on a number and printing out the number in binary, as well as
 *          determining whether the last three bits are on or off
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */
#include <stdio.h>
#include <stdint.h>
#include "rotate_and_print.h"

int main(int argc, const char * argv[])
{
    uint32_t CAFE = 0xCAFE;
    printf("%s", rotate_and_print(&CAFE, 0));
    printf("%s", rotate_and_print(&CAFE, 8)); // same as switching a short from left and right
    printf("%s", rotate_and_print(&CAFE, 12)); // rotating right 12 is the same as rotate left 4
    printf("%s", rotate_and_print(&CAFE, 8));
    return 0;
}
