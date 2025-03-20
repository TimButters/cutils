#include "hashset.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

HashSet hashset_create(TYPE t)
{
    HashSet hashset;
    hashset.size = 0;
    hashset.load_factor = 0;
    hashset.load_limit = 0.75;
    hashset.table_size = 1000;
    hashset._type = t;
    hashset.occupied = calloc(hashset.table_size, sizeof(bool));

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

    // If that bin is occupied, find the next available bin.
    while (hashset->occupied[idx]) {
        idx++;
    }

    // Set the value in the table
    if (hashset->_type == CHAR) {
        // chars are ints.
        ((int*)hashset->table)[idx] = *(int*)value;
    } else if (hashset->_type == INT) {
        ((int*)hashset->table)[idx] = *(int*)value;
    } else if (hashset->_type == FLOAT) {
        ((float*)hashset->table)[idx] = *(float*)value;
    } else {
        ((double*)hashset->table)[idx] = *(double*)value;
    }

    // Mark the bin as occupied and increment size
    hashset->occupied[idx] = true;
    hashset->size++;

    // Update load factor
    hashset->load_factor = (float)hashset->size / hashset->table_size;

    if (hashset->load_factor > hashset->load_limit) {
        // Increase size and rehash...
    }
}

void hashset_delete(HashSet* hashset, void* value)
{
    size_t idx = _hashset_hash(hashset, value);

    bool match = false;
    size_t offset = 0;

    while (!match) {
        if (hashset->_type == CHAR) {
            // chars are ints.
            match = *(int*)value == ((int*)hashset->table)[idx + offset];
        } else if (hashset->_type == INT) {
            match = *(int*)value == ((int*)hashset->table)[idx + offset];
        } else if (hashset->_type == FLOAT) {
            // NEED TO SORT FLOATING POINT EQUALITY FOR FLOAT AND DOUBLE
            match = *(float*)value == ((float*)hashset->table)[idx + offset];
        } else {
            match = *(double*)value == ((double*)hashset->table)[idx + offset];
        }
        offset++;
    }
    offset--;
    
    hashset->occupied[idx + offset] = false;
}
