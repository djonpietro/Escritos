#ifndef ARRAY_H
#define ARRAY_H
#include <stdint.h>
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
 *     mudar após uma remoção ou inserção.
 */
typedef struct {
    void * array;      // bloco de memória com os elementos
    int len;           // capacidade: número máximo de elementos em array
    int n_elem;        // número de elementos armazenados (n_elem <= len)
    size_t elem_size;  // tamanho, em bytes, de cada elemento
    uint8_t realoc_policy; // ARRAY_NO_REALLOC ou ARRAY_REALLOC (ver abaixo)
} Array;

/*
 * Política de overflow, guardada em arr->realoc_policy, que diz o que a
 * inserção faz quando o vetor está cheio (n_elem == len):
 *   ARRAY_NO_REALLOC  a inserção falha (-1);
 *   ARRAY_REALLOC     a capacidade é dobrada com array_reallocate e a
 *                     inserção prossegue; se a realocação falhar, a
 *                     inserção também falha (-1).
 * A política é escolhida em array_init.
 */
#define ARRAY_NO_REALLOC 0
#define ARRAY_REALLOC    1

/*
 * Cria um vetor vazio com capacidade para len elementos de elem_size bytes
 * e política de overflow realoc_policy (ARRAY_NO_REALLOC ou ARRAY_REALLOC).
 * A memória é inicializada com zeros.
 *
 * Retorna o vetor criado, ou NULL se len <= 0 ou se faltar memória.
 * O vetor deve ser liberado com array_free.
 */
Array * array_init(int len, size_t elem_size, uint8_t realoc_policy);

/*
 * Retorna o ponteiro para o elemento de índice i (a partir de 0), ou NULL se
 * i não estiver em [0, n_elem).
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
 * Insere uma cópia do elemento apontado por x na posição i, deslocando os
 * elementos de índice i em diante uma posição para a direita, O(n). Com
 * i == n_elem, insere no fim sem deslocar nada, O(1). Se o vetor estiver
 * cheio, segue arr->realoc_policy.
 *
 * Retorna 0 em sucesso, ou -1 se i não estiver em [0, n_elem] ou se o vetor
 * estiver cheio e não puder crescer.
 */
int array_insert(Array * arr, void * x, int i);

/*
 * Remove o elemento de índice i, O(1): o último elemento é copiado para a
 * posição i, de modo que a ordem dos elementos não é preservada.
 *
 * Retorna 0 em sucesso, ou -1 se i não estiver em [0, n_elem).
 */
int array_remove(Array * arr, int i);

// --------------- Operações de vetores ordenados
//
// Para inserir mantendo a ordem, obtenha a posição i do novo elemento e
// chame array_insert(arr, x, i).

/*
 * Remove o elemento de índice i deslocando os seguintes uma posição para a
 * esquerda, O(n); a ordem é preservada.
 *
 * Retorna 0 em sucesso, ou -1 se i não estiver em [0, n_elem).
 */
int array_remove_sorted(Array *arr, int i);

#endif
