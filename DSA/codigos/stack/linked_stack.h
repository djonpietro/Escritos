#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include "../linked-list/linked_list.h"

/*
 * Pilha sobre uma lista simplesmente encadeada (List) para dados de tipo
 * arbitrário.
 *
 * O topo da pilha é o primeiro elemento da lista; assim, empilhar e
 * desempilhar custam O(1).
 *
 * A pilha guarda apenas ponteiros para os dados (void *); ela nunca copia
 * nem interpreta o seu conteúdo.
 *
 * Convenções:
 *   - funções que retornam int devolvem 0 em caso de sucesso e -1 em caso
 *     de falha;
 *   - funções que retornam ponteiro devolvem NULL em caso de falha ou de
 *     elemento inexistente.
 */
typedef ListNode LStackNode;
typedef List LStack;

/*
 * Cria uma pilha vazia. destroy é chamada sobre o dado de cada elemento
 * desempilhado com lstack_pop(stack, NULL) e de cada elemento que restar em
 * lstack_destroy; passe NULL se os dados não precisam ser liberados.
 *
 * Retorna a pilha criada, ou NULL se faltar memória.
 * A pilha deve ser liberada com lstack_destroy.
 */
#define lstack_init list_init

/*
 * Libera a pilha e seus nós, chamando destroy sobre cada dado. Aceita
 * stack == NULL. Após a chamada, stack é inválido.
 */
#define lstack_destroy list_destroy

/*
 * Empilha data, O(1). Guarda o próprio ponteiro, não uma cópia do dado.
 *
 * Retorna 0 em sucesso, ou -1 se faltar memória.
 */
int lstack_push(LStack *stack, void *data);

/*
 * Desempilha o elemento do topo, O(1).
 *
 * Se p não for NULL, o ponteiro para o dado desempilhado é guardado em *p
 * e o chamador passa a ser responsável por ele. Se for NULL, o dado é
 * liberado com destroy.
 *
 * Retorna 0 em sucesso, ou -1 se a pilha estiver vazia.
 */
int lstack_pop(LStack *stack, void **p);

/*
 * Retorna o dado do topo, sem removê-lo, O(1), ou NULL se a pilha estiver
 * vazia.
 */
#define lstack_top(s) list_head_data(s)

#endif
