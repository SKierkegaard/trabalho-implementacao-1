# Trabalho de Implementação 1

**Instituição:** Universidade Federal do Maranhão
**Disciplina:** Estrutura de Dados 1
**Autor:** Pedro Vitório Arouche Campos

## Descrição
O Cofo é um TAD (Tipo Abstrato de Dados) que representa um "cofre" de números inteiros. O programa permite criar um cofo com capacidade fixa, inserir valores, remover um valor existente, consultar se um valor está presente, e destruir o cofo quando ele estiver vazio.

## Ambiente em que este sistema foi desenvolvido
- Sistema operacional: Arch Linux (Omarchy)
- IDE/Editor: Neovim
- Compilador: gcc (GCC) 16.2.1 20260810
- Linguagem: C

Caso o executável não rode no ambiente de correção, recompile com:

```bash
gcc -o ./build/main main.c cofo.c
./build/main
```

## Arquivos fonte

- cofo.h: Contém todas as declarações de dados, constantes, funções e estruturas  usadas por main.c.
- cofo.c: Contém os códigos das funções e estruturas usasas por main.c.
- main.c: Menu que permite criar, inserir, remover, consultar e destruir um cofo.

## Execução do programa

- Terminal:
```bash
./build/main
```

> *Caso não rode na sua máquina, recompile:*
```bash
gcc -o ./build/main main.c cofo.c
```

- VSCode:
1. Abra a pasta do projeto no VSCode (File > Open Folder).
2. Ctrl+Shift+B - roda a task de build (compila main.c + cofo.c).
3. Abra o terminal integrado (Ctrl+`) e rode:
```bash
./build/main
```

*O trabalho está disponível no meu github:* [trabalho-implementacao-1](https://github.com/SKierkegaard/trabalho-implementacao-1)
