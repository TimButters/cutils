#ifndef HASHSET_C
#define HASHSET_C

#include <stddef.h>

typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE
} TYPE;

typedef struct HashSet {
    float load_factor;
    size_t table_size;
    void* table;
} HashSet;

// Create a new Hashset instance
HashSet hashset_create(TYPE);

// Add a value to the set
void hashset_add(HashSet*, void*);

#endif
