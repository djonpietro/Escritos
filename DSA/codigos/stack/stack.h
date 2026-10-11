#ifndef STACK_H
#define STACK_H

#include "../array/array.h"

/*
 * Pilha sobre um vetor (Array) para elementos de tamanho arbitrário.
 *
 * O topo da pilha é o último elemento do vetor, de índice n_elem - 1; assim,
 * empilhar e desempilhar custam O(1), sem deslocar elementos.
 *
 * Os elementos são tratados como blocos de bytes: as funções copiam
 * elem_size bytes por elemento e nunca interpretam o seu conteúdo. Os
 * argumentos "x" e "dest" são sempre ponteiros para elementos do tipo
 * armazenado.
 *
 * Convenções:
 *   - funções que retornam int devolvem 0 em caso de sucesso e -1 em caso
 *     de falha, deixando a pilha inalterada;
 *   - funções que retornam ponteiro devolvem NULL em caso de falha ou de
 *     elemento inexistente;
 *   - ponteiros para elementos apontam para dentro do vetor, não para
 *     cópias: são invalidados por stack_pop, por stack_push com
 *     ARRAY_REALLOC e por stack_free.
 */
typedef Array Stack;

/*
 * Cria uma pilha vazia com capacidade para len elementos de elem_size bytes
 * e política de overflow realoc_policy (ARRAY_NO_REALLOC ou ARRAY_REALLOC,
 * ver array.h).
 *
 * Retorna a pilha criada, ou NULL se len <= 0 ou se faltar memória.
 * A pilha deve ser liberada com stack_free.
 */
#define stack_init array_init

/*
 * Libera a pilha e a memória dos seus elementos. Aceita stack == NULL.
 * Após a chamada, stack e todos os ponteiros para seus elementos são
 * inválidos.
 */
#define stack_free array_free

/*
 * Empilha uma cópia do elemento apontado por x, O(1). Se a pilha estiver
 * cheia, segue stack->realoc_policy: com ARRAY_REALLOC, a capacidade é
 * dobrada, O(n).
 *
 * Retorna 0 em sucesso, ou -1 se a pilha estiver cheia e não puder crescer.
 */
int stack_push(Stack *stack, void *x);

/*
 * Desempilha o elemento do topo e copia-o para a memória apontada por dest,
 * que deve ter espaço para elem_size bytes, O(1).
 *
 * Retorna 0 em sucesso, ou -1 se a pilha estiver vazia.
 */
int stack_pop(Stack *stack, void *dest);

/*
 * Retorna o ponteiro para o elemento do topo, sem removê-lo, O(1), ou NULL
 * se a pilha estiver vazia.
 */
void * stack_ptop(Stack *stack);

#endif
