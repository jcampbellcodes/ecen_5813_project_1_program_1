// TODO:
// refactor repeated code -- command pattern?
// bring out constants from magic numbers
// use platform independent integer widths
// break functions into their own files
// break types into a helper file
// add command line input?
// replace bit operations with macros

// When given an invalid radix, do we still print the minimum and maximum for the operand size?

// System includes
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// User includes
#include "constants.h"
#include "custom_types.h"

struct NumReprs parseNumeric(int32_t inRawNum, uint32_t inOpSize)
{
    struct NumReprs outNum = {0};
    outNum.dec = inRawNum;
    outNum.dec_abs = (uint32_t)ABS(inRawNum);
    int32_t mask = (1<<inOpSize)-1;
    outNum.ones_comp = (~(outNum.dec_abs)) & mask;
    outNum.twos_comp = outNum.ones_comp + 1;
    outNum.sign_mag = inRawNum < 0 ? (outNum.dec_abs & mask) | 1<<(inOpSize-1):
                                     (outNum.dec_abs & mask) & 0<<(inOpSize-1);
    
    return outNum;
};

void print_nibble(uint8_t inNum)
{
    const uint16_t NIBBLE_SIZE = 4;
    uint8_t maskedNibble = inNum & (uint8_t)0x0F;
    for(int32_t bit = NIBBLE_SIZE - 1; bit >= 0; bit--)
    {
        if(maskedNibble & (1 << bit))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

// refactor:
// more elegant way to groom data for the print nibble func?
void print_bin(uint32_t inNum, uint32_t inOpSize)
{
    const uint16_t NIBBLE_SIZE = 4;
    const uint32_t NUM_NIBBLES = inOpSize/NIBBLE_SIZE;
    
    union NumToBytesType
    {
        uint32_t num;
        uint8_t bytes[4];
    } numToBytes;

    numToBytes.num = inNum;
    
    bool lowNibble = true;
    uint8_t nibbles[8] = {0};
    int16_t byteIter = 0;
    for(int16_t nibbleIter = 0; nibbleIter < 8; nibbleIter++)
    {
        if(lowNibble)
        {
            nibbles[nibbleIter] = numToBytes.bytes[byteIter] & (uint8_t)0x0F;
        }
        else
        {
            nibbles[nibbleIter] = numToBytes.bytes[byteIter] >> 4;
            byteIter++;
        }
        lowNibble = !lowNibble;
    }
    
    for(int32_t i = NUM_NIBBLES-1; i >= 0; i--)
    {
        print_nibble(nibbles[i]);
    }
}




bool canBeRepresented(struct NumReprs inNum, uint32_t inOpSize, enum OutputType inType)
{
    const double operandStorage = (1 << inOpSize) - 1;
    const double operandStorageSignedMag =(1 << (inOpSize-1)) - 1;

    switch(inType)
    {
        case Binary:
        {
            return inNum.dec_abs <= operandStorage;
        }
        case Octal:
        {
            return true;
        }
        case Decimal:
        {
            return true;
        }
        case Hexadecimal:
        {
            return inNum.dec_abs <= operandStorage;
        }
        case SignedOnesComplement:
        {
            return inNum.dec_abs  <= operandStorage;
        }
        case SignedTwosComplement:
        {
            return inNum.dec_abs <= operandStorage;
        }
        case SignMagnitude:
        {
            return inNum.dec_abs <= operandStorageSignedMag;

        }
        default:
            return false;
    }
}

void print_numerical_representation(struct NumReprs inNum, uint32_t inRadix, uint32_t inOpSize, enum OutputType inType)
{
    const int32_t  columnWidth = (inOpSize + 5); //TODO REMOVE MAGIC NUMBER

    if((4 == inOpSize || 8 == inOpSize || 16 == inOpSize) &&
       (8 == inRadix || 10 == inRadix || 16 == inRadix) &&
       canBeRepresented(inNum, inOpSize, inType))
    {
        switch(inType)
        {
            case Binary:
            {
                printf("0b");
                print_bin(inNum.dec_abs, inOpSize);
                printf("   ");
                return;
            }
            case Octal:
            {
                char buffer[50];
                uint32_t  sz = sprintf(buffer, "%#o", ABS(inNum.dec));
                printf("%s%*s", buffer, columnWidth - sz ,"");
                return;
            }
            case Decimal:
            {
                char buffer[50];
                uint32_t  sz = sprintf(buffer, "%d", ABS(inNum.dec));
                printf("%s%*s", buffer, columnWidth - sz ,"");
                return;
            }
            case Hexadecimal:
            {
                char buffer[50];
                uint32_t  sz = sprintf(buffer, "0x%X", ABS(inNum.dec));
                printf("%s%*s", buffer, columnWidth - sz ,"");
                return;
            }
            case SignedOnesComplement:
            {
                printf("0b"); print_bin(inNum.ones_comp, inOpSize);
                printf("   ");
                return;
            }
            case SignedTwosComplement:
            {
                printf("0b"); print_bin(inNum.twos_comp, inOpSize);
                printf("   ");
                return;
            }
            case SignMagnitude:
            {
                printf("0b"); print_bin(inNum.sign_mag, inOpSize);
                printf("   ");
                return;
            }
            default:
                break; // Will go to error condition printing below
        }
    }
    printf("Error%*s", inOpSize, "");
}

void print_maximum_representation(int32_t inRadix, uint32_t inOpSize, enum OutputType inType)
{
    const int32_t  columnWidth = (inOpSize + 5); //TODO REMOVE MAGIC NUMBER
    const uint32_t operandStorage = (uint32_t)((1 << inOpSize) - 1);
    const uint32_t operandStorageSignedMag = (uint32_t)((1 << (inOpSize-1)) - 1);
    
    if((4 == inOpSize || 8 == inOpSize || 16 == inOpSize) &&
       (8 == inRadix || 10 == inRadix || 16 == inRadix))
    {
        switch(inType)
        {
            case Binary:
            {
                printf("0b");
                print_bin((uint32_t)operandStorage, inOpSize);
                printf("   ");
                return;
            }
            case Octal:
            {
                char buffer[50];
                int sz = sprintf(buffer, "%#o", operandStorage);
                printf("%s%*s", buffer, columnWidth - sz ,"");
                return;
            }
            case Decimal:
            {
                char buffer[50];
                int sz = sprintf(buffer, "%d", operandStorage);
                printf("%s%*s", buffer, columnWidth - sz ,"");
                return;
            }
            case Hexadecimal:
            {
                char buffer[50];
                uint32_t  sz = sprintf(buffer, "0x%X", operandStorage);
                printf("%s%*s", buffer, columnWidth - sz ,"");
                return;
            }
            case SignedOnesComplement:
            {
                printf("0b");
                print_bin((uint32_t)operandStorageSignedMag, inOpSize);
                printf("   ");
                return;
            }
            case SignedTwosComplement:
            {
                printf("0b");
                print_bin((uint32_t)operandStorageSignedMag+1, inOpSize);
                printf("   ");
                return;
            }
            case SignMagnitude:
            {
                printf("0b");
                print_bin((uint32_t)operandStorageSignedMag, inOpSize);
                printf("   ");
                return;
            }
            default:
                break; // Will go to error condition printing below
        }
    }
    printf("Error%*s", inOpSize, "");
}

void print_minimum_representation(int32_t inRadix, uint32_t inOpSize, enum OutputType inType)
{

    const uint32_t operandStorage = (uint32_t)((1 << inOpSize) - 1);
    const uint32_t operandStorageSignedMag = (uint32_t)(1 << (inOpSize-1));
    
    if((4 == inOpSize || 8 == inOpSize || 16 == inOpSize) &&
       (8 == inRadix || 10 == inRadix || 16 == inRadix))
    {
        switch(inType)
        {
            case Binary:
            {
                printf("0b");
                print_bin(0, inOpSize);
                return;
            }
            case Octal:
            {
                printf("0");
                return;
            }
            case Decimal:
            {
                printf("0");
                return;
            }
            case Hexadecimal:
            {
                const uint16_t NIBBLE_SIZE = 4;
                const int32_t numNibbles = inOpSize/NIBBLE_SIZE;
                printf("0x%0*d", numNibbles, 0);
                return;
            }
            case SignedOnesComplement:
            {
                printf("0b");
                print_bin((uint32_t)operandStorageSignedMag, inOpSize);
                printf("   ");
                return;
            }
            case SignedTwosComplement:
            {
                printf("0b");
                print_bin((uint32_t)operandStorageSignedMag+1, inOpSize);
                printf("   ");
                return;
                break;
            }
            case SignMagnitude:
            {
                printf("0b");
                print_bin((uint32_t)operandStorage, inOpSize);
                printf("   ");
                return;
            }
            default:
                break; // Will go to error condition printing below
        }
    }
    printf("Error%*s", inOpSize, "");
}

void print_numerical_representations(int32_t inRawNum, int32_t inRadix, int32_t inOpSize)
{
    static const char* labelOutput =         "\nOutput:                    ";
    static const char* labelBinary =         "\nBinary (abs)               ";
    static const char* labelOctal =          "\nOctal (abs)                ";
    static const char* labelDecimal =        "\nDecimal (abs)              ";
    static const char* labelHexadecimal =    "\nHexadecimal (abs)          ";
    static const char* labelOnesComplement = "\nSigned One's Complement    ";
    static const char* labelTwosComplement = "\nSigned Two's Complement    ";
    static const char* labelSignMagnitude =  "\nSign-Magnitude             ";

    struct NumReprs nr = parseNumeric(inRawNum, inOpSize);
    printf("Raw num: %d  Radix: %d  OpSize: %d\n", inRawNum, inRadix, inOpSize);
    printf("%s%s%*s%*s", labelOutput, "Value", inOpSize+2+5, "Maximum", inOpSize+2+3, "Minimum");
    
    printf("%s", labelBinary);
    print_numerical_representation(nr, inRadix, inOpSize, Binary);
    print_maximum_representation(inRadix, inOpSize, Binary);
    print_minimum_representation(inRadix, inOpSize, Binary);
    
    printf("%s", labelOctal);
    print_numerical_representation(nr, inRadix, inOpSize, Octal);
    print_maximum_representation(inRadix, inOpSize, Octal);
    print_minimum_representation(inRadix, inOpSize, Octal);
    
    printf("%s", labelDecimal);
    print_numerical_representation(nr, inRadix, inOpSize, Decimal);
    print_maximum_representation(inRadix, inOpSize, Decimal);
    print_minimum_representation(inRadix, inOpSize, Decimal);
    
    printf("%s", labelHexadecimal);
    print_numerical_representation(nr, inRadix, inOpSize, Hexadecimal);
    print_maximum_representation(inRadix, inOpSize, Hexadecimal);
    print_minimum_representation(inRadix, inOpSize, Hexadecimal);
    
    printf("%s", labelOnesComplement);
    print_numerical_representation(nr, inRadix, inOpSize, SignedOnesComplement);
    print_maximum_representation(inRadix, inOpSize, SignedOnesComplement);
    print_minimum_representation(inRadix, inOpSize, SignedOnesComplement);
    
    printf("%s", labelTwosComplement);
    print_numerical_representation(nr, inRadix, inOpSize, SignedTwosComplement);
    print_maximum_representation(inRadix, inOpSize,  SignedTwosComplement);
    print_minimum_representation(inRadix, inOpSize, SignedTwosComplement);
    
    printf("%s", labelSignMagnitude);
    print_numerical_representation(nr, inRadix, inOpSize, SignMagnitude);
    print_maximum_representation(inRadix, inOpSize, SignMagnitude);
    print_minimum_representation(inRadix, inOpSize, SignMagnitude);
    printf("\n\n");
}

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
