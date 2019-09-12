/*
 * @file File Name and Description
 * @brief File
 *
 * @details
 *
 * @author Jack Campbell
 * @tools (compiler, linker, debugger)
 * LEVERAGED CODE
 * LINKS
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