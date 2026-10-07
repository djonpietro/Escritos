#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>

/*
 * Vetor de capacidade fixa (redimensionável sob demanda) para elementos de
 * tamanho arbitrário.
 *
 * Os elementos são tratados como blocos de bytes: as funções copiam
 * elem_size bytes por elemento e nunca interpretam o seu conteúdo. Os
 * argumentos "x" e "k" são sempre ponteiros para elementos (ou chaves) do
 * tipo armazenado.
 *
 * Convenções:
 *   - funções que retornam int devolvem 0 em caso de sucesso e -1 em caso
 *     de falha, deixando o vetor inalterado;
 *   - funções que retornam ponteiro devolvem NULL em caso de falha ou de
 *     elemento inexistente;
 *   - ponteiros para elementos apontam para dentro do vetor, não para
 *     cópias: são invalidados por array_reallocate, por inserções com
 *     ARRAY_REALLOC e por array_free, e o elemento para o qual apontam pode
 *     mudar após uma remoção ou inserção ordenada.
 */
typedef struct {
    void * array;      // bloco de memória com os elementos
    int len;           // capacidade: número máximo de elementos em array
    int n_elem;        // número de elementos armazenados (n_elem <= len)
    size_t elem_size;  // tamanho, em bytes, de cada elemento
} Array;

/*
 * Política de overflow, passada às funções de inserção para dizer o que
 * fazer quando o vetor está cheio (n_elem == len):
 *   ARRAY_NO_REALLOC  a inserção falha (-1);
 *   ARRAY_REALLOC     a capacidade é dobrada com array_reallocate e a
 *                     inserção prossegue; se a realocação falhar, a
 *                     inserção também falha (-1).
 */
#define ARRAY_NO_REALLOC 0
#define ARRAY_REALLOC    1

/*
 * Cria um vetor vazio com capacidade para len elementos de elem_size bytes.
 * A memória é inicializada com zeros.
 *
 * Retorna o vetor criado, ou NULL se len <= 0 ou se faltar memória.
 * O vetor deve ser liberado com array_free.
 */
Array * array_init(int len, size_t elem_size);

/*
 * Retorna o ponteiro para o elemento de índice i (a partir de 0).
 *
 * Não verifica limites: o chamador deve garantir 0 <= i < arr->len. Só os
 * índices menores que arr->n_elem contêm elementos válidos.
 */
void * array_pti(Array *arr, int i);

/*
 * Aumenta a capacidade do vetor para len elementos, preservando os n_elem
 * elementos existentes. O ponteiro arr continua válido, mas os ponteiros
 * para elementos obtidos antes da chamada deixam de valer.
 *
 * Retorna 0 em sucesso, ou -1 se len < arr->len (o vetor não encolhe) ou se
 * faltar memória; nesse caso o vetor permanece intacto. len == arr->len é
 * aceito.
 */
int array_reallocate(Array *arr, int len);

/*
 * Libera o vetor e a memória dos seus elementos. Aceita arr == NULL.
 * Após a chamada, arr e todos os ponteiros para seus elementos são inválidos.
 */
void array_free(Array * arr);

// --------------- Operações de vetores não ordenados

/*
 * Busca linear, O(n). Compara cada elemento e com a chave k chamando
 * compare(e, k), que deve retornar 0 quando são iguais.
 *
 * Retorna o ponteiro para o primeiro elemento igual a k, ou NULL se não
 * houver nenhum.
 */
void * array_search(Array * arr, void * k, int (*compare)(void*a,void*b));

/*
 * Insere uma cópia do elemento apontado por x no fim do vetor, O(1).
 * policy é ARRAY_NO_REALLOC ou ARRAY_REALLOC (ver acima).
 *
 * Retorna 0 em sucesso, ou -1 se o vetor estiver cheio e não puder crescer.
 */
int array_insert(Array * arr, void * x, int policy);

/*
 * Remove o elemento apontado por x, O(1): o último elemento é copiado para
 * a posição de x, de modo que a ordem dos elementos não é preservada.
 *
 * x deve ser um ponteiro para um elemento do vetor, como os devolvidos por
 * array_search. Retorna 0 em sucesso, ou -1 se x não apontar para um dos
 * n_elem elementos armazenados.
 */
int array_remove(Array * arr, void * x);

// --------------- Operações de vetores ordenados
//
// Estas operações supõem o vetor em ordem crescente segundo a função
// compare(a, b), que retorna um valor negativo, zero ou positivo conforme
// a seja menor, igual ou maior que b. Use apenas array_insert_sorted para
// inserir, a fim de manter essa ordem.

/*
 * Insere uma cópia do elemento apontado por x na posição que mantém o vetor
 * ordenado, O(n). Elementos iguais mantêm a ordem de inserção (a inserção é
 * estável: x entra depois dos elementos iguais a ele).
 * policy é ARRAY_NO_REALLOC ou ARRAY_REALLOC (ver acima).
 *
 * Retorna 0 em sucesso, ou -1 se o vetor estiver cheio e não puder crescer,
 * ou se faltar memória.
 */
int array_insert_sorted(Array *arr, void *x, int (*compare)(void*a,void*b), int policy);

/*
 * Remove o elemento apontado por x deslocando os seguintes uma posição para
 * a esquerda, O(n); a ordem é preservada.
 *
 * x deve ser um ponteiro para um elemento do vetor, como os devolvidos por
 * array_search, array_min ou array_max. Retorna 0 em sucesso, ou -1 se x não
 * apontar para um dos n_elem elementos armazenados.
 */
int array_remove_sorted(Array *arr, void *x);

/*
 * Retorna o ponteiro para o maior elemento (o último), O(1), ou NULL se o
 * vetor estiver vazio.
 */
void * array_max(Array *arr);

/*
 * Retorna o ponteiro para o menor elemento (o primeiro), O(1), ou NULL se o
 * vetor estiver vazio.
 */
void * array_min(Array *arr);

/*
 * Retorna o ponteiro para o sucessor de x (o elemento seguinte), O(1).
 *
 * Retorna NULL se x for o maior elemento ou se não apontar para um dos
 * n_elem elementos armazenados.
 */
void * array_elem_successor(Array *arr, void *x);

/*
 * Retorna o ponteiro para o predecessor de x (o elemento anterior), O(1).
 *
 * Retorna NULL se x for o menor elemento ou se não apontar para um dos
 * n_elem elementos armazenados.
 */
void * array_elem_predecessor(Array *arr, void *x);

#endif
