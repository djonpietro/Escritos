# Revisão — erros e pendências

Levantamento feito em 2026-09-29 sobre o estado do `main.pdf` (121 p.).
Números de linha referem-se aos `.tex` nessa data e podem ter deslocado.

## 1. Erros matemáticos (prioridade alta)

### Teoria da Medida — `distribuicoes/probabilidades/medida.tex`

- [ ] **l.14** — definição de continuidade num ponto diz "uniformemente contínua em $a$"; deve ser "contínua em $a$". Em todas as definições, $\exists \delta \in \real$ → $\exists \delta > 0$.
- [ ] **l.56** — exemplo de continuidade *uniforme* chama $\sin$, $\cos$ de "absolutamente contínuas".
- [ ] **l.~62** — $1/x$: especificar o domínio $(0, \infty)$.
- [ ] **l.66** — compacto descrito como "contido em um aberto e que possui todos os pontos de acumulação"; o correto em $\real$ é fechado e limitado (ou: toda cobertura aberta admite subcobertura finita).
- [ ] **l.109** — axioma (iii) da σ-álgebra quantifica sobre um $A$; deve ser: para toda sequência $(A_i) \subset \mathcal{B}$, $\bigcup A_i \in \mathcal{B}$.
- [ ] **l.116** — "topologia usual = intervalos e conjuntos enumeráveis" está errado; a topologia usual é gerada pelos intervalos abertos. Reescrever a motivação da σ-álgebra de Borel.
- [ ] **l.130** — medida nula: cobertura enumerável escrita como $\{I_k\}_1^n$; usar $\{I_k\}_{k \in \nat}$.
- [ ] **l.353** — $\int f = \int f^+ + \int f^-$; o correto é $\int f^+ - \int f^-$.
- [ ] **l.235** — "a medida de contagem é σ-finita": falso em $\real$ (não enumerável). Só vale em conjuntos enumeráveis. **Afeta a prova de existência da f.m.p.** (ver `discreta.tex`).
- [ ] **l.498–501** — Hölder enunciado como igualdade; correto: $\int |fg|\,d\mu \le \|f\|_p \|g\|_q$.
- [ ] **l.521** — inclusão invertida: com $\mu(\Omega) < \infty$ e $p \le q$, vale $L^q \subset L^p$.
- [ ] Tonelli: integrais iteradas estão sem o sinal de integral interno ($\int (\int f\,d\mu_1)\,d\mu_2$).
- [ ] Grafias: "Steltjes/Steljes" → Stieltjes; "Toneli" → Tonelli; "Cauchy-Schwartz" → Cauchy–Schwarz.

### Probabilidade — `distribuicoes/probabilidades/`

- [ ] **`condicional.tex:25`** — Regra do Produto exige "eventos disjuntos" (interseção seria vazia). Deve ser família qualquer com $P(\bigcap_{j<n} E_j) > 0$. A prova também está com o comentário "consertar para enumeráveis".

### Variáveis Aleatórias — `distribuicoes/variaveis/`

- [ ] **`discreta.tex` (Prop. suporte enumerável) — RESULTADO FALSO.** "Suporte enumerável ⇔ discreta" não vale. Contraexemplo: massas $2^{-n}$ nos racionais $q_n$ → $X$ discreta com suporte $\real$. Erro na prova (**l.39**): o conjunto de pontos de acumulação de um enumerável não é necessariamente enumerável. Manter só a direção "suporte enumerável ⇒ discreta".
- [ ] **`discreta.tex` (existência da f.m.p.)** — usa Radon–Nikodym com a contagem em $\real$ (não σ-finita). Corrigir usando a contagem restrita ao conjunto enumerável $S$ com $P_X(S)=1$, ou provar diretamente por σ-aditividade.
- [ ] **`discreta.tex:70`** — "$0 < P(X = x) < 1$ para todo $x$"; correto $0 \le P(X=x) \le 1$.
- [ ] **`discreta.tex` (final)** — $F(x_i) - \lim_{x\to x_i^-}F(x) = F(x_i) - F(x_{i-1})$ só vale se o suporte for discreto e ordenável; mesmo problema do resultado falso acima.
- [ ] **`cumulada.tex:73`** — $\lim \{X = b_n\}$ deveria ser $\{X \le b_n\}$; "$\{X \le \infty\}$" não é evento de $\real$ — escrever como $\bigcup_n \{X \le n\} = \Omega$.
- [ ] **`transformacoes.tex:77`** — "pelo Lema" sem referência (o lema foi comentado em `discreta.tex`).
- [ ] **`transformacoes.tex`** — Teorema da f.d.a. da transformação: para $g$ decrescente, $g^{-1}(y)$ precisa de $g$ bijetora; o enunciado não exige. Na versão não monótona, a hipótese (iii) $g_i(A_i) = \Omega_Y$ é forte demais (ex.: $x^2$ com suporte assimétrico).
- [ ] **`esperanca.tex:235`** — f.g.m. com domínio $\nat$; deve ser $\real$ (ou vizinhança de 0).
- [ ] **`esperanca.tex`** — prova da derivada da f.g.m. só trata o caso contínuo e não justifica a troca derivada/integral.
- [ ] **`esperanca.tex:320`** — teorema "momentos × distribuição": a prova só mostra a direção trivial, supõe densidade e a integração por partes está com termos de fronteira mal escritos. Ou provar direito, ou declarar "sem demonstração".
- [ ] **`esperanca.tex`** — notação do momento: `\mm_(\mu)'` (typo no LaTeX).
- [ ] **`simetria.tex`** — prova do caso contínuo em `thm:simetria funcao de probabilidade` é confusa ($F_Y$, $F_U$); refazer derivando $F_X(m+t) = 1 - F_X(m-t)$ em $t$. Em "$u = w$" a troca de variável é vazia.
- [ ] **`simetria.tex`** — Teorema média = mediana: exigir $\ev{|X|} < \infty$, não $\ev{X} < \infty$. Unimodal ⇒ moda = $m$ supõe moda única; ok, mas deixar explícito.

### Modelos — `distribuicoes/modelos/`

- [ ] **`discretos.tex:371, 377`** — binomial negativa: $\binom{n}{r}$ → $\binom{n-1}{r-1}$ (a própria dedução mostra isso).
- [ ] **`discretos.tex:221`** — hipergeométrica: $\binom52\binom71/\binom{12}{3} = 70/220 \approx 0{,}318$, não $0{,}053$.
- [ ] **`discretos.tex`** — notação da hipergeométrica: $\mathrm{HG}(N, n, k)$ na definição vs. $\mathrm{HG}(N, m, n)$ nas observações.
- [ ] **`discretos.tex:294`** — geométrica: soma 4 com prob. 1/12 exige **dois** dados.
- [ ] **`discretos.tex`** — prova de $E[X]$ da geométrica começa em $k=0$; binomial: variância enunciada mas não provada; binomial negativa: idem para variância.
- [ ] **`discretos.tex`** — Poisson: "$\lim 1 - (\lambda/n)^a = 1$" deveria ser $(1-\lambda/n)^a \to 1$. Prova de $\ev{X^2}$ tem índices confusos.
- [ ] **`normal.tex:41`** — lema gaussiano: integrando $e^{-(t+u)^2/2}$ → $e^{-(t^2+u^2)/2}$; $u = r\cos\theta$ → $u = r\sin\theta$; ordem $dr\,d\theta$ inconsistente com os limites.
- [ ] **`normal.tex:102`** — $x = (y-b)/\mu$ → $(y-b)/a$. A prova também confunde densidade com distribuição e não trata $a < 0$.
- [ ] **`normal.tex:185`** — $f(-x) = f(x)$ e $F(-x) = 1 - F(x)$ só valem para $\mu = 0$ (a prova usa $|-x-\mu| = |x-\mu|$, falso). Enunciar para a normal padrão, ou simetria em torno de $\mu$.
- [ ] **`normal.tex:3` × `intro/visao-geral.tex:88`** — datas de De Moivre inconsistentes. Aproximação normal da binomial é de 1733 (incluída na 2ª ed. da *Doctrine*, 1738); a intro atribui a 1718.
- [ ] **`normal.tex`** — "Abraham de De Moivre" → "Abraham de Moivre".
- [ ] **`continuos.tex:117`** — exponencial: $1 - e^{\lambda x}$ → $1 - e^{-\lambda x}$.
- [ ] **`continuos.tex`** — sem memória da exponencial: $1 - P(X \le s) = e^{-\lambda s}$ ok, mas conferir sinais após corrigir a f.d.a.
- [ ] **`continuos.tex:153`** — $\Gamma(n) = n!$ → $(n-1)!$. Também "$\Gamma(\alpha)$ pode ser expressa por fórmula fechada" é falso em geral. `\Gamma{\alpha}` → `\Gamma(\alpha)`.
- [ ] **`continuos.tex:231`** — χ²: $x^{n/2}$ → $x^{n/2-1}$.
- [ ] **`continuos.tex`** — Cauchy: "todos os momentos são infinitos" — na verdade não existem (a média não está definida; $\ev{X^n}$ de ordem ímpar é indefinida). Notação $\mathrm{Cauchy}(\theta)$ ignora $\gamma$.
- [ ] **`continuos.tex:296`** — Weibull: "Weilbull" (título e texto). Na lista de interpretação, os papéis de $\alpha$ (escala) e $\beta$ (forma) estão trocados em relação à densidade definida.
- [ ] **`continuos.tex:351`** — Beta: definição usa $a, b$; fórmula de $B$ e o resto usam $\alpha, \beta$. Variância para $\alpha=\beta$ está correta.
- [ ] **`continuos.tex`** — log-normal: faltou suporte $x > 0$ na densidade.
- [ ] **`continuos.tex`** — Laplace: "seleção de atributos" — esclarecer que é via priori de Laplace ⇔ penalização L1 (LASSO).
- [ ] **`continuos.tex`** — referência à "transformação de variáveis uniformes contínuas" em `normal.tex` aparece antes da seção da uniforme (ordem de inclusão).
- [ ] **`desigualdade.tex`** — "Jansen" → Jensen; Chebyshev enunciado como Corolário mas com `\label` de corolário, ok. Prop. variância 0: "para todo $n \in \real$" → $n \in \nat$; e a igualdade $X = \ev{X}$ é q.c.

## 2. Análise Exploratória — `aed/`

- [ ] **`modelos/tabelas.tex:10`** — "a terceira é a frequência relativa" (só há duas colunas).
- [ ] **`modelos/tabelas.tex`** — frequência acumulada: $\sum_{j=1}^i f_i$ → $\sum_{j=1}^i f_j$.
- [ ] **`modelos/tipo-dados.tex`** — "idades" como exemplo de discreto é discutível; escala de razão: "transformações lineares" → multiplicação por constante positiva.
- [ ] **`modelos/grafico.tex:62–65`** — Scott e Freedman–Diaconis dão a **largura** $h$ do bin, não o número $k$. Ramo-e-folha: ramos não são necessariamente a parte inteira.
- [ ] **`modelos/grafico.tex`** — código do pirulito usa `group_by`/`summarise` sem `library(dplyr)`.
- [ ] **`medidas/posicao.tex:46–47`** — mediana: $n$ ímpar → índice $(n+1)/2$; $n$ par → média dos índices $n/2$ e $n/2 + 1$.
- [ ] **`medidas/posicao.tex`** — definição $N(x)/n = 0{,}5$ pode não ter solução; usar a definição por desigualdades.
- [ ] **`medidas/dispersao.tex:14`** — "seção ??" (referência faltando). Variância com $|x_i - \bar x|^2$ (módulo desnecessário); mencionar divisor $n-1$. Fórmula do DMA termina com "$\quad e \quad$" solto.
- [ ] **`medidas/quantis.tex:55`** — **texto colado no meio da fórmula**: "Fazendo $h = (n-1)p +usados para medir simetria. Para distribuições aproximada 1$". Restaurar para "Fazendo $h = (n-1)p + 1$".
- [ ] **`medidas/quantis.tex`** — definição de quantil $F(q) = p$ pode não ter solução (discretas); usar $Q(p) = \inf\{x : F(x) \ge p\}$. "probabilidade ... é $q$" → é $p$. A dedução "$x_j < (n-1)p + 1 < x_{j+1}$" mistura índices com valores. IQR: "Intervalo Interquantílico" → Interquartílico.
- [ ] **`medidas/simetria.tex:30, 36`** — Pearson I e II dividem por $s$, não $\sigma^3$.
- [ ] **`medidas/simetria.tex:42`** — quartílico: $q_1 + q_2 - 2\,\mathrm{med}$ → $q_1 + q_3 - 2\,\mathrm{med}$.
- [ ] **`medidas/simetria.tex:48`** — Fisher: usa $\sigma^3$ sem dizer qual desvio (com $n$); conferir fórmula.
- [ ] **`medidas/simetria.tex:54`** — direções trocadas: $c > 0$ = assimetria **à direita** (cauda longa à direita, $\bar x > \mathrm{mo}$); $c < 0$ = à esquerda.
- [ ] **`medidas/robustas.tex:21`** — média aparada: $\alpha \in [0, 1]$ → $\alpha \in [0, 0{,}5)$.
- [ ] **`medidas/robustas.tex:26`** — coeficiente de variação apresentado como medida robusta (não é: usa média e desvio-padrão). Também "Uma segunda medida" repetido para o MAD.

## 3. Introdução — `intro/visao-geral.tex`

- [ ] **l.88** — ver inconsistência de datas de De Moivre (seção 1).
- [ ] **l.89** — "trazando" → trazendo.
- [ ] **l.233–235** — "estatśitica", "econtrar", "mudanos".
- [ ] Frase duplicada: "teriam diploma teriam diploma".
- [ ] "Uma função ... é fundamenta" → fundamentada; "hipoteses" → hipóteses; "probablísticos" → probabilísticos.

## 4. Ortografia recorrente (buscar e substituir)

- "calda/caldas" → cauda/caudas
- "entorno de" → em torno de
- "probablidade" → probabilidade
- "defini-se/decidi-se" → define-se/decide-se
- "Weilbull" → Weibull; "Jansen" → Jensen; "Steltjes" → Stieltjes; "Toneli" → Tonelli
- "univero", "medidad", "signfica", "signigica", "seqência", "sequêcia", "absulotamente", "elemetos", "resltados", "densiade", "transoformação", "Hipótse", "Conseideremos"

## 5. Estrutura e pedagogia (para decidir depois)

- [ ] Definir público-alvo: a Parte I usa teoria da medida; a Parte II é receituário descritivo que não aproveita essa base.
- [ ] "Noções de Medida" é lista densa sem provas e concentra muitos erros — enxugar ao que é usado depois ou mover para apêndice.
- [ ] Parte I sem figuras (densidades, f.d.a.) e com poucos exemplos/exercícios.
- [ ] Muitas proposições dos modelos contínuos sem demonstração (uniforme, exponencial, gama, χ², Cauchy, log-normal).
- [ ] Capítulos vazios no meio da Parte I (Multidimensionais, Simulação); `covariancia.tex` comentado.
- [ ] TCL mencionado só informalmente ao fim de `normal.tex`; Lei dos Grandes Números comentada em `desigualdade.tex`.
