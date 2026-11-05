/* driver.c -- misusing a queue whose type is really a linked list.
 */
#include <stdio.h>
#include "LL.h"
#include "queue.h"

typedef LL_t stack_t;       // someone else's stack, built the same way

int main() {
    queue_t *Q = queue_create();
    queue_enqueue(Q, 1);    
    queue_enqueue(Q, 2);    
    queue_enqueue(Q, 3);    

    LLprepend(Q, 99);       // BAD
    LLprint(Q);             // BAD

    stack_t *S = LLcreate();
    queue_enqueue(S, 7);    // BAD

    while (!queue_isEmpty(Q)) {
        printf("%d ", queue_dequeue(Q));
    }
    printf("\n");

    LLdestroy(S);
    queue_destroy(Q);
    return 0;
}
