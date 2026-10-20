#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} point_t;

point_t *makePoint(int x, int y) {
    point_t *p = malloc(sizeof(point_t));
    p->x = x;
    p->y = y;
    return p;
}

int main(void) {
    point_t *p = makePoint(3, 4);
    printf("(%d, %d)\n", p->x, p->y);
    return 0;                      // forgot free(p)
}