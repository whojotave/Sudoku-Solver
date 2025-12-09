# 🧩 Sudoku Solver em C++

Este projeto implementa um resolvedor de Sudoku utilizando a técnica de **backtracking**.  
Ele lê um tabuleiro 9×9 a partir de um arquivo, tenta resolvê-lo e salva a solução (ou `-1` caso não exista) em um arquivo de saída.

---

## 📌 Funcionalidades

- Leitura de tabuleiros 9×9 a partir de arquivo texto  
- Validação da configuração inicial  
- Resolução automática via backtracking recursivo  
- Salvamento do resultado em arquivo  
- Tratamento de erros (arquivos inválidos ou inexistentes)

---

## 📂 Estrutura do Projeto

main.cpp
Sudoku.h
Sudoku.cpp
README.md


---

## 📥 Formato da Entrada

O arquivo de entrada deve conter **81 números (0–9)** separados por espaços ou quebras de linha.

- `0` representa célula vazia  
- Qualquer dado inválido faz o programa encerrar 1


---

## 📤 Saída

Se houver solução, o arquivo de saída conterá o tabuleiro resolvido.  
Se **não houver solução**, o conteúdo será:

-1


---

## ▶️ Como Compilar e Executar

### Compilar:
```bash
g++ -std=c++11 main.cpp Sudoku.cpp -o sudoku

Executar:

./sudoku <arquivo_entrada> <arquivo_saida>

Exemplo:

./sudoku sudoku.txt resposta.txt
````
---

🧠 Algoritmo Utilizado

O resolvedor utiliza backtracking, seguindo estes passos:

    Encontra uma célula vazia

    Tenta números de 1 a 9

    Verifica validade na linha, coluna e bloco

    Caso gere conflito, desfaz e tenta outro

    Continua até completar ou detectar impossibilidade

---

🏗️ Implementação

Principais métodos da classe Sudoku:

    carregarArquivo() — lê o tabuleiro

    salvarArquivo() — grava a solução

    configuracaoInicialValida() — verifica conflitos

    ehPosicaoValida() — valida linha, coluna e bloco

    resolverBacktracking() — algoritmo recursivo

    resolverJogo() — integra validação + resolução

---

