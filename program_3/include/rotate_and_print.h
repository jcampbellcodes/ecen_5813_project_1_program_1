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
#ifndef PROJECT_ROTATE_AND_PRINT_H
#define PROJECT_ROTATE_AND_PRINT_H

#include <stdint.h>

// From Slide 31 of "More C Topics" lecture from ECEN 5813
// https://canvas.colorado.edu/courses/53078/files/folder/Class%20FIles?preview=7085601

/**
 * @brief
 */
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)

/**
 * @brief
 */
#define lastThreeBitsOn(value) (bitRead(value, 0) && bitRead(value, 1) && bitRead(value, 2))

/**
 * @brief
 */
#define rotateRight(value, shiftAmt) (uint32_t)((value >> shiftAmt)|(value << (16 - shiftAmt)))

/**
 * @brief
 * @param value
 * @param rotateAmt
 * @return
 */
const char* rotate_and_print(uint32_t* value, uint32_t rotateAmt);

#endif //PROJECT_ROTATE_AND_PRINT_H
