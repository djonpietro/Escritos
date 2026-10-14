# Revisão — `aed/medidas/dispersao.tex`

Revisão de 2026-10-14. Números de linha referem-se ao arquivo nesta data.

## Achados matemáticos

- [x] **`dispersao.tex:26`** — `\var{X}` com divisor $n-1$ choca com o símbolo já definido: `esperanca.tex:151` dá $\var{X} = \mm_2$, e aplicado a $X$ sob $P_D$ (`modelos/tipo-dados.tex:85–90`) isso tem divisor $n$. Com $(1,2,3)$, uma definição dá $2/3$ e a outra dá $1$. A nota de rodapé ainda chama a quantidade de estimador da variância populacional, que também se escreve $\var{X}$. Usar notação própria ($s_X^2$ e $s_X = \sqrt{s_X^2}$). Se quiser, notar que $\frac{n-1}{n} s_X^2$ é a variância de $X$ sob $P_D$. Dependentes: `dispersao.tex:34` (`\dep{X}`); `robustas.tex:27` passa a apontar para $s_X$ sem precisar de edição.
- [x] **`dispersao.tex:22`** — falta exigir $n \ge 2$: com $n = 1$, a fórmula vira $0/0$. Escrever "com $n \ge 2$ linhas". O desvio-padrão (l.34) herda a mesma hipótese.
- [x] **`dispersao.tex:19`** — "erro quadrático médio" não vale com divisor $n-1$: a quantidade é essa média multiplicada por $\frac{n}{n-1}$. Escrever "a menos do fator $\frac{n}{n-1}$" ou "aproximadamente, para $n$ grande".
- [x] **`dispersao.tex:6–8`** — o nome está em negrito como "desvio médio absoluto", mas a definição e a l.38 dizem "desvio absoluto médio": usar um nome só. Além disso, a quantidade *é* o erro absoluto médio em relação à média, não "uma estimativa" dele, então a palavra deve sair.

## Língua (não editado)

- [x] **l.41** — "independente da magnitude": a norma pede "independentemente".
- [x] **l.30–31** — "Como …, então sua interpretação…": o "então" sobra. É estilo.

## Descartados pela batida

- l.9, "indica se a média é uma boa medida de resumo" (o centro ótimo no erro absoluto é a mediana): frase informal e não falsa; seria minúcia.
- l.42–44, desvio-padrão "preferível para detectar atípicos": o texto só diz que ele reage mais a valores distantes, o que está certo; o mascaramento só vale para regras do tipo $|z| > k$, que o texto não propõe.

## Edições gramaticais revertidas

Nenhuma.
