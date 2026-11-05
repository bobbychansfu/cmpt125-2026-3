
#ifndef QUEUE_H
#define QUEUE_H

#include "LL.h"

typedef LL_t queue_t;

// Creates a pointer to a new empty queue.
// Returns NULL on failure.
queue_t *queue_create(void);

// Recycles a queue
void queue_destroy(queue_t *q);

// Returns 1 iff queue is empty
int queue_isEmpty(queue_t *q);

// Adds element to the back of the queue
void queue_enqueue(queue_t *q, int element);

// Removes element from the front of the queue.
// Undefined behaviour if queue is empty
int queue_dequeue(queue_t *q);

#endif
