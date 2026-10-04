#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "array.h"

// get pointer p to index i
void * array_pti(Array *arr, int i) {
    uint8_t * p = (uint8_t *) arr->array + i * arr->elem_size;
    return p;
}

Array * array_init(int len, size_t elem_size) {
    Array *arr = malloc(sizeof(Array));
    if (!arr || len <= 0) return NULL;

    arr->len = len;
    arr->elem_size = elem_size;
    arr->n_elem = 0;

    if(!(arr->array = calloc(len,elem_size))) {
        free(arr);
        return NULL;
    }
    return arr;
}

void * array_search(Array * arr, void * k, int (*compare)(void*a,void*b)) {
    for (int i = 0; i < arr->n_elem; i++) {
        void * elem = (char *) arr->array + i * arr->elem_size;
        if (compare(elem, k) == 0) return elem;
    }
    return NULL;
}

int array_insert(Array * arr, void * x) {
    if (arr->n_elem >= arr->len) return -1;

    char * dest = (char *) arr->array + arr->n_elem * arr->elem_size;
    memcpy(dest, x, arr->elem_size);
    arr->n_elem++;
    return 0;
}

int array_remove(Array *arr, void *x) {
    if (arr->n_elem == 0) return -1;

    arr->n_elem--;
    void * last = (char *) arr->array + arr->n_elem * arr->elem_size;
    if (x != last)
        memcpy(x, last, arr->elem_size);
    return 0;
}

int array_insert_sorted(Array *arr, void *x, int (*compare)(void*a,void*b)) {
    if (arr->n_elem == arr->len) return -1;

    memcpy(array_pti(arr, arr->n_elem), x, arr->elem_size);
    int i = arr->n_elem;
    void *temp;

    temp = malloc(arr->elem_size);
    if (!temp) return -1;

    while( i >= 1 && compare(array_pti(arr, i-1), array_pti(arr, i)) > 0) {
        void *a = array_pti(arr, i-1);
        void *b = array_pti(arr, i);
        memcpy(temp, a, arr->elem_size);
        memcpy(a, b, arr->elem_size);
        memcpy(b, temp, arr->elem_size);
        i--;
    }
    arr->n_elem++;
    free(temp);
    return 0;
}

int array_remove_sorted(Array *arr, void *x) {
    if (arr->n_elem == 0) return -1;

    int idx = ((uint8_t *) x - (uint8_t *) arr->array) / arr->elem_size;
    for (int i = idx; i < arr->n_elem - 1; i++) {
        memcpy(array_pti(arr, i), array_pti(arr, i+1), arr->elem_size);
    }
    arr->n_elem--;
    return 0;
}

void array_free(Array *arr) {
    if (!arr) return;
    free(arr->array);
    free(arr);
}
