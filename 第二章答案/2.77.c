#include <stdio.h>
#include <assert.h>

// K = 17
int A(int x) {
    return (x << 4) + x;
}

// K = -7
int B(int x) {
    return x - (x << 3);
}

// K = 60
int C(int x) {
    return (x << 6) - (x << 2);
}

// K = -112
int D(int x) {
    return (x << 4) - (x << 7);
}

int main() {
    int x = 0x12345678;

    assert(A(x) == x * 17);
    assert(B(x) == x * -7);
    assert(C(x) == x * 60);
    assert(D(x) == x * -112);

    printf("Passed.\n");
    return 0;
}