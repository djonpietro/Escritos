---
name: estilo-escritos
description: Convenções dos textos do repositório Escritos — estrutura dos livros LaTeX, macros, zonas que a revisão de prosa não pode tocar, formato do relatório de revisão e como compilar. Fonte única para os agentes revisores.
disable-model-invocation: true
---

# Convenções dos Escritos

## Estrutura

- Um livro por disciplina, cada um com seu `main.tex`: `Estatistica/escritos/`,
  `Analise/escritos/`, `AlgeLin/escritos/`, `Discreta/`, `FundamentosMat/`, etc.
  O **diretório do livro** é o que contém o `main.tex`.
- `main.tex` monta o livro por `\input{...}`; a ordem dos `\input` é a ordem de
  leitura. Um resultado só pode usar o que veio antes nessa ordem.
- `temp.tex` é o preâmbulo: pacotes e macros (`\real`, `\nat`, `\borel`, `\ev{}`,
  `\var{}`, `\cov{}{}`, `\dep{}`, `\med{}`, `\mo{}`, `\norm{}`, `\qs`, `\Parts{}` …).
  Antes de apontar notação estranha, confira se é macro definida ali.
- `thm.tex` (na raiz do livro e em subpastas) declara os ambientes de teorema com
  `\newtheorem`. Os nomes são do tipo `def:supremo`, `prop:completude infimo`,
  `ax:supremo`, `thm:...`, `cor:...`, `ex:...`. **São nomes de ambiente, não texto**:
  `\begin{prop:completude infimo}` não é prosa e não se corrige.
- Achados de revisão ficam em `<livro>/docs/`.

## Língua

- Português brasileiro, registro formal de livro-texto, 1ª pessoa do plural
  ("vamos provar", "enunciaremos").
- A terminologia do autor é escolha, não erro: majorante/cota superior,
  "q.s.", "f.d.a.", "f.m.p.", nomes de teoremas. Só se corrige grafia errada de
  nome próprio (Stieltjes, Tonelli, Cauchy–Schwarz, Jensen, Weibull…).

## Zonas intocáveis para revisão de prosa

Uma edição gramatical **nunca** altera:

- matemática: `$…$`, `\(…\)`, `\[…\]`, `equation`, `align`, `gather`,
  `multline` e afins — nem espaçamento dentro deles;
- `\text{…}` dentro de matemática também fica como está (vai para o relatório,
  se tiver erro);
- nomes de ambiente, `\label{}`, `\ref{}`, `\eqref{}`, `\cite{}`, `\input{}`;
- `lstlisting`, `verbatim`, código R/Python, `tikzpicture`;
- linhas comentadas com `%`.

Se o erro de língua estiver dentro de uma dessas zonas, ele é reportado, não editado.

## Formato do relatório

Espelha `Estatistica/escritos/docs/revisao-erros.md`:

```markdown
# Revisão — <arquivo>

Levantamento feito em AAAA-MM-DD. Números de linha referem-se ao `.tex` nessa
data e podem ter deslocado.

## Achados matemáticos

- [ ] **<caminho/arquivo.tex>:<linha>** — [gravidade] problema. Correção: …
```

Gravidades, da mais grave para a menos: **falso**, **lacuna**, **imprecisão**,
**notação**, **apresentação**. Linhas vêm de `grep -n` ou do Read — nunca estimadas.

## Compilação

No diretório do livro:

```bash
latexmk -pdf -interaction=nonstopmode -halt-on-error main.tex
```

Para comparar com uma versão anterior sem mexer na árvore, compile uma cópia do
diretório do livro no scratchpad. Warnings de referência indefinida na primeira
passada não contam como erro.
