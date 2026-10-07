#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/*
 * Lista simplesmente encadeada com nó sentinela para dados de tipo
 * arbitrário.
 *
 * A lista guarda apenas ponteiros para os dados (void *); ela nunca copia
 * nem interpreta o seu conteúdo. O nó apontado por head é a sentinela: não
 * contém elemento, e o primeiro elemento da lista é head->next.
 *
 * Convenções:
 *   - funções que retornam int devolvem 0 em caso de sucesso e -1 em caso
 *     de falha;
 *   - funções que retornam ponteiro devolvem NULL em caso de falha ou de
 *     elemento inexistente.
 */
typedef struct _ListNode {
  void *data;             // ponteiro para o dado guardado no nó
  struct _ListNode *next; // próximo nó da lista
} ListNode;

typedef struct {
  ListNode *head; // sentinela da lista
  ListNode *tail; // último nó (igual a head se a lista estiver vazia)
  int num_elem;   // número de elementos
  void (*destroy)(void *data); // libera um dado; NULL se não for necessário
} List;

/*
 * Cria uma lista vazia. destroy é chamada sobre o dado de cada elemento
 * removido ou destruído; passe NULL se os dados não precisam ser liberados.
 *
 * Retorna a lista criada, ou NULL se faltar memória.
 * A lista deve ser liberada com list_destroy.
 */
List *list_init(void (*destroy)(void *data));

/*
 * Insere data no início da lista, O(1).
 *
 * Retorna 0 em sucesso, ou -1 se faltar memória.
 */
int list_insert(List* list, void *data);

/*
 * Insere data logo depois do nó previous, O(1). Se previous for NULL, a
 * inserção é no início, como em list_insert.
 *
 * Retorna 0 em sucesso, ou -1 se faltar memória.
 */
int list_insert_next(List *list, ListNode *previous, void *data);

/*
 * Remove o elemento logo depois do nó previous, O(1). Se previous for NULL,
 * remove o primeiro elemento.
 *
 * Se data não for NULL, o ponteiro para o dado removido é guardado em *data
 * e o chamador passa a ser responsável por ele. Se for NULL, o dado é
 * liberado com destroy.
 *
 * Retorna 0 em sucesso, ou -1 se não houver elemento a remover.
 */
int list_remove_next(List *list, ListNode *previous, void **data);

/*
 * Libera a lista e seus nós, chamando destroy sobre cada dado. list não
 * pode ser NULL. Após a chamada, list é inválido.
 */
void list_destroy(List *list);

/*
 * Insere data no fim da lista, O(1).
 *
 * Retorna 0 em sucesso, ou -1 se faltar memória.
 */
int list_append(List *list, void *data);

/*
 * Busca linear, O(n). Chama compare(e, x) sobre o dado e de cada elemento,
 * que deve retornar 0 quando são iguais, como strcmp. Funções da biblioteca
 * padrão não servem diretamente por causa dos tipos dos parâmetros; é
 * preciso embrulhá-las:
 *
 *   int cmp_str(void *a, void *b) {
 *     return strcmp((const char *)a, (const char *)b);
 *   }
 *
 * Retorna o nó anterior ao primeiro elemento igual a x, ou NULL se não
 * houver nenhum. Quando o elemento é o primeiro da lista, o retorno é a
 * sentinela: serve como argumento de list_remove_next e list_insert_next,
 * mas seu campo data não deve ser acessado.
 */
ListNode *list_search(const List *list, int (*compare)(void *a, void *b),
                      void *x);

/*
 * Retorna o dado do primeiro elemento, O(1), ou NULL se a lista estiver vazia.
 */
// #define list_head(list) ((list)->head->next->data)
void * list_head_data(const List * list);

/*
 * Retorna o dado do último elemento, O(1). Se a lista estiver vazia, devolve
 * o dado da sentinela (NULL).
 */
#define list_tail_data(list) ((list)->tail->data)

/*
 * Retorna o número de elementos da lista, O(1).
 */
#define list_num_elem(list) ((list)->num_elem)

#endif /* LINKED_LIST_H */
