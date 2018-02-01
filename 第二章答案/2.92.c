#include <stdio.h>
#include <assert.h>

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    unsigned sig = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    int is_nan = (exp == 0xFF && frac != 0);
    if (is_nan) {
        return f;
    }

    return ~sig << 31 | exp << 23 | frac;
}

int main() {
    printf("%u", float_negate(32.0));
    assert(float_negate(32.0) == -32.0);
    return 0;
}