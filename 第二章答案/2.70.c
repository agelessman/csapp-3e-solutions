#include <stdio.h>
#include <assert.h>

// 如果x的二进制可以用n位表示就返回1，
/*
   * Assume w = 8, n = 3
   * if x > 0
   *   0b00000110 is ok, 0b00001010 is not
   *   first w-n bits must be 0
   * if x < 0
   *   0b11111100 is ok, 0b10111100 is not, and 0b11111000 is not yet
   *   first w-n+1 bits must be 1
   */
int fits_bits(int x, int n) {
    int w = sizeof(int) << 3;
    x >>= n - 1;

    /*
     * !(x >> 1) 用于判断x大于0的情况
     * !~x 用于判断x小于0的情况
     */
    return !(x >> 1) || !~x;
}

int main(void) {
    assert(fits_bits(0xFF, 8));
    assert(!fits_bits(0xFFFFFF00, 8));
    return 0;
}