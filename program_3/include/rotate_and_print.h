/*
 * @file rotate_and_print.h
 * @brief Helper macros and public interface for rotating and printing a number
 *
 * @details Made to follow along with the steps for program 3 of project 1
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 *
 *  Leveraged code:
 *  - bitRead macro is from Slide 31 of "More C Topics" lecture from ECEN 5813
 *  Link: https://canvas.colorado.edu/courses/53078/files/folder/Class%20FIles?preview=7085601
 *
 *  - rotateRight macro is adapted from a GeeksForGeeks article:
 *  Link: https://www.geeksforgeeks.org/rotate-bits-of-an-integer/
 */
#ifndef PROJECT_ROTATE_AND_PRINT_H
#define PROJECT_ROTATE_AND_PRINT_H

#include <stdint.h>

/**
 * Define for how many bits are in a short. Used in the rotateRight macro
 */
#define NUM_SHORT_BITS 16

/**
 * - bitRead macro is from Slide 31 of "More C Topics" lecture from ECEN 5813
 *  Link: https://canvas.colorado.edu/courses/53078/files/folder/Class%20FIles?preview=7085601
 *  Given a numeric value and a bit to check, returns whether the requested bit is on or off
 */
#define bitRead(value, bit) (((value) >> (bit)) & 0x01UL)

/**
 * - rotateRight macro is adapted from a GeeksForGeeks article:
 *  Link: https://www.geeksforgeeks.org/rotate-bits-of-an-integer/
 *  Given a numeric value and a shift amount, returns a value shifted to the right by that amount
 *  while wrapping around.
 */
#define rotateRight(value, shiftAmt) (uint32_t)((value >> shiftAmt)|(value << (NUM_SHORT_BITS - shiftAmt)))

/**
 * lastThreeBitsOn
 * Given a numeric value, returns whether the last three bits of that value are on.
 */
#define lastThreeBitsOn(value) (bitRead(value, 0UL) && bitRead(value, 1UL) && bitRead(value, 2UL))


/**
 * rotate_and_print
 * @brief Given a pointer to a number, rotate that number in place by a specified amount.
 * @param value A pointer to the value to rotate
 * @param rotateAmt The amount to rotate the number to the right
 * @return A string, true or false, describing whether the last three bits are on.
 */
const char* rotate_and_print(uint32_t* value, uint32_t rotateAmt);

#endif //PROJECT_ROTATE_AND_PRINT_H
