#include <stdio.h>
#include <assert.h>
#include <limits.h>

// 该函数是饱和加法，当正溢出，取最大整数，负溢出，取最小整数
int saturationg_add(int x, int y) {
    int sum = x + y;
    int sig_mask = INT_MIN;

    // 如果x > 0 y > 0 sum < 0 正溢出
    // 如果x < 0 y < 0 sum > 0 负溢出
    int pos_over = !(x & sig_mask) && !(y & sig_mask) && (sum & sig_mask);
    int neg_over = (x & sig_mask) && (y & sig_mask) && !(sum & sig_mask);

    (pos_over && (sum = INT_MAX)) || (neg_over && (sum = INT_MIN));

    return sum;
}


int main() {
    assert(INT_MAX == saturationg_add(INT_MAX, 0x1234));
    assert(INT_MIN == saturationg_add(INT_MIN, -0x1234));
    assert(0x12 + 0x34 == saturationg_add(0x12, 0x34));

    return 0;
}