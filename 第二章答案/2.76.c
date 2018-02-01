#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

void *another_calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    size_t buff_size = nmemb * size;
    if (nmemb == buff_size / size) {
        void *ptr = malloc(buff_size);
        memset(ptr, 0, buff_size);
        return ptr;
    }

    return NULL;
}


int main() {
    void *p;
    p = another_calloc(0x1234, 1);
    assert(p != NULL);
    free(p);

    p = another_calloc(SIZE_MAX, 2);
    assert(p == NULL);
    free(p);

    return 0;
}