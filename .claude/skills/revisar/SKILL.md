---
name: revisar
description: Revisa um arquivo .tex dos Escritos com os agentes revisor-gramatical (edita), revisor-matematico (reporta) e revisor-batida (confere os dois), grava os achados em <livro>/docs/ e reverte edições gramaticais reprovadas. Use quando pedirem revisão de um capítulo, seção ou arquivo.
argument-hint: <arquivo.tex> [tudo|gramatica|matematica]
---

# Revisão de um arquivo

Argumentos: `$ARGUMENTS` — caminho do `.tex` e, opcionalmente, o modo
(`tudo` é o padrão). Se o caminho não existir ou não for `.tex`, pare e diga.

## 0. Preparação

- Descubra o **livro**: o diretório ancestral mais próximo com `main.tex`.
- Crie `<scratchpad>/revisao-<nome>-<timestamp>/` e copie o arquivo para lá como
  `original.tex` — esse é o snapshot, independente do estado do git.
- Se o arquivo tem alterações não commitadas, avise o usuário numa linha (o diff
  da revisão vai se misturar com o dele) e continue.

## 1. Revisores

Rode os agentes **em sequência** com a ferramenta Agent, passando caminhos
absolutos:

1. `gramatica` ou `tudo`: **revisor-gramatical** sobre o arquivo. Guarde o
   relatório.
2. `matematica` ou `tudo`: **revisor-matematico** sobre o arquivo (já com as
   edições gramaticais). Guarde o relatório.
3. Sempre: **revisor-batida**, com snapshot, arquivo atual, os relatórios dos
   passos anteriores e o diretório de trabalho.

Não rode os dois primeiros em paralelo: o matemático precisa ver o texto final.

## 2. Aplicar o veredito da batida

- Cada edição gramatical marcada `reverter`: restaure o trecho a partir do
  `original.tex` com Edit. Não reverta nada que a batida marcou `ok`.
- Se a batida acusou erro de compilação novo causado por edição gramatical,
  reverta essa edição também.

## 3. Relatório

Grave em `<livro>/docs/revisao-<nome-do-arquivo-sem-.tex>.md` no formato da skill
`estilo-escritos`. Se o arquivo já existir, **acrescente** uma nova seção datada
no fim em vez de sobrescrever.

- Entram na lista `- [ ]` apenas os achados matemáticos **confirmados** e
  **ajustados** (com a correção da batida, quando ajustada), ordenados por
  gravidade, cada um com os dependentes afetados.
- Seção curta **Descartados pela batida**: achado + motivo em uma linha.
- Seção curta **Edições gramaticais revertidas**: trecho + motivo.
- Dúvidas gramaticais e erros em zonas intocáveis relatados pelo gramatical
  entram como `- [ ]` numa seção **Língua (não editado)**.

## 4. Resumo no terminal

Em poucas linhas: edições gramaticais aplicadas / revertidas, achados
matemáticos por gravidade (e quantos descartados), status da compilação, e o
caminho do relatório. Não commite — o usuário usa `/commit` quando quiser.
