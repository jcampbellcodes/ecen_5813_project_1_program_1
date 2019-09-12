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

#ifndef PROJECT_PRINT_ASCII_INFO_H
#define PROJECT_PRINT_ASCII_INFO_H

#include <stdint.h>

/**
 * @brief
 * @param inCode
 * @return
 */
const char* get_ascii_type_string(uint8_t inCode);

/**
 * @brief
 * @param inCode
 */
void print_ascii_info(uint8_t inCode);

#endif //PROJECT_GET_ASCII_TYPE_STRING_H
