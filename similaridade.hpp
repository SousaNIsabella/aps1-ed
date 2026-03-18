#ifndef SIMILARIDADE_HPP
#define SIMILARIDADE_HPP

#include "listacompras.hpp"
#include <vector>

class Similaridade {
private:
    std::vector<std::vector<double>> matrizSimilaridade;
    int numClientes;
    int numProdutos;

public:
    // Construtor que recebe a lista e já processa as matrizes
    Similaridade(const ListaCompras& lista);

    // Retorna a distancia calculada entre dois clientes
    double getSimilaridade(int indiceClienteA, int indiceClienteB) const;

// Encontra o cliente mais proximo (menor distancia) para um dado cliente
    int getClienteMaisSimilar(int indiceCliente) const;
};

#endif