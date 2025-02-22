#include "hashset.h"
#include <stdio.h>
#include <stdlib.h>

HashSet hashset_create(TYPE t)
{
    HashSet hashset;
    hashset.load_factor = 0;
    hashset.table_size = 1000;

    if (t == CHAR) {
        hashset.table = malloc(hashset.table_size * sizeof(char));
    } else if (t == INT) {
        hashset.table = malloc(hashset.table_size * sizeof(int));
    } else if (t == FLOAT) {
        hashset.table = malloc(hashset.table_size * sizeof(float));
    } else if (t == DOUBLE) {
        hashset.table = malloc(hashset.table_size * sizeof(double));
    } else {
        printf("Unrecognised type.\n");
        exit(EXIT_FAILURE);
    }

    return hashset;
}
