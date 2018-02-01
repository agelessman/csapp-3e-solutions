#include <stdio.h>
#include <assert.h>
#include <limits.h>

// 该函数用于检查两个整数相减会不会产生溢出
// 这个和上边的题目很相似，可以把x-y看做x+（-y）
int tsub_ok(int x, int y) {
    // 当y为最小整数的时候，就产生了溢出，因为任何数减最小数都会溢出
    if (y == INT_MIN) {
        return 0;
    }

    int neg_y = -y;
    int sum = x + neg_y;
    int pos_over = x > 0 && neg_y > 0 && sum < 0;
    int neg_over = x < 0 && neg_y < 0 && sum >= 0;

    return !(pos_over || neg_over);
}


int main(int argc, char* argv[]) {
  assert(!tsub_ok(0x00, INT_MIN));
  assert(tsub_ok(0x00, 0x00));
  return 0;
}
