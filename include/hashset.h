#ifndef HASHSET_C
#define HASHSET_C

#include <stddef.h>
#include <stdbool.h>

typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} TYPE;

typedef struct HashSet {
    size_t size;
    float load_factor;
    float load_limit;
    size_t table_size;
    void* table;
    bool* occupied;
    TYPE _type;
} HashSet;

// The hash function
size_t _hashset_hash(HashSet*, void*);

// Create a new Hashset instance
HashSet hashset_create(TYPE);

// Add a value to the set
void hashset_add(HashSet*, void*);

// Remove a value from the set
void hashset_delete(HashSet*, void*);

#endif
