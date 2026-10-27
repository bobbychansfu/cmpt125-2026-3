#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *items;      // items[0..length-1] are in use
    int length;
    int capacity;
} intarray_t;

void append(intarray_t *a, int x) {
    if (a->length == a->capacity) {          // full: double it
        int *bigger = realloc(a->items, 2 * a->capacity * sizeof(int));
        if (bigger == NULL) exit(1);         // out of memory
        a->items = bigger;
        a->capacity *= 2;
    }
    a->items[a->length++] = x;
}
int main(void){ 
    intarray_t a = { malloc(sizeof(int)), 0, 1 }; 
    for (int i=0;i<100;i++) 
        append(&a,i); 
    printf("%d %d %d\n", a.length, a.capacity, a.items[99]); 
    free(a.items); 
    return 0; 
}
