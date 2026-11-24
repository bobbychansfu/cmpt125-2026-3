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

/* The 7-node tree used in lecture:
            10
          /    \
         5      21
        / \    /  \
       1   7  16   25
*/
BTnode_t *demo_tree(void)
{
    return node(10, node(5, BTnode_create(1), BTnode_create(7)),
                node(21, BTnode_create(16), BTnode_create(25)));
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

// Post: returns the number of nodes in the tree.
int BTsize(const BTnode_t *root) {
    if (root == NULL) return 0;
    return 1 + BTsize(root->left) + BTsize(root->right);
}

int main() {
    BTnode_t *t = demo_tree();
    printf("BTsize = %d\n", BTsize(t));
    printf("(not shown on the slide: height = %d, leaves = %d)\n",
           BTheight(t), BTcount_leaves(t));
    BTdestroy(t);
    return 0;
}
