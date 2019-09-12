/*
 * @file print_ascii_info.h
 * @brief Contains a function that can output information about an ASCII code.
 *
 * @details As requested in the project, the criteria we use for what constitutes an uppercase, lowercase,
 *          digit, white space, or special ASCII digit is based on the helper functions available in ctype.h.
 *          "Special" is designated as any character that is not alphanumeric or whitespace.
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */

#ifndef PROJECT_PRINT_ASCII_INFO_H
#define PROJECT_PRINT_ASCII_INFO_H

#include <stdint.h>

/**
 * print_ascii_info
 * @brief Given an ASCII code, prints the code, type of ASCII, and character value
 * @param inCode The code to print
 * @return None
 */
void print_ascii_info(uint8_t inCode);

#endif //PROJECT_GET_ASCII_TYPE_STRING_H
