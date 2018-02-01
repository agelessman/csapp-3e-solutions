#include <stdio.h>

int int_shifts_are_arithmetic() {
    int i = -1;
    return (i >> 1) == -1;
}

int main(void) {
    printf("%d", int_shifts_are_arithmetic());
}