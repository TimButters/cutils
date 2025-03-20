#include "tree.h"
#include "hashset.h"
#include <stdio.h>
#include <stdlib.h>

int test_tree()
{
    printf("=== Starting Tree Tests ===\n");
    Tree tree = tree_create();
    printf("Tree size = %u\n", tree.size);

    tree_insert(&tree, 8);
    tree_insert(&tree, 3);
    tree_insert(&tree, 9);
    tree_insert(&tree, 5);
    tree_insert(&tree, 10);
    tree_insert(&tree, 11);
    tree_insert(&tree, 12);
    tree_insert(&tree, 13);
    
    printf("Tree size = %u\n", tree.size);

    int* n = tree_search(&tree, 13);
    printf("Found %d\n", *n);

    n = tree_search(&tree, 5);
    printf("Found %d\n", *n);

    n = tree_search(&tree, 100);
    if (n == NULL) {
        printf("Not Found %d\n", 100);
    }

    printf("The minimum value is: %d\n", *tree_min(&tree));
    printf("The maximum value is: %d\n", *tree_max(&tree));

    Node* node = tree_subtree_search(&tree, tree.root, 3);
    printf("Subtree max %d\n", tree_subtree_max(&tree, node)->value);

    n = tree_search(&tree, 13);
    printf("Found %d\n", *n);

    n = tree_search(&tree, 5);
    printf("Found %d\n", *n);

    tree_delete_node(&tree, 13);
    n = tree_search(&tree, 13);
    if (n == NULL) {
        printf("Deleted Node 13.\n");
        printf("Tree size = %u\n", tree.size);
    } else {
        printf("Well...%d\n", *n);
    }

    tree_delete_node(&tree, 11);
    n = tree_search(&tree, 11);
    if (n == NULL) {
        printf("Deleted Node 11.\n");
        printf("Tree size = %u\n", tree.size);
    } else {
        printf("Well...%d\n", *n);
    }

    tree_delete_node(&tree, 5);
    n = tree_search(&tree, 5);
    if (n == NULL) {
        printf("Deleted Node 5.\n");
        printf("Tree size = %u\n", tree.size);
    } else {
        printf("Well...%d\n", *n);
    }

    int* values = tree_traverse(&tree);
    printf("Tree size %u\n\n", tree.size);
    printf("Elements:\n");
    for (int i = 0; i < tree.size; i++) {
        printf("%d\n", values[i]);
    }
    free(values);

    printf("=== Tree tests all done ===\n\n");
    return 0;
}

int test_hashset()
{
    printf("=== Starting HashSet Tests ===\n");

    HashSet hashset = hashset_create(INT);

    int a = 1;
    hashset_add(&hashset, &a);
    a = 2;
    hashset_add(&hashset, &a);
    a = 3;
    hashset_add(&hashset, &a);

    for (int i = 0; i < hashset.table_size; i++) {
        if (hashset.occupied[i]) {
            printf("%d: %d\n", i, ((int*)hashset.table)[i]);
        }
    }

    printf("\nDeleting\n");
    hashset_delete(&hashset, &a);

    for (int i = 0; i < hashset.table_size; i++) {
        if (hashset.occupied[i]) {
            printf("%d: %d\n", i, ((int*)hashset.table)[i]);
        }
    }

    printf("=== HashSet tests all done ===\n\n");
    
    return 0;
}

int main(int argc, char* argv[])
{

    int tree_result = test_tree();
    if (tree_result > 0) {
        printf("Hashset failure\n");
    }

    int hashset_result = test_hashset();
    if (hashset_result > 0) {
        printf("Hashset failure\n");
    }

    return 0;
}
