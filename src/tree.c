#include "tree.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

Tree tree_create()
{
    Tree t = { NULL, 0 };
    return t;
}

void tree_insert(Tree* t, int new_value)
{
    Node* new_n = malloc(sizeof(Node));
    new_n->value = new_value;
    new_n->left = NULL;
    new_n->right = NULL;

    if (t->root == NULL) {
        // New tree, adding root
        t->root = new_n;
        return;
    }

    Node* n = t->root;

    while (true) {
        if (n->value == new_value) {
            free(new_n);
            return;
        }

        if (n->value > new_value) {
            if (n->left == NULL) {
                // Insert at leaf
                new_n->parent = n;
                n->left = new_n;
                t->size++;
                return;
            } else {
                n = n->left;
            }
        } else {
            if (n->right == NULL) {
                // Insert at leaf
                new_n->parent = n;
                n->right = new_n;
                t->size++;
                return;
            } else {
                n = n->right;
            }
        }
    }
}

void tree_delete_node(Tree* t, int search_value)
{
    Node* n = t->root;

    while (n != NULL && n->value != search_value) {
        if (n->value > search_value) {
            n = n->left;
        } else {
            n = n->right;
        }
    }

    if (n == NULL) {
        return;
    }

    // To free memory
    Node* n_del = n;

    if (n->left == NULL && n->right == NULL) {
        // Leaf Node
        if (n->parent->left == n) {
            n->parent->left = NULL;
        } else {
            n->parent->right = NULL;
        }
    } else if ((n->left == NULL && n->right != NULL)
        || (n->left != NULL && n->right == NULL)) {
        // Single Child
        Node* parent = n->parent;
        Node* child = n->left  == NULL ? n->right : n->left;
        child->parent = parent;
        if (parent->value > n->value) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    } else {
        Node* y = tree_successor(t, n);
        if (y->parent != n) {
            tree_shift_nodes(t, y, y->right);
            y->right = n->right;
            y->right->parent = y;
        }
        tree_shift_nodes(t, n, y);
        y->left = n->left;
        y->left->parent = y;
    }
    t->size--;
    free(n_del);
}

void tree_shift_nodes(Tree* t, Node* u, Node* v)
{
    if (u->parent == NULL) {
        t->root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (v != NULL) {
        v->parent = u->parent;
    }
}

Node* tree_successor(const Tree* t, Node* n)
{
    if (n->right != NULL) {
        return tree_subtree_min(t, n->right);
    }
    Node* y = n->parent;
    while (y != NULL && n == y->right) {
        n = y;
        y = y->parent;
    }
    return y;
}

Node* tree_predecessor(const Tree* t, Node* n)
{
    if (n->left != NULL) {
        return tree_subtree_max(t, n->left);
    }
    Node* y = n->parent;
    while (y != NULL && n == y->left) {
        n = y;
        y = y->parent;
    }
    return y;
}

Node* tree_subtree_search(const Tree* t, Node* n, int search_value)
{
    while (n != NULL && n->value != search_value) {
        if (n->value > search_value) {
            n = n->left;
        } else {
            n = n->right;
        }
    }

    return n;
}

int* tree_search(const Tree* t, int search_value)
{
    Node* n = t->root;
   
    n = tree_subtree_search(t, n, search_value);

    return n == NULL ? NULL : &n->value;
}

Node* tree_subtree_max(const Tree* t, Node* n)
{
    while (n->right != NULL) {
        n = n->right;
    }

    return n;
}

int* tree_max(const Tree* t)
{
    Node* n = t->root;

    n = tree_subtree_max(t, n);

    return &n->value;
}

Node* tree_subtree_min(const Tree* t, Node* n)
{
    while (n->left != NULL) {
        n = n->left;
    }

    return n;
}

int* tree_min(const Tree* t)
{
    Node* n = t->root;

    n = tree_subtree_min(t, n);

    return &n->value;
}

void* tree_traverse(const Tree* t)
{
    int* values = malloc((t->size + 1) * sizeof t->root->value);
    size_t num_values = 0;

    tree_inorder_walk(t->root, values, &num_values);
    
    return values;
}

void tree_inorder_walk(const Node* n, int* values, size_t* num_values)
{
    if (n == NULL) {
        return;
    }

    tree_inorder_walk(n->left, values, num_values);
    values[*num_values] = n->value;
    (*num_values)++;
    tree_inorder_walk(n->right, values, num_values);
}
