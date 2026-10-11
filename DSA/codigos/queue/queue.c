#include <string.h>
#include "queue.h"

static int queue_reallocate(Queue *queue, int len) {
    Array *arr = queue->arr;
    if (len < arr->len) return -1;

    void * new_array = calloc(len, arr->elem_size);
    if (!new_array) return -1;

    uint8_t *dest, *src;
    for (int i = 0; i < arr->n_elem; i++) {
        dest = (uint8_t*) new_array + i * arr->elem_size;
        src = (uint8_t*) arr->array + ( (queue->front+i) % arr->len ) * arr->elem_size;
        memcpy(dest, src, arr->elem_size);
    }
    queue->front = 0;
    queue->rear = arr->n_elem - 1;

    arr->len = len;
    free(arr->array);
    arr->array = new_array;
    return 0;
}

static int queue_make_room(Queue *queue) {
    Array *arr = queue->arr;
    if (arr->n_elem < arr->len) return 0;
    if (arr->realoc_policy != ARRAY_REALLOC) return -1;
    return queue_reallocate(queue, 2 * arr->len);
}


Queue * queue_init(int len, size_t elem_size, uint8_t realoc_policy) {
    Queue *queue = malloc(sizeof(Queue));
    if (!queue) return NULL;

    if (!(queue->arr = array_init(len, elem_size, realoc_policy))) {
        free(queue);
        return NULL;
    }
    queue->front = 0;
    queue->rear = len - 1;
    return queue;
}

int enqueue(Queue *queue, void *data) {
    if (queue_make_room(queue) != 0) return -1;
    Array *arr = queue->arr;
    queue->rear = (queue->rear + 1) % arr->len;
    memcpy((uint8_t*) arr->array + queue->rear * arr->elem_size, data, arr->elem_size);
    arr->n_elem++;
    return 0;
}

int dequeue(Queue *queue, void *data) {
    Array *arr = queue->arr;
    if (arr->n_elem == 0) return -1;
    memcpy(data, (uint8_t*) arr->array + queue->front * arr->elem_size, arr->elem_size);
    queue->front = (queue->front + 1) % arr->len;
    arr->n_elem--;
    return 0;
}

void queue_free(Queue *queue) {
    if (!queue) return;
    array_free(queue->arr);
    free(queue);
}
