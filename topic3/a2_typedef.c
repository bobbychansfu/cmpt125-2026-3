#include <stdio.h>

typedef struct {
    int x;
    int y;
} point_t;

int main(void) {
    point_t corners[2] = { {0, 0}, {640, 480} };
    printf("%d x %d\n", corners[1].x, corners[1].y);
    return 0;
}
