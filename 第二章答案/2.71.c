#include <stdio.h>
#include <assert.h>

typedef unsigned packet_t;

// 该函数的作用是取出一个字中的某个字节，然后把该字节扩展为有符号整数
// 难点在于如何利用算数右移填充前边的位
// 核心思想就是先把目前字节左移到最高位，然后再利用算数右移
int xbyte(packet_t word, int bytenum) {
    int size = sizeof(unsigned);
    int shift_left_val = (size - 1 - bytenum) << 3;
    int shift_right_val = (size - 1) << 3;
    return (int)word << shift_left_val >> shift_right_val;
}

int main(void) {
    assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
    assert(xbyte(0x00112233, 2) == 0x11);
    return 0;
}