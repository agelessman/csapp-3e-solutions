#include <stdio.h>
#include <assert.h>

// 1. 先使用或加位移让第一个1的后边都是1
// 2. 然后取非后右移一位后，最右边的1就是我们想要的掩码
// 3. 由于上边得到的那个1就是原值中的第一个1的位置，因此&上原值就清空了1前边的位
int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x & (~x >> 1);
}

int main(void) {
    assert(leftmost_one(0xff00) == 0x8000);
    assert(leftmost_one(0x6600) == 0x4000);
    return 0;
}