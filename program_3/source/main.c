#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "rotate_and_print.h"


int main(int argc, const char * argv[])
{
    uint32_t CAFE = 0xCAFE;
    printf("%s", rotate_and_print(&CAFE, 0));
    printf("%s", rotate_and_print(&CAFE, 8)); // flips a short
    printf("%s", rotate_and_print(&CAFE, 12)); // same as rotate left 4
    printf("%s", rotate_and_print(&CAFE, 8));
    return 0;
}