#include <stdlib.h>
typedef struct node { int data; struct node *next; } node_t;
typedef struct { node_t *head; node_t *tail; } LL_t;
void LLdestroyWrong(LL_t *L) {
    for (node_t *curr = L->head; curr != NULL; curr = curr->next) {
        free(curr);
    }
    free(L);
}
int main(void) {
    LL_t *L = malloc(sizeof(LL_t));
    node_t *a = malloc(sizeof(node_t)), *b = malloc(sizeof(node_t));
    a->data = 1; a->next = b; b->data = 2; b->next = NULL;
    L->head = a; L->tail = b;
    LLdestroyWrong(L);
    return 0;
}
