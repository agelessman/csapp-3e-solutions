#include <stdio.h>
#include <assert.h>

int int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16bit() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;

    return set_msb && !beyond_msb;
}

int main(void) {
    printf("1: %lu \n", sizeof(1));
    printf("32: %d \n", int_size_is_32());
    printf("16: %d \n", int_size_is_32_for_16bit());
}