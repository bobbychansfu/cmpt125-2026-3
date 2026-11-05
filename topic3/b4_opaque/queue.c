#include <stdlib.h>
#include "LL.h"
#include "queue.h"

struct queue
{ // the ONLY place the fields appear
    LL_t *list;
};

queue_t *queue_create(void)
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q != NULL)
        q->list = LLcreate();
    return q;
}
void queue_destroy(queue_t *q)
{
    if (q)
    {
        LLdestroy(q->list);
        free(q);
    }
}

int queue_isEmpty(queue_t *q) { 
    return q->list->head == NULL; 
}

void queue_enqueue(queue_t *q, int x) { 
    LLappend(q->list, x); 
}

int queue_dequeue(queue_t *q) { 
    return LLremoveHead(q->list); 
}
