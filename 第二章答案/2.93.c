#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float_bits float_absval(float_bits f) {
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nan = (exp == 0xFF && frac != 0);
    if (is_nan) {
        return f;
    }

    return 0 << 31 | exp << 23 | frac;
}

int main() {
    printf("%u\n", float_absval(32.0));
    return 0;
}