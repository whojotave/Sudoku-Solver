#include "Sudoku.h"
#include <fstream>
#include <iostream>

Sudoku::Sudoku() {
    // Inicializa o tabuleiro com zeros
    grade = new int*[9];
    for (int i = 0; i < 9; i++) {
        grade[i] = new int[9];
        for (int j = 0; j < 9; j++) {
            grade[i][j] = 0;
        }
    }
}
Sudoku::~Sudoku() {
    for (int i = 0; i < 9; i++) {
        delete[] grade[i];
    }
    delete[] grade;
}


bool Sudoku::carregarArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir arquivo de entrada: " << nomeArquivo << std::endl;
        return false;
    }

    // Lê os 81 números do tabuleiro
    for (int linha = 0; linha < 9; linha++) {
        for (int coluna = 0; coluna < 9; coluna++) {
            if (!(arquivo >> grade[linha][coluna])) {
                std::cerr << "Erro ao ler dados do arquivo." << std::endl;
                arquivo.close();
                return false;
            }
        }
    }

    arquivo.close();
    return true;
}

bool Sudoku::salvarArquivo(const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir arquivo de saída: " << nomeArquivo << std::endl;
        return false;
    }

    // Escreve a matriz 9x9 no arquivo
    for (int linha = 0; linha < 9; linha++) {
        for (int coluna = 0; coluna < 9; coluna++) {
            arquivo << grade[linha][coluna];
            if (coluna < 8)
                arquivo << " ";
        }
        arquivo << "\n";
    }

    arquivo.close();
    return true;
}

bool Sudoku::configuracaoInicialValida() {
    // Verifica todas as posições preenchidas
    for (int linha = 0; linha < 9; linha++) {
        for (int coluna = 0; coluna < 9; coluna++) {
            if (grade[linha][coluna] != 0) {
                int numero = grade[linha][coluna];
                grade[linha][coluna] = 0;

                if (!ehPosicaoValida(linha, coluna, numero)) {
                    grade[linha][coluna] = numero;
                    return false;
                }

                grade[linha][coluna] = numero;
            }
        }
    }

    return true;
}

bool Sudoku::ehPosicaoValida(int linha, int coluna, int numero) {
    // Verifica linha
    for (int j = 0; j < 9; j++) {
        if (j != coluna && grade[linha][j] == numero)
            return false;
    }

    // Verifica coluna
    for (int i = 0; i < 9; i++) {
        if (i != linha && grade[i][coluna] == numero)
            return false;
    }

    // Verifica bloco 3x3
    int inicioBlocoLinha = (linha / 3) * 3;
    int inicioBlocoColuna = (coluna / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int l = inicioBlocoLinha + i;
            int c = inicioBlocoColuna + j;

            if (l != linha && c != coluna && grade[l][c] == numero)
                return false;
        }
    }

    return true;
}

bool Sudoku::numeroPresenteNoBloco(int linhaInicio, int colunaInicio, int numero) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grade[linhaInicio + i][colunaInicio + j] == numero)
                return false;
        }
    }
    return true;
}

bool Sudoku::resolverBacktracking() {
    for (int linha = 0; linha < 9; linha++) {
        for (int coluna = 0; coluna < 9; coluna++) {

            if (grade[linha][coluna] == 0) { // Célula vazia encontrada

                for (int numero = 1; numero <= 9; numero++) {

                    if (ehPosicaoValida(linha, coluna, numero)) {

                        grade[linha][coluna] = numero;

                        // Continua recursivamente
                        if (resolverBacktracking())
                            return true;

                        // Backtracking
                        grade[linha][coluna] = 0;
                    }
                }

                return false; // Nenhum número funcionou
            }
        }
    }

    return true; // Tabuleiro completo
}

bool Sudoku::resolverJogo() {
    // Primeiro verifica se o tabuleiro inicial está correto
    if (!configuracaoInicialValida())
        return false;

    return resolverBacktracking();
}
