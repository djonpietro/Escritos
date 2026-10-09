#ifndef STACK_H
#define STACK_H

#include "../array/array.h"

typedef Array Stack;

#define stack_init array_init

#define stack_free array_free

int stack_push(Stack *stack, void *x);

int stack_pop(Stack *stack, void *dest);

void * stack_ptop(Stack *stack);

#endif
