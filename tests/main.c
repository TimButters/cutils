#include <stdio.h>
#include "tree.h"

int main(int argc, char *argv[])
{
    Tree tree = tree_create();

    tree_insert(&tree, 8);
    tree_insert(&tree, 3);
    tree_insert(&tree, 9);
    tree_insert(&tree, 5);
    tree_insert(&tree, 10);
    tree_insert(&tree, 11);
    tree_insert(&tree, 12);
    tree_insert(&tree, 13);

    int* n = tree_search(&tree, 13);
    printf("Found %d\n", *n);

    n = tree_search(&tree, 5);
    printf("Found %d\n", *n);

    n = tree_search(&tree, 100);
    if (n == NULL) {
        printf("Not Found\n");
    }

    return 0;
}
