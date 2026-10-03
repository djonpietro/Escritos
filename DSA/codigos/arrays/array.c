#include <string.h>
#include "array.h"

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

void array_free(Array *arr) {
    if (!arr) return;
    free(arr->array);
    free(arr);
}
