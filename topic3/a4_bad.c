typedef struct { int x; int y; } point_t;
point_t *makePointBad(int x, int y) {
    point_t p = {x, y};
    return &p;
}
int main(void) { point_t *p = makePointBad(1,2); return p != 0; }
