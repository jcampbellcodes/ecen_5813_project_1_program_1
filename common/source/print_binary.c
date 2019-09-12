/*
 * @file print_binary.c
 * @brief Utilities for printing binary representations of unsigned 32 bit integers.

 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */

#include "print_binary.h"

// System includes
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief
 */
static const uint16_t NIBBLE_SIZE = 4;
static const uint16_t BYTE_SIZE = 8;

/**
 * @brief
 * @param inNum
 */
void print_nibble(uint8_t inNum)
{
    const uint8_t maskedNibble = (inNum & (uint8_t)0x0F);
    for(int32_t bit = NIBBLE_SIZE - 1; bit >= 0; bit--)
    {
        if(maskedNibble & (1 << bit))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

/**
 * @brief
 * @param inNum
 * @param inOpSize
 */
void print_bin(uint32_t inNum, uint32_t inOpSize)
{
    const uint32_t NUM_NIBBLES = inOpSize/NIBBLE_SIZE;

    union NumToBytesType
    {
        uint32_t num;
        uint8_t bytes[NIBBLE_SIZE];
    } numToBytes;
    numToBytes.num = inNum;

    // Grooming the nibbles into their own bytes
    bool lowNibble = true;
    uint8_t nibbles[BYTE_SIZE];
    int16_t byteIter = 0;
    for(int16_t nibbleIter = 0; nibbleIter < NIBBLE_SIZE * 2; nibbleIter++)
    {
        if(lowNibble)
        {
            nibbles[nibbleIter] = numToBytes.bytes[byteIter] & (uint8_t)0x0F;
        }
        else
        {
            nibbles[nibbleIter] = numToBytes.bytes[byteIter] >> 4;
            byteIter++;
        }
        lowNibble = !lowNibble;
    }

    // iterate over the nibbles
    for(int32_t i = NUM_NIBBLES-1; i >= 0; i--)
    {
        print_nibble(nibbles[i]);
    }
}
