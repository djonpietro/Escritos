#include <stdlib.h>
#include "cdlinked_list.h"

CDList * cdlist_init(void (*destroy)(void*data)) {
    CDList *cdlist = malloc(sizeof(CDList));
    if (!cdlist) return NULL;

    CDListNode *head = malloc(sizeof(CDListNode));
    if (!head) {
        free(cdlist);
        return NULL;
    }

    head->next = head->prev = head;
    head->data = NULL;
    cdlist->head = head;
    cdlist->num_elem = 0;
    cdlist->destroy = destroy;
    return cdlist;
}

CDListNode * cdlist_search(CDList *cdlist, void *k, int (*compare)(void*a,void*b)) {
   CDListNode *walker = cdlist->head->next;

   while(walker != cdlist->head) {
       if(!compare(walker->data, k)) return walker;
       walker = walker->next;
   }
   return NULL;
}

int cdlist_insert_next(CDList *cdlist, CDListNode *prev, void *data) {
    if (!cdlist || !prev) return -1;

    CDListNode *new = malloc(sizeof(CDListNode));
    if (!new) return -1;

    new->next = prev->next;
    new->prev = prev;
    new->next->prev = new;
    prev->next = new;
    new->data = data;

    cdlist->num_elem++;
    return 0;
}

int cdlist_insert_prev(CDList *cdlist, CDListNode *next, void *data) {
    if (!cdlist || !next) return -1;

    CDListNode *new = malloc(sizeof(CDListNode));
    if (!new) return -1;

    new->prev = next->prev;
    new->next = next;
    new->prev->next = new;
    next->prev = new;
    new->data = data;

    cdlist->num_elem++;
    return 0;
}

int cdlist_remove(CDList *cdlist, CDListNode *node, void **data) {
    if (!cdlist || !node) return -1;
    if (node == cdlist->head) return -1;

    CDListNode *prev = node->prev;
    prev->next = node->next;
    node->next->prev = prev;

    if (data)
        *data = node->data;
    else if (cdlist->destroy)
        cdlist->destroy(node->data);

    free(node);

    cdlist->num_elem--;
    return 0;
}

void cdlist_destroy(CDList *cdlist) {
    if (!cdlist) return;

    while (cdlist->head->next != cdlist->head)
        cdlist_remove(cdlist, cdlist->head->next, NULL);
    free(cdlist->head);
    free(cdlist);
}
