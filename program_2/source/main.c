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

#include "print_ascii_info.h"
#include <stdint.h>

/**
 * @brief
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char * argv[])
{
    const int8_t NUM_INPUTS = 20;
    uint8_t inputs[NUM_INPUTS] = {66,114,117,99,101,32,83,97,121,115,32,72,105,33,7,9,50,48,49,57};

    for(int8_t iter = 0; iter < NUM_INPUTS; iter++)
    {
        print_ascii_info(inputs[iter]);
    }
    return 0;
}
