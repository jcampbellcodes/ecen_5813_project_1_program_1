/*
 * @file main.c
 * @brief Project 1 Program 1
 *
 * @details Program 1 takes a series of inputs that contain a raw number, a radix, and an
 *          operand size and output a table containing various representations of that number
 *          as well as the minimum and maximum allowed values for each representation.
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */

#include "print_helpers.h"

#define NUM_INPUTS 11
#define NUM_ARGS_PER_INPUT 3

int main(int argc, const char * argv[])
{
    static const int32_t inputs[NUM_INPUTS][NUM_ARGS_PER_INPUT] =
    {
        {-6, 10, 4},
        {-6, 9, 4},
        {-6, 10, 5},
        {-9, 10, 4},
        {237, 10, 8},
        {0354, 8, 8},
        {0xEB, 16, 8},
        {-125, 10, 8},
        {65400, 10, 8},
        {65400, 10, 16},
        {-32701, 10, 16}
    };
    
    for(int8_t iter = 0; iter < NUM_INPUTS; iter++)
    {
        print_numerical_representations(inputs[iter][0], inputs[iter][1], inputs[iter][2]);
    }
    
    return 0;
}
