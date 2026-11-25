# 🚗 Sistema de Estacionamento em C

## 📌 Sobre o projeto

Este projeto consiste no desenvolvimento de um sistema de gerenciamento de estacionamento utilizando a linguagem **C**, com foco na aplicação prática das estruturas de dados **Fila (Queue)** e **Pilha (Stack)**.

O sistema controla a entrada, organização, consulta e saída de veículos, respeitando a lógica de funcionamento de cada estrutura.

O projeto foi desenvolvido com **alocação dinâmica de memória**, utilizando `malloc()`, `calloc()` e `free()`, sem o uso de listas encadeadas.

## 🎯 Objetivos

- Aplicar os conceitos de estruturas de dados em C.
- Implementar uma fila seguindo o princípio FIFO.
- Implementar pilhas seguindo o princípio LIFO.
- Utilizar alocação dinâmica de memória.
- Integrar diferentes estruturas de dados em um único sistema.
- Simular o funcionamento de um estacionamento.

## 🛠️ Tecnologias utilizadas

- Linguagem C
- GCC (compilador)
- Alocação dinâmica de memória
- Estruturas de dados: Filas e Pilhas

## 🧩 Estruturas de dados

### 1. Fila (FIFO — First In, First Out)

Responsável pelo controle de entrada e espera dos veículos.

Funcionalidades:
- Registrar veículos na fila de entrada.
- Respeitar a ordem de chegada.
- Encaminhar veículos para vagas disponíveis.
- Controlar a capacidade da fila.

### 2. Pilha (LIFO — Last In, First Out)

Responsável pela organização dos veículos nas vagas do estacionamento.

Funcionalidades:
- Organizar veículos em pilhas.
- Controlar a capacidade de cada pilha.
- Empilhar e desempilhar veículos.
- Consultar a posição dos veículos.

### 3. Remoção e integração

Responsável pela retirada dos veículos e integração entre as estruturas.

Funcionalidades:
- Localizar o veículo solicitado.
- Remover temporariamente os veículos que estão acima dele.
- Utilizar uma pilha auxiliar para preservar a ordem.
- Retirar o veículo desejado.
- Devolver os veículos temporários à pilha original.
- Atualizar as vagas disponíveis e encaminhar veículos da fila de espera.

## 📂 Organização dos arquivos

```text
sistema-estacionamento/
│
├── estacionamento.h
├── main.c
├── fila.c
├── pilha.c
├── remocao.c
└── README.md
```

| Arquivo | Responsabilidade |
|---|---|
| `estacionamento.h` | Declaração das estruturas e funções |
| `main.c` | Menu principal e integração |
| `fila.c` | Operações da fila |
| `pilha.c` | Operações das pilhas |
| `remocao.c` | Remoção e consulta de veículos |
| `README.md` | Documentação do projeto |

## ⚙️ Alocação dinâmica de memória

O projeto utiliza alocação dinâmica para reservar memória durante a execução.

| Função | Aplicação |
|---|---|
| `malloc()` | Alocação de memória para fila e pilhas |
| `calloc()` | Alocação do conjunto de pilhas |
| `free()` | Liberação da memória utilizada |

A implementação utiliza armazenamento dinâmico para as estruturas de fila e pilha, sem listas encadeadas.

## 🚀 Como executar o projeto

### Pré-requisitos

- GCC instalado.
- Terminal ou ambiente de desenvolvimento com suporte à linguagem C.

### 1. Clone o repositório

```bash
git clone URL_DO_REPOSITORIO
```

### 2. Acesse a pasta do projeto

```bash
cd sistema-estacionamento
```

### 3. Compile os arquivos

```bash
gcc main.c fila.c pilha.c remocao.c -o estacionamento
```

### 4. Execute o programa

No Linux:

```bash
./estacionamento
```

No Windows:

```bash
estacionamento.exe
```

## 🖥️ Funcionalidades do sistema

Ao executar
