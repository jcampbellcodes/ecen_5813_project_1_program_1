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

#include <stdint.h>
#include <stdbool.h>
#include "custom_types.h"

/**
 * @brief
 * @param inRawNum
 * @param inRadix
 * @param inOpSize
 */
void print_numerical_representations(int32_t inRawNum, int32_t inRadix, int32_t inOpSize);

#endif //PROJECT_PRINT_HELPERS_H
