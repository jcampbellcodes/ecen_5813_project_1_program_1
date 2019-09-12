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
    const uint32_t COLUMN_WIDTHS[2] = {15, 25};
    // TODO: get rid of magic number for char buffer
    char buffer[20];
    uint32_t usedWidth = sprintf(buffer, "\nCode: %d", inCode);
    printf("%s%*s", buffer, COLUMN_WIDTHS[0] - usedWidth, "");

    usedWidth = sprintf(buffer, "Type: %s", get_ascii_type_string(inCode));
    printf("%s%*s", buffer, COLUMN_WIDTHS[1] - usedWidth, "");

    printf("ASCII Char: %c", inCode);
}