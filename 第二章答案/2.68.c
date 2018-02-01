#include <stdio.h>
#include <assert.h>

int lower_one_mask(int n) {
    int w = sizeof(int) << 3;
    return (unsigned)-1 >> (w - n);
}

int main(void) {
    assert(lower_one_mask(6) == 0x3F);
    assert(lower_one_mask(17) == 0x1FFFF);
    assert(lower_one_mask(32) == 0xFFFFFFFF);
    return 0;
}