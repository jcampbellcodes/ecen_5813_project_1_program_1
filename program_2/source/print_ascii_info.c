/*
 * @file print_ascii_info.c
 * @brief Contains a function that can output information about an ASCII code.
 *
 * @details Contains defines and utilities for printing out ASCII types.
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */
#include <ctype.h>
#include <stdio.h>
#include "print_ascii_info.h"

const char* const DISPLAY_LOWER_CASE = "Lower Case";
const char* const DISPLAY_UPPER_CASE = "Upper Case";
const char* const DISPLAY_DIGIT = "Digit";
const char* const DISPLAY_WHITE_SPACE = "White Space";
const char* const DISPLAY_SPECIAL = "Special";

/**
 * @brief
 * @param inCode
 * @return
 */
const char* get_ascii_type_string(uint8_t inCode)
{
    if(islower(inCode))
    {
        return DISPLAY_LOWER_CASE;
    }
    else if(isupper(inCode))
    {
        return DISPLAY_UPPER_CASE;
    }
    else if(isdigit(inCode))
    {
        return DISPLAY_DIGIT;
    }
    else if(isspace(inCode))
    {
        return DISPLAY_WHITE_SPACE;
    }
    else
    {
        return DISPLAY_SPECIAL;
    }
}

void print_ascii_info(uint8_t inCode)
{
    const uint32_t BUFFER_SIZE = 256;
    const uint32_t LEFT_COLUMN_WIDTH = 15;
    const uint32_t CENTER_COLUMN_WIDTH = 25;
    const uint32_t COLUMN_WIDTHS[2] = {LEFT_COLUMN_WIDTH, CENTER_COLUMN_WIDTH};
    char buffer[BUFFER_SIZE];

    uint32_t usedWidth = sprintf(buffer, "\nCode: %d", inCode);
    printf("%s%*s", buffer, COLUMN_WIDTHS[0] - usedWidth, "");

    usedWidth = sprintf(buffer, "Type: %s", get_ascii_type_string(inCode));
    printf("%s%*s", buffer, COLUMN_WIDTHS[1] - usedWidth, "");

    printf("ASCII Char: %c", inCode);
}