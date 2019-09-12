/*
 * @file print_binary.h
 * @brief Utilities for printing binary representations of unsigned 32 bit integers.

 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */

#ifndef PROJECT_PRINT_BINARY_H
#define PROJECT_PRINT_BINARY_H

#include <stdint.h>

/**
 * print_bin
 * @brief Prints a binary representation of a unsigned 32 bit integer
 * @param inNum The value to print as binary
 * @param inOpSize How many bits of the number to print
 * @return None
 */
void print_bin(uint32_t inNum, uint32_t inOpSize);

#endif //PROJECT_PRINT_HELPERS_H
