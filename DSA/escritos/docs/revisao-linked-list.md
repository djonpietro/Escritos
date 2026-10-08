# Revisão — Listas Encadeadas

## 2026-10-07 — `estrutras-elementares/sequenciais/linked-list.tex`

Escopo: só a seção "Lista Circular Duplamente Encadeada" (l. 144–203), que ainda não foi
commitada. Os números de linha valem para o arquivo nesta data. Compilação: ok, sem erro
novo.

Os três algoritmos (Busca-Lista-DC, Insere-Lista-DC e Remove-Lista-DC) estão corretos,
inclusive com a lista vazia, na inserção e remoção no fim e na proteção da sentinela.

### Pendentes

- [ ] **l. 146–157 (imprecisão).** A frase "o último nó aponta para o primeiro" vale para a
  lista circular em geral. Na versão com sentinela, porém, o `proximo` do último nó aponta
  para a sentinela, e o `anterior` da sentinela aponta para o último. Isso não está dito.
  Correção: acrescentar a precisão no parágrafo da sentinela (l. 153–157).
  Dependentes: nenhum.
- [ ] **l. 147–149 (apresentação).** A frase "não há mais o `tail`" sugere que se perde o
  acesso ao último nó. Na lista duplamente encadeada ele continua acessível em O(1), como
  `L.head.anterior` (as l. 189 e 201 mantêm isso).
  Correção: dizer isso logo depois de introduzir o `anterior` (l. 148–149).
  Dependentes: nenhum.
- [ ] **l. 159 / 193–203 (apresentação).** A busca devolve o próprio nó, mas
  Remove-Lista-DC recebe o antecessor `prev`, e o texto não diz como juntar as duas.
  Correção: uma frase após Remove-Lista-DC dizendo "para remover o nó $w$ devolvido pela
  busca, chama-se Remove-Lista-DC($L$, $w$.anterior)". Na lista circular isso vale para
  todo $w \ne \nil$, porque `anterior` nunca é $\nil$.
  Dependentes: a mesma lacuna existe na seção da lista dupla (l. 95–142).
- [ ] **l. 144 (apresentação).** A seção abre com `\section`, mas as outras variantes são
  `\subsection` de "Listas Encadeadas" (l. 30 e 91). Correção: trocar por `\subsection`.
  Não há `\label` nem `\ref` que dependam disso.
  Dependentes: só a numeração e o sumário.
- [ ] **l. 186–187 (notação).** Nessas linhas, `prev` está em modo texto, enquanto a l. 188
  e Remove-Lista-DC usam `$\mathrm{prev}$`. Correção: `$x.\Prox \gets \mathrm{prev}.\Prox$\;`
  e `$\mathrm{prev}.\Prox \gets x$\;`.
  Dependentes: as seções simples e dupla misturam as duas formas do mesmo jeito (l. 63–64,
  82, 86, 113–114, 135).

### Descartados pela batida

Nenhum.

### Edições gramaticais revertidas

Nenhuma. Foram 5 edições aplicadas (l. 146, 149, 157, 161, 179), todas aprovadas.

### Língua (não editado)

- [ ] l. 151: "listas duplamente ligadas" destoa de "encadeada" no resto do arquivo. A
  troca é segura.
- [ ] l. 161–162: "o critério torna-se quando visitamos novamente a sentinela" soa
  truncado. Sugestão: "o critério de parada passa a ser revisitar a sentinela".

### Decisões do autor

- Na l. 8, a frase "`head` aponta para o primeiro elemento" descreve a versão básica,
  antes da sentinela. Não é contradição.
- `Busca-Lista` começar em `L.Head` e `Busca-Lista-D` começar em `L.Head.Prox` é
  coerente: a primeira devolve o predecessor, a segunda devolve o próprio nó.
