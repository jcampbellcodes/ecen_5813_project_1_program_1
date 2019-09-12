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

/**
 * @brief
 * @param value
 * @param rotateAmt
 * @return
 */
const char* rotate_and_print(uint32_t* value, uint32_t rotateAmt)
{
    if(!value)
        return "";

    *value = rotateRight(*value, rotateAmt);
    printf("0x%X\n", (uint16_t)*value);
    print_bin(*value, 16);
    printf(" -> 3 of last 4 bits are on?");
    return lastThreeBitsOn(*value) ? " true\n" : " false\n";
}