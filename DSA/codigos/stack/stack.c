#include <string.h>
#include "stack.h"

int stack_push(Stack *stack, void *x) {
    return array_insert(stack, x, stack->n_elem);
}

int stack_pop(Stack *stack, void *dest) {
    if (stack->n_elem == 0) return -1;
    memcpy(dest, array_pti(stack, stack->n_elem - 1), stack->elem_size);
    return array_remove(stack, stack->n_elem - 1);
}

void * stack_ptop(Stack *stack) {
    if (stack->n_elem == 0) return NULL;
    return array_pti(stack, stack->n_elem - 1);
}
