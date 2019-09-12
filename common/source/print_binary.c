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

#include "print_binary.h"

// System includes
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief
 */
static const uint16_t NIBBLE_SIZE = 4;

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
    uint8_t nibbles[NIBBLE_SIZE * 2] = {0};
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
