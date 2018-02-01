#include <stdio.h>
#include <assert.h>

unsigned f2u(float x) {
    return *(unsigned *)&x;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return sx == sy ? (sx == 0 ? ux <= uy : ux >= uy) : sx > sy;
}


int main() {
    assert(float_le(+0, -0));
    assert(float_le(0, 3));
    assert(float_le(-4.12, -0));
    assert(float_le(-4, 4));

    return 0;
}