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

/**
 * The display strings corresponding to the ASCII types.
 */
const char* const DISPLAY_LOWER_CASE = "Lower Case";
const char* const DISPLAY_UPPER_CASE = "Upper Case";
const char* const DISPLAY_DIGIT = "Digit";
const char* const DISPLAY_WHITE_SPACE = "White Space";
const char* const DISPLAY_SPECIAL = "Special";

/**
 * Memory buffer size used as a scratch buffer when printing
 */
#define SCRATCH_BUFFER_SIZE 256

/**
 * get_ascii_type_string
 * @brief Private function that parses the ASCII code and gives back the type string
 * @param inCode The code to parse
 * @return A string corresponding to the ASCII type. Lower, upper, digit, whitespace, or special
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

/**
 * print_ascii_info
 * @brief Given an ASCII code, prints the code, type of ASCII, and character value
 * @param inCode The code to print
 * @return None
 */
void print_ascii_info(uint8_t inCode)
{
    const uint32_t LEFT_COLUMN_WIDTH = 15;
    const uint32_t CENTER_COLUMN_WIDTH = 25;
    const uint32_t COLUMN_WIDTHS[2] = {LEFT_COLUMN_WIDTH, CENTER_COLUMN_WIDTH};
    static char SCRATCH_BUFFER[SCRATCH_BUFFER_SIZE] = {0};

    uint32_t usedWidth = sprintf(SCRATCH_BUFFER, "\nCode: %d", inCode);
    printf("%s%*s", SCRATCH_BUFFER, COLUMN_WIDTHS[0] - usedWidth, "");

    usedWidth = sprintf(SCRATCH_BUFFER, "Type: %s", get_ascii_type_string(inCode));
    printf("%s%*s", SCRATCH_BUFFER, COLUMN_WIDTHS[1] - usedWidth, "");

    printf("ASCII Char: %c", inCode);
}