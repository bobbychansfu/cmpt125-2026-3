#include <stdlib.h>
#include "LL.h"
#include "queue.h"

queue_t *queue_create(void) { 
    return LLcreate(); 
}

void queue_destroy(queue_t *q) { 
    LLdestroy(q); 
}

int queue_isEmpty(queue_t *q) { 
    return q->head == NULL; 
}

void queue_enqueue(queue_t *q, int element) { 
    LLappend(q, element); 
}

int queue_dequeue(queue_t *q) { 
    return LLremoveHead(q); 
}
