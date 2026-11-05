typedef struct queue queue_t;          // no fields!
queue_t *queue_create(void);
void queue_destroy(queue_t *q);
int  queue_isEmpty(queue_t *q);
void queue_enqueue(queue_t *q, int x);
int  queue_dequeue(queue_t *q);
