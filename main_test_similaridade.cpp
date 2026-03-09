#include "listacompras.hpp"
#include "similaridade.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Uso: ./teste_similaridade <arquivo_csv>\n";
        return 1;
    }

    std::string caminhoCSV = argv[1];

    try {
        ListaCompras lista;
        lista.carregarCSV(caminhoCSV);
        lista.imprimirResumo();

        std::cout << "\n--- INICIANDO MODULO DE SIMILARIDADE ---\n";
        Similaridade sim(lista);
        std::cout << "Matriz de similaridade computada com sucesso!\n\n";

        // O entregável pede para testar dois clientes quaisquer por índice interno
        int clientesParaTestar[2] = {0, 1}; // Vamos testar os índices internos 0 e 1

        for (int i = 0; i < 2; ++i) {
            int indiceAlvo = clientesParaTestar[i];
            int indiceVizinho = sim.getClienteMaisSimilar(indiceAlvo);

            std::cout << "--------------------------------------------------\n";
            std::cout << "Analisando Cliente [Indice " << indiceAlvo << "]\n";
            
            if (indiceVizinho != -1) {
                double distancia = sim.getSimilaridade(indiceAlvo, indiceVizinho);
                std::cout << "Vizinho mais similar encontrado: [Indice " << indiceVizinho << "]\n";
                std::cout << "Distancia de Jaccard: " << distancia << " (quanto mais perto de 0, mais parecido)\n";
            } else {
                std::cout << "Nenhum vizinho similar encontrado.\n";
            }
        }

    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << '\n';
        return 1;
    }

    return 0;
}