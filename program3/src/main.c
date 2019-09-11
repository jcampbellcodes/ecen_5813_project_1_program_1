/*
 * @file main.c
 * @brief program to demonstrate bit manipulation
 * @author Troy Davis
 * @date 9/5/19
 * @version 0.1
 * 
 */

#include <stdio.h>
#include <stdint.h>


//TODO: move out of main
void print_binary(size_t const size, void const * const ptr);
void test_34_binary(uint16_t val);
uint16_t rotate_left(uint8_t rotate_n, uint16_t value);
uint16_t rotate_right(uint8_t rotate_n, uint16_t value);

int main(int argc, char *argv[]) 
{ 
	uint16_t val= 0xCAFE;
	
	/* print original input in hex */
	printf("Original Value: %X\n", val);
	
	/* test if 3 of the last 4 bits are on and print in binary */
	print_binary(sizeof(val), &val);
	test_34_binary(val);
	
	/* reverse byte order and print in hex */
	printf("Reversing byte order...\n");
	printf("Implement me!\n");
	
	/* test if 3 of last 4 bits are on and print in binary */
	print_binary(sizeof(val), &val);
	test_34_binary(val);
	
	/* rotate the value 4 bits to left and print in hex */
	printf("Rotating value 4 bits to the left...\n");
	val = rotate_left(4, val);
	printf("New value: %X\n", val);
	
	/* test if 3 of last 4 bits are on and print in binary */
	print_binary(sizeof(val), &val);
	test_34_binary(val);
	
	/* rotate the value by eight bits to the right and print in hex */
	printf("Rotating value 8 bits to the right...\n");
	val = rotate_right(8, val);
	printf("New value: %X\n", val);
	
	/* test if 3 of last 4 bits are on and print in binary */
	print_binary(sizeof(val), &val);
	test_34_binary(val);
}


// TODO: probably move all these helpers into different file(s)
void test_34_binary(uint16_t value)
{
	//TODO: these should move and only be initialized once
	const uint8_t lookup_table[16] = {0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1};
	const uint8_t lsb_bitmask = 0x0F;
	
	if (lookup_table[value & lsb_bitmask] == 1) {
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

uint16_t rotate_left(uint8_t rotate_n, uint16_t value) {
	uint16_t msb_mask = 0x8000;
	
	for (uint8_t i=0; i<rotate_n; i++) {
		uint16_t msb_bit = (value & msb_mask) >> 15;
		value = (value << 1) | msb_bit;
	}
	return value;
}

uint16_t rotate_right(uint8_t rotate_n, uint16_t value) {
	uint16_t msb_mask = 0x0001;
	
	for (uint8_t i=0; i<rotate_n; i++) {
		uint16_t msb_bit = (value & msb_mask) << 15;
		value = (value >> 1) | msb_bit;
	}
	return value;
}
