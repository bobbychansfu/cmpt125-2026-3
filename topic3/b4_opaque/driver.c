#include <stdio.h>
#include "queue.h"
int main(void) {
    queue_t *q = queue_create();
    for (int i = 1; i <= 3; i++)
        queue_enqueue(q, i);
    while (!queue_isEmpty(q))
        printf("%d ", queue_dequeue(q));
    printf("\n");
    queue_destroy(q);
    return 0;
}
