/*
 * @file main.c
 * @brief a program that takes a numeric input, a radix, and a operand
 *        size then checks for valid inputs and prints conversions of
 *        each value
 * @author Troy Davis
 * @date 9/10/19
 * @version 0.1
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[])  
{ 
	uint32_t number;
	uint8_t radix;
	uint16_t operand;
	
	/* check if the correct nubmer of inputs were recieved */
	if (argc != 4) {
		printf("Recieved %d arguments, but expected 3\n", argc);
		printf("Exiting...");
		return 0;
	}

	/* check if parameters are valid */
	
	
	/* print table of inputs converted values */
	
}
