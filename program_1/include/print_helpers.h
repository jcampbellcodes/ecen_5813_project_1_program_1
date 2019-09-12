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

#ifndef PROJECT_PRINT_HELPERS_H
#define PROJECT_PRINT_HELPERS_H

#include <stdint.h>

/**
 * @brief
 * @param inRawNum
 * @param inRadix
 * @param inOpSize
 */
void print_numerical_representations(int32_t inRawNum, int32_t inRadix, int32_t inOpSize);

/**
 * @brief
 * @param inRawNum
 * @param inOpSize
 * @return
 */
struct NumReprs parse_numeric(int32_t inRawNum, uint32_t inOpSize);

/**
 * @brief
 * @param inNum
 * @param inOpSize
 * @param inType
 * @return
 */
bool canBeRepresented(struct NumReprs inNum, uint32_t inOpSize, enum OutputType inType);

/**
 * @brief
 * @param inNum
 * @param inOpSize
 * @param inType
 */
void print_numerical_representation(struct NumReprs inNum, uint32_t inOpSize, enum OutputType inType);

/**
 * @brief
 * @param inOpSize
 * @param inType
 */
void print_max_min_representation(uint32_t inOpSize, enum OutputType inType);

#endif //PROJECT_PRINT_HELPERS_H
