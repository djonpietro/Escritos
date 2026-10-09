# Revisão — Pilha

## 2026-10-09 — `estrutras-elementares/sequenciais/pilha.tex`

Escopo: o arquivo inteiro, uma seção nova ainda não commitada, conferido de novo depois das
correções do autor. Os números de linha valem para o arquivo após essas correções.
Compilação: ok, sem erro.

Estão corretos: a definição de LIFO, o Push com vetor (o teste de overflow impede a
realocação, então Insere-Vetor com i = num_elem custa O(1)), o Pop com vetor (verifica o
underflow antes de ler), o Push com lista após a sentinela e o Pop com lista. Agora os dois
Pop devolvem o objeto, de forma coerente com a l. 22.

### Pendentes

Foram corrigidos pelo autor: a definição de LIFO, o underflow no Pop com vetor, o `\;` do
`\Retorna`, o custo constante (a realocação saiu, e o Push com vetor passou a levantar
overflow), a diferença de tipo de $x$ entre as implementações e a justificativa do topo no
início (l. 45–47).

Nenhum item pendente.

### Descartados pela batida

Nenhum.

### Edições gramaticais revertidas

Nenhuma. Foram aplicadas: "é estrutura" → "é uma estrutura" (l. 3), "podem ou não serem
realizadas" → "podem ou não ser realizadas" (l. 19) e "ínicio" → "início" (trecho depois reescrito pelo autor).

### Língua (não editado)

- [ ] **l. 13.** "implementar pilhas: como vetores ou como listas encadeadas": "com vetores ou
  com listas" soa mais natural. A frase não está errada, então a escolha fica com o autor.

### Decisões do autor

- l. 46–47: "de forma a impossibilitar remoções eficientes" se refere ao pop com o topo no
  final da lista. Fica como está.
