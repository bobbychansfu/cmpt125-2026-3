
#ifndef LL_H
#define LL_H

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct {
    node_t *head;
    node_t *tail;
} LL_t;

/* Post: returns a pointer to a new, empty list (or NULL if out of memory). */
LL_t *LLcreate(void);

/* Post: every node of L, and L itself, has been freed. L may be NULL. */
void LLdestroy(LL_t *L);

/* Post: a new node holding x is the last node of L. */
void LLappend(LL_t *L, int x);

/* Post: a new node holding x is the first node of L. */
void LLprepend(LL_t *L, int x);

/* Pre:  L is not empty.
 * Post: the first node is removed and freed; its data is returned. */
int LLremoveHead(LL_t *L);

/* Post: returns the number of nodes in L. */
int LLlength(const LL_t *L);

/* Post: prints the list as  [a, b, c]  followed by a newline. */
void LLprint(const LL_t *L);

/* Post: returns a new list holding arr[0..n-1] in order. (Handy for testing.) */
LL_t *LLfromArray(const int arr[], int n);

#endif
