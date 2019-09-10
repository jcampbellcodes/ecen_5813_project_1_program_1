//
// Created by Jack Campbell on 2019-09-10.
//

#ifndef PROJECT_CUSTOM_TYPES_H
#define PROJECT_CUSTOM_TYPES_H

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

#endif //PROJECT_CUSTOM_TYPES_H
