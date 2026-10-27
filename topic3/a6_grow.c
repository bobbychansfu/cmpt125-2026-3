#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;
    int length;
    int capacity;
} intarray_t;

/* Post: x is appended; the array doubles when full. */
void append(intarray_t *a, int x) {
    if (a->length == a->capacity) {
        a->capacity *= 2;
        a->items = realloc(a->items, a->capacity * sizeof(int));
    }
    a->items[a->length++] = x;
}

int main(void) {
    intarray_t a = { malloc(1 * sizeof(int)), 0, 1 };
    long copies = 0;
    for (int i = 0; i < 1000000; i++) {
        if (a.length == a.capacity) copies += a.length;
        append(&a, i);
    }
    printf("1000000 appends, %ld copies, capacity %d\n", copies, a.capacity);
    free(a.items);
    return 0;
}
