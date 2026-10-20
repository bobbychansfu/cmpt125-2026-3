#include <stdlib.h>
 
int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}
 
int main(void) {
    int v[] = {88, 56, 100, 2, 25};
    qsort(v, 5, sizeof v[0], cmp_int);
    return 0;
}
