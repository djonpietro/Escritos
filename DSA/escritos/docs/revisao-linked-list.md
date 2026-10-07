# Revisão — Listas Encadeadas

## 2026-10-06 — `estrutras-elementares/sequenciais/linked-list.tex`

Escopo: o arquivo inteiro (ainda não commitado). Números de linha referem-se ao arquivo
nessa data. Compilação: ok na revisão; não recompilada após as correções do autor.

### Pendentes

Nenhum.

### Descartados pela batida

- l. 8 ("`head` aponta para o primeiro elemento" vs. sentinela): é apresentação em dois
  passos (versão típica, depois refinamento com sentinela), não contradição.
- Remoção do `tail` em `Remove-Lista-D`: falso positivo; `prev.Prox = nil` após o
  religamento equivale a `x.Prox = nil`, e o ramo das l. 133–135 já atualiza o `Tail`.
- `Busca-Lista` (parte de `L.Head`) vs. `Busca-Lista-D` (parte de `L.Head.Prox`): coerentes,
  pois a primeira devolve o predecessor e a segunda, o próprio nó.

### Edições gramaticais revertidas

Nenhuma.

### Língua (não editado)

Nenhum.

### Decisões do autor

- Na l. 8, `head` "aponta para o primeiro elemento" na versão básica, antes da sentinela:
  não é contradição.
