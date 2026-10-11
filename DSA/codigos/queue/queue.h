#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdint.h>
#include "../array/array.h"

/*
 * Fila circular sobre um vetor (Array) para elementos de tamanho arbitrário.
 *
 * Os elementos ocupam as posições front, front+1, ..., rear do vetor,
 * tomadas módulo arr->len: ao chegar ao fim do vetor, a fila continua do
 * índice 0. Assim, enfileirar e desenfileirar custam O(1), sem deslocar
 * elementos.
 *
 * Os elementos são tratados como blocos de bytes: as funções copiam
 * arr->elem_size bytes por elemento e nunca interpretam o seu conteúdo. O
 * argumento "data" é sempre um ponteiro para um elemento do tipo armazenado.
 *
 * Convenções:
 *   - funções que retornam int devolvem 0 em caso de sucesso e -1 em caso
 *     de falha, deixando a fila inalterada;
 *   - o vetor arr deve ser manipulado só pelas funções desta fila: as
 *     operações de array.h não conhecem front e rear e quebrariam a ordem
 *     circular dos elementos.
 */
typedef struct {
    Array * arr;  // vetor com os elementos; arr->n_elem é o tamanho da fila
    int front;    // índice, em arr, do primeiro elemento (o próximo a sair)
    int rear;     // índice, em arr, do último elemento (o mais recente)
} Queue;

/*
 * Cria uma fila vazia com capacidade para len elementos de elem_size bytes
 * e política de overflow realoc_policy (ARRAY_NO_REALLOC ou ARRAY_REALLOC,
 * ver array.h).
 *
 * Retorna a fila criada, ou NULL se len <= 0 ou se faltar memória.
 * A fila deve ser liberada com queue_free.
 */
Queue * queue_init(int len, size_t elem_size, uint8_t realoc_policy);

/*
 * Insere uma cópia do elemento apontado por data no fim da fila, O(1). Se a
 * fila estiver cheia, segue arr->realoc_policy: com ARRAY_REALLOC, a
 * capacidade é dobrada e os elementos são copiados, em ordem, para o início
 * do novo vetor, O(n).
 *
 * Retorna 0 em sucesso, ou -1 se a fila estiver cheia e não puder crescer.
 */
int enqueue(Queue *queue, void *data);

/*
 * Remove o elemento do início da fila e copia-o para a memória apontada por
 * data, que deve ter espaço para arr->elem_size bytes, O(1).
 *
 * Retorna 0 em sucesso, ou -1 se a fila estiver vazia.
 */
int dequeue(Queue *queue, void *data);

/*
 * Libera a fila e a memória dos seus elementos. Aceita queue == NULL.
 * Após a chamada, queue é inválido.
 */
void queue_free(Queue *queue);

#endif
