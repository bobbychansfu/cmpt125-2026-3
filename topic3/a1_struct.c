#include <stdio.h>

struct point {
    int x;
    int y;
};

void change_point(struct point p){
    p.x = 1;
    p.y = 2;
}

int main(void) {
    struct point p = {3, 4};
    struct point q = p;        // copies BOTH fields
    q.x = 10;
    change_point(q); // does not change q
    printf("p = (%d, %d)\n", p.x, p.y);
    printf("q = (%d, %d)\n", q.x, q.y);
    return 0;
}
