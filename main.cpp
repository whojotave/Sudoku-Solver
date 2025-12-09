#include "Sudoku.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

    // Verifica se a quantidade de argumentos está correta
    if (argc != 3) {
        std::cerr << "Uso correto: " << argv[0]
                  << " <arquivo_entrada> <arquivo_saida>" << std::endl;
        return 1;
    }

    // Armazena os nomes dos arquivos informados pela linha de comando
    std::string nomeArquivoEntrada = argv[1];
    std::string nomeArquivoSaida   = argv[2];

    Sudoku jogoSudoku;  // Instância do jogo Sudoku

    // Carrega o tabuleiro do arquivo de entrada
    if (!jogoSudoku.carregarArquivo(nomeArquivoEntrada)) {
        std::cerr << "Erro: não foi possível processar o arquivo de entrada." << std::endl;
        return 1;
    }

    // Tenta resolver o Sudoku
    if (jogoSudoku.resolverJogo()) {

        // Se conseguiu resolver, salva o resultado no arquivo de saída
        if (!jogoSudoku.salvarArquivo(nomeArquivoSaida)) {
            std::cerr << "Erro ao salvar a solução no arquivo de saída." << std::endl;
            return 1;
        }

        std::cout << "Sudoku resolvido com sucesso!" << std::endl;

    } else {
        // Caso não seja possível resolver, grava -1 no arquivo de saída
        std::ofstream arquivoSaida(nomeArquivoSaida);

        if (!arquivoSaida.is_open()) {
            std::cerr << "Erro ao tentar abrir o arquivo de saída." << std::endl;
            return 1;
        }

        arquivoSaida << "-1" << std::endl;
        arquivoSaida.close();

        std::cout << "Não foi possível resolver o Sudoku." << std::endl;
    }

    return 0;
}
