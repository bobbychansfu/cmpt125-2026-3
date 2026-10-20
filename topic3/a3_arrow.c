#include <stdio.h>

typedef struct {
    int x;
    int y;
} point_t;

void moveRight(point_t *p, int dx) {
    p->x += dx;            // same as (*p).x += dx
}

int main(void) {
    point_t a = {3, 4};
    moveRight(&a, 5);
    printf("a = (%d, %d)\n", a.x, a.y);
    return 0;
}
