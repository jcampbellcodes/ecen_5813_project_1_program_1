// TODO:
// refactor repeated code -- command pattern?
// make sure that all the print representation functions make sense as one
// bring out constants from magic numbers
// break functions into their own files
// break types into a helper file
// add command line input?
// replace bit operations with macros
// make sure those char buffers are

#include "print_helpers.h"



int main(int argc, const char * argv[])
{
    const int8_t NUM_INPUTS = 11;
    const int8_t NUM_ARGS_PER_INPUT = 3;
    int32_t inputs[NUM_INPUTS][NUM_ARGS_PER_INPUT] =
    {
        {-6, 10, 4},
        {-6, 9, 4},
        {-6, 10, 5},
        {-9, 10, 4},
        {237, 10, 8},
        {0354, 8, 8},
        {0xEB, 16, 8},
        {-125, 10, 8},
        {65400, 10, 8},
        {65400, 10, 16},
        {-32701, 10, 16}
    };
    
    for(int8_t iter = 0; iter < NUM_INPUTS; iter++)
    {
        print_numerical_representations(inputs[iter][0], inputs[iter][1], inputs[iter][2]);
    }
    
    return 0;
}
