# Revisão — Fila

## 2026-10-10 — `estrutras-elementares/sequenciais/fila.tex`

Escopo: o arquivo inteiro. A parte com vetores (l. 18–49) já tinha sido revista; a parte com listas encadeadas está nas l. 51–72. É uma seção nova,
ainda não commitada, conferida de novo depois das correções do autor. Os números de linha valem
para o arquivo depois dessas correções.
Compilação: ok, sem erro.

Estão corretos: a política FIFO e a analogia (l. 5–6), o argumento de custo da l. 15 e o
Enqueue (l. 31–38). No Dequeue, já estão certos o avanço de `Q.f`, o decremento do contador e
o retorno de x. Na parte com lista estão certos: o Enqueue pelo tail, em O(1) (com a fila
vazia o tail é a sentinela, porque `Remove-Lista` faz tail ← prev ao tirar o último); o
Dequeue pelo início, que também atualiza o tail quando esvazia a fila; e o tipo de x (nó no
Enqueue, conteúdo no retorno do Dequeue), que segue a convenção do Push e do Pop.

### Pendentes

Foram corrigidos pelo autor: o contador no Dequeue, o retorno de x, o Enqueue, o avanço de
`Q.f`, o estado inicial f = 0 e r = n − 1 (l. 22–23), a definição de n, o `\bmod`, a leitura `Q[Q.f]` no Dequeue (l. 44) e a
motivação da fila circular, que agora é o tempo constante (l. 18–19). O critério de fila cheia
saiu do texto. Na parte com lista, o autor acrescentou o teste de underflow no Dequeue
(l. 65–67) e a justificativa de inserir no fim e remover no início (l. 54–56).

Nenhum item pendente.

### Descartados pela batida

Nenhum.

### Edições gramaticais revertidas

Nenhuma. Foram aplicadas: "um política" → "uma política" (l. 3), "é chamada de" → "é chamado
de" (l. 7), "criar um fila … é inserido os novos membros" → "criar uma fila … é inserir os
novos membros" (l. 12) e "tem" → "têm" (l. 22).

### Língua (não editado)

- [ ] **l. 6.** "assim como filas de atendimento": "assim como em filas de atendimento" leria
  melhor. A frase não está errada, então a escolha fica com o autor.

### Decisões do autor

- Ordem do Enqueue: o autor acha que fica implícito que r avança e depois grava. Agora a ordem está descrita
  na l. 24.
- "r aponta para o último inserido" não contradiz f = r com um elemento, porque
  nesse caso o primeiro é também o último.
- Não é preciso dizer que NumElem = 0 com a fila vazia: isso decorre da própria definição do contador.
