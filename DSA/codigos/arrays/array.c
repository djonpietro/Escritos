#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "array.h"

// get pointer p to index i
void * array_pti(Array *arr, int i) {
    if(i < 0 || i >= arr->n_elem) return NULL;
    uint8_t * p = (uint8_t *) arr->array + i * arr->elem_size;
    return p;
}

int array_reallocate(Array *arr, int len) {
    if (len < arr->len) return -1;

    void * new_array = calloc(len, arr->elem_size);
    if (!new_array) {
        return -1;
    }

    memcpy(new_array, arr->array, arr->len * arr->elem_size);

    arr->len = len;
    free(arr->array);
    arr->array = new_array;
    return 0;
}

// if the array is full, doubles its length when policy is ARRAY_REALLOC
static int array_make_room(Array *arr) {
    if (arr->n_elem < arr->len) return 0;
    if (arr->realoc_policy != ARRAY_REALLOC) return -1;
    return array_reallocate(arr, 2 * arr->len);
}

Array * array_init(int len, size_t elem_size, uint8_t realoc_policy) {
    if (len <= 0) return NULL;

    Array *arr = malloc(sizeof(Array));
    if (!arr) return NULL;

    arr->len = len;
    arr->elem_size = elem_size;
    arr->n_elem = 0;
    arr->realoc_policy = realoc_policy;

    if(!(arr->array = calloc(len,elem_size))) {
        free(arr);
        return NULL;
    }
    return arr;
}

void * array_search(Array * arr, void * k, int (*compare)(void*a,void*b)) {
    for (int i = 0; i < arr->n_elem; i++) {
        void *elem = array_pti(arr, i);
        if (compare(elem, k) == 0) return elem;
    }
    return NULL;
}

int array_insert(Array * arr, void * x, int i) {
    if (i < 0 || i > arr->n_elem) return -1;
    if (array_make_room(arr) != 0) return -1;

    uint8_t *dest, *source;

    for (int j = arr->n_elem; j != i; j--) {
        dest = (uint8_t *) arr->array + j * arr->elem_size;
        source = (uint8_t*) arr->array + (j-1) * arr->elem_size;
        memcpy(dest, source, arr->elem_size);
    }

    memcpy((uint8_t *) arr->array + i * arr->elem_size, x, arr->elem_size);
    arr->n_elem++;
    return 0;
}

int array_remove(Array *arr, int i) {
    if (arr->n_elem == 0 || i < 0 || i >= arr->n_elem) return -1;
    memcpy(array_pti(arr, i), array_pti(arr, arr->n_elem - 1), arr->elem_size);
    arr->n_elem--;
    return 0;
}

int array_remove_sorted(Array *arr, int i) {
    if (arr->n_elem == 0 || i < 0 || i >= arr->n_elem) return -1;

    for (int j = i; j < arr->n_elem - 1; j++)
        memcpy(array_pti(arr, j), array_pti(arr, j+1), arr->elem_size);
    arr->n_elem--;
    return 0;
}

void array_free(Array *arr) {
    if (!arr) return;
    free(arr->array);
    free(arr);
}
