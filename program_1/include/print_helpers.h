/*
 * @file print_helpers.h
 * @brief Exposes a function that can be used to generate the numerical representation table
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */

#ifndef PROJECT_PRINT_HELPERS_H
#define PROJECT_PRINT_HELPERS_H

// System includes
#include <stdint.h>
#include <stdbool.h>

// User includes
#include "custom_types.h"

/**
 * print_numerical_representations
 * @brief Generates and prints a table of various representations of a numeric value
 * @param inRawNum The raw number to display numeric representations of
 * @param inRadix The radix of inRawNum. Must be 8, 10, or 16
 * @param inOpSize The operand size of inRawNum. Must be 4, 8, or 16
 * @return None
 */
void print_numerical_representations(int32_t inRawNum, int32_t inRadix, int32_t inOpSize);

#endif //PROJECT_PRINT_HELPERS_H
