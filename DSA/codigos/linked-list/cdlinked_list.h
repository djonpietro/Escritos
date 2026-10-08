#ifndef CDLINKED_LIST_H
#define CDLINKED_LIST_H

/*
 * Lista circular duplamente encadeada com nó sentinela para dados de tipo
 * arbitrário.
 *
 * A lista guarda apenas ponteiros para os dados (void *); ela nunca copia
 * nem interpreta o seu conteúdo. O nó apontado por head é a sentinela: não
 * contém elemento, e o primeiro elemento da lista é head->next. A lista é
 * circular: o next do último elemento e o prev do primeiro são a sentinela,
 * e o último elemento é head->prev. Com a lista vazia, head->next e
 * head->prev apontam para a própria sentinela.
 *
 * Convenções:
 *   - funções que retornam int devolvem 0 em caso de sucesso e -1 em caso
 *     de falha, deixando a lista inalterada (o dado continua sendo do
 *     chamador);
 *   - funções que retornam ponteiro devolvem NULL em caso de falha ou de
 *     elemento inexistente;
 *   - a sentinela nunca é um elemento: seu campo data não deve ser acessado
 *     e ela não pode ser removida, mas pode ser usada como referência nas
 *     inserções.
 */
typedef struct _CDListNode {
    void *data;               // ponteiro para o dado guardado no nó
    struct _CDListNode *next; // próximo nó (a sentinela, no último)
    struct _CDListNode *prev; // nó anterior (a sentinela, no primeiro)
} CDListNode;

typedef struct {
    int num_elem;                // número de elementos
    CDListNode *head;            // sentinela da lista; head->prev é o último nó
    void (*destroy)(void *data); // libera um dado; NULL se não for necessário
} CDList;

/*
 * Cria uma lista vazia. destroy é chamada sobre o dado de cada elemento
 * removido sem recuperação do dado ou destruído; passe NULL se os dados não
 * precisam ser liberados.
 *
 * Retorna a lista criada, ou NULL se faltar memória.
 * A lista deve ser liberada com cdlist_destroy.
 */
CDList * cdlist_init(void (*destroy)(void *data));

/*
 * Busca linear, O(n). Chama compare(e, k) sobre o dado e de cada elemento,
 * que deve retornar 0 quando são iguais, como strcmp. Funções da biblioteca
 * padrão não servem diretamente por causa dos tipos dos parâmetros; é
 * preciso embrulhá-las.
 *
 * Retorna o primeiro elemento igual a k, ou NULL se não houver nenhum.
 */
CDListNode * cdlist_search(CDList *cdlist, void *k, int (*compare)(void *a, void *b));

/*
 * Insere data logo depois do nó prev, O(1). prev deve ser um elemento desta
 * lista ou a sentinela; com a sentinela, a inserção é no início da lista.
 *
 * Retorna 0 em sucesso, ou -1 se prev for NULL ou se faltar memória.
 */
int cdlist_insert_next(CDList *cdlist, CDListNode *prev, void *data);

/*
 * Insere data logo antes do nó next, O(1). next deve ser um elemento desta
 * lista ou a sentinela; com a sentinela, a inserção é no fim da lista.
 *
 * Retorna 0 em sucesso, ou -1 se next for NULL ou se faltar memória.
 */
int cdlist_insert_prev(CDList *cdlist, CDListNode *next, void *data);

/*
 * Remove o elemento node, O(1). node deve ser um elemento desta lista.
 *
 * Se data não for NULL, o ponteiro para o dado removido é guardado em *data
 * e o chamador passa a ser responsável por ele. Se for NULL, o dado é
 * liberado com destroy.
 *
 * Retorna 0 em sucesso, ou -1 se node for NULL ou a sentinela.
 */
int cdlist_remove(CDList *cdlist, CDListNode *node, void **data);

/*
 * Libera a lista e seus nós, chamando destroy sobre cada dado. cdlist pode
 * ser NULL. Após a chamada, cdlist é inválido.
 */
void cdlist_destroy(CDList *cdlist);

#endif /* CDLINKED_LIST_H */
