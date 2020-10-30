# Lecture 9.2

## Binary search trees:

super quick searching!!!

depth is on average <img src="svgs/c22fb4f7e31f9f3cc4625d0d70217902.svg?invert_in_darkmode" align=middle width=75.00398234999999pt height=24.65753399999998pt/>

```c
// you need this advanced declaration so it can refer to itself
typedef struct node node_t;
struct node {
 void *data;
 node_t *left;
 node_t *right;
}
typedef struct {
 node_t *root;
 int (*cmp)(void*, void*);
} tree_t;

tree_t *make_empty_tree(int func(void*, void*)) {
    tree_t *tree;
    tree = (tree_t *) malloc(sizeof(*tree));
    assert(tree != NULL);
    /* initialize tree to empty */
    tree->root = NULL;
    /* saves the supplied function pointer */
    tree->cmp = func;
    return tree;
}
```

Inserting into the tree:

```c
static node_t *rec_ins(tree->root, new, cmp) {
    if(root == NULL) {
        return new;
    } else if(cmp(new->data, root->data) < 0) {
        root->left = rec_ins(root->left, new, cmp);
    } else {
        root->right = rec_ins(root->right, new, cmp);
    }
    return root;
}
```

```c
void print_then_free(void *x) {
    data_t *p = x;
    printf("%...");
    free(p);
}
```
