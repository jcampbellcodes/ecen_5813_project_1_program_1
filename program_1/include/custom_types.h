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
