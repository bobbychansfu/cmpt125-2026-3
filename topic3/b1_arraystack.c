#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *items;      // items[0..top-1]; top item is items[top-1]
    int top;
    int capacity;
} stack_arr_t;

void push(stack_arr_t *s, int x) {
    if (s->top == s->capacity) { // full
        int *bigger = realloc(s->items,
              2 * s->capacity * sizeof(int));
        if (bigger == NULL) exit(1);
        s->items = bigger;
        s->capacity *= 2;
    }
    s->items[s->top++] = x;
}

// Pre: not empty
int pop(stack_arr_t *s) { 
    return s->items[--s->top]; 
}  

int isEmpty(const stack_arr_t *s) { 
    return s->top == 0; 
}

int main(void) {
    stack_arr_t s = { malloc(2 * sizeof(int)), 0, 2 };
    for (int i = 1; i <= 5; i++) push(&s, i * 10);
    while (!isEmpty(&s)) printf("%d ", pop(&s));
    printf("\n");
    free(s.items);
    return 0;
}
