#include <stdlib.h>
#include "dlinked_list.h"

DList * dlist_init(void (*destroy)(void*data)) {
    DList *dlist = malloc(sizeof(DList));
    if (!dlist) return NULL;

    DListNode *head = malloc(sizeof(DListNode));
    if (!head) {
        free(dlist);
        return NULL;
    }

    head->data = head->prev = head->next = NULL;
    dlist->head = dlist->tail = head;
    dlist->num_elem = 0;
    dlist->destroy = destroy;
    return dlist;
}

DListNode * dlist_search(DList *dlist, void *k, int (*compare)(void*a,void*b)) {
    DListNode *walker = dlist->head->next;
    while (walker != NULL) {
       if (!compare(walker->data, k)) return walker;
       walker = walker->next;
    }
    return NULL;
}

int dlist_insert_next(DList *dlist, DListNode *prev, void *data) {
    if (!prev) prev = dlist->head;

    DListNode *new = malloc(sizeof(DListNode));
    if (!new) return -1;

    new->next = prev->next;
    prev->next = new;
    new->prev = prev;

    if (new->next == NULL) dlist->tail = new;
    else new->next->prev = new;

    new->data = data;

    dlist->num_elem++;
    return 0;
}

int dlist_insert_prev(DList *dlist, DListNode *next, void *data) {
    if (!next)
        return dlist_insert_next(dlist, dlist->tail, data);

    if (next == dlist->head) return -1;

    DListNode *new = malloc(sizeof(DListNode));
    if (!new) return -1;

    new->prev = next->prev;
    next->prev = new;
    new->next = next;
    new->prev->next = new;

    new->data = data;

    dlist->num_elem++;
    return 0;
}

int dlist_remove_next(DList *dlist, DListNode *prev, void **data) {
    if (!prev) prev = dlist->head;

    if (prev->next == NULL) return -1;

    DListNode *old = prev->next;
    prev->next = old->next;

    if (prev->next == NULL)
        dlist->tail = prev;
    else
        prev->next->prev = prev;

    if (data)
        *data = old->data;
    else if (dlist->destroy)
        dlist->destroy(old->data);

    free(old);
    dlist->num_elem--;
    return 0;
}

int dlist_remove_prev(DList *dlist, DListNode *next, void **data) {
    if (!next)
        return dlist_remove_next(dlist, dlist->tail->prev, data);

    if (next->prev == dlist->head || next == dlist->head) return -1;

    DListNode *old = next->prev;
    next->prev = old->prev;
    old->prev->next = next;

    if (data)
        *data = old->data;
    else if (dlist->destroy)
        dlist->destroy(old->data);

    free(old);
    dlist->num_elem--;
    return 0;
}

void dlist_destroy(DList *dlist) {
    if (!dlist) return;
    while(dlist->head->next != NULL)
        dlist_remove_next(dlist, NULL, NULL);
    free(dlist->head);
    free(dlist);
}
