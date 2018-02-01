#include <stdio.h>

unsigned srl(unsigned x, int k) {
    int xsrl = (int)x >> k;
    int w = 8 * sizeof(int);

    unsigned z = 2 << (w - k -1);
    return (z - 1) & xsrl;
}

int sra(int x, int k) {
    int xsra = (unsigned)x >> k;
    int w = sizeof(int) << 3;

    unsigned z = 1 << (w - k - 1);
    unsigned mask = z - 1;

    unsigned right = xsra & mask;
    unsigned left = ~mask & (~(z & xsra) + z);

    return left | right;
}

int main(void) {
    unsigned t1 = srl(100, 2);
    unsigned t2 = (unsigned)100 >> 2;
    printf("%d----%d \n", t1, t2);

    int t3 = sra(100, 2);
    int t4 = 100 >> 2;
    printf("%d----%d \n", t3, t4);

    int t5 = sra(-100, 2);
    int t6 = -100 >> 2;
    printf("%d----%d \n", t5, t6);
}



