#include <stdlib.h>
#include "linked_list.h"

List * list_init(void (*destroy)(void *data)) {
  // Allocates memory for list structure
  List *list = malloc(sizeof(List));
  if (list == NULL) {
    return NULL;
  }
  // Allocates memory for list head/sentinel
  ListNode *head = malloc(sizeof(ListNode));
  if (head == NULL) {
    free(list);
    return NULL;
  }
  // Set other list attributes
  head->next = head->data = NULL;
  list->head = list->tail = head;
  list->num_elem = 0;
  list->destroy = destroy;

  return list;
}

int list_insert(List* list, void *data) {
  // Simple insertion at list head
  return list_insert_next(list, NULL, data);
}

int list_insert_next(List *list, ListNode *previous, void *data) {
  // Allocates memory for the new node
  ListNode *new_elem = malloc(sizeof(ListNode));
  if (new_elem == NULL) {
    return -1;
  }
  new_elem->data = data;

  if (!previous) previous = list->head;

  // Adjust the pointers
  new_elem->next = previous->next;
  previous->next = new_elem;

  // Checks if the new node is at tail
  if (new_elem->next == NULL)
    list->tail = new_elem;

  // Increases element count
  list_num_elem(list)++;

  return 0;
}

int list_remove_next(List *list, ListNode *previous, void **data) {
  // Previous equals NULL means removing at head
  if (!previous) previous = list->head;
  // No removal from empty list
  if (list_num_elem(list) == 0) return -1;
  // Can't remove after tail
  if (!previous->next) return -1;

  ListNode *old = previous->next;
  previous->next = old->next;

  if (data)
    *data = old->data;
  else if (list->destroy)
    list->destroy(old->data);

  // Set the new tail if necessary
  if (previous->next == NULL)
    list->tail = previous;

  list_num_elem(list)--;
  free(old);
  return 0;
}

void list_destroy(List *list) {
    if (!list) return;
    while (list->head->next != NULL) {
        list_remove_next(list, NULL, NULL);
    }
    free(list->head);
    free(list);
}

int list_append(List *list, void *data) {
    return list_insert_next(list, list->tail, data);
}

ListNode *list_search(const List *list, int (*compare)(void *a, void *b),
                      void *x) {
    ListNode *tracer = list->head;

    while (tracer->next != NULL) {
        if (!compare(tracer->next->data, x)) return tracer;
        tracer = tracer->next;
    }
    return NULL;
}

void * list_head_data(const List * list) {
    if (!list_num_elem(list)) return NULL;
    return list->head->next->data;
}
