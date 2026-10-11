#include "linked_queue.h"

int lenqueue(LQueue *lqueue, void *data) {
    return list_append(lqueue, data);
}

int ldequeue(LQueue *lqueue, void **data) {
    return list_remove_next(lqueue, lqueue->head, data);
}
