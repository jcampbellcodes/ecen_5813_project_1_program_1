/*
 * @file binary.h
 * @brief library with binary related operations
 * @author Troy Davis
 * @date 9/11/19
 * @version 0.1
 * 
 */
 
#ifndef INC_BINARY_H_
#define INC_BINARY_H_

void test_34_binary(uint16_t value);
void print_binary(size_t const size, void const * const ptr);
uint16_t rotate_left(uint8_t rotate_n, uint16_t value);
uint16_t rotate_right(uint8_t rotate_n, uint16_t value);

#endif /* INC_BINARY_H_ */
