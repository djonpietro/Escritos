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

// retorna o ponteiro para o elemento de índice i
void * array_pti(Array *arr, int i);

// --------------- Operações de vetores não ordenados

void * array_search(Array * arr, void * k, int (*compare)(void*a,void*b));

int array_insert(Array * arr, void * x);

int array_remove(Array * arr, void * x);

// --------------- Operações de vetores ordenados

int array_insert_sorted(Array *arr, void *x, int (*compare)(void*a,void*b));

int array_remove_sorted(Array *arr, void *x);

void * array_max(Array *arr);

void * array_min(Array *arr);

void * array_elem_successor(Array *arr, void *x);

void * array_elem_predecessor(Array *arr, void *x);

void array_free(Array * arr);

#endif
