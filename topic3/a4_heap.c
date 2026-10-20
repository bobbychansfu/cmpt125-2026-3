#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point_t;

point_t *makePoint(int x, int y) {
    point_t *p = malloc(sizeof(point_t));
    if (p == NULL) return NULL;    // out of memory
    p->x = x;
    p->y = y;
    return p;                      // still alive after return
}

int main(void) {
    point_t *p = makePoint(3, 4);
    printf("(%d, %d)\n", p->x, p->y);
    free(p);                       // exactly once
    p = NULL;
    return 0;
}
