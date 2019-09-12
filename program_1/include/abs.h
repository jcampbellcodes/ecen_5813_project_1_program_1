/*
 * @file ans.h
 * @brief Defines a macro that takes the absolute value of a number
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 *
 * @details Leveraged code in this file includes the ABS macro, taken from
 *          Slide 30 of "More C Topics" lecture from ECEN 5813
 *          Link: https://canvas.colorado.edu/courses/53078/files/folder/Class%20FIles?preview=7085601
 */

#ifndef PROJECT_CONSTANTS_H
#define PROJECT_CONSTANTS_H

/**
 * @brief
 */
#define ABS(x) ((x)>0?(x):-(x))

#endif //PROJECT_CONSTANTS_H
