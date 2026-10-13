# Revisão — erros e pendências

Levantamento feito em 2026-09-29 sobre o estado do `main.pdf` (121 p.); atualizado em
2026-10-13. Erros de digitação, notação e ortografia já foram corrigidos; aqui ficam os
erros conceituais, enunciados falsos e demonstrações erradas, além das pendências
(provas ainda não escritas).
Números de linha referem-se aos `.tex` em 2026-10-11 e podem ter deslocado.

## 1. Análise Exploratória — `aed/`

Ainda não revisitado após a primeira rodada.

- [ ] **`modelos/grafico.tex:62–66`** — Scott e Freedman–Diaconis dão a **largura** $h$ do bin, não o número $k$. Ramo-e-folha (l.78): ramos não são necessariamente a parte inteira.
- [ ] **`medidas/posicao.tex:43`** — definição $N(x)/n = 0{,}5$ pode não ter solução; usar a definição por desigualdades.
- [ ] **`medidas/quantis.tex:8`** — definição de quantil $F(q) = p$ pode não ter solução (discretas); usar $Q(p) = \inf\{x : F(x) \ge p\}$. A dedução "$x_j < (n-1)p + 1 < x_{j+1}$" (l.53) mistura índices com valores.
- [ ] **`medidas/simetria.tex:55–61`** — direções trocadas: $c > 0$ = assimetria **à direita** (cauda longa à direita, $\bar x > \mathrm{mo}$); $c < 0$ = à esquerda.
- [ ] **`medidas/robustas.tex:26`** — coeficiente de variação apresentado como medida robusta (não é: usa média e desvio-padrão).

## 2. Pendências (provas a escrever)

- [ ] **`discreta.tex:28`** — Proposição `prop:existencia fmp`: prova comentada ("% refazer a prova"). A versão antiga usava Radon–Nikodym com a contagem em $\real$, que não é σ-finita; dá para usar a contagem restrita ao conjunto enumerável $S$ com $P_X(S) = 1$, ou provar direto por σ-aditividade.
- [ ] **`esperanca.tex:335`** — Teorema `thm:condicao de igualdade de distribuicao e momento`: prova incompleta ("% a continuar").
- [ ] **`condicional.tex:23`** — Regra do Produto: comentário "Consertar a prova para conjuntos enumeráveis" (a prova atual cobre famílias finitas).

## 3. Estrutura e pedagogia (para decidir depois)

- [ ] Definir público-alvo: a Parte I usa teoria da medida; a Parte II é receituário descritivo que não aproveita essa base.
- [ ] "Noções de Medida" é lista densa sem provas — enxugar ao que é usado depois ou mover para apêndice.
- [ ] Parte I sem figuras (densidades, f.d.a.) e com poucos exemplos/exercícios.
- [ ] Muitas proposições dos modelos contínuos sem demonstração (uniforme, exponencial, gama, χ², Cauchy, log-normal).
- [ ] Capítulos vazios no meio da Parte I (Multidimensionais, Simulação); `covariancia.tex` comentado.
- [ ] TCL mencionado só informalmente ao fim de `normal.tex`; `desigualdade.tex` (Markov, Chebyshev, Jensen, Lei dos Grandes Números) está fora do `main.tex`.
