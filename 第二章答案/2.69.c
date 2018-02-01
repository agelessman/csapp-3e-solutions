#include <stdio.h>
#include <assert.h>

unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    unsigned t = x << n;
    unsigned t1 = x >> (w - n - 1) >> 1;
    return t | t1;
}

int main(void) {
    assert(rotate_left(0x12345678, 4) == 0x23456781);
    assert(rotate_left(0x12345678, 20) == 0x67812345);
    assert(rotate_left(0x12345678, 0) == 0x12345678);
    return 0;
}