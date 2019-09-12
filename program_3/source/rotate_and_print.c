//
// Created by Jack Campbell on 2019-09-11.
//

// System includes
#include <stdio.h>

// User includes
#include "rotate_and_print.h"
#include "print_binary.h"

// from lecture
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define lastThreeBitsOn(value) (bitRead(value, 0) && bitRead(value, 1) && bitRead(value, 2))
#define rotateRight(value, shiftAmt) (uint32_t)((value >> shiftAmt)|(value << (16 - shiftAmt)))

const char* rotate_and_print(uint32_t* value, uint32_t rotateAmt)
{
    if(!value)
        return "";

    *value = rotateRight(*value, rotateAmt);
    printf("0x%X\n", (uint16_t)*value);
    print_bin(*value, 16);
    printf(" -> 3 of last 4 bits are on?");
    return lastThreeBitsOn(*value) ? " true\n" : " false\n";
}