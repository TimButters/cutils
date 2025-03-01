#include "hashset.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

HashSet hashset_create(TYPE t)
{
    HashSet hashset;
    hashset.load_factor = 0;
    hashset.table_size = 1000;
    hashset._type = t;

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

size_t _hashset_hash(HashSet* hashset, void* value)
{
    double x;
    if (hashset->_type == CHAR) {
        // chars are ints.
        x = (double)*(int*)value;
    } else if (hashset->_type == INT) {
        x = (double)*(int*)value;
    } else if (hashset->_type == FLOAT) {
        x = (double)*(float*)value;
    } else {
        x = *(double*)value;
    }

    return floor(hashset->table_size * (fmod((x * 1.618), 1.)));
}

void hashset_add(HashSet* hashset, void* value)
{
    size_t idx = _hashset_hash(hashset, value);

    // Need a version of this for each type
    ((int*)hashset->table)[idx] = *(int*)value;
}
