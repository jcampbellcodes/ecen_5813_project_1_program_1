//
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h> // TODO: Optimize out this include?
#include <math.h>

enum OutputType
{
    Binary,
    Octal,
    Decimal,
    Hexadecimal,
    SignedOnesComplement,
    SignedTwosComplement,
    SignMagnitude
};

struct NumReprs
{
    int32_t dec;
    uint32_t dec_abs;
    uint32_t ones_comp;
    uint32_t twos_comp;
    uint32_t sign_mag;
};

struct NumReprs parseNumeric(int32_t inRawNum, int32_t inRadix, uint32_t inOpSize)
{
    // TODO: Right now just assumes that the raw num will not need ot be converted.
    // May need to add "octalToDec" and "hexToDec" converters.
    struct NumReprs outNum = {0};
    outNum.dec = inRawNum;
    outNum.dec_abs = (uint32_t)abs(inRawNum);
    int32_t mask = (1<<inOpSize)-1;
    outNum.ones_comp = (~(outNum.dec_abs)) & mask;
    outNum.twos_comp = outNum.ones_comp + 1;
    outNum.sign_mag = inRawNum < 0 ? (outNum.dec_abs & mask) | 1<<(inOpSize-1):
                                     (outNum.dec_abs & mask) & 0<<(inOpSize-1);
    
    return outNum;
};

const char* getOutputString(struct NumReprs inNum, enum OutputType inType, int32_t inOpSize);

const char* toBinary(uint32_t inNum, uint32_t inNumBits);

bool canRepresentNum(struct NumReprs inNum, enum OutputType inType, int32_t inOpSize);

// https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
const char *bit_rep[16] = {
    [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
    [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
    [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};
void printNibble(uint8_t inNum)
{
    printf("%s", bit_rep[inNum & 0x0F]);
}

void print_bin(uint32_t inNum, size_t inOpSize)
{
    const uint16_t NIBBLE_SIZE = 4;
    const int16_t numNibbles = inOpSize/NIBBLE_SIZE;
    
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
            nibbles[nibbleIter] = numToBytes.bytes[byteIter] & 0x0F;
        }
        else
        {
            nibbles[nibbleIter] = numToBytes.bytes[byteIter] >> 4;
            byteIter++;
        }
        lowNibble = !lowNibble;
    }
    
    for(int32_t i = numNibbles-1; i >= 0; i--)
    {
        printNibble(nibbles[i]);
    }
}


static const char* labelOutput =         "Output:                    ";
static const char* labelBinary =         "\nBinary (abs)               ";
static const char* labelOctal =          "\nOctal (abs)                ";
static const char* labelDecimal =        "\nDecimal (abs)              ";
static const char* labelHexadecimal =    "\nHexadecimal (abs)          ";
static const char* labelOnesComplement = "\nSigned One's Complement    ";
static const char* labelTwosComplement = "\nSigned Two's Complement    ";
static const char* labelSignMagnitude =  "\nSign-Magnitude             ";

void print_numerical_representation(struct NumReprs inNum, int32_t inRadix, int32_t inOpSize, enum OutputType inType)
{
    // error conditions:
    // opSize != 4, 8, or 16
    // radix != 8, 10, or 16
    // inNum > (2 ^ radix) - 1
    const double operandStorage = pow(2, inOpSize) - 1;
    const double operandStorageSignedMag = pow(2, inOpSize-1) - 1;

    if((4 == inOpSize || 8 == inOpSize || 16 == inOpSize) &&
       (8 == inRadix || 10 == inRadix || 16 == inRadix))
    {
        switch(inType)
        {
            case Binary:
            {
                if(inNum.dec_abs <= operandStorage)
                {
                    printf("0b"); print_bin(inNum.dec_abs, inOpSize);
                }
                else
                {
                    printf("Error");
                }
                
                return;
            }
            case Octal:
            {
                printf("%#o", abs(inNum.dec));
                return;
            }
            case Decimal:
            {
                printf("%d", abs(inNum.dec));
                return;
            }
            case Hexadecimal:
            {
                printf("0x%X", abs(inNum.dec));
                return;
            }
            case SignedOnesComplement:
            {
                if(inNum.dec_abs  <= operandStorage)
                {
                    printf("0b"); print_bin(inNum.ones_comp, inOpSize);
                }
                else
                {
                    printf("Error");
                }
                return;
            }
            case SignedTwosComplement:
            {
                if(inNum.dec_abs <= operandStorage)
                {
                    printf("0b"); print_bin(inNum.twos_comp, inOpSize);
                }
                else
                {
                    printf("Error");
                }
                return;
            }
            case SignMagnitude:
            {
                if(inNum.dec_abs <= operandStorageSignedMag)
                {
                    printf("0b"); print_bin(inNum.sign_mag, inOpSize);
                }
                else
                {
                    printf("Error");
                }
                
                return;
            }
            default:
                printf("FATAL ERROR.");
        }
    }
    
    printf("Error");
    return;

}

void print_numerical_representations(int32_t inRawNum, int32_t inRadix, int32_t inOpSize)
{
    struct NumReprs nr = parseNumeric(inRawNum, inRadix, inOpSize);
    printf("%s Raw num: %d  Radix: %d  OpSize: %d", labelOutput, inRawNum, inRadix, inOpSize);
    printf("%s", labelBinary);         print_numerical_representation(nr, inRadix, inOpSize, Binary);
    printf("%s", labelOctal);          print_numerical_representation(nr, inRadix, inOpSize, Octal);
    printf("%s", labelDecimal);        print_numerical_representation(nr, inRadix, inOpSize, Decimal);
    printf("%s", labelHexadecimal);    print_numerical_representation(nr, inRadix, inOpSize, Hexadecimal);
    printf("%s", labelOnesComplement); print_numerical_representation(nr, inRadix, inOpSize, SignedOnesComplement);
    printf("%s", labelTwosComplement); print_numerical_representation(nr, inRadix, inOpSize, SignedTwosComplement);
    printf("%s", labelSignMagnitude);  print_numerical_representation(nr, inRadix, inOpSize, SignMagnitude);
    printf("\n\n");
}

int main(int argc, const char * argv[])
{
    const int8_t NUM_INPUTS = 11;
    const int8_t NUM_ARGS_PER_INPUT = 3;
    int inputs[NUM_INPUTS][NUM_ARGS_PER_INPUT] =
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
