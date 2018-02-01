#include <stdio.h>
#include <assert.h>
#include <limits.h>

// c语言的除法要求向0取整，除法本质上就是右移操作
int divide_power2(int x, int k) {
    int is_neg = x & INT_MIN;
    (is_neg && (x = x + (1 << k) - 1));
    return x >> k;
}

int main(int argc, char* argv[]) {
  int x = 0x80000007;
  assert(divide_power2(x, 1) == x / 2);
  assert(divide_power2(x, 2) == x / 4);

  printf("%d", x);
  return 0;
}
