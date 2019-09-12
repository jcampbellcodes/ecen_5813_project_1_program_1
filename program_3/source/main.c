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