/*
 * @file custom_types.h
 * @brief Contains types used by Program One to organize various representations of integral types.
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */
#ifndef PROJECT_CUSTOM_TYPES_H
#define PROJECT_CUSTOM_TYPES_H

/**
 * @brief
 */
enum OutputType
{
    Binary,
    Octal,
    Decimal,
    Hexadecimal,
    SignedOnesComplement,
    SignedTwosComplement,
    SignMagnitude
};

/**
 * @brief
 */
struct NumReprs
{
    int32_t dec;
    uint32_t dec_abs;
    uint32_t ones_comp;
    uint32_t twos_comp;
    uint32_t sign_mag;
};

#endif //PROJECT_CUSTOM_TYPES_H
