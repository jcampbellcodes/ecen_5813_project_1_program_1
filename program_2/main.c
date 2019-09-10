#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

const char* const DISPLAY_LOWER_CASE = "Lower Case";
const char* const DISPLAY_UPPER_CASE = "Upper Case";
const char* const DISPLAY_DIGIT = "Digit";
const char* const DISPLAY_WHITE_SPACE = "White Space";
const char* const DISPLAY_SPECIAL = "Special";

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
