# Revisão — Vetores Dinâmicos

## 2026-10-04 — `estrutras-elementares/sequenciais/vetores-dinamicos.tex`

Escopo: só a seção nova "Vetores Ordenados" (l. 68–110). Números de linha referem-se ao
arquivo nessa data. Compilação: ok, sem erros novos.

### Pendentes

Nenhum.

### Descartados pela batida

Nenhum.

### Edições gramaticais revertidas

Nenhuma.

### Língua (não editado)

Nenhum.

### Decisões do autor

- Chamar $S[i]$ de "$i$-ésimo" com $i = 0$ é a convenção adotada — não é erro.
- `intro.tex` fica fora desta revisão.
- "ultimo" e "temp" sem acento no pseudocódigo são identificadores, não erro.
- Macros em `env.tex` sem uso por ora (`\BuscaVetor`, `\InsereVetor`, `\RemoveVetor`,
  `\BuscaVetorBinaria`) não são erro.
- Não explicitar a pré-condição de que $x$ aponta para dentro do vetor nas remoções: é óbvia.
- A busca binária será apresentada num capítulo posterior — não cobrar aqui.
