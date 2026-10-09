#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "../linked-list/linked_list.h"

typedef ListNode LStackNode;
typedef List LStack;

#define lstack_init list_init

#define lstack_destroy list_destroy

int lstack_push(LStack *stack, void *data);

int lstack_pop(LStack *stack, void **p);

#define lstack_top(s) list_head_data(s)

#endif
