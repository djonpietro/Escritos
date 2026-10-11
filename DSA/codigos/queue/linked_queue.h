#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include "../linked-list/linked_list.h"

/*
 * Fila sobre uma lista simplesmente encadeada (List) para dados de tipo
 * arbitrário.
 *
 * O início da fila (o próximo a sair) é o primeiro elemento da lista, e o
 * fim (o mais recente) é o último, apontado por tail; assim, enfileirar e
 * desenfileirar custam O(1).
 *
 * A fila guarda apenas ponteiros para os dados (void *); ela nunca copia
 * nem interpreta o seu conteúdo.
 *
 * Convenções:
 *   - funções que retornam int devolvem 0 em caso de sucesso e -1 em caso
 *     de falha.
 */
typedef List LQueue;
typedef ListNode LQueueNode;

/*
 * Cria uma fila vazia. destroy é chamada sobre o dado de cada elemento
 * desenfileirado com ldequeue(lqueue, NULL) e de cada elemento que restar
 * em lqueue_destroy; passe NULL se os dados não precisam ser liberados.
 *
 * Retorna a fila criada, ou NULL se faltar memória.
 * A fila deve ser liberada com lqueue_destroy.
 */
#define lqueue_init list_init

/*
 * Libera a fila e seus nós, chamando destroy sobre cada dado. Aceita
 * lqueue == NULL. Após a chamada, lqueue é inválido.
 */
#define lqueue_destroy list_destroy

/*
 * Enfileira data no fim da fila, O(1). Guarda o próprio ponteiro, não uma
 * cópia do dado.
 *
 * Retorna 0 em sucesso, ou -1 se faltar memória.
 */
int lenqueue(LQueue *lqueue, void *data);

/*
 * Desenfileira o elemento do início da fila, O(1).
 *
 * Se data não for NULL, o ponteiro para o dado desenfileirado é guardado
 * em *data e o chamador passa a ser responsável por ele. Se for NULL, o
 * dado é liberado com destroy.
 *
 * Retorna 0 em sucesso, ou -1 se a fila estiver vazia.
 */
int ldequeue(LQueue *lqueue, void **data);

#endif
