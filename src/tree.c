#include "tree.h"
#include <stdbool.h>
#include <stddef.h>
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
                n->left = new_n;
                return;
            } else {
                n = n->left;
            }
        } else {
            if (n->right == NULL) {
                // Insert at leaf
                n->right = new_n;
                return;
            } else {
                n = n->right;
            }
        }
    }
}

int* tree_search(Tree* t, int search_value)
{
    Node* n = t->root;

    while (true) {
        if (n->value == search_value) {
            return &n->value;
        }

        if (n->value > search_value) {
            if (n->left == NULL) {
                return NULL;
            }
            n = n->left;
        } else {
            if (n->right == NULL) {
                return NULL;
            }
            n = n->right;
        }
    }

    return NULL;
}
