#include <stdio.h>
#include "queue.h"

int main() {
    queue_t *Q = queue_create();
    for (int i = 1; i <= 3; i++) {
        Q->enqueue(Q, i);                     // the caller's notation: Q appears twice
    }
    while (!Q->isEmpty(Q)) {
        printf("%d ", Q->dequeue(Q));
    }
    printf("\n");
    Q->destroy(Q);
    return 0;
}
