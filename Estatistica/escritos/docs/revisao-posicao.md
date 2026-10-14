# Revisão — `aed/medidas/posicao.tex`

Revisão de 2026-10-14. Números de linha referem-se ao arquivo nesta data.

## Achados matemáticos

- [x] **`posicao.tex:47`** — mediana com $n$ par: o índice $\frac{n+1}{2}$ não é inteiro. Corrigir para $\dfrac{x_{(\frac n2)} + x_{(\frac n2 + 1)}}{2}$. Com isso, passa a concordar com a interpolação de `quantis.tex:30–41` em $p = 1/2$.
- [x] **`posicao.tex:51`** — mediana com $n$ ímpar: $x_{(\lfloor n/2 \rfloor)}$ não é o termo central ($n = 1$ dá $x_{(0)}$; $n = 5$ dá $x_{(2)}$). Corrigir para $x_{(\frac{n+1}{2})}$.
- [x] **`posicao.tex:36–37`** — a definição de estatísticas de ordem não amarra a tupla aos valores observados: qualquer tupla não decrescente a satisfaz. Exigir $x_{(i)} = X(\sigma(i))$ para alguma permutação $\sigma$ de $[n]$, com $x_{(1)} \le \dots \le x_{(n)}$. Fora deste arquivo, `quantis.tex:33` e `medidas/simetria.tex:70` escrevem $x_i$ / $x_{n-i+1}$ sem parênteses, o que conflita com $x_i = X(i)$ (`modelos/tipo-dados.tex:87–88`).
- [x] **`posicao.tex:63`** — o $n$ da média não é introduzido. Trocar por "Se $X$ é um atributo de um quadro $D$ com $n$ linhas".

## Língua (não editado)

- [x] **l.32 e l.39** — o ambiente `def:estaticas ordem` provavelmente deveria ser `estatisticas`. Se trocar, mudar também o `\newtheorem` em `aed/medidas/thm.tex`.
- [x] **l.41** — "sendo ela possivelmente uma." não tem sentido claro. Talvez a intenção fosse "possivelmente a média de dois valores".
- [x] **l.61** — "a média trata-se da média aritmética": "tratar-se de" não aceita sujeito. Sugestão: "a média é a média aritmética…".

## Descartados pela batida

- l.22, argmax pode ser um conjunto quando há empate: minúcia, e segue a mesma convenção de `def:moda`.
- l.44, $n$ não introduzido: o $n$ vem do índice da própria tupla $(x_{(i)})_{i=1}^n$.
- l.63–65, notação $\bar X$ diferente de $\bar x$: é consistente dentro do arquivo; a divergência está em `dispersao.tex` e `simetria.tex`, fora do escopo.
- l.72–74, frase sobre atributos ordinais: não há contradição com `tipo-dados.tex`; o caso de $n$ par com atributo ordinal é minúcia.
- l.55–59, intuição dos 50% com empates: o texto diz "cerca de" e é só motivação; a definição formal está em `def:mediana`.
- l.75–77, pontos médios para dados agrupados: o texto não manda tirar a média simples dos pontos médios.

## Edições gramaticais revertidas

Nenhuma.
