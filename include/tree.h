#ifndef SET_H
#define SET_H

typedef struct Node {
    int value;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
    unsigned int size;
} Tree;

// Create a new tree instance
Tree tree_create();

// Add a node to the tree
void tree_insert(Tree*, int);

// Check if value is in tree
int* tree_search(Tree*, int);

// Max value in tree
int* tree_max(Tree*);

// Min value in tree
int* tree_min(Tree*);

#endif
