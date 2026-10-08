#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H

/*
 * Lista duplamente encadeada com nó sentinela para dados de tipo arbitrário.
 *
 * A lista guarda apenas ponteiros para os dados (void *); ela nunca copia
 * nem interpreta o seu conteúdo. O nó apontado por head é a sentinela: não
 * contém elemento, e o primeiro elemento da lista é head->next. O prev do
 * primeiro elemento é a sentinela, e o next do último é NULL.
 *
 * Convenções:
 *   - funções que retornam int devolvem 0 em caso de sucesso e -1 em caso
 *     de falha, deixando a lista inalterada (o dado continua sendo do
 *     chamador);
 *   - funções que retornam ponteiro devolvem NULL em caso de falha ou de
 *     elemento inexistente;
 *   - a sentinela nunca é um elemento: seu campo data não deve ser acessado
 *     e ela não pode ser removida.
 */
typedef struct _DListNode {
    void *data;              // ponteiro para o dado guardado no nó
    struct _DListNode *next; // próximo nó (NULL no último)
    struct _DListNode *prev; // nó anterior (a sentinela, no primeiro)
} DListNode;

typedef struct {
    int num_elem;                // número de elementos
    DListNode *head;             // sentinela da lista
    DListNode *tail;             // último nó (igual a head se a lista estiver vazia)
    void (*destroy)(void *data); // libera um dado; NULL se não for necessário
} DList;

/*
 * Cria uma lista vazia. destroy é chamada sobre o dado de cada elemento
 * removido sem recuperação do dado ou destruído; passe NULL se os dados não
 * precisam ser liberados.
 *
 * Retorna a lista criada, ou NULL se faltar memória.
 * A lista deve ser liberada com dlist_destroy.
 */
DList * dlist_init(void (*destroy)(void *data));

/*
 * Busca linear, O(n). Chama compare(e, k) sobre o dado e de cada elemento,
 * que deve retornar 0 quando são iguais, como strcmp. Funções da biblioteca
 * padrão não servem diretamente por causa dos tipos dos parâmetros; é
 * preciso embrulhá-las.
 *
 * Retorna o primeiro elemento igual a k (e não o seu predecessor, ao
 * contrário de list_search), ou NULL se não houver nenhum.
 */
DListNode * dlist_search(DList *dlist, void *k, int (*compare)(void *a, void *b));

/*
 * Insere data logo depois do nó prev, O(1). Se prev for NULL, a inserção é
 * no início da lista.
 *
 * Retorna 0 em sucesso, ou -1 se faltar memória.
 */
int dlist_insert_next(DList *dlist, DListNode *prev, void *data);

/*
 * Insere data logo antes do nó next, O(1). Se next for NULL, a inserção é
 * no fim da lista.
 *
 * Retorna 0 em sucesso, ou -1 se faltar memória ou se next for a sentinela
 * (não há posição antes dela).
 */
int dlist_insert_prev(DList *dlist, DListNode *next, void *data);

/*
 * Remove o elemento node, O(1). node deve ser um elemento desta lista.
 *
 * Se data não for NULL, o ponteiro para o dado removido é guardado em *data
 * e o chamador passa a ser responsável por ele. Se for NULL, o dado é
 * liberado com destroy.
 *
 * Retorna 0 em sucesso, ou -1 se node for NULL ou a sentinela.
 */
int dlist_remove(DList *dlist, DListNode *node, void **data);

/*
 * Libera a lista e seus nós, chamando destroy sobre cada dado. dlist pode
 * ser NULL. Após a chamada, dlist é inválido.
 */
void dlist_destroy(DList *dlist);

#endif /* DLINKED_LIST_H */
