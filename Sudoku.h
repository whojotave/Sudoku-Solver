#ifndef SUDOKU_H
#define SUDOKU_H

#include <string>

class Sudoku {
private:
    // Matriz 9x9 representando o tabuleiro
    int** grade;

    // Verifica se um número pode ser colocado em (linha, coluna)
    bool ehPosicaoValida(int linha, int coluna, int numero);

    // Verifica se o número existe dentro do bloco 3x3
    bool numeroPresenteNoBloco(int linhaInicio, int colunaInicio, int numero);

    // Backtracking recursivo
    bool resolverBacktracking();

    // Verifica se a configuração inicial respeita as regras
    bool configuracaoInicialValida();

public:
    // Construtor
    Sudoku();
    ~Sudoku();

    // Lê o tabuleiro de um arquivo de entrada
    bool carregarArquivo(const std::string& nomeArquivo);

    // Salva o tabuleiro (resolvido ou não) em um arquivo de saída
    bool salvarArquivo(const std::string& nomeArquivo);

    // Resolve o Sudoku chamando o backtracking
    bool resolverJogo();
};

#endif
