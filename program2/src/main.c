/*
 * @file main.c
 * @brief a program that characterizes ascii inputs.  It was a design 
 *        choice to case out the ascii boundaries so that additional
 *        libraries did not have to be included which would bloat code
 *        size
 * @author Troy Davis
 * @date 9/5/19
 * @version 0.1
 * 
 */

#include <stdio.h>
#include <stdint.h>
#include "../test/unit_test.h"

int main(int argc, char *argv[])  
{ 
	/* iterate over test vals and test functionality */
	for (int i=0; i<TEST_COUNT; i++) {
		uint8_t val = test_values[i];
		
		/* white space */
		if (val >= 0  && val <= 32) {
			printf("Code: %d\t  Type: White Space\t ASCII Char: %d\n", val, val);
		}
		
		/* special character */ 
		else if ((val >= 33  && val <= 47) || (val >= 58  && val <= 63)) {
			printf("Code: %d\t Type: Lower Case\t ASCII Char: %d\n", val, val);
		}
		
		/* digit */
		else if (val >= 48  && val <= 57) {
			printf("Code: %d\t Type: Digit\t ASCII Char: %d\n", val, val);
		}
		 
		/* upper case */
		else if (val >= 65  && val <= 90) {
			printf("Code: %d\t Type: Upper Case\t ASCII Char: %d\n", val, val);
		}
		
		/* lower case */
		else if (val >= 97  && val <= 122) {
			printf("Code: %d\t Type: Lower Case\t ASCII Char: %d\n", val, val);
		}
		
		else {
			printf("Did not recognize character %d... skipping\n", val);
		}
	}
}



