// 该题目要求，只要奇数位有1，就返回1，否则返回0

#include <stdio.h>
/* Return 1 when any odd bit of x equals 1, 0 otherwise.
   Assume w = 32.
*/
int any_odd_one(unsigned x) {
    return !!(x & 0x55555555);
}

int main(void) {
    int result = any_odd_one((unsigned)5);
    printf("The result of 5: %d \n", result);

    int result1 = any_odd_one((unsigned)2);
    printf("The result of 2: %d \n", result1);
}