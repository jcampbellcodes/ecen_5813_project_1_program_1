/*
 * @file rotate_and_print.c
 * @brief Helper macros and public interface for rotating and printing a number
 *
 * @details Made to follow along with the steps for program 3 of project 1
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */

// System includes
#include <stdio.h>

// User includes
#include "rotate_and_print.h"
#include "print_binary.h"

// Globals
const uint8_t 3_4_lookup_table[16] = {0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0};

/**
 * rotate_and_print
 * @brief Given a pointer to a number, rotate that number in place by a specified amount.
 * @param value A pointer to the value to rotate
 * @param rotateAmt The amount to rotate the number to the right
 * @return A string, true or false, describing whether the last three bits are on.
 */
const char* rotate_and_print(uint32_t* value, uint32_t rotateAmt)
{
    if(!value)
        return "";

    *value = rotateRight(*value, rotateAmt);
    printf("0x%X\n", (uint16_t)*value);
    print_bin(*value, 16);
    printf(" -> 3 of last 4 bits are on?");
    return test_3_4_binary(value) ? " true\n" : " false\n";
}

/**
 * test_3_4_binrary 
 * @brief test if 3 of the 4 last bits are turned on
 * @param value binary number to run bit analysis on
 * @return int, true or false whether 3 of 4 bits are turned on
 */
int test_3_4_binary(uint32_t value)
{
	return lookup_table[value & lsbyte_mask];
}
