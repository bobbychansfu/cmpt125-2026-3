#include <stdlib.h>
#include "LL.h"
#include "queue.h"

// The functions themselves. "static" makes them private to this file:
// users can only reach them through the pointers stored in each queue.
static void destroy(queue_t *q) {
    LLdestroy(q->intlist);
    free(q);
}

static int isEmpty(queue_t *q) {
    return q->intlist->head == NULL;
}

static void enqueue(queue_t *q, int element) {
    LLappend(q->intlist, element);
}

static int dequeue(queue_t *q) {          // Undefined behaviour if queue is empty
    return LLremoveHead(q->intlist);
}

queue_t *queue_create(void) {
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL) return NULL;
    q->intlist = LLcreate();
    q->destroy = destroy;                     // store the addresses of the functions
    q->isEmpty = isEmpty;
    q->enqueue = enqueue;
    q->dequeue = dequeue;
    return q;
}
