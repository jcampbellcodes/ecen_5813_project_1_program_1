/*
 * @file binary.c
 * @brief library with binary related operations
 * @author Troy Davis
 * @date 9/11/19
 * @version 0.1
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include "binary.h"

const uint8_t lookup_table[16] = {0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1};
const uint8_t lsbyte_mask = 0x0F;
const uint16_t msb_mask = 0x8000;
const uint16_t lsb_mask = 0x0001;
 
void test_34_binary(uint16_t value)
{	
	if (lookup_table[value & lsbyte_mask] == 1) {
		printf(" (3 of 4 bits on: True)\n");
	}
	else {
		printf(" (3 of 4 bits on: False)\n");
	}
}

/* citing code found at: https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format */
/* code found here was modified to fit needs */
void print_binary(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    printf("Binary: ");
    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
}

uint16_t rotate_left(uint8_t rotate_n, uint16_t value) 
{
	for (uint8_t i=0; i<rotate_n; i++) {
		uint16_t msb_bit = (value & msb_mask) >> 15;
		value = (value << 1) | msb_bit;
	}
	return value;
}

uint16_t rotate_right(uint8_t rotate_n, uint16_t value) 
{
	for (uint8_t i=0; i<rotate_n; i++) {
		uint16_t lsb_bit = (value & lsb_mask) << 15;
		value = (value >> 1) | lsb_bit;
	}
	return value;
}

