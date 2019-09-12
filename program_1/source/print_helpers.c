/*
 * @file print_helpers.c
 * @brief Contains private functions to support the print_numerical_representations interface
 *        which works together to generate the number representation table for program 1
 *
 * @author Jack Campbell
 * @tools Tools used to generate output files:
 *         Compiler: GCC 8.3.0
 *         Linker: GNU ld 2.32
 *         Debugger: GNU gdb 8.2.91.20190405-git
 */

// System includes
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// User includes
#include "custom_types.h"
#include "print_helpers.h"
#include "print_binary.h"
#include "abs.h"

/**
 * @brief
 */
static const char* labelOutput =         "\nOutput:                    ";
static const char* labelBinary =         "\nBinary (abs)               ";
static const char* labelOctal =          "\nOctal (abs)                ";
static const char* labelDecimal =        "\nDecimal (abs)              ";
static const char* labelHexadecimal =    "\nHexadecimal (abs)          ";
static const char* labelOnesComplement = "\nSigned One's Complement    ";
static const char* labelTwosComplement = "\nSigned Two's Complement    ";
static const char* labelSignMagnitude =  "\nSign-Magnitude             ";


/**
 * @brief
 * @param inRawNum
 * @param inOpSize
 * @return
 */
struct NumReprs parse_numeric(int32_t inRawNum, uint32_t inOpSize)
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

/**
 * @brief
 * @param inNum
 * @param inOpSize
 * @param inType
 * @return
 */
bool canBeRepresented(struct NumReprs inNum, uint32_t inOpSize, enum OutputType inType)
{
    const uint32_t operandStorage = (uint32_t)((1 << inOpSize) - 1);
    const uint32_t operandStorageSignedMag = (uint32_t)((1 << (inOpSize-1)) - 1);

    switch(inType)
    {
        case Octal:
        case Decimal:
        {
            return true;
        }
        case Binary:
        case Hexadecimal:
        case SignedOnesComplement:
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

/**
 * @brief
 * @param inNum
 * @param inOpSize
 * @param inType
 */
void print_numerical_representation(struct NumReprs inNum, uint32_t inOpSize, enum OutputType inType)
{
    const int32_t columnWidth = (inOpSize + 5); //TODO REMOVE MAGIC NUMBER
    if(canBeRepresented(inNum, inOpSize, inType))
    {
        // TODO replace with a call into a function table for each number type
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
    else
    {
        printf("Error%*s", inOpSize, "");
    }
}

/**
 * @brief
 * @param inOpSize
 * @param inType
 */
void print_max_min_representation(uint32_t inOpSize, enum OutputType inType)
{
    const uint32_t columnWidth = (inOpSize + 5); //TODO REMOVE MAGIC NUMBER
    const uint32_t operandStorage = (uint32_t)((1 << inOpSize) - 1);
    const uint32_t operandStorageSignedMag = (uint32_t)((1 << (inOpSize-1)) - 1);

    switch(inType)
    {
        case Binary:
        {
            // max
            printf("0b");
            print_bin((uint32_t)operandStorage, inOpSize);
            printf("   ");

            //min
            printf("0b");
            print_bin(0, inOpSize);
            return;
        }
        case Octal:
        {
            // max
            char buffer[50];
            int sz = sprintf(buffer, "%#o", operandStorage);
            printf("%s%*s", buffer, columnWidth - sz ,"");

            //min
            printf("0");
            return;
        }
        case Decimal:
        {
            // max
            char buffer[50];
            int sz = sprintf(buffer, "%d", operandStorage);
            printf("%s%*s", buffer, columnWidth - sz ,"");

            // min
            printf("0");
            return;
        }
        case Hexadecimal:
        {
            //max
            char buffer[50];
            uint32_t  sz = sprintf(buffer, "0x%X", operandStorage);
            printf("%s%*s", buffer, columnWidth - sz ,"");

            //min
            const uint16_t NIBBLE_SIZE = 4;
            const int32_t numNibbles = inOpSize/NIBBLE_SIZE;
            printf("0x%0*d", numNibbles, 0);
            return;
        }
        case SignedOnesComplement:
        {
            // max
            printf("0b");
            print_bin((uint32_t)operandStorageSignedMag, inOpSize);
            printf("   ");

            // min
            printf("0b");
            print_bin((uint32_t)operandStorageSignedMag, inOpSize);
            printf("   ");
            return;
        }
        case SignedTwosComplement:
        {
            // max
            printf("0b");
            print_bin((uint32_t)operandStorageSignedMag+1, inOpSize);
            printf("   ");

            // min
            printf("0b");
            print_bin((uint32_t)operandStorageSignedMag+1, inOpSize);
            printf("   ");
            return;
        }
        case SignMagnitude:
        {
            // max
            printf("0b");
            print_bin((uint32_t)operandStorageSignedMag, inOpSize);
            printf("   ");

            //min
            printf("0b");
            print_bin((uint32_t)operandStorage, inOpSize);
            printf("   ");
            return;
        }
        default:
            break; // Will go to error condition printing below
    }
}

/**
 * @brief
 * @param inRawNum
 * @param inRadix
 * @param inOpSize
 */
void print_numerical_representations(int32_t inRawNum, int32_t inRadix, int32_t inOpSize)
{
    // groom radix and inOpSize
    if((4 == inOpSize || 8 == inOpSize || 16 == inOpSize) &&
       (8 == inRadix || 10 == inRadix || 16 == inRadix))
    {
        // radix and operand size are now guaranteed >= 0
        const uint32_t opSize = (uint32_t)inOpSize;

        struct NumReprs nr = parse_numeric(inRawNum, opSize);
        printf("\nTable for: { Number: %d, Radix: %d, Operand Size: %d }", inRawNum, inRadix, inOpSize);
        printf("%s%s%*s%*s", labelOutput, "Value", inOpSize+2+5, "Maximum", inOpSize+2+3, "Minimum");

        printf("%s", labelBinary);
        print_numerical_representation(nr, opSize, Binary);
        print_max_min_representation(opSize, Binary);

        printf("%s", labelOctal);
        print_numerical_representation(nr, opSize, Octal);
        print_max_min_representation(opSize, Octal);

        printf("%s", labelDecimal);
        print_numerical_representation(nr, opSize, Decimal);
        print_max_min_representation(opSize, Decimal);

        printf("%s", labelHexadecimal);
        print_numerical_representation(nr, opSize, Hexadecimal);
        print_max_min_representation(opSize, Hexadecimal);

        printf("%s", labelOnesComplement);
        print_numerical_representation(nr, opSize, SignedOnesComplement);
        print_max_min_representation(opSize, SignedOnesComplement);

        printf("%s", labelTwosComplement);
        print_numerical_representation(nr, opSize, SignedTwosComplement);
        print_max_min_representation(opSize, SignedTwosComplement);

        printf("%s", labelSignMagnitude);
        print_numerical_representation(nr, opSize, SignMagnitude);
        print_max_min_representation(opSize, SignMagnitude);
        printf("\n");
    }
    else
    {
        printf("\nError: Input set { Number: %d, Radix: %d, Operand Size: %d } "
               "is invalid -- aborting table generation.\n",
               inRawNum,
               inRadix,
               inOpSize);
    }
}