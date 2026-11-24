/* Binary Search Tree */
#include <stdio.h>
#include <stdlib.h>

typedef struct BTnode {
    int data;
    struct BTnode *left;
    struct BTnode *right;
} BTnode_t;

/** Create a new binary tree node with the given data. */
BTnode_t *BTnode_create(int data) {
    BTnode_t *n = malloc(sizeof(BTnode_t));
    if (n == NULL)
        return NULL;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

/* Create a new binary tree node with the given data and children. */
BTnode_t *node(int d, BTnode_t *l, BTnode_t *r) {
    BTnode_t *n = BTnode_create(d);
    n->left = l;
    n->right = r;
    return n;
}

void BTdestroy(BTnode_t *r)
{
    if (r == NULL)
        return;
    BTdestroy(r->left);
    BTdestroy(r->right);
    free(r);
}

//  Returns the new root of the binary search tree
BTnode_t *BSTinsert(BTnode_t *root, int key)
{
    //  Base case: an empty subtree is where the new node goes
    if (root == NULL)
        return BTnode_create(key); //  malloc -- there is no new in C

    if (key < root->data) //  Insert into left subtree
        root->left = BSTinsert(root->left, key);
    else //  root->data <= key
        root->right = BSTinsert(root->right, key);
    return root;
}

/** In-order traversal of the binary tree */
void in(const BTnode_t *r)
{
    if (!r)
        return;
    in(r->left);
    printf("%d ", r->data);
    in(r->right);
}

int main()
{
    int keys[] = {41, 26, 58, 16, 33, 46, 72};
    BTnode_t *root = NULL;
    for (int i = 0; i < 7; i++)
        root = BSTinsert(root, keys[i]);
    printf("in-order: ");
    in(root);
    printf("\n");
    BTdestroy(root);
    return 0;
}
