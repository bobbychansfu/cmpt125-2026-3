
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BTnode {
    int data;
    struct BTnode *left;
    struct BTnode *right;
} BTnode_t;

// Post: returns a new leaf node holding data, or NULL if malloc fails.
BTnode_t *BTnode_create(int data) {
    BTnode_t *n = malloc(sizeof(BTnode_t));
    if (n == NULL) return NULL;
    n->data  = data;
    n->left  = NULL;
    n->right = NULL;
    return n;
}

// Post: frees every node in the tree.  root may be NULL.
void BTdestroy(BTnode_t *root) {
    if (root == NULL) return;
    BTdestroy(root->left);
    BTdestroy(root->right);
    free(root);
}

int main() {
    BTnode_t *root = BTnode_create(10);
    root->left  = BTnode_create(5);
    root->right = BTnode_create(21);
    printf("root->data        = %d\n", root->data);
    printf("BTis_leaf(root)   = %d\n", BTis_leaf(root));
    printf("BTis_leaf(left)   = %d\n", BTis_leaf(root->left));
    BTdestroy(root);
    return 0;
}
