/*
 * @file main.c
 * @brief Project 1 Program 2
 *
 * @details Program 2 takes in a series of ASCII codes and prints out information about them, including
 *          whether they are digits, lowercase, uppercase, whitespace, or special characters.
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */

#include "print_ascii_info.h"
#include <stdint.h>

#define NUM_INPUTS 20

int main(int argc, const char * argv[])
{
    const uint8_t inputs[NUM_INPUTS] = {66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};

    for(int8_t iter = 0; iter < NUM_INPUTS; iter++)
    {
        print_ascii_info(inputs[iter]);
    }
    return 0;
}
