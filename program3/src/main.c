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
#include "binary.h"

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
