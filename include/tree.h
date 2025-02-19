#ifndef SET_H
#define SET_H

#include <stddef.h>
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

// Delete a node to the tree
void tree_delete_node(Tree*, int);

// Helper function for delete
void tree_shift_nodes(Tree*, Node*, Node*);

// Search a subtree from a given node
Node* tree_subtree_search(const Tree*, Node*, int);

// Check if value is in tree
int* tree_search(const Tree*, int);

// Find the max of a subtree
Node* tree_subtree_max(const Tree*, Node*);

// Max value in tree
int* tree_max(const Tree*);

// Find the min of a subtree
Node* tree_subtree_min(const Tree*, Node*);

// Min value in tree
int* tree_min(const Tree*);

// Successor of a given node
Node* tree_successor(const Tree*, Node*);

// Predecessor of a given node
Node* tree_predecessor(const Tree*, Node*);

// Traverse tree
void* tree_traverse(const Tree*);

// Inorder tree walk
void tree_inorder_walk(const Node*, int*, size_t*);

#endif
