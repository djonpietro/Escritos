#include "linked_stack.h"

int lstack_push(LStack *stack, void *data) {
    return list_insert(stack, data);
}

int lstack_pop(LStack *stack, void **p) {
    return list_remove_next(stack, stack->head, p);
}
