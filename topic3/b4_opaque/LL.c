/* LL.c -- implementation of LL.h */
#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

LL_t *LLcreate(void) {
    LL_t *L = malloc(sizeof(LL_t));
    if (L != NULL) {
        L->head = NULL;
        L->tail = NULL;
    }
    return L;
}

void LLdestroy(LL_t *L) {
    if (L == NULL) return;
    node_t *curr = L->head;
    while (curr != NULL) {
        node_t *next = curr->next;   /* save it BEFORE freeing curr */
        free(curr);
        curr = next;
    }
    free(L);
}

/* Post: returns a new node holding x with next == NULL; exits if out of memory. */
static node_t *newNode(int x) {
    node_t *n = malloc(sizeof(node_t));
    if (n == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    n->data = x;
    n->next = NULL;
    return n;
}

void LLappend(LL_t *L, int x) {
    node_t *n = newNode(x);
    if (L->head == NULL) {          /* empty list: head changes too */
        L->head = n;
    } else {
        L->tail->next = n;
    }
    L->tail = n;
}

void LLprepend(LL_t *L, int x) {
    node_t *n = newNode(x);
    n->next = L->head;
    L->head = n;
    if (L->tail == NULL) {          /* list was empty: tail changes too */
        L->tail = n;
    }
}

int LLremoveHead(LL_t *L) {
    node_t *old = L->head;
    int x = old->data;
    L->head = old->next;
    if (L->head == NULL) {          /* list is now empty */
        L->tail = NULL;
    }
    free(old);
    return x;
}

int LLlength(const LL_t *L) {
    int count = 0;
    for (const node_t *curr = L->head; curr != NULL; curr = curr->next) {
        count++;
    }
    return count;
}

void LLprint(const LL_t *L) {
    printf("[");
    for (const node_t *curr = L->head; curr != NULL; curr = curr->next) {
        printf("%d%s", curr->data, (curr->next != NULL) ? ", " : "");
    }
    printf("]\n");
}

LL_t *LLfromArray(const int arr[], int n) {
    LL_t *L = LLcreate();
    for (int i = 0; i < n; i++) {
        LLappend(L, arr[i]);
    }
    return L;
}
