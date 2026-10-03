#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>

typedef struct {
    void * array;
    int len;
    int n_elem;
    size_t elem_size;
} Array;

Array * array_init(int len, size_t elem_size);

void * array_search(Array * arr, void * k, int (*compare)(void*a,void*b));

int array_insert(Array * arr, void * x);

int array_remove(Array * arr, void * x);

void array_free(Array * arr);

#endif
