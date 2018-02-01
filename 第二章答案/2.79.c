#include <stdio.h>
#include <limits.h>
#include <assert.h>

/*
 * 在这个题目中的除以4中我们需要注意的是取整问题，因此需要用到题目2.78的函数
 */

int divide_power2(int x, int k) {
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) -1));
    return x >> k;
}

int mul3div4(int x) {
    int mul3 = (x << 1) + x;
    return divide_power2(mul3, 2);
}


int main() {
    int t = 0x12345678;
    assert(mul3div4(t) == (t * 3 / 4));
    return 0;
}

