# Revisão — Vetores Dinâmicos

## 2026-10-08 — `estrutras-elementares/sequenciais/vetores-dinamicos.tex`

Escopo: o arquivo inteiro, após a reescrita do autor (ainda não commitada), conferido de novo
depois das correções. Os números de linha valem para o arquivo após as correções.
Compilação: ok, sem erro novo.

Estão corretos: Busca-Vetor (o curto-circuito evita ler `S[num_elem]`), o deslocamento de
Insere-Vetor (inclusive com i = num_elem), a cópia em Realoca-Vetor, Remove-Vetor e as
complexidades enunciadas.

### Pendentes

Os dois bugs críticos (Remove-Vetor-Ordenado e Realoca-Vetor) e os pontos sobre posição de
inserção, ordem de validação, `=`/`\gets` e "último adicionado" foram corrigidos pelo autor.

- [ ] **l. 136–137 (menor).** Máximo e mínimo ainda não dizem o que devolver com o vetor
  vazio. Pela convenção de `intro.tex`, devolve-se $\nil$, como já se faz no
  predecessor/sucessor (l. 139–140).
  Dependentes: nenhum.
- [ ] **l. 56, com l. 8 e 75–81 (menor, opcional).** `$S \gets \RealocaVetor{$S$}$` só
  surte efeito para quem chama se S for passado por referência. A l. 8 trata S como ponteiro,
  enquanto os algoritmos o tratam como registro com `.len` e `.num_elem`.
  Correção: uma frase de convenção.
  Dependentes: nenhum.

### Descartados pela batida

- l. 133–136, parte "retornar o ponteiro": é coerente com a l. 8 e a l. 44 (S+i), então
  não é erro.

### Edições gramaticais revertidas

Nenhuma. Aplicadas: "o vetores" → "os vetores" (l. 20), "caso não ele não exista" →
"caso ele não exista" (l. 28–29) e "adcionado" → "adicionado" (l. 68).

### Língua (não editado)

- [ ] **l. 139–140.** "quando esses são válidos, se não $\nil$ deve ser retornado": aqui
  o sentido é "caso contrário", que se escreve "senão", e pede vírgula ("…válidos; senão,
  $\nil$ deve ser retornado").
- [ ] **l. 138.** "consistem dos elementos": a norma pede "consistem nos". "Consistir
  de" é muito usado, então a escolha fica com o autor.

### Decisões do autor

- Chamar $S[i]$ de "$i$-ésimo" com $i = 0$ é a convenção adotada — não é erro.
- `intro.tex` fica fora desta revisão.
- "ultimo" e "temp" sem acento no pseudocódigo são identificadores, não erro.
- Macros em `env.tex` sem uso por ora (`\BuscaVetor`, `\InsereVetor`, `\RemoveVetor`,
  `\BuscaVetorBinaria`) não são erro.
- Não explicitar a pré-condição de que $x$ aponta para dentro do vetor nas remoções: é óbvia.
- A busca binária será apresentada num capítulo posterior — não cobrar aqui.
