#include <stdio.h>
#include "tree.h"

int main(int argc, char *argv[])
{
    Tree tree = tree_create();

    tree_insert(&tree, 8);
    tree_insert(&tree, 3);
    tree_insert(&tree, 10);

    int* n = tree_search(&tree, 10);
    printf("Found %d\n", *n);

    n = tree_search(&tree, 11);
    if (n == NULL) {
        printf("Not Found\n");
    }

    return 0;
}
