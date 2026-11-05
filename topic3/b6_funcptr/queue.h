
#ifndef QUEUE_H
#define QUEUE_H

#include "LL.h"

typedef struct queue {
    LL_t *intlist;
    void (*destroy)(struct queue *q);            // pointers to functions,
    int  (*isEmpty)(struct queue *q);            // not the functions themselves
    void (*enqueue)(struct queue *q, int element);
    int  (*dequeue)(struct queue *q);
} queue_t;

// Creates a new empty queue, with its function pointers filled in.
// Returns NULL on failure.
queue_t *queue_create(void);

#endif
